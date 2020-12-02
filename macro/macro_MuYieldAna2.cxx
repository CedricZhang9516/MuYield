#include "macro_MuYieldAna.h"
#include "InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
#include "MuYield_Class.C"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"

//#define drawplot
//#define saveplot
using namespace std;

void macro_MuYieldAna2(){//TString filename = "MuYield.root", int MCtype=1002){

	const int Nfile = 1;

	TString filename [Nfile] = {


		//"../Root/201103_Reflection/201103_Reflection_3005_tree_Type3005_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3005;
		//"../Root/201103_Reflection/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3006;
		//"../Root/201103_Reflection/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3006;
		//"../Root/201103_Reflection/201103_Reflection_3011_tree_Type3011_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3011;
		//"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;

		//"../Root/1002_TDR_Xfree0.38Reproduction/200420_TDR_unlimited_X150Y150_singlePiece_tree_Type1002_D87000_T322_Nrepeat1352113_H_line1_Thick7.12_NewGeo0.root", //MCtype = 3012;
		//"../Root/2001_Multi-piece-3piece/200418_Mutipiece_tree_Type12_D87000_T322_Nrepeat3031781_H_line1_Thick8.00_NewGeo0.root"

		// for scan of itv
		/*
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3012;
		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;
		*/

		"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;
		//"../Root/201202_Reflection/201202_Reflection_3021_tree_Type3021_D87000_T322_Nrepeat3031781_NewGeo0.root"
		//"../Root/201202_Reflection/201202_Reflection_3022_tree_Type3022_D87000_T322_Nrepeat3031781_NewGeo0.root"
		//"../Root/201202_Reflection/201202_Reflection_3022_tree_Type3023_D87000_T322_Nrepeat3031781_NewGeo0.root"


	};

	int MCtype [Nfile] = {
		//3005,
		//3006,
		//3006,
		//3011,
		//3006
		//3012
		//4006

		//1002,
		//2001
/*
		4002,
		4003,
		4004,
		4005,
		4006,
		4007,
		4008
*/
		3012
		//3021
		//3022
		//3023
	};

	//SetPalette();
	//SetOptStat("0000");

	MuYield_Class * t[Nfile];
	TGraph*** g = new TGraph**[Nfile];
	TGraph*** g_reflection = new TGraph**[Nfile];

	lasertime = 1.35;
	//lasertime = 3;

	for(int i = 0; i< Nfile; i++){

		filename[i].ReplaceAll(".root","");

		t[i] = new MuYield_Class(filename[i], MCtype[i]);
		t[i]->Surface();
		t[i]->SetLasertime(lasertime);
		//t[i]->LoopEvent();
		//t[i]->LoopEventWithReflection(1,"3006-reflection.dat");
		t[i]->LoopEventWithReflection(1);
		//t[i]->LoopTime();
		//t[i]->QuickLaserIonization(lasertime,Form("LaserOutput/%s.dat",MCtype) );
		//t[i]->QuickLaserIonization(lasertime);
		//t[i]->SavePlots();

		//double LasertimeAti = 1e6* (t[i]->GetTBeam(i) + t[i]->GetDecayT(i) ) * 0.99;
		//t[i]->SetLasertime(LasertimeAti);

		/// Draw track without reflection
		g[i] = new TGraph*[t[i]->Nentries];
		g_reflection[i] = new TGraph*[t[i]->Nentries];
		double LasertimeAti = 1e6* (t[i]->GetTBeam(i) + t[i]->GetDecayT(i) ) * 0.99;
		t[i]->SetLasertime(LasertimeAti);
		//for(int j = 0; j<t[i]->Nentries;j++) g[i][j] = t[i]->Track(j);
		for(int j = 0; j<20;j++) g[i][j] = t[i]->Track(j);
		for(int j = 0; j<20;j++){
			g_reflection[i][j] = t[i]->TrackWithReflection(j);
			//if(t[1]->IsInsideLaserRegion(i, lasertime))cout<<"MCtype "<<MCtype[1]<<" file "<<1<<" has the event "<<i<<" inside laser region at "<<lasertime<<" us"<<endl;
		}

	}

	//// draw preliminary
	TLegend *tl = new TLegend(0.7,0.7,0.9,0.9);
	TCanvas * c1 = new TCanvas("c1_reflection","c1_reflection",1400,500);
	c1->Divide(2,1);
	c1->cd(1);
	t[0]->hT->Draw();
	//t[6]->hT->SetLineColor(1);
	//tl->AddEntry(t[6]->hT,Form("%d mm",6+2),"L");
	//for(int i = 5; i>=0;i--){t[i]->hT->SetLineColor(7-i);t[i]->hT->Draw("same");tl->AddEntry(t[i]->hT,Form("%d mm",i+2),"L");}
	tl->Draw();

	c1->cd(2);
	t[0]->hZY2D_sf->Draw("colz");
	//t[i]->hT->Draw();
	//t[i]->hXY2D_0->Draw("colz");
	//t[0]->hZY2D_sf->Draw("colz");
	//t[0]->g_track_reflection->Draw("PLsame");
	//g[0][1]->Draw("PLsame");
	//for(int j = 0; j<100;j++){g[0][j]->SetLineColor(j);g[0][j]->Draw("PLsame");}

	//c1->SaveAs(Form("/Users/zhangce/WorkArea/MuYield/macro/20-11-19-reflection-itv-scan/%d.pdf",MCtype[0]));

	//// Comparison of the track

	TCanvas * c2 = new TCanvas("c2_comparison","c2_comparison");
	c2->Divide(2,2);
	int c_i = 0;
	for(int i = 0; i<Nfile;i++){
		c2->cd(++c_i);
		t[i]->hZY2D_sf->Draw("colz");
		//for(int j = 0; j<100;j++){g[i][j]->SetLineColor(j);g[i][j]->Draw("PLsame");}
		for(int j = 0; j<20;j++){g[i][j]->SetLineColor(j);g[i][j]->Draw("PLsame");}

		c2->cd(++c_i);
		t[i]->hZY2D_sf->Draw("colz");
		for(int j = 0; j<20;j++){g_reflection[i][j]->SetLineColor(j);g_reflection[i][j]->Draw("PLsame");}
	}

	TCanvas * c3 = new TCanvas("c3_comparison","c3_comparison");

	//t[0]->hZ1D_laser->Draw();
	t[0]->hZY2D_sf->Draw("colz");
	//for(int j = 50; j<100;j++){g_reflection[0][j]->SetLineColor(j);g_reflection[0][j]->Draw("PLsame");}


}



