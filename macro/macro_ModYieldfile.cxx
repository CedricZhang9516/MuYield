//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_ModYieldfile(){

	TString FileName(
		//"../Root/hline_SimBeamStop_25mm_DG360.root"
		//"../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root"
		//"../Root/hline_SimBeamStop_GM_7.12mm.root"

		//"/home/had/zhangce/g-2_tape/Mu1S2S/MuYield/MuYield_210120_HighStat_total_tree_Type1001_D87000_T322_H_line0_Thick8.80_NewGeo0.root"
		"../Root/210202_Reflection/210202_Reflection_5003_stopping255_tot_tree_Type5003_D87000_T322_Nrepeat2918562_NewGeo0.root" //MCtype = 3012;

		);
	TFile * f1 = new TFile(FileName.Data());

	TTree * t1 = (TTree*)f1->Get("tree");
	const auto nentries = t1->GetEntries();

	//double x, y, z;
	Double_t        TBeam;
	Double_t        DecayT;
	Double_t        X0;
	Double_t        Y0;
	Double_t        Z0;
	Double_t        vel0;
	Double_t        theta0;
	Double_t        phi0;
	Double_t        Vz0;
	Double_t        Vx0;
	Double_t        Vy0;
	Double_t        Lmfp;
	Double_t        t0;
	Double_t        DiffusionT;
	Double_t        X_sf;
	Double_t        Y_sf;
	Double_t        Z_sf;
	Double_t        VX_sf;
	Double_t        VY_sf;
	Double_t        VZ_sf;
	Double_t        theta_sf;
	Double_t        phi_sf;
	vector<double>  *DiffusionVertexX;
	vector<double>  *DiffusionVertexY;
	vector<double>  *DiffusionVertexZ;
	vector<double>  *DiffusionVertexT;
	Double_t        DecayX;
	Double_t        DecayY;
	Double_t        DecayZ;
	Double_t        SpinX;
	Double_t        SpinY;
	Double_t        SpinZ;
	Double_t        DecayPositronMomtX;
	Double_t        DecayPositronMomtY;
	Double_t        DecayPositronMomtZ;
	//   Double_t        LaserX;
	//   Double_t        LaserY;
	//   Double_t        LaserZ;
	Double_t        LaserE;
	//t1->SetBranchAddress("x", &x);
	//t1->SetBranchAddress("y", &y);
	//t1->SetBranchAddress("z", &z);

	TBranch        *b_TBeam;   //!
	TBranch        *b_DecayT;   //!
	TBranch        *b_X0;   //!
	TBranch        *b_Y0;   //!
	TBranch        *b_Z0;   //!
	TBranch        *b_vel0;   //!
	TBranch        *b_theta0;   //!
	TBranch        *b_phi0;   //!
	TBranch        *b_Vz0;   //!
	TBranch        *b_Vx0;   //!
	TBranch        *b_Vy0;   //!
	TBranch        *b_Lmfp;   //!
	TBranch        *b_t0;   //!
	TBranch        *b_DiffusionT;   //!
	TBranch        *b_X_sf;   //!
	TBranch        *b_Y_sf;   //!
	TBranch        *b_Z_sf;   //!
	TBranch        *b_VX_sf;   //!
	TBranch        *b_VY_sf;   //!
	TBranch        *b_VZ_sf;   //!
	TBranch        *b_theta_sf;   //!
	TBranch        *b_phi_sf;   //!
	TBranch        *b_DiffusionVertexX;   //!
	TBranch        *b_DiffusionVertexY;   //!
	TBranch        *b_DiffusionVertexZ;   //!
	TBranch        *b_DiffusionVertexT;   //!
	TBranch        *b_DecayX;   //!
	TBranch        *b_DecayY;   //!
	TBranch        *b_DecayZ;   //!
	TBranch        *b_SpinX;   //!
	TBranch        *b_SpinY;   //!
	TBranch        *b_SpinZ;   //!
	TBranch        *b_DecayPositronMomtX;   //!
	TBranch        *b_DecayPositronMomtY;   //!
	TBranch        *b_DecayPositronMomtZ;   //!

	t1->SetBranchAddress("TBeam", &TBeam, &b_TBeam);
	t1->SetBranchAddress("DecayT", &DecayT, &b_DecayT);
	t1->SetBranchAddress("X0", &X0, &b_X0);
	t1->SetBranchAddress("Y0", &Y0, &b_Y0);
	t1->SetBranchAddress("Z0", &Z0, &b_Z0);
	t1->SetBranchAddress("vel0", &vel0, &b_vel0);
	t1->SetBranchAddress("theta0", &theta0, &b_theta0);
	t1->SetBranchAddress("phi0", &phi0, &b_phi0);
	t1->SetBranchAddress("Vz0", &Vz0, &b_Vz0);
	t1->SetBranchAddress("Vx0", &Vx0, &b_Vx0);
	t1->SetBranchAddress("Vy0", &Vy0, &b_Vy0);
	t1->SetBranchAddress("Lmfp", &Lmfp, &b_Lmfp);
	t1->SetBranchAddress("t0", &t0, &b_t0);
	t1->SetBranchAddress("DiffusionT", &DiffusionT, &b_DiffusionT);
	t1->SetBranchAddress("X_sf", &X_sf, &b_X_sf);
	t1->SetBranchAddress("Y_sf", &Y_sf, &b_Y_sf);
	t1->SetBranchAddress("Z_sf", &Z_sf, &b_Z_sf);
	t1->SetBranchAddress("VX_sf", &VX_sf, &b_VX_sf);
	t1->SetBranchAddress("VY_sf", &VY_sf, &b_VY_sf);
	t1->SetBranchAddress("VZ_sf", &VZ_sf, &b_VZ_sf);
	t1->SetBranchAddress("theta_sf", &theta_sf, &b_theta_sf);
	t1->SetBranchAddress("phi_sf", &phi_sf, &b_phi_sf);
	t1->SetBranchAddress("DiffusionVertexX", &DiffusionVertexX, &b_DiffusionVertexX);
	t1->SetBranchAddress("DiffusionVertexY", &DiffusionVertexY, &b_DiffusionVertexY);
	t1->SetBranchAddress("DiffusionVertexZ", &DiffusionVertexZ, &b_DiffusionVertexZ);
	t1->SetBranchAddress("DiffusionVertexT", &DiffusionVertexT, &b_DiffusionVertexT);
	t1->SetBranchAddress("DecayX", &DecayX, &b_DecayX);
	t1->SetBranchAddress("DecayY", &DecayY, &b_DecayY);
	t1->SetBranchAddress("DecayZ", &DecayZ, &b_DecayZ);
	t1->SetBranchAddress("SpinX", &SpinX, &b_SpinX);
	t1->SetBranchAddress("SpinY", &SpinY, &b_SpinY);
	t1->SetBranchAddress("SpinZ", &SpinZ, &b_SpinZ);
	t1->SetBranchAddress("DecayPositronMomtX", &DecayPositronMomtX, &b_DecayPositronMomtX);
	t1->SetBranchAddress("DecayPositronMomtY", &DecayPositronMomtY, &b_DecayPositronMomtY);
	t1->SetBranchAddress("DecayPositronMomtZ", &DecayPositronMomtZ, &b_DecayPositronMomtZ);

	//t1->SetBranchAddress("MUONID",&MUONID);

	FileName.ReplaceAll(".root","_TBEAM_0.root");
	TFile newfile(FileName.Data(), "recreate");
	auto newtree = t1->CloneTree(0);

	for (auto i : ROOT::TSeqI(nentries)) {
		t1->GetEntry(i);
		if(TBeam<0.3)newtree->Fill();
	}

	newtree->Print();
	newfile.Write();

}