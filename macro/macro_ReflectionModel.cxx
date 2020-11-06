#include "ReflectionModel.h"



void macro_ReflectionModel(TString filename = "MuYield.root", double Lasertime = 1.35){


	filename =
			//"../Root/201103_Reflectoin/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3006;
			//"../Root/201103_Reflectoin/201103_Reflection_3011_tree_Type3011_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3011;
			"../Root/201103_Reflectoin/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3012;
	filename.ReplaceAll(".root","");

	lasertime = Lasertime;

	int MCtype = 3012;

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get("tree");
	InitTree(tree);

	double x, y, z, vx, vy, vz, t, muonid,
		   prev_x, prev_y, prev_z, prev_t;

	int Nentries = tree->GetEntries();

	for(int i = 0; i<Nentries; i++){

		tree->GetEntry(i);

		cout<<i<<"/"<<Nentries<<"\r"<<flush;

		double delT = DecayT - DiffusionT;

		t = DiffusionT + TBeam;

		x = X_sf;
		y = Y_sf;
		z = Z_sf;
		vx = VX_sf;
		vy = VY_sf;
		vz = VZ_sf;

		prev_x = x;
		prev_y = y;
		prev_z = z;
		prev_t = t;


		for(int j = 0; j < nbinT; j++){

			if(Tstep*j >= delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			if( InsideLaserRegion(x,y,z,MCtype) ) hT->Fill(t);

			if( InsideAerogel ( x, y, z, MCtype ) && ! InsideAerogel ( prev_x, prev_y, prev_z, MCtype ) ){

				ReflectionModel(
					x,y,z,t,
					vx,vy,vz,
					(delT - (Tstep*j)), MCtype );


				j = j + (t-prev_t)/Tstep -1;
			}

			prev_x = x;
			prev_y = y;
			prev_z = z;
			prev_t = t;

		} // event time loop



	}

	hT->Draw("");


///////////// Laser ionization

	/*

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


			hZY2D_laser->Fill(z, y);
			hZX2D_laser->Fill(z, x);
			hXY2D_laser->Fill(x, y);

			hZY2D_0->Fill(Z0, Y0);
			hZX2D_0->Fill(Z0, X0);
			hXY2D_0->Fill(X0, Y0);


		}
	*/


}
