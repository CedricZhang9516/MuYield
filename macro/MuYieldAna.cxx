#include "MuYieldAna.h"
#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void MuYieldAna(){

	//const char * filename ="./Root/PulseE0824_tree_Type1_D87000_T322_Nrepeat280000_Xfree1_Thick2.00_NewGeo1_.root";
	//TString filename ="../Root/TRIUMF_Reproduce_200204_tree_Type2_D87000_T322_Nrepeat20000_Xfree1_Thick7.12_NewGeo0";

	//TString filename = "../Root/TDR_Reproduce_200204_tree_Type3_D87000_T322_Nrepeat200000_Xfree1_Thick7.12_NewGeo0";
	//TString filename = "../Root/TRIUMF_Reproduce_200204_tree_Type2_D87000_T322_Nrepeat200000_Xfree1_Thick7.12_NewGeo0";
	//TString filename = "../Root/NewGeo_200206_HLINE_tree_Type5_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";
	TString filename = "../Root/HLINENEWGEO_200206_tree_Type5_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";

	gROOT->ProcessLine(Form(".!mkdir %s",filename.Data()));

	SetPalette();
	SetOptStat();

	TCanvas * c = NewTCanvas("c","c",1000,1000,1,1);
	c->cd(1);

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get("tree");

	int Nentries = tree->GetEntries();

	InitTree(tree);



	//c6->Divide(1,3);

	//////// Draw the tack of one of the events
/*
	tree->GetEntry(1);
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");
*/


	//////// Draw The TRIUMF result in each regions
/*
	TH1F * hDecayT = TreeToTH1F(tree,"DecayT * 1e6",100,0,10,
		"DecayZ>10 && DecayZ<20 && sqrt(pow(DecayPositronMomtX,2) + pow(DecayPositronMomtY,2) + pow(DecayPositronMomtZ,2)) > 30 && DecayPositronMomtX>10");
	hDecayT->SetTitle("DecayT, P > 30 Mev, Px > 10 MeV, 10 mm to 20 mm; T [us]; N");
 	hDecayT->Draw("");
*/

	//////// Draw Mu yield dynamics in vacuum

	MuYieldInVacuum(tree, c);
	hZY2D->Draw("colz");

	SaveTCanvas(c,(filename+"/"+hZY2D->GetName()).Data());

	// Draw other 2D and 3D plots
/*
	c->cd(1);
 	hZT2D->Draw("colz");
 	c->cd(2);
 	hZY2D->Draw("colz");
 	c->cd(3);
 	hZX2D->Draw("colz");
 	c->cd(4);
 	hXY2D->Draw("colz");
 	c->cd(5);
 	hZXT3D->Draw("LEGO");
 	c->cd(6);
 	hZXY3D->Draw("lego2");
*/

 	//////////////// TRIUMF region count

 	//TRIUMFVacuumRegion(tree);

	//////////// PlayGround

	//tree->Draw("Z0");


}


void TRIUMFVacuumRegion(TTree * tree, TCanvas * c = NewTCanvas("c_intrnl","c_intrnl",1000,1000,2,2) )
{
	c->cd(1);
	tree->Draw("DecayT","DecayZ<40 && DecayZ>-8");
	c->cd(2);
	tree->Draw("DecayT","DecayZ<20 && DecayZ>10");
	c->cd(3);
	tree->Draw("DecayT","DecayZ<30 && DecayZ>20");
	c->cd(4);
	tree->Draw("DecayT","DecayZ<40 && DecayZ>30");


}


