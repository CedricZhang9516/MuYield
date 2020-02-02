#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <array>
#include <time.h>


double* MCLmfp();
void FillTZ();
void ShootLaser(double , double , double , double , double , double  ,double );
void ShootLaserPulseE(double , double , double , double , double , double  ,double );

void SetTreeBranch();
void SetHist();
void WriteHist();
void InitialTreeVar();

void DrawHistPlot();
void DrawGeo();
void Setstyle(TH1D*, int);
void SetstyleG(TGraph*, int);
double expo(double, double);

double GenerateGaus(double, double );
double GenerateUniform(double, double );
double GenerateHlineY(TH1D*);

double MichelSpec();

bool InsideLaserRegion(double, double, double);

TString name;

// only for debug
int NLaserR = 0;
int NLaserL = 0;
int Nemission = 0;
int Nhline = 0;

/////////input and constant

int MCtype = 1;
int flag_xfree = 0;
int flag_newGeo = 0;
int Nrepeat = 1e5;
int nbinT = 4500;

double By = -0.1035;//mT
//double Bx = 0;//mT
double Bx = 0.0696;//mT
//double By = 0;//mT
double Bz = 0.0696;//mT
//double Bz = 0;//mT


double Thick = 7.12;
double D = 87000;// diffussion coefficient mm^2/s
double T = 322;
double light = 299792458; // m/s
double massMu = 106.16/light/light; // MeV/c2
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


//aux parameters, middle-step use, not to be saved:
double x,y,z,t,vx,vy,vz,theta,phi;
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

// laser region/decay information
double LaserX;// = -1;
double LaserY;// = -1;
double LaserXp;// = -1;
double LaserYp;// = -1;
double LaserZ;// = -1;
double LaserE;

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
