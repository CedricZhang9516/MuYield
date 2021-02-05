void macro_draw_LaserScan(){

	TString nameVar[9] = {"laser_center","yield_noReflection","time_noReflection","err_noReflection","yield_withReflection","time_withReflection","Ratio","err_withReflection","zero"};

  	TTree * t = TxtToTree(
    "/Users/zhangce/WorkArea/MuYield/macro/210204_Reflection/210204_LaserCenterScan_total.txt",
    nameVar,9,22);

	TGraphErrors * g_noReflection = TreeToTGraphErrors(t,"laser_center","yield_noReflection","err_noReflection");
	TGraphErrors * g_withReflection = TreeToTGraphErrors(t,"laser_center","yield_withReflection","err_withReflection");

	g_noReflection->SetTitle("Mu vacuum yield vs. laser center position ;  laser center position [mm];  Mu yield");
	g_withReflection->SetTitle("Mu vacuum yield vs. laser center position ;  laser center position [mm];  Mu yield");

	TCanvas * c1 = new TCanvas("c1","c1");
	g_withReflection->Draw("APEL");
	g_noReflection->Draw("samePEL");

	g_withReflection->SetLineWidth(2);
	g_withReflection->SetMarkerStyle(20);
	g_withReflection->SetMarkerSize(0.5);
	g_withReflection->SetLineColor(1);

	g_noReflection->SetLineWidth(2);
	g_noReflection->SetMarkerStyle(20);
	g_noReflection->SetMarkerSize(0.5);
	g_noReflection->SetLineColor(4);

	c1->SaveAs("210204_comparison_MuYield_Laserposition.pdf");

	TLegend * tl = new TLegend(0.5,0.7,0.9,0.9);
	tl->AddEntry(g_withReflection,"with reflection, multi-pieces","l");
	tl->AddEntry(g_noReflection,"no reflection, multi-pieces","l");
	tl->Draw();


}