void MuYieldInVacuum(TTree * tree, TCanvas * c = new TCanvas("c_intrnl","c_intrnl",1000,1000))
//void MuYieldInVacuum(TTree * tree)
{


	int Nentries = tree->GetEntries();

	double x, y, z, vx, vy, vz, t;



	for(int i = 0; i<Nentries; i++){
	//for(int i = 0; i<9; i++){

		tree->GetEntry(i);

		double delT = DecayT - DiffusionT;
		//double delT = DecayT - t0;

		t = DiffusionT + TBeam;

		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		hZY2D->Fill(Z_sf, Y_sf);

		//double flag = 0;

		for(int j = 0; j < nbinT; j++){

			if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			hZT2D->Fill(TBeam + t, z);
			hZY2D->Fill(z, y);
			hZX2D->Fill(z, x);
			hXY2D->Fill(x, y);
			hXYT3D->Fill(t, x, y);
			hZXY3D->Fill(z, x, y);

			/// STRICTLY, IT SHOULD BE TBEAM+T. IN TRIUMF CASE, TBEAM = 0
/*
			if(fabs(y)<=20 && Tstep*i <= delT)
			{
				if( (MCtype == 1 || MCtype == 3) && flag_xfree == 0 && fabs(x)>20)continue;
				if( z >= 1 && z <= 6) {hTlaserR->Fill(TBeam + t);}
				if( z >= (-6-Thick) && z <= (-1-Thick)) {hTlaserL->Fill(TBeam + t);}
			}
*/

			//hXY2D->Draw("colz");
			//hZY2D->Draw("colz");
			//hZXY3D->Draw("lego2");
			//hXYT3D->Draw("lego2");
/*
			c->Modified();
			c->Update();
			//c_intrnl->SaveAs(Form("./png/%i.png",i));
			gSystem->ProcessEvents();
			//gSystem->Sleep(100);
			//if( gSystem->ProcessEvents()) break;
*/
		}
	}



}

/*
bool InsideLaserRegion(double x, double y, double z){ // t = t0 + tbeam
	if( (DecayT + TBeam) < tLaser) return false;
	if( (t0 + TBeam) > tLaser)return false;

	if( flag_xfree == 0 && (fabs(x)>20 || fabs(y)>20) )return false;
	if( flag_xfree == 1 && fabs(y)>20 )return false;

	if( z <= 6 && z>= 1)return true;
	if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
	return false;
}
*/

