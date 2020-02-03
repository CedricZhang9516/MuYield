#include "MuYield.h"
#include "MyMuonDecay.h"
#include "InitializingXYZ0.h"
#include "DiffusionModel.h"

void MuYield(
	TString name = "Dev_200202",
	int MCtype = 2,
	int Nrepeat = 1e3,//8.4e5,//2e6,//8.4e5,//1e6,//2.8e5,//1e6,//2.8e4,
	int flag_xfree = 1,
	int flag_newGeo = 0,
	double Thick = 7.12)
{
	cout<<"Initialize..."<<endl;

/*
	omega_x = 14*Bx/(2*PI);
	omega_y = 14*By/(2*PI);
	omega_z = 14*Bz/(2*PI);
*/

	N_DiffusionTrack = -1;//4660 for new geo; 271 for old geo.//gRandom->Integer(Nrepeat);
	flag_DiffusionTrack = 0;

	if(flag_newGeo == 1) Thick = 2;
	if(flag_newGeo == 0) Thick = 7.12;

	//MCtype:
	// 1: My own MC
	// 2: TRIUMF
	// 3: H-line file input
	//flag = 0: no x limit, otherwise = 1;


	treefile = new TFile(Form("./Root/%s_tree_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d_.root",
		name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo), "recreate");
	tree = new TTree("tree","MuYield event");
	SetTreeBranch(tree);

	histfile = new TFile(Form("./Root/%s_hist_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d_.root",
		name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo), "recreate");
	SetHist(histfile);


	// only for test!!!
/*
	TFile * f5 = new TFile("./Root/3tmp_Hline.root");
	TH1D *hY0tgt_hline = new TH1D("hY0tgt_hline","hY0tgt_hline",2000,-100,100); // mm
	hY0tgt_hline = (TH1D*)f5->Get("hY0tgt");
*/

	//////Read from hline file to generate actual simulation
	// H-line
	double x_dec, y_dec, z_dec, Nentries;
	TFile *hlinefile = new TFile("./Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root");
	TTree * Thlinefile = (TTree*) hlinefile->Get("101");
	Thlinefile->SetBranchAddress("x_dec", &x_dec);
	Thlinefile->SetBranchAddress("y_dec", &y_dec);
	Thlinefile->SetBranchAddress("z_dec", &z_dec);
	Nentries = Thlinefile->GetEntries();

	if(MCtype == 3) Nrepeat = Nentries;

	//if(MCtype == 3)


	//static double ResultSP[6];

	////////////////////////////////////////

	cout<<Form("Main Monte Carlo Simulation:\n_MCType_%0.0d_D_%0.0f_T_%0.0f_Nrepeat_%0.0d_flag_xfree_%d_thick_%0.2f_NewGeo_%d_",MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo)<<endl;

	Nemission = 0;
	NLaserR = 0;
	NLaserL = 0;


	histfile->cd();

	for(int index_m=0; index_m < Nrepeat; index_m++){

		if(index_m>=10000 && index_m%10000==0) cout << index_m << " in the total of  "<<Nrepeat<<endl;

		InitialTreeVar();

		// Initializing the XYZ0
		if(MCtype == 3){
			Thlinefile->GetEntry(index_m);
			if (z_dec > 0 || z_dec < -Thick) continue;
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
		}
		else InitializingXYZ0( MCtype, &X0, &Y0, &Z0 );
		if( fabs(Y0)>20)continue;

		/// Generate the time structure

		if(MCtype == 2) TBeam = 0;
		else{
			TBeam = GenerateUniform(0.0e-6,0.2e-6);
			if( ((double) rand() / (RAND_MAX))<=0.5 )TBeam = TBeam + 0.6e-6;
		}


		// Generate Maxwell-Boltzmann speed distribution.
		do{
			tempX = ((double) rand() / (RAND_MAX)) * 3*sqrt(2*k*T/massMu);
			tempY = ((double) rand() / (RAND_MAX)) * 2*sqrt(2*massMu/PI/k/T)*exp(-1.0);

		}while(
			tempY>sqrt(2/PI*pow(massMu/k/T,3))*pow(tempX,2)*exp(-massMu*tempX*tempX/(2*k*T))
			);

		vel0 = tempX*1000 ; // UNIT: [mm/s]


		// Random walk, Generate theta and phi
		tempX = TMath::ACos(-1 + 2 * ((double)rand()/(RAND_MAX)));
		tempY = ((double) rand()/(RAND_MAX)) * 2* PI;

		theta0 = tempX;  // in rad unit: [0,PI]
		phi0 = tempY; //[0,+2PI] radians


		// initial velocity input in MCmfp random walk
		Vx0 = vel0 * sin(theta0) * cos(phi0);
		Vy0 = vel0 * sin(theta0) * sin(phi0);
		Vz0 = vel0 * cos(theta0);

		Lmfp = 12*D/(PI * vel0_avrg);//mm

		// Generate time of Mu Lifetime
		do{
			tempX = ((double) rand() / (RAND_MAX)) * 10e-5;  // t=0~10^-5 s
			tempY = ((double) rand() / (RAND_MAX)) * 1/lifeMu;

		} while (tempY>1/lifeMu*exp(-tempX/lifeMu) );

		DecayT = tempX;

		SpinX = 0;
		SpinY =   TMath::Sin(2*PI * 11.54/360);
		SpinZ = - TMath::Cos(2*PI * 11.54/360);

		TVector3 Spin(SpinX, SpinY, SpinZ);

		DecayPositronMomtX = 0;
		DecayPositronMomtY = 0;
		DecayPositronMomtZ = 0;

		TVector3 Bamb(Bx,By,Bz);

		//TVector3 Spin2 = Spin - Spin.Dot(Bamb.Unit())*Bamb.Unit();
		//TVector3 Spin3 = Spin.Dot(Bamb.Unit())*Bamb.Unit();

		double Omega = 14 * Bamb.Mag() * (2*PI);
		double delT = DecayT;
		//double delT = DecayT - TBeam;

		Spin.Rotate(Omega * delT *1e6, Bamb); // rotation around v2

		//Spin2.Rotate(Omega * delT * 1e6, Bamb);
		//Spin3 = Spin2 + Spin3;

		SpinX = Spin.X();
		SpinY = Spin.Y();
		SpinZ = Spin.Z();

		TVector3* DecayPositronMomentum = G4MuonDecay(Spin);

		DecayPositronMomtX = DecayPositronMomentum->X();
		DecayPositronMomtY = DecayPositronMomentum->Y();
		DecayPositronMomtZ = DecayPositronMomentum->Z();

		//////////////// Fill the necessary histogram for the check

		hLmfp->Fill(Lmfp * 1000);//um
		hDecayT->Fill(DecayT);
		hvel0->Fill(vel0);
		T0->Fill(TBeam);
		hZ0tgt->Fill(Z0);
		hX0tgt->Fill(X0);
		hY0tgt->Fill(Y0);
		hTheta0->Fill(TMath::Cos(theta0));
		hPhi0->Fill(phi0);

		////////////////




		DiffusionModel(
			//&X0, &Y0, &Z0,
			//Vx0, Vy0, Vz0, theta0, phi0,
			InsideAerogel//void (*GeometryFunction)(double, double, double),
			//&DiffusionVertexX,
			//&DiffusionVertexY,
			//&DiffusionVertexZ
			//DecayT, Thick,
			//&DiffusionT,
			//&X_sf, &Y_sf, &Z_sf,
			//&VX_sf, &VY_sf, &VZ_sf,
			//&theta_sf, &phi_sf
		);
		//cout<<DiffusionT<<endl;
		//cout<<DiffusionVertexX->at(DiffusionVertexX->size()-1)<<DiffusionVertexY->at(DiffusionVertexX->size()-1)<<endl;

		DecayX = X_sf + VX_sf * (DecayT - t0);
		DecayY = Y_sf + VY_sf * (DecayT - t0);
		DecayZ = Z_sf + VZ_sf * (DecayT - t0);



		if(flag_newGeo == 0 && Z_sf<0){
			tree->Fill();
			continue;
		}


		if( t0 >= DecayT ){
			tree->Fill();
			continue;
		}

		if( MCtype == 2 && t0 >= DecayT)hTlaserVtot->Fill(DecayT+TBeam); //Only for TRIUMF



		/////////////////// Here the Mu successfully get emitted out of the aerogel

		Nemission++;

		tree->Fill();

	}



	///////// Draw the last event's tracks
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");


	histfile->Write();

	//////// Save the tree file
	treefile->cd();
	treefile->Write();
	cout<<"Tree (Mesh) Entries: "<<tree->GetEntries()<<endl;

		//return ResultSP;
}



