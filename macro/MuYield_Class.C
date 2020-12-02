#define MuYield_Class_cxx
#include "MuYield_Class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "ReflectionModel.h"
#include "ReInitializaingSurfaceXYZ0.h"


//#define TrackTime
//#define TrackEventTime

void MuYield_Class::Surface()
{

	if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Double_t x, y, z, vx, vy, vz, t;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {

		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;

		nb = fChain->GetEntry(jentry);
		nbytes += nb;

		cout<<"Surface: "<<jentry<<"/"<<nentries<<"\r"<<flush;

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

			ReInitializaingSurfaceXYZ0(X_sf,Y_sf,Z_sf, MCtype);

			hZY2D_sf->Fill(Z_sf, Y_sf);
			hZX2D_sf->Fill(Z_sf, X_sf);
			hXY2D_sf->Fill(X_sf, Y_sf);
		}
	}

}

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

	//hT->Reset("");
	hT->Reset("ICESM");


   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Double_t x, y, z, vx, vy, vz, t;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {

		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;

		nb = fChain->GetEntry(jentry);
		nbytes += nb;

		cout<<"LoopEvent: "<<jentry<<"/"<<nentries<<"\r"<<flush;

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

   cout<<"Maximum Yield in the laser region "
		<<hT->GetMaximum()
		<<" at "
		<<hT->GetMaximumBin()
		<<" ns"
		<<endl;

}

void MuYield_Class::LoopEventWithReflection(int N_track_event = -1, TString Outputfilename = "")
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

	//hT->Clear();
	hT->Reset("ICESM");

   const double mmu = 105.658;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Double_t x, y, z, vx, vy, vz, t;

   Double_t prev_x, prev_y, prev_z, prev_t;

   ofstream wf(Outputfilename.Data());
	if(Outputfilename!=""){
		OutputLaserIonization = 1;
		cout<<Outputfilename.Data()<<" created"<<endl;
	}

   //if(N_track_event>0 && N_track_event == jentry){
   if(N_track_event>0 ){
		g_track_reflection = new TGraph();
		tree->GetEntry(N_track_event);
		for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track_reflection->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	}

   int NLaserRegion3 = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {

		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;

		nb = fChain->GetEntry(jentry);
		nbytes += nb;

		cout<<"LoopEventWithReflection: "<<jentry<<"/"<<nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;

		if(MCtype>4000 && !(Y_sf>-7 && Y_sf<7)  )continue;
		//ReInitializaingSurfaceXYZ0(X_sf,Y_sf,Z_sf, MCtype);

		t = DiffusionT + TBeam;
		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

		prev_x = x;
		prev_y = y;
		prev_z = z;
		prev_t = t;

		hT_sf->Fill(t);
		hZXY3D_sf->Fill(Z_sf, X_sf, Y_sf);

		if(z>0){
			hZY2D_sf->Fill(Z_sf, Y_sf);
			hZX2D_sf->Fill(Z_sf, X_sf);
			hXY2D_sf->Fill(X_sf, Y_sf);
		}

		for(int j = 0; j < nbinT; j++){

			if(Tstep*j >= delT)break;

			if(N_track_event>0 && N_track_event == jentry)
			g_track_reflection->SetPoint(
				g_track_reflection->GetN(),z,y);


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

			std::streamsize prev_precision = wf.precision(); // save old precision

			if(InsideLaserRegion(x,y,z,MCtype))hT->Fill(t);

			if(InsideLaserRegion(x,y,z,MCtype) && abs(t-lasertime*1e-6)<Tstep/2 ){

				hZY2D_laser->Fill(z, y);
				hZX2D_laser->Fill(z, x);
				hXY2D_laser->Fill(x, y);
				hZ1D_laser->Fill(z);
				hX1D_laser->Fill(x);
				hY1D_laser->Fill(y);

			 	if(OutputLaserIonization==0) continue;

				NLaserRegion3++;

				double p = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE);
				double g = 1.0*(mmu+LaserE)/mmu;
				double b = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE)/(mmu+LaserE);
				//cout << g << "\t" << b << endl;

				double xp = VX_sf/VZ_sf;
				double yp = VY_sf/VZ_sf;

				wf << x*0.1 << " "
				<< xp*1000 << " "
				<< y*0.1 << " "
				<< yp*1000 << " ";

				wf << scientific
				<< mmu/1000*g*b << " ";

				wf.precision(prev_precision); // restore old precision

				wf << fixed << z << " "
				<< 0 << " "
				<< "-1 -1 " << endl;

				//wf << fixed << setprecision(0) << MUONID
				//<< endl;

				wf.precision(prev_precision); // restore old precision


			}


			if( InsideAerogel ( x, y, z, MCtype ) && ! InsideAerogel ( prev_x, prev_y, prev_z, MCtype ) ){

				ReflectionModel(
					x,y,z,t,
					vx,vy,vz,
					(delT - (Tstep*j)), MCtype );

				if(N_track_event>0 && N_track_event == jentry){
					for(int i = 0; i<ReflectionVertexX->size() ;i++)
					g_track_reflection->SetPoint(
						g_track_reflection->GetN(),
						ReflectionVertexZ->at(i),ReflectionVertexY->at(i)
					);
				}


				j = j + (t-prev_t)/Tstep -1;
			}

			prev_x = x;
			prev_y = y;
			prev_z = z;
			prev_t = t;

			#ifdef TrackTime

			//hXY2D->Draw("colz");
			hZXY3D->Draw("lego2");
			//hXYT3D->Draw("lego2");
			c->Modified();
			c->Update();
			//gSystem->Sleep(1);
			if( gSystem->ProcessEvents()) break;

			#endif

		}  // end of time loop

		#ifdef TrackEventTime
		//if(jentry==100)hZY2D_sf->Draw("colz");
		if(jentry==1)hZY2D_sf->Draw("colz");
		//if( jentry>=100 && jentry % 100 == 0){
		if( jentry>=1 && jentry % 2 == 0){
			hZY2D->Draw("sameCOLZ");
			c->Modified();
			c->Update();
			//gSystem->Sleep(100);
			if( gSystem->ProcessEvents()) break;
		}
		//c->SaveAs(Form("./png/%i.png",i));
		//hZY2D->Reset();
		#endif // track event time

   } // events loop

   	if(OutputLaserIonization!=0){
		TString OutputfilenameWithN = Outputfilename;
		OutputfilenameWithN.ReplaceAll(".dat", Form("_%d.dat",NLaserRegion3) );

		gROOT->ProcessLine( Form(".!mv %s %s",
			Outputfilename.Data(),OutputfilenameWithN.Data()
			) );
	}

	cout<<"Maximum Yield in the laser region "
		<<hT->GetMaximum()
		<<" at "
		<<hT->GetMaximumBin()
		<<" ns"
		<<endl;
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

   		cout<<"LoopTime: "<<j<<"/"<<nbinT<<"\r"<<flush;

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