void Emittance(TTree* tree){

	int Nentries = tree->GetEntries();

	for(int i = 0; i<Nentries; i++){

		tree->GetEntry(i);


	///////////////// Calculate the emittance /////////////

		XXp = MeshX * MeshXp;
		hXXp->Fill(XXp);
		Xp2 = MeshXp * MeshXp;
		hXp2->Fill(Xp2);
		X2 = MeshX * MeshX;
		hX2->Fill(X2);

		YYp = MeshY * MeshYp;
		hYYp->Fill(YYp);
		Yp2 = MeshYp * MeshYp;
		hYp2->Fill(Yp2);
		Y2 = MeshY * MeshY;
		hY2->Fill(Y2);

		BetaGamma = MeshBeta * (1/sqrt(1 - MeshBeta*MeshBeta ));
		hBetaGamma->Fill(BetaGamma);

		//EmissionX->SetPoint(i,MeshZ,MeshXp);
		//if(flag_Newgeo==1){
		//	EmissionX->Fill(MeshZ,MeshXp);
		//	EmissionY->Fill(MeshX,MeshYp);
		//}

		//if(flag_Newgeo==0){
			EmissionX->Fill(MeshX,MeshXp);
			EmissionY->Fill(MeshY,MeshYp);
			CorrMeshTE->Fill(MeshT,MeshEk);
		//}

		hMeshEk->Fill(MeshEk);
		hMeshT->Fill(MeshT);
		hMeshT_ab->Fill(MeshT_ab);
		hMeshX->Fill(MeshX);
		hMeshY->Fill(MeshY);
		hMeshZ->Fill(MeshZ);
		hMeshXp->Fill(MeshXp);
		hMeshYp->Fill(MeshYp);

		hMeshBeta->Fill(MeshBeta);
		hMeshVY->Fill(MeshVY);
		hMeshVX->Fill(MeshVX);
		hMeshVZ->Fill(MeshVZ);

		hDriftT->Fill(DriftT);
		hDriftT_ab->Fill(DriftT_ab);
		hDriftX->Fill(DriftX);
		hDriftY->Fill(DriftY);
		hDriftZ->Fill(DriftZ);

	}

	TCanvas *c5 = new TCanvas("c5","c5",600,800);
	c5->Divide(1,2);
	c5->cd(1);
	EmissionX->Draw("colz");
	c5->cd(2);
	EmissionY->Draw("colz");
	//c5->SaveAs(Pngname);

	TCanvas *c4 = new TCanvas("c4","c4",900,600);
	c4->Divide(3,4);
	c4->cd(1);
	EmissionX->Draw("colz");
	c4->cd(2);
	EmissionY->Draw("colz");

	c4->cd(3);
	//hMeshEk->Draw();
	tree->Draw("MeshEk");
	SetXTitleTreeDraw("MeV");

	c4->cd(4);
	//hMeshT_ab->Draw();
	tree->Draw("MeshT_ab");
	SetXTitleTreeDraw("s");

	c4->cd(5);
	//hMeshX->Draw();
	tree->Draw("MeshX");
	SetXTitleTreeDraw("mm");
	c4->cd(6);
	//hMeshY->Draw();
	tree->Draw("MeshY");
	SetXTitleTreeDraw("mm");
	c4->cd(7);
	hMeshZ->Draw();
	c4->cd(8);
	//hMeshXp->Draw();
	tree->Draw("MeshXp");
	SetXTitleTreeDraw("MeshXp");

	c4->cd(9);
	//hMeshYp->Draw();
	tree->Draw("MeshYp");
	SetXTitleTreeDraw("MeshYp");

	c4->cd(10);
	//hMeshVY->Draw();
	tree->Draw("MeshVX");
	SetXTitleTreeDraw("mm/s");
	c4->cd(11);
	//hMeshVX->Draw();
	tree->Draw("MeshVY");
	SetXTitleTreeDraw("mm/s");

	c4->cd(12);
	tree->Draw("MeshVZ");
	SetXTitleTreeDraw("mm/s");
	//hMeshVZ->Draw();
	//c4->SaveAs(Pdfname);


	TCanvas *c3 = new TCanvas("c3","c3",1000,1000);
	c3->Divide(3,4);
	//c3->cd(1);hDriftT->Draw();
	c3->cd(1);tree->Draw("DriftT_ab","DecayT>=(DriftT_ab-TBeam)");//hDriftT_ab->Draw();
	c3->cd(2);tree->Draw("DriftX","DecayT>=(DriftT_ab-TBeam)");//hDriftX->Draw();
	c3->cd(3);tree->Draw("DriftY","DecayT>=(DriftT_ab-TBeam)");//hDriftY->Draw();
	c3->cd(4);tree->Draw("DriftZ","DecayT>=(DriftT_ab-TBeam)");//hDriftZ->Draw();
	c3->cd(5);//tree->Draw("CorrMeshTE");
	CorrMeshTE->Draw("colz");

	//tree->Draw("MeshVZ");

	//TCanvas *c6 = new TCanvas("c6","c6",900,600);

	c3->cd(6);hXXp->Draw();
	c3->cd(7);hXp2->Draw();
	c3->cd(8);hX2->Draw();
	c3->cd(9);hYYp->Draw();
	c3->cd(10);hYp2->Draw();
	c3->cd(11);hY2->Draw();
	c3->cd(12);hBetaGamma->Draw();

	//c3->SaveAs("./Root/Geo1_PulseE.pdf");

}






