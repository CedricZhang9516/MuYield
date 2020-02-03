#include "MuYield.h"
#include "MyMuonDecay.h"
#include "DiffusionModel.h"

void MuYield(
	TString name_ = "Dev_200202",
	int MCtype_ = 2,
	int Nrepeat_ = 2e3,//8.4e5,//2e6,//8.4e5,//1e6,//2.8e5,//1e6,//2.8e4,
	int flag_xfree_ = 1,
	int flag_newGeo_ = 0,
	double Thick_ = 7.12)
{
	cout<<"Initialize..."<<endl;

	MCtype = MCtype_;
	flag_xfree = flag_xfree_;
	flag_newGeo = flag_newGeo_;
	Nrepeat = Nrepeat_;
	Thick = Thick_;

	N_DiffusionTrack = -1;
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
		else InitializingXYZ0(  );
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

		SpinX = Spin.X();
		SpinY = Spin.Y();
		SpinZ = Spin.Z();

		TVector3* DecayPositronMomentum = G4MuonDecay(Spin);

		DecayPositronMomtX = DecayPositronMomentum->X();
		DecayPositronMomtY = DecayPositronMomentum->Y();
		DecayPositronMomtZ = DecayPositronMomentum->Z();


		DiffusionVertexX = new std::vector<double>;
		DiffusionVertexY = new std::vector<double>;
		DiffusionVertexZ = new std::vector<double>;
		DiffusionVertexT = new std::vector<double>;




		DiffusionModel(
			InsideAerogel//void (*GeometryFunction)(double, double, double),
		);


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

		/////////////////// Here the Mu successfully get emitted out of the aerogel

		Nemission++;
		tree->Fill();

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



