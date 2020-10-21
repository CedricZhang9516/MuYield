#define MuYield_Class_cxx
#include "MuYield_Class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MuYield_Class::Loop()
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

			if(InsideLaserRegion_3006(x,y,z)){

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
		}

		// if (Cut(ientry) < 0) continue;
   }
}
