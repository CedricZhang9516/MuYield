void draw_210208_itvScan_4mm_noReflection()
{
//=========Macro generated from canvas: c0_reflection_hT/c0_hT_reflection
//=========  (Mon Feb  8 13:12:33 2021) by ROOT version 6.22/02
   TCanvas *c0_reflection_hT = new TCanvas("c0_reflection_hT", "c0_hT_reflection",20,43,700,500);
   c0_reflection_hT->Range(-3.1375,768,28.2375,4590);
   c0_reflection_hT->SetFillColor(0);
   c0_reflection_hT->SetBorderMode(0);
   c0_reflection_hT->SetBorderSize(2);
   c0_reflection_hT->SetFrameBorderMode(0);
   c0_reflection_hT->SetFrameBorderMode(0);

   Double_t _fx1[22] = {
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16,
   17,
   18,
   19,
   20,
   21,
   22,
   23};
   Double_t _fy1[22] = {
   2135,
   2875,
   3454,
   3876,
   3953,
   3714,
   3417,
   2972,
   2625,
   2368,
   2094,
   1951,
   1878,
   1809,
   1736,
   1767,
   1762,
   1765,
   1682,
   1632,
   1549,
   1405};
   TGraph *graph = new TGraph(22,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   graph->SetLineColor(ci);

   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,25.1);
   Graph_Graph1->SetMinimum(1150.2);
   Graph_Graph1->SetMaximum(4207.8);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);

   graph->Draw("alp");
   c0_reflection_hT->Modified();
   c0_reflection_hT->cd();
   c0_reflection_hT->SetSelected(c0_reflection_hT);
}
