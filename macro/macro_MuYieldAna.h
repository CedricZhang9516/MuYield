#include <vector>
#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../CZhang/CZhangNew.h"

double TBeam;// = -1;
double DecayT;// = -1;
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
double DiffusionT;// = -1;// is not the initial t, but the total time spent inside aerogel


std::vector<Double_t>* DiffusionVertexX = 0;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexY = 0;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexZ = 0;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexT = 0;// = new std::vector<double>;//(5,0);


double SpinX;
double SpinY;
double SpinZ;

double DecayPositronMomtX;
double DecayPositronMomtY;
double DecayPositronMomtZ;


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


double XXp,Xp2,X2;
double YYp,Yp2,Y2;
double BetaGamma;

int nbinT = 8000;
double Tstep = 1e-9;


void InitTree(TTree* tree){

tree->SetBranchAddress("TBeam",&TBeam);//,"TBeam/D");
tree->SetBranchAddress("DecayT",&DecayT);//,"DecayT/D");
tree->SetBranchAddress("X_sf",&X_sf);// = -1;
tree->SetBranchAddress("Y_sf",&Y_sf);// = -1;
tree->SetBranchAddress("Z_sf",&Z_sf);// = -1;
tree->SetBranchAddress("VX_sf",&VX_sf);// = -1;
tree->SetBranchAddress("VY_sf",&VY_sf);// = -1;
tree->SetBranchAddress("VZ_sf",&VZ_sf);// = -1;
tree->SetBranchAddress("theta_sf",&theta_sf);// = -1;
tree->SetBranchAddress("phi_sf",&phi_sf);// = -1;

tree->SetBranchAddress("t0",&t0);// = -1;// is not the initial t, but the total time spent inside aerogel
tree->SetBranchAddress("DiffusionT",&DiffusionT);// = -1;// is not the initial t, but the total time spent inside aerogel

// laser region/decay information
tree->SetBranchAddress("LaserX",&LaserX);// = -1;
tree->SetBranchAddress("LaserY",&LaserY);// = -1;
tree->SetBranchAddress("LaserZ",&LaserZ);// = -1;

tree->SetBranchAddress("DecayX",&DecayX);// = -1;
tree->SetBranchAddress("DecayY",&DecayY);// = -1;
tree->SetBranchAddress("DecayZ",&DecayZ);// = -1;
tree->SetBranchAddress("DecayT",&DecayT);// = -1;


tree->SetBranchAddress("DiffusionVertexX", &DiffusionVertexX);//, "DiffusionVertexX/D");// std::vector<double> DiffusionVertexX;
tree->SetBranchAddress("DiffusionVertexY", &DiffusionVertexY);//, "DiffusionVertexY/D");// std::vector<double> DiffusionVertexY;
tree->SetBranchAddress("DiffusionVertexZ", &DiffusionVertexZ);//, "DiffusionVertexZ/D");// std::vector<double> DiffusionVertexZ;
tree->SetBranchAddress("DiffusionVertexT", &DiffusionVertexT);//, "DiffusionVertexT/D");// std::vector<double> DiffusionVertexT;

//tree->SetBranchAddress("DecayX",&DecayX);//,"DecayX/D");
//tree->SetBranchAddress("DecayY",&DecayY);//,"DecayY/D");
//tree->SetBranchAddress("DecayZ",&DecayZ);//,"DecayZ/D");

tree->SetBranchAddress("SpinX",&SpinX);//,"SpinX/D");
tree->SetBranchAddress("SpinY",&SpinY);//,"SpinY/D");
tree->SetBranchAddress("SpinZ",&SpinZ);//,"SpinZ/D");

tree->SetBranchAddress("DecayPositronMomtX",&DecayPositronMomtX);//,"DecayPositronMomtX/D");
tree->SetBranchAddress("DecayPositronMomtY",&DecayPositronMomtY);//,"DecayPositronMomtY/D");
tree->SetBranchAddress("DecayPositronMomtZ",&DecayPositronMomtZ);//,"DecayPositronMomtZ/D");



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

}


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

//TH2D* EmissionX;
//TH2D* EmissionY;
//if(flag_Newgeo==0){
TH2D* EmissionX = new TH2D("EmissionX","EmissionX;X;X'",240,-120,120,320,0.16,0.16); // mm
TH2D* EmissionY = new TH2D("EmissionY","EmissionY;Y;Y'",500,-25,25,320,0.16,0.16); // mm
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

TH1D* hT = new TH1D("hT","hT;T[s];N",nbinT,0,nbinT*Tstep);
TH1D* hT_sf = new TH1D("hT_sf","hT_sf;T[s];N",nbinT,0,nbinT*Tstep);


TH2D *hZT2D = new TH2D("Z-T-2D","Z-T-2D; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);

//TH2D *hZY2D = new TH2D("Z-Y-2D","Z-Y-2D; Z(mm);Y (mm)",100,-10,10,100,-40,40);
TH2D *hZY2D = new TH2D("Z-Y-2D","Z-Y-2D; Z(mm);Y (mm)",500,-40,40,500,-40,40);
TH2D *hZX2D = new TH2D("Z-X-2D","Z-X-2D; Z(mm);X (mm)",500,-40,40,500,-40,40);
TH2D *hXY2D = new TH2D("X-Y-2D","X-Y-2D; X(mm);Y (mm)",500,-40,40,500,-40,40);

TH3D *hXYT3D = new TH3D("ZX-T-3D","ZX-T-3D; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);
TH3D *hZXY3D = new TH3D("ZXY-3D","ZXY-3D;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);


TH2D *hZT2D_sf = new TH2D("Z-T-2D_sf","Z-T-2D_sf; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);

//TH2D *hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",100,-10,10,100,-40,40);
TH2D *hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",500,-10,40,500,-40,40);
TH2D *hZX2D_sf = new TH2D("Z-X-2D_sf","Z-X-2D_sf; Z(mm);X (mm)",500,-40,40,500,-40,40);
TH2D *hXY2D_sf = new TH2D("X-Y-2D_sf","X-Y-2D_sf; X(mm);Y (mm)",500,-40,40,500,-40,40);

TH3D *hXYT3D_sf = new TH3D("ZX-T-3D_sf","ZX-T-3D_sf; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);
TH3D *hZXY3D_sf = new TH3D("ZXY-3D_sf","ZXY-3D_sf;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);

//if(flag_Newgeo==1){
//	EmissionX = new TH2D("EmissionZ","EmissionZ;Z;Z'",240,-120,120,320,0.16,0.16); // mm
//	EmissionY = new TH2D("EmissionX","EmissionX;X;X'",500,-25,25,320,0.16,0.16); // mm
//}


//TGraph * EmissionX = new TGraph();
//TGraph * EmissionY = new TGraph();
//TGraph * gZXY3D_sf = new TGraph();


void Emittance(TTree* tree);
void MuYieldInVacuum(TTree * tree, TCanvas *);
void TRIUMFVacuumRegion(TTree * tree, TCanvas * c = NewTCanvas("c_intrnl","c_intrnl",1000,1000,2,2));
/*
bool InsideLaserRegion(double x, double y, double z);//{ // t = t0 + tbeam
bool InsideLaserRegionNewGeo(double x, double y, double z);//{ // t = t0 + tbeam
bool InsideLaserRegionNewGeo_4mm(double x, double y, double z);//{ // t = t0 + tbeam
bool InsideLaserRegionNewGeo_yannis(double x, double y, double z);//{ // t = t0 + tbeam
bool InsideLaserRegionNewGeo_7_4mm(double x, double y, double z);//{ // t = t0 + tbeam
*/