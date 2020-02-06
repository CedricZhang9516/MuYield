#include "MuYield.h"
#include "MyMuonDecay.h"
#include "DiffusionModel.h"

//void MuYield(
int main(int argc, char **argv){

	if(argc < 2){cout<<"Error, input the run name as first arg"<<endl; return 1;}

	name = argv[1];//"TRIUMF_Reproduce_200204";

	if(argc > 2) MCtype = stoi(argv[2]);// 4;
	if(argc > 3) Nrepeat = stoi(argv[3]);// 2e4;//8.4e5,//2e6,//8.4e5,//1e6,//2.8e5,//1e6,//2.8e4,
	if(argc > 4) flag_xfree = stoi(argv[4]);//1;
	if(argc > 5) flag_newGeo = stoi(argv[5]);// 0;
	else {
		MCtype = 5;
		Nrepeat = 1e5;
		flag_xfree = 1;
		flag_newGeo = 1;
	}

	Thick = 7.12;

	//if(flag_newGeo == 1) Thick = 2;
	if(flag_newGeo == 0) Thick = 7.12;

	N_DiffusionTrack = -1;
	flag_DiffusionTrack = 0;

//{
	cout<<"Initialize..."<<endl;


	//MCtype:
	// 1: My own MC
	// 2: TRIUMF
	// 3: H-line file input
	// 4: S-line (S2) file input
	// 5: New Geo

	//flag = 0: no x limit, otherwise = 1;


	//////Read from hline file to generate actual simulation

	// H-line and S-line

	if(MCtype == 3 || MCtype == 5){
		InputFile = new TFile("./Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root");
		InputTree = (TTree*) InputFile->Get("101");
		InputTree->SetBranchAddress("x_dec", &x_dec);
		InputTree->SetBranchAddress("y_dec", &y_dec);
		InputTree->SetBranchAddress("z_dec", &z_dec);
		Nentries = InputTree->GetEntries();
	}

	if(MCtype == 4){
		InputFile = new TFile("/Users/zhangce/WorkArea/Archive/OldGitResBackup/MuYieldLaser/Root/SimBeamStop_191202_tot.root");
		InputTree = (TTree*) InputFile->Get("position");
		InputTree->SetBranchAddress("x", &x_dec);
		InputTree->SetBranchAddress("y", &y_dec);
		InputTree->SetBranchAddress("z", &z_dec);
		InputTree->SetBranchAddress("glbt_gen", &t_dec);
		Nentries = InputTree->GetEntries();

	}


	Nrepeat = Nentries;


	////////////////////////////////////////
	treefile = new TFile(Form("./Root/%s_tree_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d.root",
		name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo), "recreate");
	tree = new TTree("tree","MuYield event");
	SetTreeBranch(tree);

	cout<<Form("Main Monte Carlo Simulation:\n%s_tree_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d",
		name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo)<<endl;

	Nemission = 0;
	NLaserR = 0;
	NLaserL = 0;

	//histfile->cd();

	for(int index_m=0; index_m < Nrepeat; index_m++){

		//if(index_m>=10000 && index_m%10000==0) cout << index_m << " in the total of "<<Nrepeat<<endl;
		if(index_m>=10000 && index_m%10000==0) cout << index_m << "/" << Nrepeat << "\r" << std::flush;

		InitialTreeVar();


		////////////////////// Initializing the XYZ0
		InitializingXYZ0( index_m );

		if(MCtype == 3){
			if (z_dec > 0 || z_dec < -Thick) continue;
			if (flag_newGeo == 0 && fabs(Y0)>20)continue;
		}
		if(MCtype == 4){
			if (z_dec > 0 || z_dec < -Thick) continue;
			if (x_dec*x_dec+y_dec*y_dec>39*39)continue;
		}
		if(MCtype == 5 && !InsideAerogel(X0,Y0,Z0) ) continue;
		//////////////////////



		/// Generate the time structure
		if(MCtype == 2) TBeam = 0;
		else if(MCtype == 4) TBeam = t_dec;

		///// MCtype  = 1,3 (H-LINE), 5 (H-line, new Geo)
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


		DecayX = X_sf + VX_sf * (DecayT - DiffusionT);
		DecayY = Y_sf + VY_sf * (DecayT - DiffusionT);
		DecayZ = Z_sf + VZ_sf * (DecayT - DiffusionT);


		//if(flag_newGeo == 0 && Z_sf<0){continue;}


		if(DecayT > DiffusionT){
			Nemission++;
			tree->Fill();
		}
		/////////////////// Here the Mu successfully get emitted out of the aerogel


		//tree->Fill();

	}



	///////// Draw the last event's tracks
/*
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");
*/

	//////// Save the tree file
	treefile->cd();
	treefile->Write();
	cout<<"Total Nrepeat: "<<Nrepeat<<endl
		<<"Nemission: "<<Nemission<<endl
		<<"Tree Entries: "<<tree->GetEntries()<<endl;

		//return ResultSP;
}

void InitializingXYZ0(int index_m){

	//double* X0, double* Y0, double* Z0

	//beam xy: uniformed or gaussian from tdr
	//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index_m+xStep/2;
	//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;


	/////// My own MC
	if(MCtype == 1){

		Z0 = - ((double) rand() / (RAND_MAX)) * Thick;    // z0=-0.0~-7.12mm
		X0 = GenerateGaus(0,31.96);//
		Y0 = GenerateGaus(0,14.36);//2mm
		//y0 = GenerateHlineY(hY0tgt_hline);//only for test

		///NEW GEOMETRY here!!!!
		//tempZ = ((double) rand() / (RAND_MAX));
		//if( tempZ <=(1.0/3) )Z0 = Z0 + (7+Thick) ;
		//if( tempZ >=(2.0/3) )Z0 = Z0 - (7+Thick) ;
	}

	//if(flag_newGeo == 1 && fabs(Y0)>20)continue;

	// for TRIUMF case z
	if(MCtype == 2){
		X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index_m+xStep/2;
		Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
		Z0 = GenerateGaus(0,1.69);//2mm
		if( Z0 > 0) Z0 = - Z0;
	}

	////// H-line
	if(MCtype == 3){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	///////// S-line
	if(MCtype == 4){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	// MCType = 5; New Geometry inspired by Uetake-san and Mibe-san

	if(MCtype == 5){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 20 && Y0 > 12) Z0 = Z0 + Thick;
		//if(Y0 < 12 && Y0 > 4)
		if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		//if(Y0 < -4 && Y0 > -12)
		if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
	}



}


bool InsideAerogel(double x, double y, double z){

	if(MCtype <5){
		if( ( z <= 0 && z >= -7.12 ) ) return true;
		else return false;
	}

	if(MCtype == 5){

		if(x>25 || x<-25)return false;

		if( z>0 && z<Thick){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}

		if( z<0 && z>-Thick){
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
		}

		return false;
	}
		//|| (z <= -9 && z >= -11)
		//|| (z <= 9 && z >= 7) ) return true;
	cout<<"Wrong MCtype!"<<endl;
	return false;


}





