#include "macro_MuYieldAna.h"
#include "InsideLaserRegion.h"
#include "macro_DrawAerogelGeo.h"
#include "MuYield_Class.C"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../../CZhang/CZhangNew.h"

#define drawplot

void macro_MuYieldAna2(TString filename = "MuYield.root"){


	//TString filename =
	filename =
	//"../Root/1002_hline_SimBeamStop_GM_7.12mm_tree_Type1002_D87000_T322_Nrepeat1352113_H_line1_Thick25.00_NewGeo0";
	"../Root/201101_test_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0";

	filename.ReplaceAll(".root","");
	MCtype = 3006;
	//MCtype = 1002;

	//SetPalette();
	//SetOptStat();

	MuYield_Class * t1 = new MuYield_Class(filename, MCtype);
	t1->LoopEvent();
	//t1->LoopTime();
	t1->LaserIonization(1.35);
	//t1->hT->Draw();
	//t1->hXY2D_0->Draw("colz");
	//t1->Track(1);


	#ifdef drawplot

	//TCanvas * c0 = NewTCanvas("c0","c0",800,800,1,1);
	TCanvas * c1 = NewTCanvas("c1","c1_surface",1000,1000,3,3);
	TCanvas * c2 = NewTCanvas("c2","c2_accumulation_yield",1333,333,4,1);
	TCanvas * c3_laser = NewTCanvas("c3_laser","c3_laser",1000,1000,3,3);

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
	c3_laser->cd(++c_i);
	t1->hZY2D_0->Draw("colz");
	c3_laser->cd(++c_i);
	t1->hZX2D_0->Draw("colz");
	c3_laser->cd(++c_i);
	t1->hXY2D_0->Draw("colz");
	c3_laser->cd(++c_i);
	t1->hZY2D_laser->Draw("colz");
	c3_laser->cd(++c_i);
	t1->hZX2D_laser->Draw("colz");
	c3_laser->cd(++c_i);
	t1->hXY2D_laser->Draw("colz");

	/////////////////
	///// Draw other 2D and 3D plots
	/////////////////
/*
	c1->cd(1);
 	t1->hZT2D->Draw("colz");
 	c1->cd(2);
 	t1->hZY2D->Draw("colz");
 	c1->cd(3);
 	t1->hZX2D->Draw("colz");
 	c1->cd(4);
 	t1->hXY2D->Draw("colz");
 	c1->cd(5);
 	t1->hZXT3D->Draw("LEGO");
 	c1->cd(6);
 	t1->hZXY3D->Draw("lego2");
*/

	#endif

	////////////////
 	///// TRIUMF region count
 	///////////////

 	//TRIUMFVacuumRegion(t1->tree);



}
