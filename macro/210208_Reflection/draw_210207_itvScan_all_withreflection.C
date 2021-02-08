void draw_210207_itvScan_all_withreflection()
{
//=========Macro generated from canvas: c2/
//=========  (Mon Feb  8 10:22:42 2021) by ROOT version 6.22/02
   TCanvas *c2 = new TCanvas("c2", "",0,23,600,400);
   c2->Range(-3.1375,-3.725291e-05,28.2375,5000);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetFrameBorderMode(0);
   c2->SetFrameBorderMode(0);

   Double_t _fx7[22] = {
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
   Double_t _fy7[22] = {
   2383,
   2989,
   3594,
   4005,
   4050,
   3941,
   3633,
   3329,
   2885,
   2576,
   2409,
   2293,
   2138,
   2018,
   1943,
   1903,
   1848,
   1819,
   1729,
   1732,
   1619,
   1466};
   TGraph *graph = new TGraph(22,_fx7,_fy7);
   graph->SetName("");
   graph->SetTitle(";Laser center[mm]; Yield");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph17 = new TH1F("Graph_Graph_Graph17","",100,0,25.1);
   Graph_Graph_Graph17->SetMinimum(500);
   Graph_Graph_Graph17->SetMaximum(4500);
   Graph_Graph_Graph17->SetDirectory(0);
   Graph_Graph_Graph17->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph17->SetLineColor(ci);
   Graph_Graph_Graph17->GetXaxis()->SetTitle("Laser center[mm]");
   Graph_Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph17->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph17->GetYaxis()->SetTitle(" Yield");
   Graph_Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph17->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph17);

   graph->Draw("apl");

   Double_t _fx8[22] = {
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
   Double_t _fy8[22] = {
   1905,
   2485,
   2965,
   3267,
   3300,
   3185,
   3005,
   2735,
   2461,
   2224,
   1977,
   1770,
   1644,
   1578,
   1545,
   1522,
   1502,
   1456,
   1392,
   1396,
   1325,
   1196};
   graph = new TGraph(22,_fx8,_fy8);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ffcc00");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph28 = new TH1F("Graph_Graph_Graph28","",100,0,25.1);
   Graph_Graph_Graph28->SetMinimum(985.6);
   Graph_Graph_Graph28->SetMaximum(3510.4);
   Graph_Graph_Graph28->SetDirectory(0);
   Graph_Graph_Graph28->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph28->SetLineColor(ci);
   Graph_Graph_Graph28->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph28->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph28->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph28->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph28->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph28->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph28->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph28->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph28);

   graph->Draw("pl");

   Double_t _fx9[22] = {
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
   Double_t _fy9[22] = {
   1601,
   2043,
   2414,
   2708,
   2794,
   2762,
   2609,
   2280,
   2063,
   1862,
   1646,
   1555,
   1455,
   1406,
   1373,
   1327,
   1298,
   1231,
   1186,
   1134,
   1102,
   1007};
   graph = new TGraph(22,_fx9,_fy9);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph39 = new TH1F("Graph_Graph_Graph39","",100,0,25.1);
   Graph_Graph_Graph39->SetMinimum(828.3);
   Graph_Graph_Graph39->SetMaximum(2972.7);
   Graph_Graph_Graph39->SetDirectory(0);
   Graph_Graph_Graph39->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph39->SetLineColor(ci);
   Graph_Graph_Graph39->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph39->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph39->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph39->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph39->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph39->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph39->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph39->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph39);

   graph->Draw("pl");

   Double_t _fx10[22] = {
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
   Double_t _fy10[22] = {
   1375,
   1724,
   2043,
   2269,
   2387,
   2322,
   2167,
   2042,
   1805,
   1630,
   1476,
   1318,
   1241,
   1180,
   1150,
   1118,
   1088,
   1050,
   1035,
   984,
   909,
   800};
   graph = new TGraph(22,_fx10,_fy10);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0033");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph410 = new TH1F("Graph_Graph_Graph410","",100,0,25.1);
   Graph_Graph_Graph410->SetMinimum(641.3);
   Graph_Graph_Graph410->SetMaximum(2545.7);
   Graph_Graph_Graph410->SetDirectory(0);
   Graph_Graph_Graph410->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph410->SetLineColor(ci);
   Graph_Graph_Graph410->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph410->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph410->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph410->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph410->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph410->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph410->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph410->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph410);

   graph->Draw("pl");

   Double_t _fx11[22] = {
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
   Double_t _fy11[22] = {
   1212,
   1475,
   1733,
   1884,
   1907,
   1850,
   1851,
   1709,
   1587,
   1431,
   1318,
   1211,
   1092,
   1036,
   1010,
   978,
   1017,
   917,
   901,
   818,
   789,
   712};
   graph = new TGraph(22,_fx11,_fy11);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff00ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph511 = new TH1F("Graph_Graph_Graph511","",100,0,25.1);
   Graph_Graph_Graph511->SetMinimum(592.5);
   Graph_Graph_Graph511->SetMaximum(2026.5);
   Graph_Graph_Graph511->SetDirectory(0);
   Graph_Graph_Graph511->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph511->SetLineColor(ci);
   Graph_Graph_Graph511->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph511->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph511->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph511->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph511->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph511->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph511->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph511->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph511);

   graph->Draw("pl");

   Double_t _fx12[22] = {
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
   Double_t _fy12[22] = {
   1080,
   1265,
   1428,
   1538,
   1563,
   1604,
   1579,
   1509,
   1359,
   1268,
   1186,
   1099,
   1012,
   970,
   918,
   853,
   813,
   759,
   742,
   720,
   683,
   592};
   graph = new TGraph(22,_fx12,_fy12);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#cc00ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   TH1F *Graph_Graph_Graph612 = new TH1F("Graph_Graph_Graph612","",100,0,25.1);
   Graph_Graph_Graph612->SetMinimum(490.8);
   Graph_Graph_Graph612->SetMaximum(1705.2);
   Graph_Graph_Graph612->SetDirectory(0);
   Graph_Graph_Graph612->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph612->SetLineColor(ci);
   Graph_Graph_Graph612->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph612->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph_Graph612->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph612->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph612->GetYaxis()->SetTitleOffset(0.78);
   Graph_Graph_Graph612->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph612->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph612->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph612);

   graph->Draw("pl");

   TLegend *leg = new TLegend(0.7,0.7,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.02659575);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","itv = 6 mm","lpf");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
}