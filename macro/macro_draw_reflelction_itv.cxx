#include "../../CZhang/CZhangNew.h"
void macro_draw_reflelction_itv(){

	TCanvas *c1 = new TCanvas("c1","hists with different scales",600,400);
	TCanvas *c2 = new TCanvas("c2","",600,400);

	TString nameVar[10] = {"itv","N","density","err_N","err_density","err_0","area","laser_power","laser_power2","N_scaled"};

  TTree * t = TxtToTree(
    "macro_draw_reflelction_itv.txt",
    nameVar,10,7);

  TGraphErrors * g2 = TreeToTGraphErrors(t,"itv","N","err_N");
  g2->Draw("APL*");
  g2->GetYaxis()->SetRangeUser(34200,38600);

  TGraphErrors * g3 = TreeToTGraphErrors(t,"itv","laser_power2","err_0");
  g3->Draw("samePL*");
  g3->SetLineColor(kRed);
  g3->SetMarkerColor(kRed);

  TGraphErrors * g4 = TreeToTGraphErrors(t,"itv","N_scaled","err_N");


  //TH1F * h[7];
  //for(int i =0;i<7;i++)h[i]=new TH1F(Form("h%d",i) )

  gStyle->SetOptStat(kFALSE);
   TH1F *h1 = new TH1F("h1","my histogram",100,-3,3);
   Int_t i;
   for (i=0;i<10000;i++) h1->Fill(gRandom->Gaus(0,1));
   //h1->Draw();
   c1->Update();

  TH1F *hint1 = new TH1F("hint1","h1 bins integral",100,-3,3);
   Float_t sum = 0;
   for (i=1;i<=100;i++) {
      sum += h1->GetBinContent(i);
      hint1->SetBinContent(i,sum);
   }


  Float_t rightmax = 1;//1.1*hint1->GetMaximum();
  //Float_t scale = gPad->GetUymax()/rightmax;
   //hint1->SetLineColor(kRed);
   //hint1->Scale(scale);
   //hint1->Draw("same");

   //draw an axis on the right side
   TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
         gPad->GetUxmax(), gPad->GetUymax(),0,rightmax,510,"+L");
   axis->SetLineColor(kRed);
   axis->SetLabelColor(kRed);
   axis->Draw();

   c2->cd();g4->Draw("APL*");



}