int InsideAerogel(double x, double y, double z){

	if( (z <= 0 && z >= -7.12 )
		|| (z <= -9 && z >= -11)
		|| (z <= 9 && z >= 7) ) return 1;
	else return 0;

}

bool InsideLaserRegion(double x, double y, double z){ // t = t0 + tbeam
	if( (DecayT + TBeam) < tLaser) return false;
	if( (t0 + TBeam) > tLaser)return false;

	if( flag_xfree == 0 && (fabs(x)>20 || fabs(y)>20) )return false;
	if( flag_xfree == 1 && fabs(y)>20 )return false;

	if( z <= 6 && z>= 1)return true;
	if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
	return false;
}

















void Setstyle(TH1D *g, int c){
	g->SetFillColor(c);
    g->SetFillStyle(3001);
    g->SetLineColor(c);
    g->SetMarkerColor(1);
   	g->SetMarkerSize(0.5);
    g->SetMarkerStyle(20);
}

void SetstyleG(TGraph *g, Int_t c){
    g->SetLineColor(c);
    g->SetLineStyle(4);
    g->SetLineWidth(4);
    g->SetMarkerColor(c);
    g->SetMarkerStyle(14);

}
double expo(double x, double a)
{
	return exp(-x/a);
}

double GenerateGaus(double mean, double sigma){
    return gRandom->Gaus(mean,sigma);

}
double GenerateUniform(double ti,double tf){

    return gRandom->Uniform(ti,tf);
}

