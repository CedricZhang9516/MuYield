#ifndef _MuYield
#define _MuYield

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

void SetTreeBranch(TTree * tree);
void SetHist(TFile * f);
void WriteHist();
void InitialTreeVar();

int InsideAerogel(double x, double y, double z);

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


std::vector<double>* DiffusionVertexX = new std::vector<double>(5,0);;
std::vector<double>* DiffusionVertexY = new std::vector<double>(5,0);;
std::vector<double>* DiffusionVertexZ = new std::vector<double>(5,0);;
std::vector<double>* DiffusionVertexT = new std::vector<double>(5,0);;


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


void DrawHistPlot(){

	TCanvas *c2 = new TCanvas("c2","c2",800,600);
	c2->Divide(3,4);


	c2->cd(1);  T0->SetTitle("TBeam"); Setstyle(T0,29);T0->Draw("HIST");
	c2->cd(2);  hvel0->SetTitle("initial velocity (mm/s);vel0 (mm/s);");
	          hvel0->GetXaxis()->SetNdivisions(5,kTRUE); Setstyle(hvel0,29);hvel0->Draw("HIST");
	c2->cd(3);  hX0tgt->SetTitle("x0tgt"); Setstyle(hX0tgt,29);hX0tgt->Draw("HIST");
	c2->cd(4);  hY0tgt->SetTitle("y0tgt"); Setstyle(hY0tgt,29);hY0tgt->Draw("HIST");
	c2->cd(5);hZ0tgt->SetTitle("z0_tgt"); Setstyle(hZ0tgt,29);hZ0tgt->Draw("HIST");
 	c2->cd(6);Setstyle(hZ0tgt_emission,29);hZ0tgt_emission->Draw("HIST");
 	//hZ0tgt_emission->Fit("expo","R","",-2,-0.01);

	c2->cd(7);
	hTlaserR->SetTitle("Emission Mu-r; t (us);"); //SetstyleG(TLaser,8);
	Setstyle(hTlaserR,29);
	hTlaserR->Draw();
	c2->cd(8);
	hTlaserL->SetTitle("Emission Mu-l; t (us);");
	Setstyle(hTlaserL,29);
	hTlaserL->Draw();
	c2->cd(9);
	hZT2D->Draw("colz");
	c2->cd(10);
	hEmissionXY->Draw("colz");

	c2->cd(11);
	Setstyle(hZLaserL,29);hZLaserL->Draw();
	c2->cd(12);
	Setstyle(hZLaserR,29);hZLaserR->Draw();

	c2->SaveAs(Form("./Root/%s_hist_Type%0.0d_D%0.0f_T%0.0f_Nrepeat%0.0d_Xfree%d_Thick%0.2f_NewGeo%d_.pdf",name.Data(),MCtype,D,T,Nrepeat,flag_xfree,Thick,flag_newGeo));


	if(MCtype==2){

		TCanvas *c5 = new TCanvas("c5","c5",800,600);
		c5->Divide(3,3);
		c5->cd(1);Setstyle( hTlaserVtot,29); hTlaserVtot->Draw("EP");
		c5->cd(2);Setstyle(hTlaserV1,29);hTlaserV1->Draw("EP");
		c5->cd(3);Setstyle(hTlaserV2,29);hTlaserV2->Draw("EP");
		c5->cd(4);Setstyle(hTlaserV3,29);hTlaserV3->Draw("EP");

		//TCanvas *c6 = new TCanvas("c6","c6",1000,1000);
		//c6->Divide(3,2);
		c5->cd(5);Setstyle(hDecayZ,29); hDecayZ->Draw("");
		c5->cd(6);Setstyle(TEmission,29);TEmission->Draw("");
		c5->cd(7);Setstyle(VEmission,29);VEmission->Draw("");
		c5->cd(8);Setstyle(hTheta0_emission,29);hTheta0_emission->Draw("");
		c5->cd(9);Setstyle(hTheta0,29);hTheta0->Draw("");

	}

}




void DrawGeo(){
	//TBox *aerogel = new TBox(-2,-7.05,0.0,-5.15);
	TBox *aerogel = new TBox(-2,-15,0.0,20);
	//TBox *aerogel = new TBox(-0.5,-8.3,0.0,-7.7);
	//TBox *LaserRegion = new TBox(1,-7.05,6.0,-5.15);
	TBox *LaserRegion = new TBox(1,-15,6.0,20);
	TBox *LaserRegion2 = new TBox(-8,-15,-3,20);

	aerogel->SetFillStyle(3002);
	aerogel->SetFillColor(1);
	LaserRegion->SetFillStyle(3004);
	LaserRegion->SetFillColor(3);
	LaserRegion2->SetFillStyle(3004);
	LaserRegion2->SetFillColor(3);


	DiffusionTrack->GetXaxis()->SetRangeUser(-2.0,11.0);
	//DiffusionTrack->GetYaxis()->SetRangeUser(-7.05,-5.15);
	//DiffusionTrack->GetYaxis()->SetRangeUser(-8.3,-7.7);
	DiffusionTrack->GetYaxis()->SetRangeUser(-15,35);
	DiffusionTrack->GetXaxis()->SetLimits(-11,11);

	TCanvas *c6 = new TCanvas("c6","c6",800,600);
	DiffusionTrack->SetMarkerStyle(20);
	DiffusionTrack->SetMarkerSize(0.4);
	DiffusionTrack->SetMarkerColor(2);
	DiffusionTrack->SetLineColor(2);


	DiffusionTrack->Draw("ALP");
	LaserRegion->Draw();
	LaserRegion2->Draw();
	aerogel->Draw();

}


#endif