/*
	#ifdef drawplot

	//TCanvas * c0 = NewTCanvas("c0","c0",800,800,1,1);
	TCanvas * c1 = NewTCanvas("c1","c1_surface",1000,1000,3,3);
	TCanvas * c2 = NewTCanvas("c2","c2_accumulation_yield",1000,1000,3,3);
	TCanvas * c3 = NewTCanvas("c3_laser","c3_laser",1000,1000,3,3);

	/////////////////
	// Yield on the surface
	/////////////////

	c1->cd(1);
	t1->hZY2D_sf->Draw("colz");
	c1->cd(2);
	t1->hZX2D_sf->Draw("colz");
	c1->cd(3);
	t1->hXY2D_sf->Draw("colz");
	c1->cd(4);
	t1->hT_sf->Draw("");


	/////////////////
	// Total yield
	/////////////////

	c2->cd(1);
	t1->hXY2D->Draw("colz");
	c2->cd(2);
	t1->hZY2D->Draw("colz");
	c2->cd(3);
	t1->hZX2D->Draw("colz");
	c2->cd(4);
	t1->hT->Draw();
	cout<<"Maximum Yield in the laser region "
		<<t1->hT->GetMaximum()
		<<" in the bin "
		<<t1->hT->GetMaximumBin()
		<<endl;

	/////////////////
	// Laser yield
	/////////////////

	int c_i = 0;
	c3->cd(++c_i);
	t1->hZY2D_0->Draw("colz");
	c3->cd(++c_i);
	t1->hZX2D_0->Draw("colz");
	c3->cd(++c_i);
	t1->hXY2D_0->Draw("colz");
	c3->cd(++c_i);
	t1->hZY2D_laser->Draw("colz");
	c3->cd(++c_i);
	t1->hZX2D_laser->Draw("colz");
	c3->cd(++c_i);
	t1->hXY2D_laser->Draw("colz");

	/////////////////
	///// Draw other 2D and 3D plots
	/////////////////

	//c1->cd(1);
 	//t1->hZT2D->Draw("colz");
 	//c1->cd(2);
 	//t1->hZY2D->Draw("colz");
 	//c1->cd(3);
 	//t1->hZX2D->Draw("colz");
 	//c1->cd(4);
 	//t1->hXY2D->Draw("colz");
 	//c1->cd(5);
 	//t1->hZXT3D->Draw("LEGO");
 	//c1->cd(6);
 	//t1->hZXY3D->Draw("lego2");


	#endif

	////////////////
 	///// TRIUMF region count
 	///////////////

 	//TRIUMFVacuumRegion(t1->tree);

 	#ifdef saveplot

 	c1->SaveAs( Form("%s.pdf(", filename.Data()) );
 	c2->SaveAs( Form("%s.pdf", filename.Data()) );
 	c3->SaveAs( Form("%s.pdf)", filename.Data()) );


 	#endif

*/
