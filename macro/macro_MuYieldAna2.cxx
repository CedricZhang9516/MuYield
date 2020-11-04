#include "macro_MuYieldAna.h"
#include "InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
#include "MuYield_Class.C"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"

//#define drawplot
//#define saveplot

void macro_MuYieldAna2(){//TString filename = "MuYield.root", int MCtype=1002){

	const int Nfile = 2;

	TString filename [Nfile] = {
	//filename =
	//"../Root/1002_hline_SimBeamStop_GM_7.12mm_tree_Type1002_D87000_T322_Nrepeat1352113_H_line1_Thick25.00_NewGeo0";
	//"../Root/201101_test_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0";

		//"../Root/201103_Reflectoin/201103_Reflection_3005_tree_Type3005_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3005;
		//"../Root/201103_Reflectoin/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3006;
		//"../Root/201103_Reflectoin/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3006;
		"../Root/201103_Reflectoin/201103_Reflection_3011_tree_Type3011_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root", //MCtype = 3011;
		"../Root/201103_Reflectoin/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root" //MCtype = 3012;

	};

	int MCtype [Nfile] = {
		//3005,
		//3006,
		//3006,
		3011,
		3012
	};

	//SetPalette();
	//SetOptStat();

	MuYield_Class * t[Nfile];

	for(int i = 0; i< Nfile; i++){

		filename[i].ReplaceAll(".root","");

		t[i] = new MuYield_Class(filename[i], MCtype[i]);
		t[i]->LoopEvent();
		//t[i]->LoopTime();
		t[i]->LaserIonization(1.35);
		//t[i]->hT->Draw();
		//t[i]->hXY2D_0->Draw("colz");
		//t[i]->Track(1);
		//t[i]->SavePlots();
	}

	int c_i = 0;

	TCanvas * c1 = new TCanvas("c1_comparison","c1_comparison");
	c1->Divide(2,2);
	c1->cd(++c_i);
	t[0]->Track(1);
	c1->cd(++c_i);
	t[1]->Track(1);


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