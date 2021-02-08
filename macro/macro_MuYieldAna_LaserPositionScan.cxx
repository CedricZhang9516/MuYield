#include "macro_MuYieldAna.h"
#include "InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
#include "MuYield_Class.C"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"

//#define drawplot
//#define saveplot
using namespace std;



void macro_MuYieldAna_LaserPositionScan(){//TString filename = "MuYield.root", int MCtype=1002){

	const int Nfile = 1;//4;//8;

	TString filename [Nfile] = {


		//"../Root/210113_Reflection/210113_Reflection_3012_stopping360_tree_Type3012_D87000_T322_Nrepeat139907_NewGeo0.root",
		//"../Root/210113_Reflection/210113_Reflection_3012_stopping400_tree_Type3012_D87000_T322_Nrepeat160677_NewGeo0.root",
		//"../Root/210113_Reflection/210113_Reflection_3012_stopping450_tree_Type3012_D87000_T322_Nrepeat163165_NewGeo0.root",
		//"../Root/210113_Reflection/210113_Reflection_3012_stopping500_tree_Type3012_D87000_T322_Nrepeat133583_NewGeo0.root",

		//"../Root/210113_Reflection/210113_Reflection_5003_stopping450_tree_Type5003_D87000_T322_Nrepeat163165_NewGeo0.root"


		//"../Root/201103_Reflection/201103_Reflection_3005_tree_Type3005_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3005;
		//"../Root/201103_Reflection/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3006;
		//"../Root/201103_Reflection/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3006;
		//"../Root/201103_Reflection/201103_Reflection_3011_tree_Type3011_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3011;
		//"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;

		//"/home/had/zhangce/g-2_tape/Mu1S2S/MuYield/MuYield_210120_HighStat_total_tree_Type1001_D87000_T322_H_line0_Thick8.80_NewGeo0_TBEAM_0.root"
		//"../Root/210202_Reflection/210202_Reflection_5003_stopping255_tot_tree_Type5003_D87000_T322_Nrepeat2918562_NewGeo0_TBEAM_0.root" //MCtype = 3012;
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_Sline_210205/S2areaMuYield_Sline_210205_tot-Itv-4_Type5003_D87000_T322_NewGeo0_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-4/S2areaMuYield_SlineItvScan_210205_tot-Itv-4_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-5/S2areaMuYield_SlineItvScan_210205_tot-Itv-5_TBEAM_0.root",
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-6/S2areaMuYield_SlineItvScan_210205_tot-Itv-6_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-7/S2areaMuYield_SlineItvScan_210205_tot-Itv-7_TBEAM_0.root",
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-8/S2areaMuYield_SlineItvScan_210205_tot-Itv-8_TBEAM_0.root"
		"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-9/S2areaMuYield_SlineItvScan_210205_tot-Itv-9_TBEAM_0.root"



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

		//"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;
		//"../Root/201202_Reflection/201202_Reflection_3021_tree_Type3021_D87000_T322_Nrepeat3031781_NewGeo0.root"
		//"../Root/201202_Reflection/201202_Reflection_3022_tree_Type3022_D87000_T322_Nrepeat3031781_NewGeo0.root"
		//"../Root/201202_Reflection/201202_Reflection_3022_tree_Type3023_D87000_T322_Nrepeat3031781_NewGeo0.root"

		//"../Root/210113_Reflection/210113_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat139907_NewGeo0.root"
	};

	int MCtype [Nfile] = {
		//3005,
		//3006,
		//3006,
		//3011,
		//3006
		//3012,
		//3012,
		//3012,
		//3012,
		//3012
		//4006
		//5003
		//5004
		//5005
		//5006
		//5007
		5008

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
		//3021
	};

	//SetPalette();
	//SetOptStat();

	MuYield_Class * t[Nfile];
	TGraph*** g = new TGraph**[Nfile];
	TGraph*** g_reflection = new TGraph**[Nfile];

	TGraph** g_YieldWithLaserPosition = new TGraph*[Nfile];

	lasertime = 1.35;

	for(int i = 0; i< Nfile; i++){

		g_YieldWithLaserPosition[i] = new TGraph();

		filename[i].ReplaceAll(".root","");

		t[i] = new MuYield_Class(filename[i], MCtype[i]);

		for(int j = 2; j<24; j++){
			TString savefilename = filename[i] + Form("WithoutReflection_%1d",j); //("TBEAM_0",Form("TBEAM_0_%d",j) )
			t[i]->Init(t[i]->tree);
			t[i]->Surface();
			t[i]->SetLasertime(lasertime);
			t[i]->SetLaserCenter(j);
			t[i]->LoopEvent();
			//t[i]->LoopEventWithReflection(1);
			t[i]->SavePlots(savefilename.Data() );
			cout<<"Maximum Yield in the laser region (Without Reflection) "
			<<t[i]->hT->GetMaximum()
			<<" in the bin "
			<<t[i]->hT->GetMaximumBin()
			<<" when laser position is z = "
			<<j<<" mm"
			<<" with interval "
			<<i+9
			<<endl;

			g_YieldWithLaserPosition[i]->SetPoint(j-2,j,t[i]->hT->GetMaximum());
		}


	}

	EColor ci[6] = {kYellow, kOrange, kRed, kPink, kMagenta ,kViolet};
	TCanvas * c0 = new TCanvas("c0_reflection_hT","c0_hT_reflection",700,500);

	for(int i = 0; i< Nfile; i++){


		g_YieldWithLaserPosition[i]->SetLineColor(ci[i]);
		//t[i]->hT->SetLineWidth(2);
		if(i==0)g_YieldWithLaserPosition[i]->Draw();
		else g_YieldWithLaserPosition[i]->Draw("same");

	}


	//// draw preliminary

/*
	TLegend *tl = new TLegend(0.7,0.7,0.9,0.9);
	tl->AddEntry(g_YieldWithLaserPosition[0],"itv = 4 mm","l");
	tl->AddEntry(g_YieldWithLaserPosition[1],"itv = 5 mm","l");
	tl->AddEntry(g_YieldWithLaserPosition[2],"itv = 6 mm","l");
	tl->AddEntry(g_YieldWithLaserPosition[3],"itv = 7 mm","l");
	tl->AddEntry(g_YieldWithLaserPosition[4],"itv = 8 mm","l");
	tl->AddEntry(g_YieldWithLaserPosition[5],"itv = 9 mm","l");
	tl->Draw();
	c0->SaveAs("210207-itvScan.C");
	c0->SaveAs("210207-itvScan.pdf");
	c0->SaveAs("210207-itvScan.root");
*/

	//c0->SaveAs("210204_Reflection/210204_bottomNoreflction.C");
	//c0->SaveAs("210204_Reflection/210204_bottomNoreflction.pdf");
/*
	TCanvas * c1 = new TCanvas("c1_reflection","c1_reflection",1400,500);
	c1->Divide(2,1);
	c1->cd(1);
	//t[Nfile-1]->hT->SetNormFactor(0.1*t[Nfile-1]->hT->GetEntries());
	//t[Nfile-1]->hT->GetYaxis()->SetRangeUser(0,62000);
	t[Nfile-1]->hT->Draw();
	//t[Nfile-1]->hT->SetLineColor(1);
	//t[Nfile-1]->hT->SetLineWidth(2);
	tl->AddEntry(t[Nfile-1]->hT,Form("%d mm",6+2),"L");
	//for(int i = Nfile-2; i>=0;i--){t[i]->hT->SetLineColor(Nfile+1-i);t[i]->hT->SetLineWidth(2);t[i]->hT->Draw("same");tl->AddEntry(t[i]->hT,Form("%d mm",i+2),"L");}
	for(int i = Nfile-2; i>=0;i--){t[i]->hT->SetLineColor(ci[i+1]);t[i]->hT->SetLineWidth(2);t[i]->hT->Draw("same");tl->AddEntry(t[i]->hT,Form("%d mm",i+2),"L");}
	tl->Draw();
*/
/*
	c1->cd(2);
	t[0]->hZY2D_sf->Draw("colz");
	//t[i]->hT->Draw();
	//t[i]->hXY2D_0->Draw("colz");
	//t[0]->hZY2D_sf->Draw("colz");
	//t[0]->g_track_reflection->Draw("PLsame");
	//t[0]->hZY2D_sf->Draw("colz");
	t[0]->g_track_reflection->Draw("PLsame");
	//g[0][1]->Draw("PLsame");

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

	c2->cd(3);
	t[0]->hZY2D_laser->Draw("colz");
*/

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