double GenerateHlineY(TH1D *hY0tgt_hline){

	int intn;
	do{
		tempX = ((double) rand() / (RAND_MAX)) * 6000;  // l=0~0.01 mm
		tempY = -60 + ((double) rand() / (RAND_MAX)) * 120;  // l=0~0.01 mm
		tempZ = (tempY*10.0)/1 ;

		intn = (int) tempZ;

	}while(tempX>hY0tgt_hline->GetBinContent((intn + 1001)));

	return tempY;
}
/*
double* MCLmfp(){

	t = 0;
	z = Z0;
	x = X0;
	y = Y0;
	vx = Vx0;
	vy = Vy0;
	vz = Vz0;
	theta = theta0;
	phi = phi0;

	double L;
	int N = 0; // only for debug

	static double ResultDiff[9];

	do{

		//if(flag_DiffusionTrack==1){DiffusionTrack->SetPoint(N,z,y);}//cout<<"filling track"<<N<<endl;}

		// generate the L step lenth according to Lmfp exp. distri.
		do {
			tempX = ((double) rand() / (RAND_MAX)) * 5;  // l=0~0.01 mm
			tempY = ((double) rand() / (RAND_MAX)) * 1/Lmfp;
		} while (tempY>1/Lmfp*exp(-tempX/Lmfp) );

		L = tempX;

		t = t + L/vel0;
		x = x + vx * (L/vel0);
		y = y + vy * (L/vel0);
		z = z + vz * (L/vel0);

		if( (z <= 0 && z >= -Thick) || (z <= -9 && z >= -11) || (z <= 9 && z >= 7) )//(z <= 14.12 && z >= 7) )//(z <= -9 && z >= -11) || (z <= 9 && z >= 7) )
		{

			tempX = TMath::ACos(-1 + 2 * ((double)rand()/(RAND_MAX)) );
			tempY = ((double) rand()/(RAND_MAX)) * 2* PI;

			theta = tempX;  // [0,+PI] radians
			phi = tempY; //[0,+2PI] radians

			vx = vel0 * sin(theta) * cos(phi);
			vy = vel0 * sin(theta) * sin(phi);
			vz = vel0 * cos(theta);
		}
		N++;

	}while( (z <= 0 && z >= -Thick && t<DecayT)
		|| (z <= -9 && z >= -11 && t<DecayT)
		|| (z <= 9 && z >= 7 && t<DecayT)
		);

	if( MCtype != 2 && (fabs(y)>130 || fabs(x)>130) ) t = 100000;

	Nhits = N;

	if(t>DecayT)t = t - L/vel0;

	ResultDiff[0] = t;
	ResultDiff[1] = x;
	ResultDiff[2] = y;
	ResultDiff[3] = z;
	ResultDiff[4] = vx;
	ResultDiff[5] = vy;
	ResultDiff[6] = vz;
	ResultDiff[7] = theta;
	ResultDiff[8] = phi;
	return ResultDiff;
}
*/
/*
void FillTZ()
{

	double delT = DecayT - t0;

	t = t0;

	x = X_sf;
	y = Y_sf;
	z = Z_sf;
	vx = VX_sf;
	vy = VY_sf;
	vz = VZ_sf;

	//double flag = 0;

	for(int i =0; i < nbinT; i++){

		if(Tstep*i >= delT)break;

		x = x + vx * (Tstep);
		y = y + vy * (Tstep);
		z = z + vz * (Tstep);
		t = t + Tstep;

		hZT2D->Fill(TBeam + t, z);

		if(fabs(y)<=20 && Tstep*i <= delT)
		{
			if( (MCtype == 1 || MCtype == 3) && flag_xfree == 0 && fabs(x)>20)continue;
			if( z >= 1 && z <= 6) {hTlaserR->Fill(TBeam + t);}
			if( z >= (-6-Thick) && z <= (-1-Thick)) {hTlaserL->Fill(TBeam + t);}
		}
	}
}
*/

