#include "../../CZhang/CZhangNew.h"
#include <iostream>
#include <fstream>
#define drawseries

void draw_210208_afterdiscussion(int interval = 5){


  int Nfile = 2;
  int LaserEnd = 22;
  //int interval = 5;
  int shootingtime = 1300;


  TFile *** f = new TFile**[Nfile];
  TCanvas ***c1 = new TCanvas**[Nfile];//(TCanvas*)_file0->Get("c0_reflection_hT");
  TH1D *** hT = new TH1D**[Nfile];
  TGraphErrors ** g_OptTime = new TGraphErrors*[Nfile];
  TGraphErrors ** g_OptYield = new TGraphErrors*[Nfile];
  TGraphErrors ** g_Yield = new TGraphErrors*[Nfile];
  TGraphErrors * g_YieldDiff = new TGraphErrors();

  ofstream OutputTxtFile;
  OutputTxtFile.open(Form("210208_AfterDiscussion/Itv_%d_OptYield.txt",interval));


  for(int i = 0 ; i< Nfile; i++){
    f[i] = new TFile*[LaserEnd];
    c1[i] = new TCanvas*[LaserEnd];
    hT[i] = new TH1D*[LaserEnd];
    g_OptTime[i] = new TGraphErrors();
    g_OptYield[i] = new TGraphErrors();
    g_Yield[i] = new TGraphErrors();

      for(int j = 0; j<LaserEnd; j++){
        switch (i){
        case 0:
          f[i][j] = new TFile(
          Form("/home/had/zhangce/g-2_tape/Mu1S2S/zhangce/MuYield/Root/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-%d/S2areaMuYield_SlineItvScan_210205_tot-Itv-%d_TBEAM_0WithReflection_%d_hT_reflection_%d.0.root",interval,interval,j+2,j+2) );
          break;
        case 1:
          f[i][j] = new TFile(
          Form("/home/had/zhangce/g-2_tape/Mu1S2S/zhangce/MuYield/Root/210205_Reflection/S2areaMuYield_SlineItvScan_210205-sus-Itv-%d/S2areaMuYield_SlineItvScan_210205_tot-Itv-%d_TBEAM_0WithoutReflection_%d_hT_reflection_%d.0.root",interval,interval,j+2,j+2) );
          break;
        }
        c1[i][j] = (TCanvas*)f[i][j]->Get("c0_reflection_hT");
        hT[i][j] = (TH1D*)c1[i][j]->GetPrimitive("hT");
        g_OptTime[i]->SetPoint(j,j+2,hT[i][j]->GetMaximumBin());
        g_OptYield[i]->SetPoint(j,j+2,hT[i][j]->GetMaximum());
      }
  }


  for(int j = 0; j<LaserEnd; j++){
    //g_YieldDiff->SetPoint(j,j+2,hT[0][j]->GetMaximum()-hT[1][j]->GetMaximum());
    g_YieldDiff->SetPoint(j,j+2,hT[0][j]->GetBinContent(hT[0][j]->GetMaximumBin() )-hT[1][j]->GetBinContent(hT[0][j]->GetMaximumBin()));
    for(int i = 0; i<Nfile;i++){
      g_Yield[i]->SetPoint(j,j+2,hT[i][j]->GetBinContent(shootingtime));
    }
  }

  TText * tt;// = new TText();

  TLegend * tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(hT[0][0],"with reflection","l");
  tl->AddEntry(hT[1][0],"without reflection","l");

  #ifdef drawseries

  TCanvas ** c2 = new TCanvas*[LaserEnd];

  for(int k = 0; k<LaserEnd; k++){
    c2[k] = new TCanvas(Form("c2_%d",k),Form("Mu yield in the laser region, interval %d, laser position %d",interval,k+2),700,500);

    //hT[0][k]->SetLineColor();
    hT[1][k]->SetLineColor(kRed);

    hT[0][k]->Draw();
    hT[1][k]->Draw("same");
    tl->Draw();

    tt = new TText(4e-6,0.5*hT[0][k]->GetMaximum(),Form("laser center Z=%d mm",k+2) );
    //tt->SetTextSize(2);
    tt->Draw();


    c2[k]->SaveAs( Form("210208_AfterDiscussion/Itv_%d_LaserPosition_%d.pdf",interval,k+2));
    OutputTxtFile
      <<"With reflection, maximum Yield in the laser region "
      <<hT[0][k]->GetMaximum()
      <<" in the bin "
      <<hT[0][k]->GetMaximumBin()
      <<" when laser position is z = "
      <<k+2<<" mm"
      <<" with interval "
      <<interval
      <<"Without reflection, maximum Yield in the laser region "
      <<hT[1][k]->GetMaximum()
      <<" in the bin "
      <<hT[1][k]->GetMaximumBin()
      <<" when laser position is z = "
      <<k+2<<" mm"
      <<" with interval "
      <<interval
      <<endl;

  }
  OutputTxtFile.close();
  #endif


  EColor ci[7] = {kYellow, kOrange, kRed, kPink, kMagenta ,kViolet, kBlack};

  TCanvas * c3 = new TCanvas("c3","c3_time");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptTime[l]->SetLineColor(ci[2]);g_OptTime[l]->SetMarkerColor(ci[2]);}
    g_OptTime[l]->SetLineWidth(2);
    g_OptTime[l]->SetMarkerStyle(20);
  }

  g_OptTime[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserEnd,g_OptTime[1]->GetY()),1.1*TMath::MaxElement(LaserEnd,g_OptTime[0]->GetY()));
  g_OptTime[0]->SetTitle("Optimal time vs. laser position; z [mm]; time [ns]");
  g_OptTime[0]->Draw("APL");
  g_OptTime[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptTime[0],"with reflection","l");
  tl->AddEntry(g_OptTime[1],"without reflection","l");
  tl->Draw();

  c3->SaveAs( Form("210208_AfterDiscussion/Itv_%d_OptTime.pdf",interval));

  TCanvas * c4 = new TCanvas("c4","c4_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_OptYield[l]->SetLineColor(ci[2]);g_OptYield[l]->SetMarkerColor(ci[2]);}
    g_OptYield[l]->SetLineWidth(2);
    g_OptYield[l]->SetMarkerStyle(20);
  }

  //g_OptYield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_OptYield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserEnd,g_OptYield[1]->GetY()),1.1*TMath::MaxElement(LaserEnd,g_OptYield[0]->GetY()));
  g_OptYield[0]->SetTitle("Optimal yield vs. laser position; z [mm]; Yield");
  g_OptYield[0]->Draw("APL");
  g_OptYield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_OptYield[0],"with reflection","l");
  tl->AddEntry(g_OptYield[1],"without reflection","l");
  tl->Draw();

  c4->SaveAs( Form("210208_AfterDiscussion/Itv_%d_OptYield.pdf",interval));

  TCanvas * c5 = new TCanvas("c5","c5_YieldDiff");
  g_YieldDiff->SetLineColor(ci[2]);
  g_YieldDiff->SetMarkerColor(ci[2]);
  g_YieldDiff->SetLineWidth(2);
  g_YieldDiff->SetMarkerStyle(20);
  g_YieldDiff->SetTitle("Yield Difference between w/ and w/o reflection at the Optimal shooting time (w/ ref.)");
  g_YieldDiff->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserEnd,g_YieldDiff->GetY()),1.1*TMath::MaxElement(LaserEnd,g_YieldDiff->GetY()));
  g_YieldDiff->Draw();

  c5->SaveAs( Form("210208_AfterDiscussion/Itv_%d_YieldDiff.pdf",interval));

  TCanvas * c6 = new TCanvas("c6","c6_yield");

  for(int l = 0; l<Nfile; l++){
    if(l==1){g_Yield[l]->SetLineColor(ci[2]);g_Yield[l]->SetMarkerColor(ci[2]);}
    g_Yield[l]->SetLineWidth(2);
    g_Yield[l]->SetMarkerStyle(20);
  }

  //g_Yield[0]->GetYaxis()->SetRangeUser(500,1300);
  g_Yield[0]->SetTitle( Form(" Yield vs. laser position at %d; z [mm]; Yield",shootingtime) );
  g_Yield[0]->GetYaxis()->SetRangeUser(0.9*TMath::MinElement(LaserEnd,g_Yield[1]->GetY()),1.1*TMath::MaxElement(LaserEnd,g_Yield[0]->GetY()));
  g_Yield[0]->Draw("APL");
  g_Yield[1]->Draw("PLsame");

  tl = new TLegend(0.6,0.7,0.9,0.9);
  tl->AddEntry(g_Yield[0],"with reflection","l");
  tl->AddEntry(g_Yield[1],"without reflection","l");
  tl->Draw();

  c6->SaveAs( Form("210208_AfterDiscussion/Itv_%d_YieldAt%d.pdf",interval,shootingtime));





}
void macro_draw_210208_afterdiscussion(){
  for(int i = 5; i<10;i++)draw_210208_afterdiscussion(i);
}