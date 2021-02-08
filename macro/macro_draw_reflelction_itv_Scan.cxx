#include "../../CZhang/CZhangNew.h"

void macro_draw_reflelction_itv_Scan(){

	//TCanvas *c1 = new TCanvas("c1","hists with different scales",600,400);
	TCanvas *c2 = new TCanvas("c2","",600,400);

  int Nfile = 6;

	TString nameVar[4] = {"N","time","itv","LaserPosition"};

  TTree ** t = new TTree*[Nfile];
  TGraph** g_YieldWithLaserPosition = new TGraph*[Nfile];


  EColor ci[6] = {kYellow, kOrange, kRed, kPink, kMagenta ,kViolet};
  //TCanvas * c0 = new TCanvas("c0_reflection_hT","c0_hT_reflection",700,500);



  for(int i = 4;i<10;i++){

    t[i] = TxtToTree(
      Form("210208_Reflection_data/210208-ItvScan-%d.txt",i),
      nameVar,4,22);

    g_YieldWithLaserPosition[i] = TreeToTGraph(t[i],"LaserPosition","N");
    g_YieldWithLaserPosition[i]->SetLineColor(ci[i-4]);

    if(i==4){g_YieldWithLaserPosition[i]->Draw("APL");g_YieldWithLaserPosition[i]->SetTitle(";Laser center[mm]; Yield");g_YieldWithLaserPosition[i]->GetYaxis()->SetRangeUser(500,4500);}
    else g_YieldWithLaserPosition[i]->Draw("PLsame");

  }

  TLegend *tl = new TLegend(0.7,0.7,0.9,0.9);
  //tl->AddEntry(g_YieldWithLaserPosition[0],"itv = 4 mm","l");
  //tl->AddEntry(g_YieldWithLaserPosition[1],"itv = 5 mm","l");
  //tl->AddEntry(g_YieldWithLaserPosition[2],"itv = 6 mm","l");
  //tl->AddEntry(g_YieldWithLaserPosition[3],"itv = 7 mm","l");
  //tl->AddEntry(g_YieldWithLaserPosition[4],"itv = 8 mm","l");
  //tl->AddEntry(g_YieldWithLaserPosition[5],"itv = 9 mm","l");
  tl->Draw();
  //c2->SaveAs("210207-itvScan-tot.C");
  //c2->SaveAs("210207-itvScan-tot.pdf");
  //c2->SaveAs("210207-itvScan-tot.root");






  //g2->GetYaxis()->SetRangeUser(34200,38600);
/*
  TGraphErrors * g3 = TreeToTGraphErrors(t,"itv","laser_power2","err_0");
  g3->Draw("samePL*");
  g3->SetLineColor(kRed);
  g3->SetMarkerColor(kRed);

  TGraphErrors * g4 = TreeToTGraphErrors(t,"itv","N_scaled","err_N");
*/

  //TH1F * h[7];
  //for(int i =0;i<7;i++)h[i]=new TH1F(Form("h%d",i) )

   //c2->cd();g4->Draw("APL*");



}