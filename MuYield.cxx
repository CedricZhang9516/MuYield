#include "MuYield.h"
#include "MyMuonDecay.h"
#include "InitializingXYZ0.h"
#include "DiffusionModel.h"

void MuYield(
	TString name = "Dev_200202",
	int MCtype = 2,
	int Nrepeat = 2e3,//8.4e5,//2e6,//8.4e5,//1e6,//2.8e5,//1e6,//2.8e4,
	int flag_xfree = 1,
	int flag_newGeo = 0,
	double Thick = 7.12)
{
	cout<<"Initialize..."<<endl;



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

	//histfile = new TFile(Form("./Root/%s_hist_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d_.root",
	//	name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo), "recreate");
	//SetHist(histfile);


	// only for test
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

	////////////////////////////////////////

	cout<<Form("Main Monte Carlo Simulation:\n_MCType_%0.0d_D_%0.0f_T_%0.0f_Nrepeat_%0.0d_flag_xfree_%d_thick_%0.2f_NewGeo_%d_",MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo)<<endl;

	Nemission = 0;
	NLaserR = 0;
	NLaserL = 0;


	//histfile->cd();

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
		else InitializingXYZ0();
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

		TVector3 Spin(SpinX, SpinY, SpinZ);


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
/*
		hLmfp->Fill(Lmfp * 1000);//um
		hDecayT->Fill(DecayT);
		hvel0->Fill(vel0);
		T0->Fill(TBeam);
		hZ0tgt->Fill(Z0);
		hX0tgt->Fill(X0);
		hY0tgt->Fill(Y0);
		hTheta0->Fill(TMath::Cos(theta0));
		hPhi0->Fill(phi0);
*/
		////////////////

		DiffusionVertexX = new std::vector<double>;
		DiffusionVertexY = new std::vector<double>;
		DiffusionVertexZ = new std::vector<double>;
		DiffusionVertexT = new std::vector<double>;




		DiffusionModel(
			//&X0, &Y0, &Z0,
			//Vx0, Vy0, Vz0, theta0, phi0,
			InsideAerogel//void (*GeometryFunction)(double, double, double),
			//DiffusionVertexX,
			//DiffusionVertexY,
			//DiffusionVertexZ,
			//DiffusionVertexT
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
/*
		if(flag_newGeo == 0 && Z_sf<0){
			tree->Fill();
			continue;
		}

		if( t0 >= DecayT ){
			tree->Fill();
			continue;
		}
*/
		//if( MCtype == 2 && t0 >= DecayT)hTlaserVtot->Fill(DecayT+TBeam); //Only for TRIUMF

		/////////////////// Here the Mu successfully get emitted out of the aerogel

		Nemission++;
		//cout<<index_m<<endl;
		tree->Fill();
		//cout<<DiffusionVertexX->size()<<endl;

	}



	///////// Draw the last event's tracks
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");


	//histfile->Write();

	//////// Save the tree file
	treefile->cd();
	treefile->Write();
	cout<<"Tree Entries: "<<tree->GetEntries()<<endl;

		//return ResultSP;
}



bool InsideAerogel(double x, double y, double z){

	if( (z <= 0 && z >= -7.12 )
		|| (z <= -9 && z >= -11)
		|| (z <= 9 && z >= 7) ) return true;
	else return false;

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



