#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_Hline_Initial(){

	TString filename = "../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum";

	SetPalette();
	SetOptStat();

	TCanvas * c = NewTCanvas("c","c",600,600,2,2);

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get("101");

	c->cd(1);
	TH1F * hDecayZ = TreeToTH1F(tree,"z_dec",100,-10,2,
		"z_dec<10 && z_dec>-8");
	hDecayZ->SetTitle("H-line-Stopping_Z;Z[mm];N");
	c->cd(2);
	TH1F * hDecayX = TreeToTH1F(tree,"x_dec",200,-100,100,
		"z_dec<10 && z_dec>-8");
	hDecayX->SetTitle("H-line-Stopping_X;X[mm];N");
	c->cd(3);
	TH1F * hDecayY = TreeToTH1F(tree,"y_dec",100,-40,40,
		"z_dec<10 && z_dec>-8");
	hDecayY->SetTitle("H-line-Stopping_Y;Y[mm];N");
	c->cd(4);
	TH2F * hDecayXY = TreeToTH2F(tree,"y_dec:x_dec",200,-100,100,100,-40,40,
		"z_dec<10 && z_dec>-8");
	hDecayXY->SetTitle("H-line-Stopping_XY;X[mm];Y[mm]");
	hDecayXY->Draw("colz");

	TBox * b = new TBox(-25,-20,25,20);
	//b->SetFillStyle(3003);
	b->SetFillColorAlpha(10,0.0);
	b->SetLineStyle(1);
	b->SetLineColor(2);
	b->SetLineWidth(10);
	b->Draw();

	SaveTCanvas(c,"H-line_initial_Profile");

}