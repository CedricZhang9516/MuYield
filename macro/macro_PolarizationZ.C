

void macro_PolarizationZ(){


	TCanvas * c = new TCanvas("c","c",1000,1000);
	//c->Divide(2,1);

	//TFile * f = new TFile("/home/had/zhangce/g-2/Root/TRIUMF_Spin_0129_A0.5_9_tree_Type2_D87000_T322_Nrepeat2000000_Xfree1_Thick7.12_NewGeo0_.root");
	TFile * f = new TFile("../Root/Dev_200202_surface_tree_Type2_D87000_T322_Nrepeat20000_Xfree1_Thick7.12_NewGeo0.root");
	TTree * t = (TTree*) f-> Get("tree");

	TGraphErrors * gP = new TGraphErrors();
	TGraph * gt = new TGraph();


	const int Nt = 40;
	TH1F * hx[Nt];
	TH1F * hy[Nt];
	TH1F * hz[Nt];
	TH1F * ht[Nt];
	TH2F * hxt;

	for(int i = 0; i<Nt; i++){

		t->Draw("SpinX>>hspinx(1e3,-1,1)",Form("DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		t->Draw("SpinY>>hspiny(1e3,-1,1)",Form("DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		t->Draw("SpinZ>>hspinz(1e3,-1,1)",Form("DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		//t->Draw("SpinX>>hspinx(1e3,-1,1)",Form("DecayT < 0.16e-6 && DecayT > 0.14e-6 && DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		//t->Draw("SpinY>>hspiny(1e3,-1,1)",Form("DecayT < 0.16e-6 && DecayT > 0.14e-6 && DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		//t->Draw("SpinZ>>hspinz(1e3,-1,1)",Form("DecayT < 0.16e-6 && DecayT > 0.14e-6 && DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		t->Draw("DecayT>>hdecayt(1e3,0,10e-6)",Form("DecayZ<(%i+1) && DecayZ>%i",i,i),"");
		t->Draw("SpinX:DecayT>>hxt(1e3,0,10e-6,1e3,-1,1)",Form("DecayZ<(%i+1) && DecayZ>%i",i,i),"");

		hx[i] = (TH1F*)gDirectory->Get("hspinx");//
		hy[i] = (TH1F*)gDirectory->Get("hspiny");//
		hz[i] = (TH1F*)gDirectory->Get("hspinz");//
		ht[i] = (TH1F*)gDirectory->Get("hdecayt");//
		hxt = (TH2F*)gDirectory->Get("hxt");//


		double P = sqrt(
			pow(hx[i]->GetMean(),2) +
			pow(hy[i]->GetMean(),2) +
			pow(hz[i]->GetMean(),2)
		);
/*
		double Ep =
			sqrt(
				pow(hx[i]->GetMean() * hx[i]->GetStdDev(), 2) +
				pow(hy[i]->GetMean() * hy[i]->GetStdDev(), 2) +
				pow(hz[i]->GetMean() * hz[i]->GetStdDev(), 2)
	 	)/P;
*/
		gP->SetPoint(i-10,i+0.5,P);
		//gt->SetPoint(i-10,i+0.5,ht[i]->GetMean());

		cout<<
			ht[i]->GetMean()<<" "<<
			//ht[i]->GetEntries()<<" "<<
			hx[i]->GetMean()<<" "<<
			hx[i]->GetEntries()<<" "<<
			//hx[i]->GetStdDev()<<" "<<
			//hy[i]->GetMean()<<" "<<
			//hz[i]->GetMean()<<" "<<
			P<<" "<<endl;

		if(i==0){
			c->cd(1);
			hx[i]->Draw();
			c->cd(2);
			hxt->Draw();
			break;
		}

	}

//	gP->Draw("APL*");
	gP->SetLineColor(1);
	gP->SetMarkerStyle(20);
	gP->SetMarkerSize(0.3);
	gP->SetMarkerColor(1);

	gP->SetTitle("Polarization vs. DecayZ; DecayZ [mm]; Polarization");
	gP->GetYaxis()->SetTitleOffset(0.58);
	gP->GetYaxis()->SetTitleSize(0.06);
	gP->GetXaxis()->SetTitleSize(0.06);
	gP->GetXaxis()->SetTitleOffset(0.8);
	//c->SaveAs("1.png");
}
