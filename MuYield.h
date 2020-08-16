#ifndef _MuYield
#define _MuYield
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
#include "../CZhang/CZhangNew.h"
#include "MuonID.h"


//bool InsideLaserRegion(double, double, double);
//bool InsideAerogel(double x, double y, double z);

//void InitializingXYZ0(int index);

TString name;
TString InputName;

int MCtype = 3;
int flag_xfree = 0; ///// NOT USED NOW
int flag_newGeo = 0; ///// NOT USED NOW
int Nrepeat = 1e5;
//double Thick = 7.12;
//double Thick = 14;
double Thick = 25;
//double Thick = 8;
int H_line = 0;
int S_line = 0;

TFile * InputFile;
TTree * InputTree;
double x_dec, y_dec, z_dec, t_dec, Nentries;

double D = 87000;// diffussion coefficient mm^2/s
double T = 322;

double Index_M = 0;
//double light = 299792458; // m/s
//double massMu = 106.16/light/light; // MeV/c2

double lifeMu = 2.2e-6; //s
double k = 8.62e-11 ; //Boltzmann constant, MeV/K
double PI = 3.1415926;
double Tstep = 1e-9;
double tLaser = 1.3e-6;
double Ef = 20000;//V/m
double A = 1.6932087e16;//Ef/massMu, mm/s^2
double zMesh = 10;//mm
double yMesh = 30;//mm

double vel0_avrg = 1000*sqrt(8*k*T/(PI*massMu));

double By = -0.1035;//mT
double Bx = 0.0696;//mT
double Bz = 0.0696;//mT

// only for debug
int NLaserR = 0;
int NLaserL = 0;
int Nemission = 0;
int Nhline = 0;
int Nstopping = 0;

/////////input and constant


TVector3 Bamb(Bx,By,Bz);
double Omega = 14 * Bamb.Mag() * (2*PI);

//double Omega;// = 14 * Bamb.Mag() * (2*PI);

//aux parameters, middle-step use, not to be saved:
//double x,y,z,t,vx,vy,vz,theta,phi;
double tempX, tempY, tempZ;
int aux1,aux2;
double aux3;


// only for diffusion plots
TGraph * DiffusionTrack;
int flag_DiffusionTrack;
int N_DiffusionTrack;
int Nhits;

////////////Saved


TFile* histfile;
TFile* treefile;
TTree* tree;


// initial information
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
double DiffusionT;

double MUONID;


std::vector<Double_t>* DiffusionVertexX;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexY;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexZ;// = new std::vector<double>;//(5,0);
std::vector<Double_t>* DiffusionVertexT;// = new std::vector<double>;//(5,0);


double DecayX;// = -1;
double DecayY;// = -1;
double DecayZ;// = -1;

double omega_x;//MHz
double omega_y;//MHz
double omega_z;//MHz

double SpinX;
double SpinY;
double SpinZ;

double DecayPositronMomtX;
double DecayPositronMomtY;
double DecayPositronMomtZ;


/*
	omega_x = 14*Bx/(2*PI);
	omega_y = 14*By/(2*PI);
	omega_z = 14*Bz/(2*PI);
*/


// laser region/decay information
double LaserX;// = -1;
double LaserY;// = -1;
double LaserXp;// = -1;
double LaserYp;// = -1;
double LaserZ;// = -1;
double LaserE;

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
double DriftD = 500;// mm


///////////////////////Histgram to be saved

TH1D *T0;

TH1D *hLmfp;

TH1D *hX0tgt;
TH1D *hY0tgt;
TH1D *hZ0tgt;

TH1D *hvel0;
TH1D *hTheta0;
TH1D *hPhi0;

TH1D *hZ0tgt_emission;
TH1D *TEmission;
TH1D *VEmission;

TH2D *hZT2D;
TH1D *hTlaserR;
TH1D *hTlaserL;

TH1D *hZLaserR;
TH1D *hZLaserL;

// for TRIUMF case v1-v3， 10 - 40 mm
TH1D *hTlaserVtot;
TH1D *hTlaserV1;
TH1D *hTlaserV2;
TH1D *hTlaserV3;

TH1D *hDecayX;
TH1D *hDecayY;
TH1D *hDecayZ;
TH1D *hDecayT;


// this two maybe helpful with hZLaser
TH1D *hXLaser;
TH1D *hYLaser;

TH1D *hTheta0_emission;
TH1D *hPhi0_emission;
TH2D *hEmissionXY;

////////////////////////////////////////

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
	//tree->Branch("DiffusionVertexX", DiffusionVertexX,  "DiffusionVertexX/D");// std::vector<double> DiffusionVertexX;
	//tree->Branch("DiffusionVertexY", DiffusionVertexY, "DiffusionVertexY/D");// std::vector<double> DiffusionVertexY;
	//tree->Branch("DiffusionVertexZ", DiffusionVertexZ, "DiffusionVertexZ/D");// std::vector<double> DiffusionVertexZ;
	//tree->Branch("DiffusionVertexT", DiffusionVertexT, "DiffusionVertexT/D");// std::vector<double> DiffusionVertexT;


	tree->Branch("DiffusionVertexX", "vector<Double_t>", &DiffusionVertexX);//  "DiffusionVertexX/D");// std::vector<double> DiffusionVertexX;
	tree->Branch("DiffusionVertexY", "vector<Double_t>", &DiffusionVertexY);// "DiffusionVertexY/D");// std::vector<double> DiffusionVertexY;
	tree->Branch("DiffusionVertexZ", "vector<Double_t>", &DiffusionVertexZ);// "DiffusionVertexZ/D");// std::vector<double> DiffusionVertexZ;
	tree->Branch("DiffusionVertexT", "vector<Double_t>", &DiffusionVertexT);// "DiffusionVertexT/D");// std::vector<double> DiffusionVertexT;



	tree->Branch("DecayX",&DecayX,"DecayX/D");
	tree->Branch("DecayY",&DecayY,"DecayY/D");
	tree->Branch("DecayZ",&DecayZ,"DecayZ/D");

	tree->Branch("SpinX",&SpinX,"SpinX/D");
	tree->Branch("SpinY",&SpinY,"SpinY/D");
	tree->Branch("SpinZ",&SpinZ,"SpinZ/D");

	tree->Branch("DecayPositronMomtX",&DecayPositronMomtX,"DecayPositronMomtX/D");
	tree->Branch("DecayPositronMomtY",&DecayPositronMomtY,"DecayPositronMomtY/D");
	tree->Branch("DecayPositronMomtZ",&DecayPositronMomtZ,"DecayPositronMomtZ/D");

	///////////////////

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
	tree->Branch("MUONID",&MUONID,"MUONID/D");
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



	SpinX = 0;
	SpinY =   TMath::Sin(2*PI * 11.54/360);
	SpinZ = - TMath::Cos(2*PI * 11.54/360);

	DecayPositronMomtX = 0;
	DecayPositronMomtY = 0;
	DecayPositronMomtZ = 0;

	//DiffusionVertexX->clear();
	//DiffusionVertexY->clear();
	//DiffusionVertexZ->clear();
	//DiffusionVertexT->clear();

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
	MUONID = -1;


}



#endif

