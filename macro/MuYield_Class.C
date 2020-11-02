#define MuYield_Class_cxx
#include "MuYield_Class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


//#define TrackTime
//#define TrackEventTime

void MuYield_Class::LoopEvent()
{
//   In a ROOT session, you can do:
//      root> .L MuYield_Class.C
//      root> MuYield_Class t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch


   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Double_t x, y, z, vx, vy, vz, t;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {

		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;

		nb = fChain->GetEntry(jentry);
		nbytes += nb;

		cout<<jentry<<"/"<<nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;

		t = DiffusionT + TBeam;
		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		hT_sf->Fill(t);
		hZXY3D_sf->Fill(Z_sf, X_sf, Y_sf);

		if(z>0){
			hZY2D_sf->Fill(Z_sf, Y_sf);
			hZX2D_sf->Fill(Z_sf, X_sf);
			hXY2D_sf->Fill(X_sf, Y_sf);
		}
		//cout<<nbinT<<endl;
		for(int j = 0; j < nbinT; j++){

			if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			hZT2D->Fill(t, z);
			hZY2D->Fill(z, y);
			hZX2D->Fill(z, x);
			hXY2D->Fill(x, y);
			hXYT3D->Fill(t, x, y);
			hZXY3D->Fill(z, x, y);

			//if(InsideLaserRegion_3006(x,y,z)){
			if(InsideLaserRegion(x,y,z,MCtype)){

				hT->Fill(t);
				/*
				hZY2D_0->Fill(z, y);
				hZX2D_0->Fill(z, x);
				hXY2D_0->Fill(x, y);
				*/
				/*
				hZT2D->Fill(t, z);
				hZY2D->Fill(z, y);
				hZX2D->Fill(z, x);
				hXY2D->Fill(x, y);
				hXYT3D->Fill(t, x, y);
				hZXY3D->Fill(z, x, y);
				*/
			}

			#ifdef TrackTime

			//hXY2D->Draw("colz");
			//hZY2D->Draw("colz");
			hZXY3D->Draw("lego2");
			//hXYT3D->Draw("lego2");
			c->Modified();
			c->Update();
			//gSystem->Sleep(1);
			if( gSystem->ProcessEvents()) break;

			#endif

		}  // end of time loop

		#ifdef TrackEventTime

		if( jentry>=100 && jentry % 100 == 0){
			hZY2D->Draw("colz");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			if( gSystem->ProcessEvents()) break;
		}
		//c->SaveAs(Form("./png/%i.png",i));
		hZY2D->Reset();
		#endif // track event time

   } // events loop
}

void MuYield_Class::LoopTime()
{

	nbinT = 80; /// 8 us
	Tstep = 2e-8; /// 0.01 us

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Double_t x, y, z, vx, vy, vz, t;

   for(int j = 0; j < nbinT; j++){

   		cout<<j<<"/"<<nbinT<<"\r"<<flush;

   		hZT2D->Reset();
		hZY2D->Reset();
		hZX2D->Reset();
		hXY2D->Reset();
		hXYT3D->Reset();
		hZXY3D->Reset();

	   for (Long64_t jentry=0; jentry<nentries;jentry++) {

			Long64_t ientry = LoadTree(jentry);
			if (ientry < 0) break;

			nb = fChain->GetEntry(jentry);
			nbytes += nb;

			if( (Tstep*j <= (DiffusionT+TBeam)) || (Tstep*j >= (DecayT+TBeam) ))continue;

			double delT = (Tstep) * j - (DiffusionT+TBeam);

			t = Tstep*j;
			//cout<<t<<endl;
			x = X_sf + VX_sf * delT;
			y = Y_sf + VY_sf * delT;
			z = Z_sf + VZ_sf * delT;

			if(InsideLaserRegion(x,y,z,MCtype)){
				hZT2D->Fill(t, z);
				hZY2D->Fill(z, y);
				hZX2D->Fill(z, x);
				hXY2D->Fill(x, y);
				hXYT3D->Fill(t, x, y);
				hZXY3D->Fill(z, x, y);
				hT->Fill(t);
			}
		} //  event loop

		// Save the dynamic png
		if( j>=0 && j % 1 == 0){

			c->cd(4);
			hT->Draw("");
			c->cd(2);
			hZY2D->Draw("colz");
			c->cd(3);
			hZX2D->Draw("colz");
			c->cd(1);
			hXY2D->Draw("colz");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			//c->SaveAs(Form("MuYieldAsTime_%.3f_us.png",j*0.1));
			if( gSystem->ProcessEvents()) break;

		}

	} // time loop
}