/*
void ShootLaser(double distance, double x_, double y_, double z_, double vx_, double vy_ ,double vz_)
{
	x = x_;
	y = y_;
	z = z_;

	vx = vx_;
	vy = vy_;
	vz = vz_;

	t = (sqrt(vz*vz + 2*A * distance) - vz)/A;

	x = x + vx * t ;
	y = y + vy * t ;
	z = z + vz * t + 0.5 * A * t * t;

	vz = vz + A * t;

	double v = sqrt(vx*vx + vy*vy + vz*vz);

	double Xp = vx/vz;
	double Yp = vy/vz;

	double beta = v * 1e-3/light;
	double Ek = 0.5 * massMu * 1e-6 * (vx*vx + vy*vy + vz*vz);//v:mm/s, Ek: MeV


	MeshX = x;
	MeshY = y;
	MeshZ = z;

	MeshVX = vx;
	MeshVY = vy;
	MeshVZ = vz;

	MeshT = t;
	MeshT_ab = MeshT + tLaser;
	MeshXp = Xp;
	MeshYp = Yp;
	MeshEk = Ek;
	MeshBeta = beta;

	///////// Drift

	t = DriftD/vz;//500mm
	DriftT = t;
	DriftT_ab = DriftT + MeshT_ab;

	DriftZ = MeshZ + MeshVZ * t;
	DriftX = MeshX + MeshVX * t;
	DriftY = MeshY + MeshVY * t;

}
*/