/*
void ShootLaser(double distance, double x_, double y_, double z_, double vx_, double vy_ ,double vz_)
{
	x = x_;
	y = y_;
	z = z_;

	vx = vx_;
	vy = vy_;
	vz = vz_;

	t = (sqrt(vz*vz + 2*A * distance) - vz)/A;

	x = x + vx * t ;
	y = y + vy * t ;
	z = z + vz * t + 0.5 * A * t * t;

	vz = vz + A * t;

	double v = sqrt(vx*vx + vy*vy + vz*vz);

	double Xp = vx/vz;
	double Yp = vy/vz;

	double beta = v * 1e-3/light;
	double Ek = 0.5 * massMu * 1e-6 * (vx*vx + vy*vy + vz*vz);//v:mm/s, Ek: MeV


	MeshX = x;
	MeshY = y;
	MeshZ = z;

	MeshVX = vx;
	MeshVY = vy;
	MeshVZ = vz;

	MeshT = t;
	MeshT_ab = MeshT + tLaser;
	MeshXp = Xp;
	MeshYp = Yp;
	MeshEk = Ek;
	MeshBeta = beta;

	///////// Drift

	t = DriftD/vz;//500mm
	DriftT = t;
	DriftT_ab = DriftT + MeshT_ab;

	DriftZ = MeshZ + MeshVZ * t;
	DriftX = MeshX + MeshVX * t;
	DriftY = MeshY + MeshVY * t;

}
*/
/*
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
*/


