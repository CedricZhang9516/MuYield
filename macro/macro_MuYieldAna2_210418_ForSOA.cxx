#include "macro_MuYieldAna.h"
#include "InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
#include "MuYield_Class.C"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"

//#define drawplot
//#define saveplot
using namespace std;



void macro_MuYieldAna2_210418_ForSOA(){//TString filename = "MuYield.root", int MCtype=1002){

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


		// 21-02-07 check the three files are consistent:
		//"../Root/Root_tape/210202_Reflection/210202_Reflection_5003_stopping255_tot_tree_Type5003_D87000_T322_Nrepeat2918562_NewGeo0_TBEAM_0.root", //MCtype = 3012;
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_Sline_210205/S2areaMuYield_Sline_210205_tot-Itv-4_Type5003_D87000_T322_NewGeo0_TBEAM_0.root",
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-4/S2areaMuYield_SlineItvScan_210205_tot-Itv-4_TBEAM_0.root"

		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-4/S2areaMuYield_SlineItvScan_210205_tot-Itv-4_TBEAM_0.root",
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-4/S2areaMuYield_SlineItvScan_210205_tot-Itv-4_TBEAM_0.root",
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-4/S2areaMuYield_SlineItvScan_210205_tot-Itv-4_TBEAM_0.root"

		"/home/had/zhangce/MuYield/Root/210506_hline/210506_hline_5003_210506_2e6_999_330076_450_tree_Type5003_D87000_T322_Nrepeat83151_NewGeo0.root"
		//"/home/had/zhangce/MuYield/Root/210506_hline/210506_hline_5003_210506_all_2e6_999_330076_450_tree_Type3012_D87000_T322_Nrepeat162986_NewGeo0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-5/S2areaMuYield_SlineItvScan_210205_tot-Itv-5_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-6/S2areaMuYield_SlineItvScan_210205_tot-Itv-6_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-7/S2areaMuYield_SlineItvScan_210205_tot-Itv-7_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-8/S2areaMuYield_SlineItvScan_210205_tot-Itv-8_TBEAM_0.root"
		//"/home/had/zhangce/MuYield/Root/Root_tape/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-9/S2areaMuYield_SlineItvScan_210205_tot-Itv-9_TBEAM_0.root"




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
		//4003,
		//5003,
		//5003
		4003
		//3012
	};
	int LaserCenter[Nfile] = {
		6//,6,20
	};

	//SetPalette();
	//SetOptStat();

	MuYield_Class * t[Nfile];
	TGraph*** g = new TGraph**[Nfile];
	TGraph*** g_reflection = new TGraph**[Nfile];

	double LaserTime[Nfile] = {1.2};//1.0,0.9,0.9};

	for(int i = 0; i< Nfile; i++){

		filename[i].ReplaceAll(".root","");

		t[i] = new MuYield_Class(filename[i], MCtype[i]);
		t[i]->Surface();
		//t[i]->SetLasertime(lasertime);
		t[i]->SetLasertime(LaserTime[i]);
		t[i]->SetLaserCenter(LaserCenter[i]);
		//t[i]->LoopEvent();
		t[i]->LoopEventWithReflection(1,Form("Output-210508-hline-reflection_ForSOA-%d-MCtype-%d.dat",i,MCtype[i]) );
		//t[i]->LoopEventWithReflection(1);
		//t[i]->LoopTime();
		//t[i]->QuickLaserIonization(lasertime,Form("LaserOutput/%s.dat",MCtype) );
		//t[i]->QuickLaserIonization(lasertime);

		//t[i]->SavePlots();

		//double LasertimeAti = 1e6* (t[i]->GetTBeam(i) + t[i]->GetDecayT(i) ) * 0.99;
		//t[i]->SetLasertime(LasertimeAti);

		/// Draw track without reflection
		//g[i] = new TGraph*[t[i]->Nentries];
		//g_reflection[i] = new TGraph*[t[i]->Nentries];

		//double LasertimeAti = 1e6* (t[i]->GetTBeam(i) + t[i]->GetDecayT(i) ) * 0.99;
		//t[i]->SetLasertime(LasertimeAti);
		//for(int j = 0; j<t[i]->Nentries;j++) g[i][j] = t[i]->Track(j);
		//for(int j = 0; j<20;j++) g[i][j] = t[i]->Track(j);
		//for(int j = 0; j<20;j++){
		//	g_reflection[i][j] = t[i]->TrackWithReflection(j);
			//if(t[1]->IsInsideLaserRegion(i, lasertime))cout<<"MCtype "<<MCtype[1]<<" file "<<1<<" has the event "<<i<<" inside laser region at "<<lasertime<<" us"<<endl;
		//}

	}

	//// draw preliminary
	//c0->SaveAs("210204_Reflection/210204_bottomNoreflction.C");
	//c0->SaveAs("210204_Reflection/210204_bottomNoreflction.pdf");

	TCanvas * c1 = new TCanvas("c1_reflection","c1_reflection",1400,1500);
	c1->Divide(3,3);
	for(int i=0;i<1;i++){
		c1->cd( 3*(i)+1 );
	//t[Nfile-1]->hT->SetNormFactor(0.1*t[Nfile-1]->hT->GetEntries());
	//t[Nfile-1]->hT->GetYaxis()->SetRangeUser(0,62000);
		t[i]->hT->Draw();
		c1->cd(3*i+2);
		t[i]->hZY2D_laser->Draw("colz");
		c1->cd(3*i+3);
		t[i]->hXY2D->Draw("colz");
	//t[Nfile-1]->hT->SetLineColor(1);
	//t[Nfile-1]->hT->SetLineWidth(2);
	//tl->AddEntry(t[Nfile-1]->hT,Form("%d mm",6+2),"L");
	//for(int i = Nfile-2; i>=0;i--){t[i]->hT->SetLineColor(Nfile+1-i);t[i]->hT->SetLineWidth(2);t[i]->hT->Draw("same");tl->AddEntry(t[i]->hT,Form("%d mm",i+2),"L");}
	//for(int i = Nfile-2; i>=0;i--){t[i]->hT->SetLineColor(ci[i+1]);t[i]->hT->SetLineWidth(2);t[i]->hT->Draw("same");tl->AddEntry(t[i]->hT,Form("%d mm",i+2),"L");}
	//tl->Draw();
	}

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