/*
void ShootLaserPulseE(double distance, double x_, double y_, double z_, double vx_, double vy_ ,double vz_)
{

	vz = 5.652e6;//mm/s
	double PulseD = 10;//10 mm
	double PulseT = (sqrt(vz*vz + 2*A * PulseD) - vz)/A;

	x = x_;
	y = y_;
	z = z_;

	vx = vx_;
	vy = vy_;
	vz = vz_;

	t = (sqrt(vz*vz + 2*A * distance) - vz)/A;

	if(t>=PulseT){
		distance = distance - vz * PulseT - 0.5 * A * PulseT * PulseT;

		z = z + vz * PulseT + 0.5 * A * PulseT * PulseT;
		vz = vz + A * PulseT;


		double delt = distance/vz;

		x = x + vx * delt ;
		y = y + vy * delt ;
		z = z + vz * delt ;

		//cout<<z<<endl;

	}

	if(t<PulseT){

		x = x + vx * t ;
		y = y + vy * t ;
		z = z + vz * t + 0.5 * A * t * t;

		vz = vz + A * t;
	}

	double v = sqrt(vx*vx + vy*vy + vz*vz);

	double Xp = vx/vz;
	double Yp = vy/vz;

	double beta = v * 1e-3/light;
	double Ek = 0.5 * massMu * 1e-6 * (vx*vx + vy*vy + vz*vz);//v:mm/s, Ek: MeV


	MeshX = x;
	MeshY = y;
	MeshZ = z;

	MeshVX = vx;
	MeshVY = vy;
	MeshVZ = vz;

	MeshT = t;
	MeshT_ab = MeshT + tLaser;
	MeshXp = Xp;
	MeshYp = Yp;
	MeshEk = Ek;
	MeshBeta = beta;

	///////// Drift

	t = DriftD/vz;//500mm
	DriftT = t;
	DriftT_ab = DriftT + MeshT_ab;

	DriftZ = MeshZ + MeshVZ * t;
	DriftX = MeshX + MeshVX * t;
	DriftY = MeshY + MeshVY * t;

}
*/



void SetTreeBranch(TTree * tree){

	tree->Branch("TBeam",&TBeam,"TBeam/D");
	tree->Branch("DecayT",&DecayT,"DecayT/D");
	tree->Branch("X0",&X0,"X0/D");
	tree->Branch("Y0",&Y0,"Y0/D");
	tree->Branch("Z0",&Z0,"Z0/D");
	tree->Branch("vel0",&vel0,"vel0/D");
	tree->Branch("theta0",&theta0,"theta0/D");
	tree->Branch("phi0",&phi0,"phi0/D");
	tree->Branch("Vz0",&Vz0,"Vz0/D");
	tree->Branch("Vx0",&Vx0,"Vx0/D");
	tree->Branch("Vy0",&Vy0,"Vy0/D");
	tree->Branch("Lmfp",&Lmfp,"Lmfp/D");

	tree->Branch("t0",&t0,"t0/D");
	tree->Branch("DiffusionT",&DiffusionT,"DiffusionT/D");

	tree->Branch("X_sf",&X_sf,"X_sf/D");
	tree->Branch("Y_sf",&Y_sf,"Y_sf/D");
	tree->Branch("Z_sf",&Z_sf,"Z_sf/D");
	tree->Branch("VX_sf",&VX_sf,"VX_sf/D");
	tree->Branch("VY_sf",&VY_sf,"VY_sf/D");
	tree->Branch("VZ_sf",&VZ_sf,"VZ_sf/D");
	tree->Branch("theta_sf",&theta_sf,"theta_sf/D");
	tree->Branch("phi_sf",&phi_sf,"phi_sf/D");

	//double DiffusionT;
	tree->Branch("DiffusionVertexX", DiffusionVertexX, "DiffusionVertexX/D");// std::vector<double> DiffusionVertexX;
	tree->Branch("DiffusionVertexY", DiffusionVertexY, "DiffusionVertexY/D");// std::vector<double> DiffusionVertexY;
	tree->Branch("DiffusionVertexZ", DiffusionVertexZ, "DiffusionVertexZ/D");// std::vector<double> DiffusionVertexZ;
	tree->Branch("DiffusionVertexT", DiffusionVertexT, "DiffusionVertexT/D");// std::vector<double> DiffusionVertexT;

	tree->Branch("DecayX",&DecayX,"DecayX/D");
	tree->Branch("DecayY",&DecayY,"DecayY/D");
	tree->Branch("DecayZ",&DecayZ,"DecayZ/D");

	tree->Branch("SpinX",&SpinX,"SpinX/D");
	tree->Branch("SpinY",&SpinY,"SpinY/D");
	tree->Branch("SpinZ",&SpinZ,"SpinZ/D");

	tree->Branch("DecayPositronMomtX",&DecayPositronMomtX,"DecayPositronMomtX/D");
	tree->Branch("DecayPositronMomtY",&DecayPositronMomtY,"DecayPositronMomtY/D");
	tree->Branch("DecayPositronMomtZ",&DecayPositronMomtZ,"DecayPositronMomtZ/D");






	tree->Branch("LaserX",&LaserX,"LaserX/D");
	tree->Branch("LaserY",&LaserY,"LaserY/D");
	tree->Branch("LaserZ",&LaserZ,"LaserZ/D");
	tree->Branch("LaserE",&LaserE,"LaserE/D");
	tree->Branch("LaserXp",&LaserXp,"LaserXp/D");
	tree->Branch("LaserYp",&LaserYp,"LaserYp/D");

	tree->Branch("MeshEk",&MeshEk,"MeshEk/D");
	tree->Branch("MeshE",&MeshE,"MeshE/D");
	tree->Branch("MeshT",&MeshT,"MeshT/D");
	tree->Branch("MeshT_ab",&MeshT_ab,"MeshT_ab/D");
	tree->Branch("MeshX",&MeshX,"MeshX/D");
	tree->Branch("MeshY",&MeshY,"MeshY/D");
	tree->Branch("MeshZ",&MeshZ,"MeshZ/D");
	tree->Branch("MeshXp",&MeshXp,"MeshXp/D");
	tree->Branch("MeshYp",&MeshYp,"MeshYp/D");
	tree->Branch("MeshBeta",&MeshBeta,"MeshBeta/D");
	tree->Branch("MeshVY",&MeshVY,"MeshVY/D");
	tree->Branch("MeshVX",&MeshVX,"MeshVX/D");
	tree->Branch("MeshVZ",&MeshVZ,"MeshVZ/D");

	tree->Branch("DriftT",&DriftT,"DriftT/D");
	tree->Branch("DriftT_ab",&DriftT_ab,"DriftT_ab/D");
	tree->Branch("DriftX",&DriftX,"DriftX/D");
	tree->Branch("DriftY",&DriftY,"DriftY/D");
	tree->Branch("DriftZ",&DriftZ,"DriftZ/D");
}