/*
void ShootLaserPulseE(double distance, double x_, double y_, double z_, double vx_, double vy_ ,double vz_)
{

	vz = 5.652e6;//mm/s
	double PulseD = 10;//10 mm
	double PulseT = (sqrt(vz*vz + 2*A * PulseD) - vz)/A;

	x = x_;
	y = y_;
	z = z_;

	vx = vx_;
	vy = vy_;
	vz = vz_;

	t = (sqrt(vz*vz + 2*A * distance) - vz)/A;

	if(t>=PulseT){
		distance = distance - vz * PulseT - 0.5 * A * PulseT * PulseT;

		z = z + vz * PulseT + 0.5 * A * PulseT * PulseT;
		vz = vz + A * PulseT;


		double delt = distance/vz;

		x = x + vx * delt ;
		y = y + vy * delt ;
		z = z + vz * delt ;

		//cout<<z<<endl;

	}

	if(t<PulseT){

		x = x + vx * t ;
		y = y + vy * t ;
		z = z + vz * t + 0.5 * A * t * t;

		vz = vz + A * t;
	}

	double v = sqrt(vx*vx + vy*vy + vz*vz);

	double Xp = vx/vz;
	double Yp = vy/vz;

	double beta = v * 1e-3/light;
	double Ek = 0.5 * massMu * 1e-6 * (vx*vx + vy*vy + vz*vz);//v:mm/s, Ek: MeV


	MeshX = x;
	MeshY = y;
	MeshZ = z;

	MeshVX = vx;
	MeshVY = vy;
	MeshVZ = vz;

	MeshT = t;
	MeshT_ab = MeshT + tLaser;
	MeshXp = Xp;
	MeshYp = Yp;
	MeshEk = Ek;
	MeshBeta = beta;

	///////// Drift

	t = DriftD/vz;//500mm
	DriftT = t;
	DriftT_ab = DriftT + MeshT_ab;

	DriftZ = MeshZ + MeshVZ * t;
	DriftX = MeshX + MeshVX * t;
	DriftY = MeshY + MeshVY * t;

}
*/
/*
void SetHist(TFile * f){

	 T0 = new TH1D("T0","T0",100,0,1.0e-6); // Tbeam distribution

	 hLmfp = new TH1D("hLmfp","hLmfp;Lmfp (um)",100,0,100); // um

	 hX0tgt = new TH1D("hX0tgt","hX0tgt",2000,-100,100); // mm
	 hY0tgt = new TH1D("hY0tgt","hY0tgt",2000,-100,100); // mm
	 hZ0tgt = new TH1D("hZ0tgt","hZ0tgt",100,-11,9); // mm

	 hZ0tgt_emission = new TH1D("hZ0tgt_emission","hZ0tgt_emission; mm",200,-11,9); // mm

	 hvel0 = new TH1D("hvel0","hvel0",50,0,30000000); // mm/s
	 hTheta0 = new TH1D("hTheta0-cos","Cos(Theta0)",100,-1,1); // cos(theta)
	 hPhi0 = new TH1D("hPhi0","hPhi0",100,0,2*PI); // rad


	 hZT2D = new TH2D("Z-T-2D","Z-T-2D; t(us);z (mm)",100,0e-7,10e-6,1000,-50,50);
	 hTlaserR = new TH1D("T-laser-R","T-laser-R",nbinT,0,Tstep*nbinT);
	 hTlaserL = new TH1D("T-laser-L","T-laser-L",nbinT,0,Tstep*nbinT);

	 hZLaserR = new TH1D("hZLaser-r","hZLaser-r",50,1,6);  // mm
	 hZLaserL = new TH1D("hZLaser-l","hZLaser-l",50,-6-Thick,-1-Thick);  // mm
	//hZlaser right, but no need this plot anymore

	 hDecayX = new TH1D("hDecayX","hDecayX",100,-2,2);  // mm
	 hDecayY = new TH1D("hDecayY","hDecayY",100,-2,2);  // mm
	 hDecayZ = new TH1D("hDecayZ","hDecayZ",100,-10,40);  // mm
	 hDecayT = new TH1D("hDecayT","hDecayT",50,0,12e-6);  // s


	// for TRIUMF case v1-v3
	 hTlaserVtot = new TH1D("T-laser-totV","T-laser-totV",120,0,12e-6);
	 hTlaserV1 = new TH1D("T-laser-v1","T-laser-v1",120,0,12e-6);
	 hTlaserV2 = new TH1D("T-laser-v2","T-laser-v2",120,0,12e-6);
	 hTlaserV3 = new TH1D("T-laser-v3","T-laser-v3",120,0,12e-6);

	 TEmission = new TH1D("TEmission","TEmission",100,0,10e-6);
	 VEmission = new TH1D("VEmission","VEmission;mm/s",100,0,2e7);

	// this two maybe helpful with hZLaser
	 hXLaser = new TH1D("hXLaser","hXLaser",100,-40,40);  // mm
	 hYLaser = new TH1D("hYLaser","hYLaser",100,-40,40);  // mm


	 hTheta0_emission = new TH1D("hTheta0_emission","hTheta0_emission",100,0,1); // rad
	 hPhi0_emission = new TH1D("hPhi0_emission","hPhi0_emission",100,0,1); // rad
	 hEmissionXY = new TH2D("hEmissionXY","hEmissionXY; x(mm);y (mm)",640,-320,320,640,-320,320);

	 DiffusionTrack = new TGraph();

}



void WriteHist(){

	 T0 ->Write();

	 hLmfp ->Write();

	 hX0tgt ->Write();
	 hY0tgt ->Write();
	 hZ0tgt ->Write();

	 hZ0tgt_emission ->Write();

	 hvel0 ->Write();
	 hTheta0 ->Write();
	 hPhi0 ->Write();


	 hZT2D ->Write();
	 hTlaserR ->Write();
	 hTlaserL ->Write();

	 hZLaserR ->Write();
	 hZLaserL ->Write();
	//hZlaser right, but no need this plot anymore

	 hDecayX ->Write();
	 hDecayY ->Write();
	 hDecayZ ->Write();
	 hDecayT ->Write();


	// for TRIUMF case v1-v3
	 hTlaserVtot ->Write();
	 hTlaserV1 ->Write();
	 hTlaserV2 ->Write();
	 hTlaserV3 ->Write();

	 TEmission ->Write();
	 VEmission ->Write();

	// this two maybe helpful with hZLaser
	 hXLaser ->Write();
	 hYLaser ->Write();


	 hTheta0_emission ->Write();
	 hPhi0_emission ->Write();
	 hEmissionXY ->Write();


}

*/