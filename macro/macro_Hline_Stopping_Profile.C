#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_Hline_Stopping_Profile(){

	TString filename = "../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum"; TString treename="101";
	//TString filename = "../Root/hline_SimBeamStop";
	TString filename = "../Root/hline_SimBeamStop_Mibe"; TString treename = "position";

	SetPalette();
	//SetOptStat();

	TCanvas * c = NewTCanvas("c","c",1500,1500,2,2);

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get(treename.Data());

	//TTree * tree = (TTree*) f-> Get("position");

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
	b->SetFillColorAlpha(10,0.5);
	b->SetLineStyle(1);
	b->SetLineColor(2);
	b->SetLineWidth(10);
	b->Draw();

	//SaveTCanvas(c,"H-line_initial_Profile_50_40");


	TCanvas * c2 = NewTCanvas("c2","c2",500,500,1,1);

	TH2F * hDecayYZ = TreeToTH2F(tree,"y_dec:z_dec",
		100,-10,5,
		100,-50,50,
		//50,-40,40,
		"z_dec<10 && z_dec>-8");
	hDecayYZ->SetTitle("H-line-Stopping_YZ;Z[mm];Y[mm]");
	hDecayYZ->Draw("colz");

	//SaveTCanvas(c2,"H-line_initial_Profile_2_ZY");
	SaveTCanvas(c2,"H-line_initial_Profile_2_MySim_Mibe");

/*
	TH3F * hDecayXYZ = new TH3F("hDecayXYZ","hDecayXYZ;Z[mm];X[mm];Y[mm]",20,-10,2,100,-50,50,80,-40,40);

	double x_dec, y_dec, z_dec;
	tree->SetBranchAddress("x_dec", &x_dec);
	tree->SetBranchAddress("y_dec", &y_dec);
	tree->SetBranchAddress("z_dec", &z_dec);
	int Nentries = tree->GetEntries();

	for(int index_m=0; index_m < Nentries; index_m++){

		tree->GetEntry(index_m);
		if(z_dec<10 && z_dec>-8)hDecayXYZ->Fill(z_dec, x_dec, y_dec);

	}

	hDecayXYZ->Draw("lego2");
*/




}
