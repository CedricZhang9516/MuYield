void macro_draw_reflelction_itv(){

TString nameVar[6] = {"itv","N","density","err_N","err_density","err_0"};

  TTree * t = TxtToTree(
    "/Users/zhangce/WorkArea/MuYield/macro/macro_draw_reflelction_itv.txt",
    nameVar,6,7);

  TGraphErrors * g2 = TreeToTGraphErrors(t,"itv","density","err_density");
  g2->Draw("APL*");

  TH1F * h[7];
  for(int i =0;i<7;i++)h[i]=new TH1F(Form("h%d",i) )


}