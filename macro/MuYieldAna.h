double TBeam;// = -1;
double decayT;// = -1;
double X0;// = -1;
double Y0;// = -1;
double Z0;// = -1;
double vel0;// = -1;
double theta0;// = -1;
double phi0;// = -1;
double Vz0;// = -1;
double Vx0;// = -1;
double Vy0;// = -1;
double Lmfp;// = -1;

// diffusion/surface information

double X_sf;// = -1;
double Y_sf;// = -1;
double Z_sf;// = -1;
double VX_sf;// = -1;
double VY_sf;// = -1;
double VZ_sf;// = -1;
double theta_sf;// = -1;
double phi_sf;// = -1;

double t0;// = -1;// is not the initial t, but the total time spent inside aerogel

// laser region/decay information
double LaserX;// = -1;
double LaserY;// = -1;
double LaserZ;// = -1;

double DecayX;// = -1;
double DecayY;// = -1;
double DecayZ;// = -1;

// Mesh plane information

double MeshEk;// = -1;
double MeshE;// = -1;
double MeshT;// = -1;
double MeshT_ab;// = -1;
double MeshX;// = -1;
double MeshY;// = -1;
double MeshZ;// = -1;
double MeshXp;// = -1;
double MeshYp;// = -1;

double MeshBeta;// = -1;
double MeshVY;// = -1;
double MeshVX;// = -1;
double MeshVZ;// = -1;

double DriftT;
double DriftT_ab;
double DriftX;
double DriftY;
double DriftZ;
//double DriftD = 500;// mm

TTree *tree = (TTree*)f2->Get("tree");

tree->SetBranchAddress("X_sf",&X_sf);// = -1;
tree->SetBranchAddress("Y_sf",&Y_sf);// = -1;
tree->SetBranchAddress("Z_sf",&Z_sf);// = -1;
tree->SetBranchAddress("VX_sf",&VX_sf);// = -1;
tree->SetBranchAddress("VY_sf",&VY_sf);// = -1;
tree->SetBranchAddress("VZ_sf",&VZ_sf);// = -1;
tree->SetBranchAddress("theta_sf",&theta_sf);// = -1;
tree->SetBranchAddress("phi_sf",&phi_sf);// = -1;

tree->SetBranchAddress("t0",&t0);// = -1;// is not the initial t, but the total time spent inside aerogel

// laser region/decay information
tree->SetBranchAddress("LaserX",&LaserX);// = -1;
tree->SetBranchAddress("LaserY",&LaserY);// = -1;
tree->SetBranchAddress("LaserZ",&LaserZ);// = -1;

tree->SetBranchAddress("DecayX",&DecayX);// = -1;
tree->SetBranchAddress("DecayY",&DecayY);// = -1;
tree->SetBranchAddress("DecayZ",&DecayZ);// = -1;

// Mesh plane information

tree->SetBranchAddress("MeshEk",&MeshEk);// = -1;
tree->SetBranchAddress("MeshE",&MeshE);// = -1;
tree->SetBranchAddress("MeshT",&MeshT);// = -1;
tree->SetBranchAddress("MeshT_ab",&MeshT_ab);// = -1;
tree->SetBranchAddress("MeshX",&MeshX);// = -1;
tree->SetBranchAddress("MeshY",&MeshY);// = -1;
tree->SetBranchAddress("MeshZ",&MeshZ);// = -1;
tree->SetBranchAddress("MeshXp",&MeshXp);// = -1;
tree->SetBranchAddress("MeshYp",&MeshYp);// = -1;

tree->SetBranchAddress("MeshBeta",&MeshBeta);// = -1;
tree->SetBranchAddress("MeshVY",&MeshVY);// = -1;
tree->SetBranchAddress("MeshVX",&MeshVX);// = -1;
tree->SetBranchAddress("MeshVZ",&MeshVZ);// = -1;

tree->SetBranchAddress("DriftT",&DriftT);
tree->SetBranchAddress("DriftT_ab",&DriftT_ab);
tree->SetBranchAddress("DriftX",&DriftX);
tree->SetBranchAddress("DriftY",&DriftY);
tree->SetBranchAddress("DriftZ",&DriftZ);


