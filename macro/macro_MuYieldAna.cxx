#include "macro_MuYieldAna.h"
#include "macro_InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"


#define YieldTime // Calculate the # of Mu inside the laser region as the function of time
//#define Track     /// draw the track inside the aerogel for single event
//#define TrackTime
//#define TrackEventTime
#define drawplot

void macro_MuYieldAna(TString filename = "MuYield.root"){

	filename.ReplaceAll(".root","");


	/// Reproduce
	//TString filename = "../Root/TDR_Reproduce_200204_tree_Type3_D87000_T322_Nrepeat200000_Xfree1_Thick7.12_NewGeo0";
	//TString filename = "../Root/TRIUMF_Reproduce_200204_tree_Type2_D87000_T322_Nrepeat200000_Xfree1_Thick7.12_NewGeo0";

	/// 8 mm new Geo result 5
	//TString filename = "../Root/HLINENEWGEO_200206_tree_Type5_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";
	/// 4 mm new Geo result 6
	//TString filename = "../Root/HLINENEWGEO_200206_4mm_tree_Type6_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";
	/// Yannis new Geo result 7
	//TString filename = "../Root/HLINENEWGEO_200206_Yannis_tree_Type7_D87000_T322_Nrepeat3231566_Xfree0_Thick7.12_NewGeo0";
	/// 7-4mm new Geo result 8
	/////// BUGS ////// TString filename = "../Root/HLINENEWGEO_200206_7-4mm_tree_Type8_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";
	//TString filename = "../Root/HLINENEWGEO_200209_7-4mm_tree_Type8_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";

	//XY20, TDR
	//TString filename = "../Root/TDR_200206_XY20limit_tree_Type3_D87000_T322_Nrepeat3231566_Xfree1_Thick7.12_NewGeo1";
	//For the comparison, TDR
	//TString filename = "../Root/TDR_200207_X50Y28limit_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";
	//For the comparison, 300 mm, TDR 300 mm, G.Marshal's graph
	//TString filename = "../Root/TDR_200207_XY300_Reproduce_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";


	/// SHIFTED 8 mm new Geo result 9
	//TString filename = "../Root/HLINENEWGEO_200209_SHIFTED_tree_Type9_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";
	/// SHIFTED 7-4mm new Geo result 10
	//TString filename = "../Root/HLINENEWGEO_200209_SHIFTED_4mm-7_tree_Type10_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";

	///// X-free type
	//TString filename = "../Root/TDR_200209_Xfree_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";
	//TString filename = "../Root/HLINENEWGEO_200209_Xfree_tree_Type5_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";
	//TString filename = "../Root/HLINENEWGEO_200209_SHIFTED8mm_Xfree_tree_Type9_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";
	//TString filename = "../Root/HLINENEWGEO_200209_Yannis_Xfree_tree_Type7_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";


	//TString filename = "../Root/GM_test_7.12_tree_Type5_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";
	//TString filename = "../Root/GM_10_tree_Type5_D87000_T322_Nrepeat1805626_H_line1_Thick10.00_NewGeo1";
	//"../Root/GM_12_tree_Type5_D87000_T322_Nrepeat2050996_H_line1_Thick12.00_NewGeo1";
	//"../Root/200321_type3_hline_repro_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";

	//TString filename = "../Root/GM_14_tree_Type5_D87000_T322_Nrepeat2150294_H_line1_Thick14.00_NewGeo1";
	//// XY50 above, for test

	//TString filename =
	filename =

	// 0420, Type 1001
	//"../Root/1001_TDR_Fig_Reproduction/200420_TDR_Fig_X25Y28_singlePiece_tree_Type1001_D87000_T322_Nrepeat1352113_H_line1_Thick7.12_NewGeo0";
	//"../Root/1001_TDR_Fig_Reproduction/TDR_200207_X50Y28limit_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";

	// 0420, Type 1002
	"../Root/1002_TDR_Xfree0.38Reproduction/200420_TDR_unlimited_X150Y150_singlePiece_tree_Type1002_D87000_T322_Nrepeat1352113_H_line1_Thick7.12_NewGeo0";
	//"../Root/1002_TDR_Xfree0.38Reproduction/TDR_200207_XY300_Reproduce_tree_Type3_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo0";

	//"../Root/2001_Multi-piece-3piece/200418_Mutipiece_tree_Type12_D87000_T322_Nrepeat3031781_H_line1_Thick8.00_NewGeo0";

	//"../Root/3002_Multi-piece-3piece-horizontal-25mm/200420_HorizontalMulti_25mm_tree_Type3002_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0";

	//"../Root/3003_Multi-piece-horizontal-7.12mm-v/200420_HorizontalMulti_tree_Type3003_D87000_T322_Nrepeat1352113_H_line1_Thick7.12_NewGeo0";
	//"../Root/3003_Multi-piece-horizontal-7.12mm-v/HLINENEWGEO_200209_SHIFTED8mm_Xfree_tree_Type9_D87000_T322_Nrepeat3231566_H_line1_Thick7.12_NewGeo1";

	//"../Root/3004_Multi-piece-horizontal-14mm-v/200420_HorizontalMulti_14mm_tree_Type3004_D87000_T322_Nrepeat2150294_H_line1_Thick14.00_NewGeo0";
	//"../Root/3004_Multi-piece-horizontal-14mm-v/GM_14_tree_Type5_D87000_T322_Nrepeat2150294_H_line1_Thick14.00_NewGeo1";

	//"../Root/3005_Multi-piece-horizontal-25mm-v14mm/200420_HorizontalMulti_25mm-v-14mm_tree_Type3005_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0";
	//"../Root/3006/200421_HorizontalMulti_8mmShifted_25mm-v-14mm_tree_Type3006_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0";

	//"../Root/3011/200421_HorizontalMulti_4mm_25mm-v-14mm_tree_Type3011_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0";

	//"../Root/3012/200421_HorizontalMulti_4mmShifted_25mm-v-14mm_tree_Type3012_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0";


	//"../Root/200524_H-line_TDR_tree_Type1002_D87000_T322_Nrepeat6504_H_line1_Thick7.12_NewGeo0";

	//"../Root/200526_H-line_TDR_1010308_tree_Type1002_D87000_T322_Nrepeat1010308_H_line1_Thick7.12_NewGeo0";
	//"/home/had/zhangce/g-2/MuYield/Root/MuYield_200605_2e6_010_focus05_329095_tree_Type1002_D87000_T322_Nrepeat135936_H_line1_Thick7.12_NewGeo0";

	//"/home/had/zhangce/g-2/MuYield/Root/MuYield_200605_2e6_000_focus05_328933_tree_Type1002_D87000_T322_Nrepeat135905_H_line1_Thick7.12_NewGeo0";
	//"/home/had/zhangce/g-2/TDRFIG/MuYield_200605_TDR_1352591_G-2EDM_output_1e6_gendat_afterfit_SEPON_all_dump-sum_tree_Type1002_D87000_T322_Nrepeat1352591_H_line1_Thick7.12_NewGeo0";

	//gROOT->ProcessLine( Form(".!mkdir %s",filename.Data()) );

	SetPalette();
	//SetOptStat();


	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get("tree");

	int Nentries = tree->GetEntries();

	InitTree(tree);




	//////// Draw the tack of one of the events

	#ifdef Track

	tree->GetEntry(3);
	TGraph * g = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g->Draw("APL*");

	#endif


	//////// Draw the aerogel geometry

	//tree->GetEntry(3);
	//TCanvas* c3 = macro_DrawAerogelGeo(DiffusionVertexX,DiffusionVertexY,DiffusionVertexZ);


	//////// Draw The TRIUMF result in each regions
	/*
	TH1F * hDecayT = TreeToTH1F(tree,"DecayT * 1e6",100,0,10,
		"DecayZ>10 && DecayZ<20 && sqrt(pow(DecayPositronMomtX,2) + pow(DecayPositronMomtY,2) + pow(DecayPositronMomtZ,2)) > 30 && DecayPositronMomtX>10");
	hDecayT->SetTitle("DecayT, P > 30 Mev, Px > 10 MeV, 10 mm to 20 mm; T [us]; N");
 	hDecayT->Draw("");
	*/

	//////// Draw Mu yield dynamics in vacuum
	///////// THIS TWO FUNCTIONS SHOULD NOT BE USED SIMUTANEOUSLY

	lasertime = 1.35; // if comment it, the laser will not be shot


	///// OUTPUT the ionized muon events for further analysis, such as ToRFQ or Slow muon beam line

	// LaserIonization(tree,filename.Append(Form("_ionization_%0.02f.dat",lasertime)) );



	#ifdef drawplot


	TCanvas * c0 = NewTCanvas("c0","c0",800,800,1,1);
	TCanvas * c1 = NewTCanvas("c1","c1",1000,1000,3,3);
	TCanvas * c2 = NewTCanvas("c2","c2",1333,333,4,1);

	TCanvas * c_Track = NewTCanvas("c_Track","c_Track",1333,1333,1,1);
	//int NCanvas = 0;

	#endif


	//MuYieldAsTime(tree);

	MuYieldAsEvent(tree,c0);


	#ifdef drawplot

	/////////////////
	// Yield on the surface
	/////////////////

	c1->cd(1);
	hZY2D_sf->Draw("colz");

	c1->cd(2);
	hZX2D_sf->Draw("colz");

	c1->cd(3);
	hXY2D_sf->Draw("colz");

	c1->cd(4);
	hT_sf->Draw("");


	/////////////////
	// Total yield or the laser time yield
	/////////////////

	c2->cd(4);
	hT->Draw();
	cout<<"Maximum Yield in the laser region "
		<<hT->GetMaximum()
		<<" in the bin "
		<<hT->GetMaximumBin()
		<<endl;

	c2->cd(2);
	hZY2D->Draw("colz");
	c2->cd(3);
	hZX2D->Draw("colz");
	c2->cd(1);
	hXY2D->Draw("colz");

	//SaveTCanvas(c1,(filename+"/"+hZY2D_sf->GetName()+"").Data());
	//SaveTCanvas(c2,(filename+"/"+hZY2D->GetName()+"LaserRegion").Data());

	/////////////////
	///// Draw other 2D and 3D plots
	/////////////////
/*
	c1->cd(1);
 	hZT2D->Draw("colz");
 	c1->cd(2);
 	hZY2D->Draw("colz");
 	c1->cd(3);
 	hZX2D->Draw("colz");
 	c1->cd(4);
 	hXY2D->Draw("colz");
 	c1->cd(5);
 	hZXT3D->Draw("LEGO");
 	c1->cd(6);
 	hZXY3D->Draw("lego2");
*/

 	////////////////
 	///// TRIUMF region count
 	///////////////

 	//TRIUMFVacuumRegion(tree);


	////////////
	///// PlayGround
	////////////

	int iCvs = 1;
	//c0->cd(iCvs++);
	//tree->Draw("DiffusionT");
	//c0->cd(iCvs++);
	c0->cd();
/*
	TH1F* hDecayZ0 = TreeToTH1F(tree,"Z0",200,-10,2,
		"Z_sf>-1");
	hDecayZ0->SetTitle("H-line-Stopping_Z0;Z[mm];N");
	SaveTH1(hDecayZ0,"H-line_initial_Profile_GM_z0");
*/
	hT->Draw();

#endif

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

void MuYieldAsTime(TTree * tree, TCanvas * c = new TCanvas("c_intrnl","c_intrnl",300,1500))
//void MuYieldInVacuum(TTree * tree)
{
	nbinT = 800; /// 8 us
	Tstep = 1e-8; /// 0.01 us

	c = new TCanvas("c_intrnl","c_intrnl",1200,300);
	c->Divide(4,1);

	int Nentries = tree->GetEntries();

	double x, y, z, vx, vy, vz, t;



	//for(int j = lasertime; j < nbinT; j++){
	for(int j = 0; j < nbinT; j++){

		cout<<j<<"/"<<nbinT<<"\r"<<flush;

		hZT2D->Reset();
		hZY2D->Reset();
		hZX2D->Reset();
		hXY2D->Reset();
		hXYT3D->Reset();
		hZXY3D->Reset();

		for(int i = 0; i<Nentries; i++){

			tree->GetEntry(i);

			if( (Tstep*j <= (DiffusionT+TBeam)) || (Tstep*j >= (DecayT+TBeam) ))continue;

			double delT = (Tstep) * j - (DiffusionT+TBeam);

			t = Tstep*j;
			//cout<<t<<endl;
			x = X_sf + VX_sf * delT;
			y = Y_sf + VY_sf * delT;
			z = Z_sf + VZ_sf * delT;


			/// TBeam + DecayT is the total time muon went through
			//  from the Mu formation to its decay,
			//  starting from the first muon arrival at target at t = 0

			/// DecayT is the total time muon went through
			//  from Mu formation to its decay.
			//  but the exact Mu formation time for different muon event is different
			//if(InsideLaserRegionTDR(x,y,z)){
			if(InsideLaserRegionTDRnoXlimit(x,y,z)){

			//if(InsideLaserRegionNewGeo_8mm(x,y,z)){
			//if(InsideLaserRegionNewGeo_8mm_12mmthick(x,y,z)){
			//if(InsideLaserRegion_2001(x,y,z)){
			//if(InsideLaserRegion_3003(x,y,z)){
			//if(InsideLaserRegion_3004(x,y,z)){
			//if(InsideLaserRegion_3002(x,y,z)){
			//if(InsideLaserRegion_3011(x,y,z)){
			//if(InsideLaserRegion_3012(x,y,z)){
			//if(InsideLaserRegion_3006(x,y,z)){
				hZT2D->Fill(t, z);
				hZY2D->Fill(z, y);
				hZX2D->Fill(z, x);
				hXY2D->Fill(x, y);
				hXYT3D->Fill(t, x, y);
				hZXY3D->Fill(z, x, y);
				hT->Fill(t);
			}

			//if(InsideLaserRegionTDR(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionTDRnoXlimit(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm_12mmthick(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm_14mmthick(x,y,z))hT->Fill(t);


		} // loop of all the events


		/// Save the dynamic png
		//if( j == lasertime+10 ) break;

		if( j>=0 && j % 1 == 0){
			c->cd(4);
			hT->Draw("");
			c->cd(2);
			hZY2D->Draw("colz");
			c->cd(3);
			//hZT2D->Draw("colz");
			c->cd(3);
			hZX2D->Draw("colz");
			c->cd(1);
			hXY2D->Draw("colz");
			//hZXY3D->Draw("lego2");
			//hXYT3D->Draw("lego2");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			//c->SaveAs(Form("MuYieldAsTime_%.3f_us.png",j*0.1));
			if( gSystem->ProcessEvents()) break;
		}



	} // loop of all the time from 0 to 8 us, step 1 ns

}


void MuYieldAsEvent(TTree * tree, TCanvas * c = new TCanvas("c_intrnl","c_intrnl",1000,1000))
//void MuYieldInVacuum(TTree * tree)
{


	int Nentries = tree->GetEntries();

	double x, y, z, vx, vy, vz, t;

	for(int i = 0; i<Nentries; i++){
	//for(int i = 0; i<9; i++){

		tree->GetEntry(i);

		cout<<i<<"/"<<Nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;
		//double delT = DecayT - t0;

		t = DiffusionT + TBeam;

		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		if(z>0){

			hZY2D_sf->Fill(Z_sf, Y_sf);
			hZX2D_sf->Fill(Z_sf, X_sf);
			hXY2D_sf->Fill(X_sf, Y_sf);

		}

		hT_sf->Fill(t);

		hZXY3D_sf->Fill(Z_sf, X_sf, Y_sf);

#ifdef YieldTime
		for(int j = 0; j < nbinT; j++){

			if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			hZT2D->Fill(t, z);
			hZY2D->Fill(z, y);
			hZX2D->Fill(z, x);
			hXY2D->Fill(x, y);
			hXYT3D->Fill(t, x, y);
			hZXY3D->Fill(z, x, y);

			//if(InsideLaserRegionTDR(x,y,z))hT->Fill(t);
			if(InsideLaserRegionTDRnoXlimit(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_4mm(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_yannis(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_7_4mm(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mmSHIFTED(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_7_4mmSHIFTED(x,y,z))hT->Fill(t);

			//if(InsideLaserRegionNewGeo_8mm_10mmthick(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm_14mmthick(x,y,z))hT->Fill(t);
			//if(InsideLaserRegionNewGeo_8mm_12mmthick(x,y,z))hT->Fill(t);
			//if(InsideLaserRegion_3011(x,y,z))hT->Fill(t);
			//if(InsideLaserRegion_3012(x,y,z))hT->Fill(t);
			//if(InsideLaserRegion_3006(x,y,z))hT->Fill(t);

#ifdef TrackTime
			//hXY2D->Draw("colz");
			//hZY2D->Draw("colz");
			hZXY3D->Draw("lego2");
			//hXYT3D->Draw("lego2");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			if( gSystem->ProcessEvents()) break;
#endif // track time per point

		} // event loop

#ifdef TrackEventTime

		if( i>=100 && i % 100 == 0){
			hZY2D->Draw("colz");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			if( gSystem->ProcessEvents()) break;
		}
		//c->SaveAs(Form("./png/%i.png",i));

#endif // track event time
#endif // Yield time

	} // all surface events



}



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


void LaserIonization(TTree * tree, TString Outputfilename = "LaserIonization.dat")
{


	ofstream wf(Outputfilename.Data());

	int Nentries = tree->GetEntries();

	double x, y, z, vx, vy, vz, t, muonid;

	const double mmu = 105.658;
	const double light = 299792458; // m/s
	const double massMu = 106.16/light/light; // MeV/c2

	//DEBUG
	int NLaserRegion = 0;
	int NLaserRegion3 = 0;
	double tT1, tT2, tT3;
	double tZ1, tZ2, tZ3;

	for(int i = 0; i<Nentries; i++){
	//for(int i = 0; i<9; i++){

		//DEBUG
		int FNLaserRegion = 0;
		int FNLaserRegion3 = 0;
		tZ1 = 0;

		tree->GetEntry(i);

		cout<<i<<"/"<<Nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;

		if(
			( DecayT <= (lasertime*1e-6  - TBeam) )  ||
			(lasertime*1e-6 - TBeam - DiffusionT) < 0
		)continue;



		t = DiffusionT + TBeam;

		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

		//////////////////////////////////////////////////////
		///////////  DEBUG

/*



		for(int j = 0; j < nbinT; j++){

			//if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			hZT2D->Fill(t, z);
			hZY2D->Fill(z, y);
			hZX2D->Fill(z, x);
			hXY2D->Fill(x, y);
			hXYT3D->Fill(t, x, y);
			hZXY3D->Fill(z, x, y);

			//if(InsideLaserRegionTDR(x,y,z))hT->Fill(t);
			if(InsideLaserRegionTDRnoXlimit(x,y,z))hT->Fill(t);

			if( abs(t - lasertime*1e-6)<=Tstep ){
				//cout<<t<<" "<<lasertime*1e-6<<endl;
				tZ1 = z;
				if(InsideLaserRegionTDRnoXlimit(x,y,z)){NLaserRegion++;FNLaserRegion=1;}
				break;
			}

		}
*/

		///////////  DEBUG
		//////////////////////////////////////////////////////



		t = DiffusionT + TBeam;
		x = X_sf;
		y = Y_sf;
		z = Z_sf;

		x = x + vx * (lasertime*1e-6 - TBeam - DiffusionT);
		y = y + vy * (lasertime*1e-6 - TBeam - DiffusionT);
		z = z + vz * (lasertime*1e-6 - TBeam - DiffusionT);
		t = lasertime*1e-6;

		std::streamsize prev_precision = wf.precision(); // save old precision

		if(InsideLaserRegionTDRnoXlimit(x,y,z)){

			double p = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE);
			double g = 1.0*(mmu+LaserE)/mmu;
			double b = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE)/(mmu+LaserE);
			//cout << g << "\t" << b << endl;

			double xp = VX_sf/VZ_sf;
			double yp = VY_sf/VZ_sf;


			wf << x*0.1 << " "
			<< xp*1000 << " "
			<< y*0.1 << " "
			<< yp*1000 << " ";

			wf << scientific
			<< mmu/1000*g*b << " ";

			wf.precision(prev_precision); // restore old precision

			wf << fixed << z << " "
			<< 0 << " "
			<< "-1 -1 ";// << endl;

			wf << fixed << setprecision(0) << MUONID
			<< endl;


			wf.precision(prev_precision); // restore old precision

			NLaserRegion3++;

			/*
			//DEBUG
			if(FNLaserRegion==0){
				cout<<"check with two methods "<<tZ1<<" "<<z<< endl;
			}
			*/


		}

	} // all surface events


	//DEBUG
	//cout<<"total NLaserRegion "<<NLaserRegion<<endl;
	//cout<<"total NLaserRegion2 "<<NLaserRegion2<<endl;
	cout<<"total NLaserRegion3 "<<NLaserRegion3<<endl;

	TString OutputfilenameWithN = Outputfilename;
	OutputfilenameWithN.ReplaceAll(".dat", Form("_%d.dat",NLaserRegion3) );

	gROOT->ProcessLine( Form(".!mv %s %s",
		Outputfilename.Data(),OutputfilenameWithN.Data()
		) );


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