void MuYield_Class::LaserIonization(double Lasertime = -1, TString Outputfilename = "")
{

	lasertime = Lasertime;
	ofstream wf(Outputfilename.Data());
	if(Outputfilename!=""){
		OutputLaserIonization = 1;
	}

	//int Nentries = tree->GetEntries();

	double x, y, z, vx, vy, vz, t, muonid;

	const double mmu = 105.658;
	const double light = 299792458; // m/s
	const double massMu = 106.16/light/light; // MeV/c2

	//DEBUG
	int NLaserRegion = 0;
	int NLaserRegion3 = 0;
	double tT1, tT2, tT3;
	double tZ1, tZ2, tZ3;

	for(int i = 0; i<Nentries; i++){
	//for(int i = 0; i<9; i++){

		//DEBUG
		int FNLaserRegion = 0;
		int FNLaserRegion3 = 0;
		tZ1 = 0;

		tree->GetEntry(i);

		cout<<i<<"/"<<Nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;

		if(
			( DecayT <= (lasertime*1e-6  - TBeam) )  ||
			(lasertime*1e-6 - TBeam - DiffusionT) < 0
		)continue;

		t = DiffusionT + TBeam;

		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

		//////////////////////////////////////////////////////
		///////////  DEBUG

/*



		for(int j = 0; j < nbinT; j++){

			//if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			hZT2D->Fill(t, z);
			hZY2D->Fill(z, y);
			hZX2D->Fill(z, x);
			hXY2D->Fill(x, y);
			hXYT3D->Fill(t, x, y);
			hZXY3D->Fill(z, x, y);

			//if(InsideLaserRegionTDR(x,y,z))hT->Fill(t);
			if(InsideLaserRegionTDRnoXlimit(x,y,z))hT->Fill(t);

			if( abs(t - lasertime*1e-6)<=Tstep ){
				//cout<<t<<" "<<lasertime*1e-6<<endl;
				tZ1 = z;
				if(InsideLaserRegionTDRnoXlimit(x,y,z)){NLaserRegion++;FNLaserRegion=1;}
				break;
			}

		}
*/

		///////////  DEBUG
		//////////////////////////////////////////////////////



		t = DiffusionT + TBeam;
		x = X_sf;
		y = Y_sf;
		z = Z_sf;

		x = x + vx * (lasertime*1e-6 - TBeam - DiffusionT);
		y = y + vy * (lasertime*1e-6 - TBeam - DiffusionT);
		z = z + vz * (lasertime*1e-6 - TBeam - DiffusionT);
		t = lasertime*1e-6;

		std::streamsize prev_precision = wf.precision(); // save old precision

		if(InsideLaserRegion(x,y,z, MCtype)){

			double p = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE);
			double g = 1.0*(mmu+LaserE)/mmu;
			double b = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE)/(mmu+LaserE);
			//cout << g << "\t" << b << endl;

			double xp = VX_sf/VZ_sf;
			double yp = VY_sf/VZ_sf;

			NLaserRegion3++;

			/*
			//DEBUG
			if(FNLaserRegion==0){
				cout<<"check with two methods "<<tZ1<<" "<<z<< endl;
			}
			*/
			hZY2D_laser->Fill(z, y);
			hZX2D_laser->Fill(z, x);
			hXY2D_laser->Fill(x, y);

			hZY2D_0->Fill(Z0, Y0);
			hZX2D_0->Fill(Z0, X0);
			hXY2D_0->Fill(X0, Y0);

			if(OutputLaserIonization==0) continue;


			wf << x*0.1 << " "
			<< xp*1000 << " "
			<< y*0.1 << " "
			<< yp*1000 << " ";

			wf << scientific
			<< mmu/1000*g*b << " ";

			wf.precision(prev_precision); // restore old precision

			wf << fixed << z << " "
			<< 0 << " "
			<< "-1 -1 ";// << endl;

			wf << fixed << setprecision(0) << MUONID
			<< endl;


			wf.precision(prev_precision); // restore old precision


		}

	} // all surface events


	//DEBUG
	//cout<<"total NLaserRegion "<<NLaserRegion<<endl;
	//cout<<"total NLaserRegion2 "<<NLaserRegion2<<endl;
	//cout<<"total NLaserRegion3 "<<NLaserRegion3<<endl;
	if(OutputLaserIonization!=0){
		TString OutputfilenameWithN = Outputfilename;
		OutputfilenameWithN.ReplaceAll(".dat", Form("_%d.dat",NLaserRegion3) );

		gROOT->ProcessLine( Form(".!mv %s %s",
			Outputfilename.Data(),OutputfilenameWithN.Data()
			) );
	}

}


void MuYield_Class::Track(Int_t Nevent = 1){

	tree->GetEntry(Nevent);

	g_track = new TGraph();
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	g_track->Draw("APL*");



}