void MuYield_Class::QuickLaserIonization(double Lasertime = -1, TString Outputfilename = "")
{

	lasertime = Lasertime;
	ofstream wf(Outputfilename.Data());
	if(Outputfilename!=""){
		OutputLaserIonization = 1;
		cout<<Outputfilename.Data()<<" created"<<endl;
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

		cout<<"QuickLaserIonization: "<<i<<"/"<<Nentries<<"\r"<<flush;

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

			hX1D_0->Fill(X0);
			hY1D_0->Fill(Y0);
			hZ1D_0->Fill(Z0);

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

			//wf << fixed << setprecision(0) << MUONID
			wf << fixed << setprecision(0)
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






TGraph* MuYield_Class::Track(Int_t Nevent = 1){

	tree->GetEntry(Nevent);

	g_track = new TGraph();
	//for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));

	/////////// Draw the position at the laser time, remember to set the lasertime first!!!!!

	double x, y, z, vx, vy, vz, t, muonid;

	const double mmu = 105.658;
	const double light = 299792458; // m/s
	const double massMu = 106.16/light/light; // MeV/c2

	double delT = DecayT - DiffusionT;


	if(
			lasertime == -1 ||
			( DecayT <= (lasertime*1e-6  - TBeam) )  ||
			(lasertime*1e-6 - TBeam - DiffusionT) < 0
	)return g_track;


	t = DiffusionT + TBeam;

	x = X_sf;
	y = Y_sf;
	z = Z_sf;
	vx = VX_sf;
	vy = VY_sf;
	vz = VZ_sf;

	LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

	x = x + vx * (lasertime*1e-6 - TBeam - DiffusionT);
	y = y + vy * (lasertime*1e-6 - TBeam - DiffusionT);
	z = z + vz * (lasertime*1e-6 - TBeam - DiffusionT);
	t = lasertime*1e-6;


	g_track->SetPoint(DiffusionVertexX->size(),z,y);

	return g_track;

}


TGraph* MuYield_Class::TrackWithReflection(Int_t Nevent = 1){

	tree->GetEntry(Nevent);

	g_track_reflection = new TGraph();
	//for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track_reflection->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));

	/////////// Draw the position at the laser time, remember to set the lasertime first!!!!!

	double x, y, z, vx, vy, vz, t, muonid;

	double prev_x, prev_y, prev_z, prev_t;

	const double mmu = 105.658;
	const double light = 299792458; // m/s
	const double massMu = 106.16/light/light; // MeV/c2

	double delT = DecayT - DiffusionT;


	if(
			lasertime == -1 ||
			( DecayT <= (lasertime*1e-6  - TBeam) )  ||
			(lasertime*1e-6 - TBeam - DiffusionT) < 0
	)return g_track_reflection;


	t = DiffusionT + TBeam;

	x = X_sf;
	y = Y_sf;
	z = Z_sf;
	vx = VX_sf;
	vy = VY_sf;
	vz = VZ_sf;

	LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

	prev_x = x;
	prev_y = y;
	prev_z = z;
	prev_t = t;

	for(int j = 0; j < nbinT; j++){

		//if(Tstep*j >= delT)break;
		if(Tstep*j >= (lasertime*1e-6 - TBeam - DiffusionT) )break;

		x = x + vx * (Tstep);
		y = y + vy * (Tstep);
		z = z + vz * (Tstep);
		t = t + Tstep;

		g_track_reflection->SetPoint(
			g_track_reflection->GetN(),z,y);

		if( InsideAerogel ( x, y, z, MCtype ) && ! InsideAerogel ( prev_x, prev_y, prev_z, MCtype ) ){

			ReflectionModel(
				x,y,z,t,
				vx,vy,vz,
				(delT - (Tstep*j)), MCtype );

			for(int i = 0; i<ReflectionVertexX->size() ;i++)
				g_track_reflection->SetPoint(
					g_track_reflection->GetN(),
					ReflectionVertexZ->at(i),ReflectionVertexY->at(i)
				);

			j = j + (t-prev_t)/Tstep -1;
		}

		prev_x = x;
		prev_y = y;
		prev_z = z;
		prev_t = t;

	}

	//x = x + vx * (lasertime*1e-6 - TBeam - DiffusionT);
	//y = y + vy * (lasertime*1e-6 - TBeam - DiffusionT);
	//z = z + vz * (lasertime*1e-6 - TBeam - DiffusionT);
	//t = lasertime*1e-6;

	//g_track->SetPoint(DiffusionVertexX->size(),z,y);

	return g_track_reflection;

}



void MuYield_Class::SavePlots(){

	//#ifdef drawplot

	//TCanvas * c0 = NewTCanvas("c0","c0",800,800,1,1);
	c1 = NewTCanvas("c1","c1_surface",1000,1000,3,3);
	c2 = NewTCanvas("c2","c2_accumulation_yield",1000,1000,3,3);
	c3 = NewTCanvas("c3_laser","c3_laser",1000,1000,3,3);
	c4 = NewTCanvas("c4_laser","c4_laser",1000,1000,3,3);

	/////////////////
	// Yield on the surface
	/////////////////

	c1->cd(1);
	hZY2D_sf->Draw("colz");
	c1->cd(2);
	hZX2D_sf->Draw("colz");
	c1->cd(3);
	hXY2D_sf->Draw("colz");
	c1->cd(4);
	hT_sf->Draw("");


	/////////////////
	// Total yield
	/////////////////

	c2->cd(1);
	hXY2D->Draw("colz");
	c2->cd(2);
	hZY2D->Draw("colz");
	c2->cd(3);
	hZX2D->Draw("colz");
	c2->cd(4);
	hT->Draw();
	cout<<"Maximum Yield in the laser region "
		<<hT->GetMaximum()
		<<" at "
		<<hT->GetMaximumBin()
		<<" ns"
		<<endl;

	/////////////////
	// Laser yield
	/////////////////

	int c_i = 0;
	c3->cd(++c_i);
	hZY2D_0->Draw("colz");
	c3->cd(++c_i);
	hZX2D_0->Draw("colz");
	c3->cd(++c_i);
	hXY2D_0->Draw("colz");
	c3->cd(++c_i);
	hX1D_laser->Draw();
	c3->cd(++c_i);
	hY1D_laser->Draw();
	c3->cd(++c_i);
	hZ1D_laser->Draw();
	c3->cd(++c_i);
	hZY2D_laser->Draw("colz");
	c3->cd(++c_i);
	hZX2D_laser->Draw("colz");
	c3->cd(++c_i);
	hXY2D_laser->Draw("colz");

	c_i = 0;
	c4->cd(++c_i);
	hZ1D_0->Draw();
	c4->cd(++c_i);
	hX1D_0->Draw();
	c4->cd(++c_i);
	hY1D_0->Draw();

	/////////////////
	///// Draw other 2D and 3D plots
	/////////////////
/*
	c1->cd(1);
 	t1->hZT2D->Draw("colz");
 	c1->cd(2);
 	t1->hZY2D->Draw("colz");
 	c1->cd(3);
 	t1->hZX2D->Draw("colz");
 	c1->cd(4);
 	t1->hXY2D->Draw("colz");
 	c1->cd(5);
 	t1->hZXT3D->Draw("LEGO");
 	c1->cd(6);
 	t1->hZXY3D->Draw("lego2");
*/

	//#endif

 	//#ifdef saveplot

 	c1->SaveAs( Form("%s.pdf(", filename.Data()) );
 	c2->SaveAs( Form("%s.pdf", filename.Data()) );
 	c3->SaveAs( Form("%s.pdf", filename.Data()) );
 	c4->SaveAs( Form("%s.pdf)", filename.Data()) );


 	//#endif

}