void SetHist(TFile * f){

	 T0 = new TH1D("T0","T0",100,0,1.0e-6); // Tbeam distribution

	 hLmfp = new TH1D("hLmfp","hLmfp;Lmfp (um)",100,0,100); // um

	 hX0tgt = new TH1D("hX0tgt","hX0tgt",2000,-100,100); // mm
	 hY0tgt = new TH1D("hY0tgt","hY0tgt",2000,-100,100); // mm
	 hZ0tgt = new TH1D("hZ0tgt","hZ0tgt",100,-11,9); // mm

	 hZ0tgt_emission = new TH1D("hZ0tgt_emission","hZ0tgt_emission; mm",200,-11,9); // mm

	 hvel0 = new TH1D("hvel0","hvel0",50,0,30000000); // mm/s
	 hTheta0 = new TH1D("hTheta0-cos","Cos(Theta0)",100,-1,1); // cos(theta)
	 hPhi0 = new TH1D("hPhi0","hPhi0",100,0,2*PI); // rad


	 hZT2D = new TH2D("Z-T-2D","Z-T-2D; t(us);z (mm)",100,0e-7,10e-6,1000,-50,50);
	 hTlaserR = new TH1D("T-laser-R","T-laser-R",nbinT,0,Tstep*nbinT);
	 hTlaserL = new TH1D("T-laser-L","T-laser-L",nbinT,0,Tstep*nbinT);

	 hZLaserR = new TH1D("hZLaser-r","hZLaser-r",50,1,6);  // mm
	 hZLaserL = new TH1D("hZLaser-l","hZLaser-l",50,-6-Thick,-1-Thick);  // mm
	//hZlaser right, but no need this plot anymore

	 hDecayX = new TH1D("hDecayX","hDecayX",100,-2,2);  // mm
	 hDecayY = new TH1D("hDecayY","hDecayY",100,-2,2);  // mm
	 hDecayZ = new TH1D("hDecayZ","hDecayZ",100,-10,40);  // mm
	 hDecayT = new TH1D("hDecayT","hDecayT",50,0,12e-6);  // s


	// for TRIUMF case v1-v3
	 hTlaserVtot = new TH1D("T-laser-totV","T-laser-totV",120,0,12e-6);
	 hTlaserV1 = new TH1D("T-laser-v1","T-laser-v1",120,0,12e-6);
	 hTlaserV2 = new TH1D("T-laser-v2","T-laser-v2",120,0,12e-6);
	 hTlaserV3 = new TH1D("T-laser-v3","T-laser-v3",120,0,12e-6);

	 TEmission = new TH1D("TEmission","TEmission",100,0,10e-6);
	 VEmission = new TH1D("VEmission","VEmission;mm/s",100,0,2e7);

	// this two maybe helpful with hZLaser
	 hXLaser = new TH1D("hXLaser","hXLaser",100,-40,40);  // mm
	 hYLaser = new TH1D("hYLaser","hYLaser",100,-40,40);  // mm


	 hTheta0_emission = new TH1D("hTheta0_emission","hTheta0_emission",100,0,1); // rad
	 hPhi0_emission = new TH1D("hPhi0_emission","hPhi0_emission",100,0,1); // rad
	 hEmissionXY = new TH2D("hEmissionXY","hEmissionXY; x(mm);y (mm)",640,-320,320,640,-320,320);

	 DiffusionTrack = new TGraph();

}

