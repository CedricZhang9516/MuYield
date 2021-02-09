#include "../../CZhang/CZhangNew.h"
#include <iostream>
#include <fstream>
#define drawseries

void draw_210209_FurtherAnaLaserPositionScan(int interval = 5){


  int Nfile = 2;
  int LaserPositions = 21;
  int LaserPosition = 0;
  int shootingtime = 1300;


  TFile *** f = new TFile**[Nfile];
  TCanvas ***c1 = new TCanvas**[Nfile];//(TCanvas*)_file0->Get("c0_reflection_hT");
  TH1D *** hT = new TH1D**[Nfile];
  TGraphErrors ** g_OptTime = new TGraphErrors*[Nfile];
  TGraphErrors ** g_OptYield = new TGraphErrors*[Nfile];
  TGraphErrors ** g_Yield = new TGraphErrors*[Nfile];
  TGraphErrors * g_YieldDiff = new TGraphErrors();



  for(int i = 0 ; i< Nfile; i++){
    f[i] = new TFile*[LaserPositions];
    c1[i] = new TCanvas*[LaserPositions];
    hT[i] = new TH1D*[LaserPositions];
    g_OptTime[i] = new TGraphErrors();
    g_OptYield[i] = new TGraphErrors();
    g_Yield[i] = new TGraphErrors();

      for(int j = 0; j<LaserPositions; j++){

        LaserPosition = j+3;
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
        g_OptTime[i]->SetPoint(j,LaserPosition,hT[i][j]->GetMaximumBin());
        g_OptYield[i]->SetPoint(j,LaserPosition,hT[i][j]->GetMaximum());
      }
  }


  for(int j = 0; j<LaserPositions; j++){
    LaserPosition = j+3;
    //g_YieldDiff->SetPoint(j,j+2,hT[0][j]->GetMaximum()-hT[1][j]->GetMaximum());
    g_YieldDiff->SetPoint(j,LaserPosition,hT[0][j]->GetBinContent(hT[0][j]->GetMaximumBin() )-hT[1][j]->GetBinContent(hT[0][j]->GetMaximumBin()));
    for(int i = 0; i<Nfile;i++){
      g_Yield[i]->SetPoint(j,LaserPosition,hT[i][j]->GetBinContent(shootingtime));
    }
  }

  TText * tt;// = new TText();

  TLegend * tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(hT[0][0],"with reflection","l");
  tl->AddEntry(hT[1][0],"without reflection","l");

  #ifdef drawseries

  TCanvas ** c2 = new TCanvas*[2];
  c2[0] = new TCanvas(Form("c2_%d_with_Reflection",0),Form("Mu yield in the laser region (with reflection), interval %d",interval),700,500);
  c2[1] = new TCanvas(Form("c2_%d_without_Reflection",1),Form("Mu yield in the laser region (without reflection), interval %d",interval),700,500);

  for(int k = 0; k<LaserPositions; k++){
    LaserPosition = k+3;

    c2[0]->cd();
    if(k==0){hT[0][k]->SetNormFactor(hT[0][k]->GetEntries()*1.0/hT[0][k]->GetMaximum());hT[0][k]->DrawNormalized();}
    else    {hT[0][k]->SetNormFactor(hT[0][k]->GetEntries()*1.0/hT[0][k]->GetMaximum());hT[0][k]->DrawNormalized("same");}
    //tt = new TText(4e-6,0.5*hT[0][k]->GetMaximum(),Form("laser center Z=%d mm",LaserPosition) );
    //tt->Draw();
    c2[1]->cd();
    hT[1][k]->SetLineColor(kRed);
    if(k==0){hT[1][k]->SetNormFactor(hT[1][k]->GetEntries()*1.0/hT[1][k]->GetMaximum());hT[1][k]->DrawNormalized();}
    else    {hT[1][k]->SetNormFactor(hT[1][k]->GetEntries()*1.0/hT[1][k]->GetMaximum());hT[1][k]->DrawNormalized("same");}
    //tt = new TText(4e-6,0.5*hT[0][k]->GetMaximum(),Form("laser center Z=%d mm",LaserPosition) );
    //tt->Draw();

  }

  c2[0]->cd();
  //tt = new TText(5e-6,0.35*hT[0][0]->GetMaximum(),Form("interval %d mm",interval) );
  tt = new TText(5e-6,0.35,Form("interval %d mm",interval) );
  tt->Draw();
  c2[1]->cd();
  //tt = new TText(5e-6,0.35*hT[0][0]->GetMaximum(),Form("interval %d mm",interval) );
  tt = new TText(5e-6,0.35,Form("interval %d mm",interval) );
  tt->Draw();

  hT[0][0]->GetYaxis()->SetRangeUser(0,1.3*TMath::MaxElement(LaserPositions,g_OptYield[0]->GetY()));
  hT[1][0]->GetYaxis()->SetRangeUser(0,1.3*TMath::MaxElement(LaserPositions,g_OptYield[1]->GetY()));
  c2[0]->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_drawallposition_withReflection.png",interval,interval));
  c2[1]->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_drawallposition-withoutReflection.png",interval,interval));

  #endif

/*
  EColor ci[7] = {kYellow, kOrange, kRed, kPink, kMagenta ,kViolet, kBlack};

  TCanvas * c3 = new TCanvas("c3","c3_time");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptTime[l]->SetLineColor(ci[2]);g_OptTime[l]->SetMarkerColor(ci[2]);}
    g_OptTime[l]->SetLineWidth(2);
    g_OptTime[l]->SetMarkerStyle(20);
  }

  g_OptTime[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserPositions,g_OptTime[1]->GetY()),1.1*TMath::MaxElement(LaserPositions,g_OptTime[0]->GetY()));
  g_OptTime[0]->SetTitle("Optimal time vs. laser position; z [mm]; time [ns]");
  g_OptTime[0]->Draw("APL");
  g_OptTime[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptTime[0],"with reflection","l");
  tl->AddEntry(g_OptTime[1],"without reflection","l");
  tl->Draw();

  c3->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_OptTime.png",interval,interval));

  TCanvas * c4 = new TCanvas("c4","c4_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptYield[l]->SetLineColor(ci[2]);g_OptYield[l]->SetMarkerColor(ci[2]);}
    g_OptYield[l]->SetLineWidth(2);
    g_OptYield[l]->SetMarkerStyle(20);
  }

  //g_OptYield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_OptYield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserPositions,g_OptYield[1]->GetY()),1.1*TMath::MaxElement(LaserPositions,g_OptYield[0]->GetY()));
  g_OptYield[0]->SetTitle("Optimal yield vs. laser position; z [mm]; Yield");
  g_OptYield[0]->Draw("APL");
  g_OptYield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptYield[0],"with reflection","l");
  tl->AddEntry(g_OptYield[1],"without reflection","l");
  tl->Draw();

  c4->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_OptYield.png",interval,interval));

  TCanvas * c5 = new TCanvas("c5","c5_YieldDiff");
  g_YieldDiff->SetLineColor(ci[2]);
  g_YieldDiff->SetMarkerColor(ci[2]);
  g_YieldDiff->SetLineWidth(2);
  g_YieldDiff->SetMarkerStyle(20);
  g_YieldDiff->SetTitle("Yield Difference between w/ and w/o reflection at the Optimal shooting time (w/ ref.)");
  g_YieldDiff->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserPositions,g_YieldDiff->GetY()),1.1*TMath::MaxElement(LaserPositions,g_YieldDiff->GetY()));
  g_YieldDiff->Draw();

  c5->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_YieldDiff.png",interval,interval));

  TCanvas * c6 = new TCanvas("c6","c6_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_Yield[l]->SetLineColor(ci[2]);g_Yield[l]->SetMarkerColor(ci[2]);}
    g_Yield[l]->SetLineWidth(2);
    g_Yield[l]->SetMarkerStyle(20);
  }

  //g_Yield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_Yield[0]->SetTitle( Form(" Yield vs. laser position at %d; z [mm]; Yield",shootingtime) );
  g_Yield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserPositions,g_Yield[1]->GetY()),1.1*TMath::MaxElement(LaserPositions,g_Yield[0]->GetY()));
  g_Yield[0]->Draw("APL");
  g_Yield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_Yield[0],"with reflection","l");
  tl->AddEntry(g_Yield[1],"without reflection","l");
  tl->Draw();

  c6->SaveAs( Form("210209_FurtherAnaItvScan/Itv_%d/Itv_%d_YieldAt%d.png",interval,interval,shootingtime));
*/




}
void macro_draw_210209_FurtherAnaLaserPositionScan(){
  for(int i = 4; i<10;i++)draw_210209_FurtherAnaLaserPositionScan(i);
}