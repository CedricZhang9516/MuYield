#include "MuYield.h"

//void MuYield(
int main(int argc, char **argv){

	if(argc < 2){cout<<"Error, input the run name as first arg"<<endl; return 1;}

	name = argv[1];

	if(argc == 2 ){
		MCtype = 1002;//3006;
		Nrepeat = 1e5;
	}
	if(argc == 3) MCtype = stoi(argv[2]);//4;
	if(argc == 4) Nrepeat = stoi(argv[3]);//

	if(argc == 5){
		MCtype = stoi(argv[2]);//3006;
		Nrepeat = stoi(argv[3]);
		InputName = argv[4];
	}//

	H_line = 1;
	S_line = 0;


	cout<<"Initialize..."<<endl;


	//MCtype:
	// 1: My own MC
	// 2: TRIUMF
	// 3: H-line file input
	// 4: S-line (S2) file input
	// 5: New Geo 8 mm
	// 6: New Geo 4 mm
	// 7: Yannis
	// 8: 15-4 mm



	//////Read from hline file to generate actual simulation

	// H-line and S-line

	if(H_line){//MCtype == 3 || MCtype == 5 || MCtype == 6 || MCtype == 7 || MCtype == 8){

		/*
		InputFile = new TFile("./Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root");
		InputTree = (TTree*) InputFile->Get("101");
		InputTree->SetBranchAddress("x_dec", &x_dec);
		InputTree->SetBranchAddress("y_dec", &y_dec);
		InputTree->SetBranchAddress("z_dec", &z_dec);
		*/


		//InputFile = new TFile("/home/had/zhangce/stopping/SimBeamStop_200526_H-line_DG475_3321746.root");
		//InputFile = new TFile("/home/had/zhangce/stopping/SimBeamStop_200526_H-line_DG475_3326844.root");
		InputFile = new TFile(InputName.Data());


		InputTree = (TTree*) InputFile->Get("position");
		InputTree->SetBranchAddress("x", &x_dec);
		InputTree->SetBranchAddress("y", &y_dec);
		InputTree->SetBranchAddress("z", &z_dec);


	}

	if(S_line){//MCtype == 4){
		InputFile = new TFile("/Users/zhangce/WorkArea/Archive/OldGitResBackup/MuYieldLaser/Root/SimBeamStop_191202_tot.root");
		InputTree = (TTree*) InputFile->Get("position");
		InputTree->SetBranchAddress("x", &x_dec);
		InputTree->SetBranchAddress("y", &y_dec);
		InputTree->SetBranchAddress("z", &z_dec);
		InputTree->SetBranchAddress("glbt_gen", &t_dec);
	}

	Nentries = InputTree->GetEntries();
	Nrepeat = Nentries;


	////////////////////////////////////////
	treefile = new TFile(Form("./Root/%s_tree_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_H_line_%0.2f_NewGeo%d.root",
		name.Data(),MCtype,D,T,Nrepeat,H_line,flag_newGeo), "recreate");
	tree = new TTree("tree","MuYield event");
	SetTreeBranch(tree);

	cout<<Form("Main Monte Carlo Simulation:\n%s_tree_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_H_line_%0.2f_NewGeo%d",
		name.Data(),MCtype,D,T,Nrepeat,H_line,flag_newGeo)<<endl;

	Nemission = 0;
	NLaserR = 0;
	NLaserL = 0;
	Nstopping = 0;

	//histfile->cd();

	//cout<<"MCtype: "<<MCtype<<endl;

	for(int index_m=0; index_m < Nrepeat; index_m++){

		//if(index_m>=10000 && index_m%10000==0) cout << index_m << " in the total of "<<Nrepeat<<endl;
		if(index_m>=10000 && index_m%10000==0) cout << index_m << "/" << Nrepeat << "\r" << std::flush;

		InitialTreeVar();

		////////////////////// Initializing the XYZ0 /////////////////////

		InitializingXYZ0( index_m );

		if(!InsideAerogel(X0,Y0,Z0, MCtype) ) continue;
		//Nemission++;
		Nstopping++;
		// the continue command only for counting of total stopping instantly
		//continue;
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

		Index_M = index_m;
/*
		cout<<"DecayT "<<DecayT<<" s"
			<<"mfp "<<Lmfp<<" mm"
			<<"vel0_avrg "<<vel0_avrg<<" mm/s"
			<<"vel0 "<<vel0<<" mm/s"
			<<endl;
*/
		DiffusionModel(
			InsideAerogel
		);


		DecayX = X_sf + VX_sf * (DecayT - DiffusionT);
		DecayY = Y_sf + VY_sf * (DecayT - DiffusionT);
		DecayZ = Z_sf + VZ_sf * (DecayT - DiffusionT);


		//if(flag_newGeo == 0 && Z_sf<0){continue;}

		//cout<<DecayT<<" "<<DiffusionT<<endl;
		if(DecayT > DiffusionT){
			//cout<<__LINE__<<endl;
			Nemission++;
			MUONID = MuonID();
			tree->Fill();
			continue;
		}
		/////////////////// Here the Mu successfully get emitted out of the aerogel


		//// This will save all the events, including the one ends inside the target
		//tree->Fill();

	}

	///////// Debug, Draw the last event's tracks
/*
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");
*/

	//////// Save the tree file
	treefile->cd();
	treefile->Write();
	cout<<"Total Nrepeat: "<<Nrepeat<<endl
		<<"Total Nstopping: "<<Nstopping<<endl
		<<"Nemission: "<<Nemission<<endl
		<<"Tree Entries: "<<tree->GetEntries()<<endl;

	return 0;
}