void WriteHist(){

	 T0 ->Write();

	 hLmfp ->Write();

	 hX0tgt ->Write();
	 hY0tgt ->Write();
	 hZ0tgt ->Write();

	 hZ0tgt_emission ->Write();

	 hvel0 ->Write();
	 hTheta0 ->Write();
	 hPhi0 ->Write();


	 hZT2D ->Write();
	 hTlaserR ->Write();
	 hTlaserL ->Write();

	 hZLaserR ->Write();
	 hZLaserL ->Write();
	//hZlaser right, but no need this plot anymore

	 hDecayX ->Write();
	 hDecayY ->Write();
	 hDecayZ ->Write();
	 hDecayT ->Write();


	// for TRIUMF case v1-v3
	 hTlaserVtot ->Write();
	 hTlaserV1 ->Write();
	 hTlaserV2 ->Write();
	 hTlaserV3 ->Write();

	 TEmission ->Write();
	 VEmission ->Write();

	// this two maybe helpful with hZLaser
	 hXLaser ->Write();
	 hYLaser ->Write();


	 hTheta0_emission ->Write();
	 hPhi0_emission ->Write();
	 hEmissionXY ->Write();


}

void InitialTreeVar(){
	TBeam = -1;
	DecayT = -1;
	X0 = -1;
	Y0 = -1;
	Z0 = -1;
	vel0 = -1;
	theta0 = -1;
	phi0 = -1;
	Vz0 = -1;
	Vx0 = -1;
	Vy0 = -1;
	Lmfp = -1;

	t0 = -1;// is not the initial t, but the total time spent inside aerogel
	DiffusionT = -1;

	// diffusion/surface information

	X_sf = -1;
	Y_sf = -1;
	Z_sf = -1;
	VX_sf = -1;
	VY_sf = -1;
	VZ_sf = -1;
	theta_sf = -1;
	phi_sf = -1;

	DecayX = -1;
	DecayY = -1;
	DecayZ = -1;

	DiffusionVertexX->clear();
	DiffusionVertexY->clear();
	DiffusionVertexZ->clear();









	// laser region/decay information
	LaserX = -1;
	LaserY = -1;
	LaserXp = -1;
	LaserYp = -1;
	LaserZ = -1;
	LaserE = -1;



	// Mesh plane information

	MeshEk = -1;
	MeshE = -1;
	MeshT = -1;
	MeshT_ab = -1;
	MeshX = -1;
	MeshY = -1;
	MeshZ = -1;
	MeshXp = -1;
	MeshYp = -1;

	MeshBeta = -1;
	MeshVY = -1;
	MeshVX = -1;
	MeshVZ = -1;

	DriftT = -1;
	DriftT_ab = -1;
	DriftX = -1;
	DriftY = -1;
	DriftZ = -1;


}
