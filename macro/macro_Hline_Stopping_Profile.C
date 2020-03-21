#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_Hline_Stopping_Profile(){

	//TString filename = "../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum"; TString treename="101";
	//TString filename = "../Root/hline_SimBeamStop";
	TString filename = "../Root/hline_SimBeamStop_GM_7.12mm"; TString treename = "position";

	SetPalette();
	SetOptStat("0000");

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get(treename.Data());

	//TTree * tree = (TTree*) f-> Get("position");


	TH1F * hDecayZ = TreeToTH1F(tree,"z",100,-10,2,
		"z<10 && z>-8");
	hDecayZ->SetTitle("H-line-Stopping_Z;Z[mm];N");

	TH1F * hDecayX = TreeToTH1F(tree,"x",200,-100,100,
		"z<10 && z>-8");
	hDecayX->SetTitle("H-line-Stopping_X;X[mm];N");

	TH1F * hDecayY = TreeToTH1F(tree,"y",100,-40,40,
		"z<10 && z>-8");
	hDecayY->SetTitle("H-line-Stopping_Y;Y[mm];N");

	TH2F * hDecayYZ = TreeToTH2F(tree,"y:z",
		100,-10,5,
		100,-50,50,
		//50,-40,40,
		"z<10 && z>-8");
	hDecayYZ->SetTitle("H-line-Stopping_YZ;Z[mm];Y[mm]");


	TCanvas * c0 = NewTCanvas("c0","c0",1000,500,2,1);
	c0->cd(1);
	TH2F * hDecayXZ = TreeToTH2F(tree,"x:z",
		100,-10,5,
		100,-50,50,
		//50,-40,40,
		"z<10 && z>-8");
	hDecayXZ->SetTitle("H-line-Stopping_XZ;Z[mm];X[mm]");
	hDecayXZ->Draw("colz");

	c0->cd(2);
	TH2F * hDecayXY = TreeToTH2F(tree,"y:x",200,-100,100,100,-40,40,
		"z<10 && z>-8");
	hDecayXY->SetTitle("H-line-Stopping_XY;X[mm];Y[mm]");
	hDecayXY->Draw("colz");


	//hDecayYZ->Draw("colz");


	///// Draw at the very begining of the study the aerogel size
	TBox * b = new TBox(-25,-20,25,20);
	b->SetFillColorAlpha(10,0.5);
	b->SetLineStyle(1);
	b->SetLineColor(2);
	b->SetLineWidth(10);
	//b->Draw();

	//SaveTCanvas(c,"H-line_initial_Profile_50_40");

	//delete gDirectory->Get("c1");


	//hDecayXZ->Draw("colz");
	//hDecayXY->Draw("colz");
	//c->cd(3);
	//c->cd(4);

	TCanvas * c2 = NewTCanvas("c2","c2",1000,1000,2,2);


	/// Study of the density
	c2->cd(1);
	hDecayZ = TreeToTH1F(tree,"z",200,-10,2,
		"z<10 && z>-8");
	hDecayZ->SetTitle("H-line-Stopping_Z;Z[mm];N");

	c2->cd(2);
	hDecayY = TreeToTH1F(tree,"y",1000,-30,30,
		"z<10 && z>-8");
	hDecayY->SetTitle("H-line-Stopping_Y;Y[mm];N");

	c2->cd(3);
	hDecayXZ = TreeToTH2F(tree,"x:z",
		20,-10,2,
		100,-30,30,
		//50,-40,40,
		"z<10 && z>-8 && y>=-0.06 && y<= 0.06");
	hDecayXZ->SetTitle("XZ_denstiy_0_0.06mm;Z[mm];X[mm]");
	hDecayXZ->Draw("colz");

	c2->cd(4);
	hDecayXY = TreeToTH2F(tree,"y:x",100,-30,30,100,-30,30,
		"z<=0 && z>=-0.12");
	hDecayXY->SetTitle("XY_density_0_0.06mm;X[mm];Y[mm]");
	hDecayXY->Draw("colz");




	hDecayZ = new TH1F("z","H-line-Stopping_Z;Z[mm];N",300,-10,8);

	hDecayYZ = new TH2F("yz","H-line-Stopping_YZ;Z[mm];Y[mm]",
		300,-10,8,
		100,-50,50);
	//hDecayYZ->SetTitle("");


	double x_dec, y_dec, z_dec;

	tree->SetBranchAddress("x", &x_dec);
	tree->SetBranchAddress("y", &y_dec);
	tree->SetBranchAddress("z", &z_dec);

	int Nentries = tree->GetEntries();

	for(int index_m=0; index_m < Nentries; index_m++){

		tree->GetEntry(index_m);

		if (!(z_dec<10 && z_dec>-8))continue;

		double X0 = x_dec;
		double Y0 = y_dec;
		double Z0 = z_dec;

		//cout<<X0<<" "<<Y0<<" "<<Z0<<endl;
		double Thick = 7.12;
/*
		if(Y0 < 28 && Y0 > 20)Z0 = Z0 + Thick;
		//if(Y0 < 20 && Y0 > 12) Z0 = Z0 + Thick;
		if(Y0 < 12 && Y0 > 4)Z0 = Z0 + Thick;
		//if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		if(Y0 < -4 && Y0 > -12)Z0 = Z0 + Thick;
		//if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		if(Y0 < -20 && Y0 > -28)Z0 = Z0 + Thick;
		//cout<<X0<<" "<<Y0<<" "<<Z0<<endl;
*/
		hDecayZ->Fill(Z0);
		hDecayYZ->Fill(Z0,Y0);


	}

	TCanvas * c3 = NewTCanvas("c3","c3",1000,500,2,1);
	TH1Style(hDecayZ,"H-line-Stopping_Z;Z[mm];N");
	c3->cd(1);hDecayZ->Draw();
	c3->cd(2);hDecayYZ->Draw("colz");






	//SaveTH2(hDecayXY,"H-line_initial_Profile_GM_xy");
	//SaveTH2(hDecayYZ,"H-line_initial_Profile_GM_yz");

	//SaveTCanvas(c2,"H-line_initial_Profile_GM_density");

	//SaveTH1(hDecayZ,"H-line_initial_Profile_GM_z");
	/*
	SaveTH1(hDecayX,"H-line_initial_Profile_GM_x");
	SaveTH1(hDecayY,"H-line_initial_Profile_GM_y");
	SaveTH2(hDecayXY,"H-line_initial_Profile_GM_xy");
	SaveTH2(hDecayYZ,"H-line_initial_Profile_GM_yz");
	*/
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