TH1D* hMeshEk = new TH1D("hMeshEk","hMeshEk;MeV",100,0.07e-3,0.20e-3);
TH1D* hMeshT = new TH1D("hMeshT","hMeshT;s",100,20e-9,34e-9);
TH1D* hMeshT_ab = new TH1D("hMeshT_ab","hMeshT_ab;s",100,1.32e-6,1.334e-6);
TH1D* hMeshX = new TH1D("hMeshX","hMeshX;mm",200,-150,150);
TH1D* hMeshY = new TH1D("hMeshY","hMeshY;mm",200,-25,25);
TH1D* hMeshZ = new TH1D("hMeshZ","hMeshZ;mm",200,-100,100);
TH1D* hMeshXp = new TH1D("hMeshXp","hMeshXp",100,-0.04,0.04);
TH1D* hMeshYp = new TH1D("hMeshYp","hMeshYp",100,-0.05,0.05);

TH1D* hMeshBeta = new TH1D("hMeshBeta","hMeshBeta",100,0.0012,0.0019);
TH1D* hMeshVY = new TH1D("hMeshVY","hMeshVY;mm/s",100,-15e6,15e6);
TH1D* hMeshVX = new TH1D("hMeshVX","hMeshVX;mm/s",100,-20e6,20e6);
TH1D* hMeshVZ = new TH1D("hMeshVZ","hMeshVZ;mm/s",100,360e6,560e6);

TH1D* hDriftT = new TH1D("hDriftT","hDriftT;s",100,0.8e-6,1.4e-6);
TH1D* hDriftT_ab = new TH1D("hDriftT_ab","hDriftT_ab;s",100,2.2e-6,2.7e-6);
TH1D* hDriftX = new TH1D("hDriftX","hDriftX;mm",200,-150,150);
TH1D* hDriftY = new TH1D("hDriftY","hDriftY;mm",200,-40,40);
TH1D* hDriftZ = new TH1D("hDriftZ","hDriftZ;mm",200,-100,600);

TH2D* EmissionX;
TH2D* EmissionY;
//if(flag_Newgeo==0){
	EmissionX = new TH2D("EmissionX","EmissionX;X;X'",240,-120,120,320,0.16,0.16); // mm
	EmissionY = new TH2D("EmissionY","EmissionY;Y;Y'",500,-25,25,320,0.16,0.16); // mm
//}

//TH2D* CorrMeshTE = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,20e-9,34e-9,100,0.07e-3,0.20e-3);
//TH2D* CorrMeshTE = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,30e-9,80e-9,100,0.18e-3,1e-3);
	//TH2D* CorrMeshTE = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,35e-9,38e-9,100,0.07e-3,0.20e-3);
	TH2D* CorrMeshTE = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,30e-9,80e-9,100,0.185e-3,0.21e-3);

TH1D* hXXp = new TH1D("hXXp","hXXp",100,-16,16);
TH1D* hXp2 = new TH1D("hXp2","hXp2",100,0,0.0016);
TH1D* hX2 = new TH1D("hX2","hX2",100,0,1e4);
TH1D* hYYp = new TH1D("hYYp","hYYp",100,-16,16);
TH1D* hYp2 = new TH1D("hYp2","hYp2",100,0,0.0016);
TH1D* hY2 = new TH1D("hY2","hY2",100,0,1e4);
TH1D* hBetaGamma = new TH1D("hBetaGamma","hBetaGamma",100,0.0012,0.0019);
//TH1D* hBetaGamma = new TH1D("hBetaGamma","hBetaGamma",100,0.0015,0.0045);



//if(flag_Newgeo==1){
//	EmissionX = new TH2D("EmissionZ","EmissionZ;Z;Z'",240,-120,120,320,0.16,0.16); // mm
//	EmissionY = new TH2D("EmissionX","EmissionX;X;X'",500,-25,25,320,0.16,0.16); // mm
//}


//TGraph * EmissionX = new TGraph();
//TGraph * EmissionY = new TGraph();

double XXp,Xp2,X2;
double YYp,Yp2,Y2;
double BetaGamma;