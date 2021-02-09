#include "../../CZhang/CZhangNew.h"
#include <iostream>
#include <fstream>
//#define drawseries
#define drawAna

void draw_210209_FurtherAnaItvScan(int LaserPosition = 5){

  gROOT->ProcessLine(Form(".! mkdir 210209_FurtherAnaItvScan/LaserPosition_%d",LaserPosition) );


  int Nfile = 2;
  int LaserPositions = 21;
  int shootingtime = 2500;
  int interval = 4;
  int intervalpositions = 6;


  TFile *** f = new TFile**[Nfile];
  TCanvas ***c1 = new TCanvas**[Nfile];//(TCanvas*)_file0->Get("c0_reflection_hT");
  TH1D *** hT = new TH1D**[Nfile];
  TGraphErrors ** g_OptTime = new TGraphErrors*[Nfile];
  TGraphErrors ** g_OptYield = new TGraphErrors*[Nfile];
  TGraphErrors ** g_Yield = new TGraphErrors*[Nfile];
  TGraphErrors * g_YieldDiff = new TGraphErrors();

  ofstream OutputTxtFile;
  OutputTxtFile.open(Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_OptYield.txt",LaserPosition,LaserPosition));


  for(int i = 0 ; i< Nfile; i++){
    f[i] = new TFile*[intervalpositions];
    c1[i] = new TCanvas*[intervalpositions];
    hT[i] = new TH1D*[intervalpositions];
    g_OptTime[i] = new TGraphErrors();
    g_OptYield[i] = new TGraphErrors();
    g_Yield[i] = new TGraphErrors();

      for(int j = 0; j<intervalpositions; j++){

        interval = j+4;

        switch (i){
        case 0:
          f[i][j] = new TFile(
          Form("/home/had/zhangce/g-2_tape/Mu1S2S/zhangce/MuYield/Root/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-%d/S2areaMuYield_SlineItvScan_210205_tot-Itv-%d_TBEAM_0WithReflection_%d_hT_reflection_%d.0.root",interval,interval,LaserPosition,LaserPosition) );
          break;
        case 1:
          f[i][j] = new TFile(
          Form("/home/had/zhangce/g-2_tape/Mu1S2S/zhangce/MuYield/Root/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-%d/S2areaMuYield_SlineItvScan_210205_tot-Itv-%d_TBEAM_0WithoutReflection_%d_hT_reflection_%d.0.root",interval,interval,LaserPosition,LaserPosition) );
          break;
        }
        c1[i][j] = (TCanvas*)f[i][j]->Get("c0_reflection_hT");
        hT[i][j] = (TH1D*)c1[i][j]->GetPrimitive("hT");
        g_OptTime[i]->SetPoint(j,interval,hT[i][j]->GetMaximumBin());
        g_OptYield[i]->SetPoint(j,interval,hT[i][j]->GetMaximum());
      }
  }


  for(int j = 0; j<intervalpositions; j++){
    interval = j+4;
    g_YieldDiff->SetPoint(j,interval,hT[0][j]->GetBinContent(hT[0][j]->GetMaximumBin() )-hT[1][j]->GetBinContent(hT[0][j]->GetMaximumBin()));
    for(int i = 0; i<Nfile;i++)g_Yield[i]->SetPoint(j,interval,hT[i][j]->GetBinContent(shootingtime));
  }

  TText * tt;// = new TText();

  TLegend * tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(hT[0][0],"with reflection","l");
  tl->AddEntry(hT[1][0],"without reflection","l");

  #ifdef drawseries

  TCanvas ** c2 = new TCanvas*[intervalpositions];

  for(int k = 0; k<intervalpositions; k++){
    interval = k+4;
    c2[k] = new TCanvas(Form("c2_%d",k),Form("Mu yield in the laser region, interval %d, laser position %d",interval,LaserPosition),700,500);

    hT[1][k]->SetLineColor(kRed);

    hT[0][k]->Draw();
    hT[1][k]->Draw("same");
    tl->Draw();

    tt = new TText(4e-6,0.5*hT[0][k]->GetMaximum(),Form("laser center Z=%d mm",LaserPosition) );
    //tt->SetTextSize(2);
    tt->Draw();
    tt = new TText(5e-6,0.35*hT[0][k]->GetMaximum(),Form("interval %d mm",interval) );
    tt->Draw();


    c2[k]->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_Itv_%d.png",LaserPosition,LaserPosition,interval));
    OutputTxtFile
      <<"With reflection, maximum Yield in the laser region "
      <<hT[0][k]->GetMaximum()
      <<" in the bin "
      <<hT[0][k]->GetMaximumBin()
      <<" when laser position is z = "
      <<LaserPosition<<" mm"
      <<" with interval "
      <<interval
      <<"Without reflection, maximum Yield in the laser region "
      <<hT[1][k]->GetMaximum()
      <<" in the bin "
      <<hT[1][k]->GetMaximumBin()
      <<" when laser position is z = "
      <<LaserPosition<<" mm"
      <<" with interval "
      <<interval
      <<endl;

  }
  OutputTxtFile.close();

  #endif


  EColor ci[7] = {kYellow, kOrange, kRed, kPink, kMagenta ,kViolet, kBlack};

  #ifdef drawAna

  TCanvas * c3 = new TCanvas("c3","c3_time");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptTime[l]->SetLineColor(ci[2]);g_OptTime[l]->SetMarkerColor(ci[2]);}
    g_OptTime[l]->SetLineWidth(2);
    g_OptTime[l]->SetMarkerStyle(20);
  }

  g_OptTime[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(intervalpositions,g_OptTime[1]->GetY()),1.1*TMath::MaxElement(intervalpositions,g_OptTime[0]->GetY()));
  g_OptTime[0]->SetTitle("Optimal time vs. interval; interval [mm]; time [ns]");
  g_OptTime[0]->Draw("APL");
  g_OptTime[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptTime[0],"with reflection","l");
  tl->AddEntry(g_OptTime[1],"without reflection","l");
  tl->Draw();

  tt = new TText(6,0.9*TMath::MinElement(intervalpositions,g_OptTime[1]->GetY()) +0.33*(1.1*TMath::MaxElement(intervalpositions,g_OptTime[0]->GetY()) - 0.9*TMath::MinElement(intervalpositions,g_OptTime[1]->GetY()) ),Form("laser center Z=%d mm",LaserPosition) );
  tt->Draw();

  c3->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_OptTime.png",LaserPosition,LaserPosition));
  c3->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d_OptTime.png",LaserPosition));

  TCanvas * c4 = new TCanvas("c4","c4_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptYield[l]->SetLineColor(ci[2]);g_OptYield[l]->SetMarkerColor(ci[2]);}
    g_OptYield[l]->SetLineWidth(2);
    g_OptYield[l]->SetMarkerStyle(20);
  }

  //g_OptYield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_OptYield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(intervalpositions,g_OptYield[1]->GetY()),1.1*TMath::MaxElement(intervalpositions,g_OptYield[0]->GetY()));
  g_OptYield[0]->SetTitle("Optimal yield vs.interval; interval [mm]; Yield");
  g_OptYield[0]->Draw("APL");
  g_OptYield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptYield[0],"with reflection","l");
  tl->AddEntry(g_OptYield[1],"without reflection","l");
  tl->Draw();

  //tt = new TText(6,0.66*g_OptYield[0]->GetMaximum(),Form("laser center Z=%d mm",LaserPosition) );
  tt = new TText(6,0.9*TMath::MinElement(intervalpositions,g_OptYield[1]->GetY()) + 0.6*(1.1*TMath::MaxElement(intervalpositions,g_OptYield[0]->GetY()) - 0.9*TMath::MinElement(intervalpositions,g_OptYield[1]->GetY()) ),Form("laser center Z=%d mm",LaserPosition) );
  tt->Draw();

  c4->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_OptYield.png",LaserPosition,LaserPosition));
  c4->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d_OptYield.png",LaserPosition));

  TCanvas * c5 = new TCanvas("c5","c5_YieldDiff");
  g_YieldDiff->SetLineColor(ci[2]);
  g_YieldDiff->SetMarkerColor(ci[2]);
  g_YieldDiff->SetLineWidth(2);
  g_YieldDiff->SetMarkerStyle(20);
  g_YieldDiff->SetTitle("Yield Difference between w/ and w/o reflection at the Optimal shooting time (w/ ref.);interval;Yield Diff.");
  g_YieldDiff->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(intervalpositions,g_YieldDiff->GetY()),1.1*TMath::MaxElement(intervalpositions,g_YieldDiff->GetY()));
  g_YieldDiff->Draw();

  tt = new TText(6,0.9*TMath::MinElement(intervalpositions,g_YieldDiff->GetY()) + 0.66*(1.1*TMath::MaxElement(intervalpositions,g_YieldDiff->GetY()) -0.9*TMath::MinElement(intervalpositions,g_YieldDiff->GetY()) ),Form("laser center Z=%d mm",LaserPosition) );
  tt->Draw();

  c5->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_YieldDiff.png",LaserPosition,LaserPosition));
  c5->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d_YieldDiff.png",LaserPosition));

  TCanvas * c6 = new TCanvas("c6","c6_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_Yield[l]->SetLineColor(ci[2]);g_Yield[l]->SetMarkerColor(ci[2]);}
    g_Yield[l]->SetLineWidth(2);
    g_Yield[l]->SetMarkerStyle(20);
  }

  //g_Yield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_Yield[0]->SetTitle( Form(" Yield vs. interval at %d ns; interval [mm]; Yield",shootingtime) );
  g_Yield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(intervalpositions,g_Yield[1]->GetY()),1.1*TMath::MaxElement(intervalpositions,g_Yield[0]->GetY()));
  g_Yield[0]->Draw("APL");
  g_Yield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_Yield[0],"with reflection","l");
  tl->AddEntry(g_Yield[1],"without reflection","l");
  tl->Draw();

  tt = new TText(6,0.9*TMath::MinElement(intervalpositions,g_Yield[1]->GetY())+0.5*(1.1*TMath::MaxElement(intervalpositions,g_Yield[0]->GetY()) - 0.9*TMath::MinElement(intervalpositions,g_Yield[1]->GetY()) ) ,Form("laser center Z=%d mm",LaserPosition) );
  tt->Draw();

  c6->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d/LaserPosition_%d_YieldAt%dns.png",LaserPosition,LaserPosition,shootingtime));
  c6->SaveAs( Form("210209_FurtherAnaItvScan/LaserPosition_%d_YieldAt%dns.png",LaserPosition,shootingtime));

  #endif


}
void macro_draw_210209_FurtherAnaItvScan(){
  for(int i = 3; i<24;i++)draw_210209_FurtherAnaItvScan(i);
}