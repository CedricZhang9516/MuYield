#ifndef _MuYield
#define _MuYield

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <array>
#include <time.h>


double* MCLmfp();
//void FillTZ();
void ShootLaser(double , double , double , double , double , double  ,double );
void ShootLaserPulseE(double , double , double , double , double , double  ,double );

void SetTreeBranch(TTree * tree);
void SetHist(TFile * f);
void WriteHist();


void DrawHistPlot();
void DrawGeo();
void Setstyle(TH1D*, int);
void SetstyleG(TGraph*, int);
//double expo(double, double);

//double GenerateGaus(double, double );
//double GenerateUniform(double, double );
//double GenerateHlineY(TH1D*);

//double MichelSpec();

void InitializingXYZ0();

bool InsideLaserRegion(double, double, double);
bool InsideAerogel(double x, double y, double z);


TString name;


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


std::vector<double>* DiffusionVertexX;// = new std::vector<double>;//(5,0);
std::vector<double>* DiffusionVertexY;// = new std::vector<double>;//(5,0);
std::vector<double>* DiffusionVertexZ;// = new std::vector<double>;//(5,0);
std::vector<double>* DiffusionVertexT;// = new std::vector<double>;//(5,0);


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

void Setstyle(TH1D *g, int c){
	g->SetFillColor(c);
    g->SetFillStyle(3001);
    g->SetLineColor(c);
    g->SetMarkerColor(1);
   	g->SetMarkerSize(0.5);
    g->SetMarkerStyle(20);
}

void SetstyleG(TGraph *g, Int_t c){
    g->SetLineColor(c);
    g->SetLineStyle(4);
    g->SetLineWidth(4);
    g->SetMarkerColor(c);
    g->SetMarkerStyle(14);

}

void InitializingXYZ0(){
	//double* X0, double* Y0, double* Z0

	//beam xy: uniformed or gaussian from tdr
	//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index_m+xStep/2;
	//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;

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
	// for triumf case z
	if(MCtype == 2){
		X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index_m+xStep/2;
		Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
		Z0 = GenerateGaus(0,1.69);//2mm
		if( Z0 > 0) Z0 = - Z0;
	}


}

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
	tree->Branch("DiffusionVertexX", DiffusionVertexX, "DiffusionVertexX/D");// std::vector<double> DiffusionVertexX;
	tree->Branch("DiffusionVertexY", DiffusionVertexY, "DiffusionVertexY/D");// std::vector<double> DiffusionVertexY;
	tree->Branch("DiffusionVertexZ", DiffusionVertexZ, "DiffusionVertexZ/D");// std::vector<double> DiffusionVertexZ;
	tree->Branch("DiffusionVertexT", DiffusionVertexT, "DiffusionVertexT/D");// std::vector<double> DiffusionVertexT;

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

	//(5,0);
	//(5,0);
	//(5,0);
	//(5,0);




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


}

#endif

