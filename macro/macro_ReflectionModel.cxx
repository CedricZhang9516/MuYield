#include "ReflectionModel.h"



void macro_ReflectionModel(TString filename = "MuYield.root", double Lasertime = 1.35){


	filename =
			//"../Root/201103_Reflection/201103_Reflection_3006_tree_Type3006_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3006;
			//"../Root/201103_Reflection/201103_Reflection_3011_tree_Type3011_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3011;
			"../Root/201103_Reflection/201103_Reflection_3012_tree_Type3012_D87000_T322_Nrepeat3031781_H_line1_Thick25.00_NewGeo0.root"; //MCtype = 3012;
	filename.ReplaceAll(".root","");

	lasertime = Lasertime;

	int MCtype = 3012;

	TFile * f = new TFile( (filename + ".root").Data() );
	TTree * tree = (TTree*) f-> Get("tree");
	InitTree(tree);

	double x, y, z, vx, vy, vz, t, muonid,
		   prev_x, prev_y, prev_z, prev_t;

	int Nentries = tree->GetEntries();

	TCanvas* c1 = NewTCanvas("c1_initial","c1_initial",700,500,4,3);
	TCanvas* c2 = NewTCanvas("c2_reflection","c2_reflection",700,500,3,3);
	TCanvas* c3 = NewTCanvas("c3_reflection","c3_reflection",700,500,2,1);
	TCanvas* c4 = NewTCanvas("c4_decay","c4_decay",700,500,3,2);
	TCanvas* c5 = NewTCanvas("c5_decay","c5_decay",700,500,4,3);


	//hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",1000,-10,40,2000,-40,40);
	//hZY2D_decay = new TH2D("Z-Y-2D_decay","Z-Y-2D_decay; Z(mm);Y (mm)",1000,-10,40,2000,-40,40);
	//hY1D_decay = new TH1D("Y-1D_decay","Y-1D_decay; Y(mm);N",500,-10,10);

	hX1D_sf = new TH1D("X-1D_sf","X-1D_sf; X(mm);N",50,-40,40);
	hY1D_sf = new TH1D("Y-1D_sf","Y-1D_sf; Y(mm);N",50,-10,10);
	hZ1D_sf = new TH1D("Z-1D_sf","Z-1D_sf; Z(mm);N",50,0,30);
	hCosTheta1D_sf = new TH1D("CosTheta-1D_sf","CosTheta-1D_sf; CosTheta;N",100,0,1);

	hVX1D_sf = new TH1D("hVX1D_sf","hVX1D_sf;VX (mm/us)",100,0,25);
	hVY1D_sf = new TH1D("hVY1D_sf","hVY1D_sf;VY (mm/us)",100,0,25);
	hVZ1D_sf = new TH1D("hVZ1D_sf","hVZ1D_sf;VZ (mm/us)",100,0,25);
	hV_sf = new TH1D("hV_sf","hV_sf;V (mm/us)",100,0,25);

	hZT2D_sf = new TH2D("Z-T-2D_sf","Z-T-2D_sf; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);
	hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",1000,-10,40,2000,-40,40);
	//hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",1000,-5,30,1000,-8,8);
	hZX2D_sf = new TH2D("Z-X-2D_sf","Z-X-2D_sf; Z(mm);X (mm)",500,-10,40,500,-40,40);
	hXY2D_sf = new TH2D("X-Y-2D_sf","X-Y-2D_sf; X(mm);Y (mm)",500,-40,40,500,-40,40);

	hX1D_decay = new TH1D("X-1D_decay","X-1D_decay_InVac; X(mm);N",60,-45,45);
	hY1D_decay = new TH1D("Y-1D_decay","Y-1D_decay_InVac; Y(mm);N",100,-30,30);
	hZ1D_decay = new TH1D("Z-1D_decay","Z-1D_decay_InVac; Z(mm);N",50,-5,30);
	hCosTheta1D_decay = new TH1D("CosTheta-1D_decay","CosTheta-1D_decay; CosTheta;N",100,0,1);

	//hZY2D_decay = new TH2D("Z-Y-2D_decay","Z-Y-2D_decay; Z(mm);Y (mm)",100,-5,30,100,-15,15);
	hZY2D_decay = new TH2D("Z-Y-2D_decay","Z-Y-2D_decay; Z(mm);Y (mm)",100,-5,30,100,-40,40);
	hZX2D_decay = new TH2D("Z-X-2D_decay","Z-X-2D_decay; Z(mm);X (mm)",100,-5,30,100,-40,40);
	//hXY2D_decay = new TH2D("X-Y-2D_decay","X-Y-2D_decay; X(mm);Y (mm)",100,-40,40,100,-15,15);
	hXY2D_decay = new TH2D("X-Y-2D_decay","X-Y-2D_decay; X(mm);Y (mm)",100,-40,40,100,-40,40);

	hVX1D_decay = new TH1D("hVX1D_decay","hVX1D_decay;VX (mm/us)",100,0,25);
	hVY1D_decay = new TH1D("hVY1D_decay","hVY1D_decay;VY (mm/us)",100,0,25);
	hVZ1D_decay = new TH1D("hVZ1D_decay","hVZ1D_decay;VZ (mm/us)",100,0,25);
	hV_decay = new TH1D("hV_decay","hV_decay;V (mm/us)",100,0,25);

	//TH1D* hT = new TH1D("hT","hT;T[s];N",nbinT,0,nbinT*Tstep);
	TH1D* hT = new TH1D("hT","hT;T[s];N",nbinT/4,0,nbinT*Tstep);

	hX1D_reflected = new TH1D("X-1D_reflected","X-1D_reflected_InVac; X(mm);N",60,-45,45);
	hY1D_reflected = new TH1D("Y-1D_reflected","Y-1D_reflected_InVac; Y(mm);N",100,-3,3);
	hZ1D_reflected = new TH1D("Z-1D_reflected","Z-1D_reflected_InVac; Z(mm);N",50,-5,30);
	hCosTheta1D_reflected = new TH1D("CosTheta-1D_reflected","CosTheta-1D_reflected; CosTheta;N",100,0,1);

	hZY2D_reflected = new TH2D("Z-Y-2D_reflected","Z-Y-2D_reflected; Z(mm);Y (mm)",100,-5,30,100,-15,15);
	hZX2D_reflected = new TH2D("Z-X-2D_reflected","Z-X-2D_reflected; Z(mm);X (mm)",100,-5,30,100,-40,40);
	hXY2D_reflected = new TH2D("X-Y-2D_reflected","X-Y-2D_reflected; X(mm);Y (mm)",100,-40,40,100,-15,15);

	hVX1D_reflected = new TH1D("hVX1D_reflected","hVX1D_reflected;VX (mm/us)",100,0,25);
	hVY1D_reflected = new TH1D("hVY1D_reflected","hVY1D_reflected;VY (mm/us)",100,0,25);
	hVZ1D_reflected = new TH1D("hVZ1D_reflected","hVZ1D_reflected;VZ (mm/us)",100,0,25);
	hV_reflected = new TH1D("hV_reflected","hV_reflected;V (mm/us)",100,0,25);

	hX1D_reflectedOnce = new TH1D("X-1D_reflectedOnce","X-1D_reflected_Once_InVac; X(mm);N",60,-45,45);
	hY1D_reflectedOnce = new TH1D("Y-1D_reflectedOnce","Y-1D_reflected_Once_InVac; Y(mm);N",100,-3,3);
	hZ1D_reflectedOnce = new TH1D("Z-1D_reflectedOnce","Z-1D_reflected_Once_InVac; Z(mm);N",50,-5,30);
	hCosTheta1D_reflectedOnce = new TH1D("CosTheta-1D_reflectedOnce","CosTheta-1D_reflectedOnce; CosTheta;N",100,0,1);

	hZY2D_reflectedOnce = new TH2D("Z-Y-2D_reflectedOnce","Z-Y-2D_reflectedOnce; Z(mm);Y (mm)",100,-5,30,100,-15,15);
	hZX2D_reflectedOnce = new TH2D("Z-X-2D_reflectedOnce","Z-X-2D_reflectedOnce; Z(mm);X (mm)",100,-5,30,100,-40,40);
	hXY2D_reflectedOnce = new TH2D("X-Y-2D_reflectedOnce","X-Y-2D_reflectedOnce; X(mm);Y (mm)",100,-40,40,100,-15,15);

	hVX1D_reflectedOnce = new TH1D("hVX1D_reflectedOnce","hVX1D_reflectedOnce;VX (mm/us)",100,0,25);
	hVY1D_reflectedOnce = new TH1D("hVY1D_reflectedOnce","hVY1D_reflectedOnce;VY (mm/us)",100,0,25);
	hVZ1D_reflectedOnce = new TH1D("hVZ1D_reflectedOnce","hVZ1D_reflectedOnce;VZ (mm/us)",100,0,25);
	hV_reflectedOnce = new TH1D("hV_reflectedOnce","hV_reflectedOnce;V (mm/us)",100,0,25);

	TGraph * g_track_reflection = new TGraph();

	//const int N_dyn = 200;
	//TH2D** hZY2D_dyn = new TH2D*[N_dyn];
	//for(int i = 0;i<N_dyn;i++)hZY2D_dyn[i] = new TH2D(Form("Z-Y-2D-dyn-%d",i),Form("Z-Y-2D-dyn-%d;Z(mm);Y (mm)",i),5000,-5,30,5000,-15,15);


	int N_track_event = 319967;

	//g_track_reflection = new TGraph();
	tree->GetEntry(N_track_event);
	for(int i = 0; i<DiffusionVertexX->size() ;i++)g_track_reflection->SetPoint(i,DiffusionVertexZ->at(i),DiffusionVertexY->at(i));


	for(int i = 0; i<Nentries; i++){
	//for(int i = 0; i<1000; i++){


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

		double IsReflected = 0;
		double IsReflectedAnddFailed = 0;

		//if(X_sf>150 || X_sf<-150) continue;
/*
		if(!(
			//3012
			(Z_sf>0.5 && Z_sf<24.5 && Y_sf<0 && Y_sf>-3)
			|| (Z_sf>0.5 && Z_sf<24.5 && Y_sf<3 && Y_sf>0)

			//3006
			//(Z_sf>0.5 && Z_sf<24.5 && Y_sf<0 && Y_sf>-5)
			//|| (Z_sf>0.5 && Z_sf<24.5 && Y_sf<5 && Y_sf>0)

		))continue;
*/
		//double CosTheta = cos(theta_sf);


		for(int j = 0; j < nbinT; j++){

			if(Tstep*j > delT)break;

			x = x + vx * (Tstep);
			y = y + vy * (Tstep);
			z = z + vz * (Tstep);
			t = t + Tstep;

			//cout<<int((t*1e7) /10)<<endl;

			//if(   int((t*1e8) /10)<200 &&z>0 ){
			//	hZY2D_dyn[ int((t*1e8) /10)]->Fill(z,y);
			//}

			if(N_track_event>0 && N_track_event == i)
				g_track_reflection->SetPoint(
					g_track_reflection->GetN(),z,y);

			//if( InsideLaserRegion(x,y,z,MCtype) ) hT->Fill(t);
			// at the decay moment
			if( //(z>0.5 && z<24.5) &&
				(z>0.) &&
				IsReflected!=0 && InsideAerogel(x,y,z,MCtype) && (delT-Tstep*j)<Tstep ){
				NofReflectionAndFailed->Fill(IsReflected);
				NofReflection->Fill(IsReflected);
			}
			if( //(z>0.5 && z<24.5) &&
				(z>0.) &&
				!InsideAerogel(x,y,z,MCtype) && (delT-Tstep*j)<Tstep ){

				//hT->Fill(t);
				//hZY2D_decay->Fill(z,y);
				//hY1D_decay->Fill(y);
				hX1D_decay->Fill(x);
				hY1D_decay->Fill(y);
				hZ1D_decay->Fill(z);
				hZY2D_decay->Fill(z,y);
				hZX2D_decay->Fill(z,x);
				hXY2D_decay->Fill(x,y);

				hVX1D_decay->Fill(vx*1e-6);
				hVY1D_decay->Fill(vy*1e-6);
				hVZ1D_decay->Fill(vz*1e-6);
				hV_decay->Fill(sqrt(vx*vx+vy*vy+vz*vz)*1e-6);

				NofReflection->Fill(IsReflected);

				if( IsReflected >= 1  ){

					hX1D_reflected->Fill(x);
					hY1D_reflected->Fill(y);
					hZ1D_reflected->Fill(z);
					//hCosTheta1D_reflected->Fill( cos(theta_reflected) );
					//hZT2D_reflected->Fill(Z_reflected,t);
					hZY2D_reflected->Fill(z,y);
					hZX2D_reflected->Fill(z,x);
					hXY2D_reflected->Fill(x,y);

					hVX1D_reflected->Fill(vx*1e-6);
					hVY1D_reflected->Fill(vy*1e-6);
					hVZ1D_reflected->Fill(vz*1e-6);
					hV_reflected->Fill(sqrt(vx*vx+vy*vy+vz*vz)*1e-6);

				}

				if( IsReflected == 1  ){

					hX1D_reflectedOnce->Fill(x);
					hY1D_reflectedOnce->Fill(y);
					hZ1D_reflectedOnce->Fill(z);
					//hCosTheta1D_reflectedOnce->Fill( cos(theta_reflectedOnce) );
					//hZT2D_reflectedOnce->Fill(Z_reflectedOnce,t);
					hZY2D_reflectedOnce->Fill(z,y);
					hZX2D_reflectedOnce->Fill(z,x);
					hXY2D_reflectedOnce->Fill(x,y);

					hVX1D_reflectedOnce->Fill(vx*1e-6);
					hVY1D_reflectedOnce->Fill(vy*1e-6);
					hVZ1D_reflectedOnce->Fill(vz*1e-6);
					hV_reflectedOnce->Fill(sqrt(vx*vx+vy*vy+vz*vz)*1e-6);

				}

			}

			if( InsideAerogel ( x, y, z, MCtype ) && ! InsideAerogel ( prev_x, prev_y, prev_z, MCtype ) ){

				ReflectionModel(
					x,y,z,t,
					vx,vy,vz,
					(delT - (Tstep*j)), MCtype );

				j = j + (t-prev_t)/Tstep -1;

				if(N_track_event>0 && N_track_event == i)
				for(int k = 0; k<ReflectionVertexX->size() ;k++)
				g_track_reflection->SetPoint(
					g_track_reflection->GetN(),
					ReflectionVertexZ->at(k),ReflectionVertexY->at(k)
				);

				IsReflected++;

				if( //(z>0.5 && z<24.5) &&
					InsideAerogel(x,y,z,MCtype) && abs(delT-Tstep*j)<Tstep ){
					NofReflectionAndFailed->Fill(IsReflected);
					NofReflection->Fill(IsReflected);
				}

				if( //(z>0.5 && z<24.5) &&
					!InsideAerogel(x,y,z,MCtype) && abs(delT-Tstep*j)<Tstep ){
					NofReflection->Fill(IsReflected);
				}

				//cout<<i<<endl;
			}

			prev_x = x;
			prev_y = y;
			prev_z = z;
			prev_t = t;

		} // event time loop


		if(IsReflected==0)continue;
		//

		hX1D_sf->Fill(X_sf);
		hY1D_sf->Fill(Y_sf);
		hZ1D_sf->Fill(Z_sf);
		hCosTheta1D_sf->Fill( VY_sf/sqrt(VX_sf*VX_sf+VY_sf*VY_sf+VZ_sf*VZ_sf) );

		hZT2D_sf->Fill(Z_sf,t);
		hZY2D_sf->Fill(Z_sf,Y_sf);
		hZX2D_sf->Fill(Z_sf,X_sf);
		hXY2D_sf->Fill(X_sf,Y_sf);

		hVX1D_sf->Fill(VX_sf*1e-6);//mm/us
		hVY1D_sf->Fill(VY_sf*1e-6);
		hVZ1D_sf->Fill(VZ_sf*1e-6);
		hV_sf->Fill(sqrt(VX_sf*VX_sf+VY_sf*VY_sf+VZ_sf*VZ_sf)*1e-6);



	}

	int c_i = 0;
/*
	hT->Draw("");
	c1->cd(2);
	hZY2D_sf->Draw("colz");
	c1->cd(3);
	hY1D_decay->Draw();
	c1->cd(4);
	hZY2D_decay->Draw("colz");
*/

	c1->cd(++c_i);hX1D_sf->Draw();TH1Style1(hX1D_sf);
	c1->cd(++c_i);hY1D_sf->Draw();TH1Style1(hY1D_sf);
	c1->cd(++c_i);hZ1D_sf->Draw();TH1Style1(hZ1D_sf);
	c1->cd(++c_i);hCosTheta1D_sf->Draw();TH1Style1(hCosTheta1D_sf);
	c1->cd(++c_i);hVX1D_sf->Draw();TH1Style1(hVX1D_sf);
	c1->cd(++c_i);hVY1D_sf->Draw();TH1Style1(hVY1D_sf);
	c1->cd(++c_i);hVZ1D_sf->Draw();TH1Style1(hVZ1D_sf);
	c1->cd(++c_i);hV_sf->Draw();TH1Style1(hV_sf);
	c1->cd(++c_i);hZT2D_sf->Draw("colz");TH2Style(hZT2D_sf);
	c1->cd(++c_i);hZY2D_sf->Draw("colz");TH2Style(hZY2D_sf);
	c1->cd(++c_i);hZX2D_sf->Draw("colz");TH2Style(hZX2D_sf);
	c1->cd(++c_i);hXY2D_sf->Draw("colz");TH2Style(hXY2D_sf);

	c_i = 0;


	c2->cd(++c_i);//hX1D_decay->GetYaxis()->SetRangeUser(0,800);
	hX1D_decay->Draw();hX1D_reflected->Draw("same");TH1Style1(hX1D_reflected,2);hX1D_reflectedOnce->Draw("same");TH1Style1(hX1D_reflectedOnce,4);
	c2->cd(++c_i);hY1D_decay->Draw();hY1D_reflected->Draw("same");TH1Style1(hY1D_reflected,2);hY1D_reflectedOnce->Draw("same");TH1Style1(hY1D_reflectedOnce,4);
	c2->cd(++c_i);hZ1D_decay->Draw();hZ1D_reflected->Draw("same");TH1Style1(hZ1D_reflected,2);hZ1D_reflectedOnce->Draw("same");TH1Style1(hZ1D_reflectedOnce,4);


	c2->cd(++c_i);hX1D_reflected->Draw();//TH1Style1(hX1D_reflected,2);
	c2->cd(++c_i);hY1D_reflected->Draw();//TH1Style1(hY1D_reflected,2);
	c2->cd(++c_i);hZ1D_reflected->Draw();//TH1Style1(hZ1D_reflected,2);

	c2->cd(++c_i);hX1D_reflectedOnce->Draw();
	c2->cd(++c_i);hY1D_reflectedOnce->Draw();
	c2->cd(++c_i);hZ1D_reflectedOnce->Draw();

	c_i = 0;

	NofReflectionGrtT1 = (TH1D*)NofReflection->Clone();
	NofReflectionGrtT1->SetBinContent(1,0);

	c3->cd(++c_i);NofReflection->Draw();TH1Style1(NofReflection);
			NofReflectionGrtT1->Draw("same");TH1Style1(NofReflectionGrtT1);
			NofReflectionGrtT1->SetFillColor(1);
			NofReflectionGrtT1->SetFillStyle(3003);
			NofReflectionAndFailed->Draw("same");

	c3->cd(++c_i);
	//NofReflectionGrtT1->Draw();
	TH1Style1(NofReflectionAndFailed,3);
	NofReflectionAndFailed->SetFillColor(3);
	NofReflectionAndFailed->SetFillStyle(3003);
	NofReflectionAndFailed->Draw();


	c_i = 0;

	//c4->cd(++c_i);hT->Draw();TH1Style1(hT);
	c4->cd(++c_i);hX1D_decay->Draw();TH1Style1(hX1D_decay);
	c4->cd(++c_i);hY1D_decay->Draw();TH1Style1(hY1D_decay);
	c4->cd(++c_i);hZ1D_decay->Draw();TH1Style1(hZ1D_decay);
	//c4->cd(++c_i);hVX1D_decay->Draw();TH1Style1(hVX1D_decay);
	//c4->cd(++c_i);hVY1D_decay->Draw();TH1Style1(hVY1D_decay);
	//c4->cd(++c_i);hVZ1D_decay->Draw();TH1Style1(hVZ1D_decay);
	//c4->cd(++c_i);hV_decay->Draw();TH1Style1(hV_decay);
	c4->cd(++c_i);hXY2D_decay->Draw("colz");TH2Style(hXY2D_decay);
	c4->cd(++c_i);hZY2D_decay->Draw("colz");TH2Style(hZY2D_decay);
	g_track_reflection->Draw("samePL");
	c4->cd(++c_i);hZX2D_decay->Draw("colz");TH2Style(hZX2D_decay);


	c_i = 0;

	c5->cd(++c_i);hT->Draw();TH1Style1(hT);
	c5->cd(++c_i);hX1D_decay->Draw();TH1Style1(hX1D_decay);
	c5->cd(++c_i);hY1D_decay->Draw();TH1Style1(hY1D_decay);
	c5->cd(++c_i);hZ1D_decay->Draw();TH1Style1(hZ1D_decay);
	c5->cd(++c_i);hVX1D_decay->Draw();TH1Style1(hVX1D_decay);
	c5->cd(++c_i);hVY1D_decay->Draw();TH1Style1(hVY1D_decay);
	c5->cd(++c_i);hVZ1D_decay->Draw();TH1Style1(hVZ1D_decay);
	c5->cd(++c_i);hV_decay->Draw();TH1Style1(hV_decay);
	c5->cd(++c_i);hZY2D_decay->Draw("colz");TH2Style(hZY2D_decay);
	g_track_reflection->Draw("samePL");
	c5->cd(++c_i);hZX2D_decay->Draw("colz");TH2Style(hZX2D_decay);
	c5->cd(++c_i);hXY2D_decay->Draw("colz");TH2Style(hXY2D_decay);

/*
	for(int i = 0;i<80;i++){
		TCanvas * c6=NewTCanvas("c6","c6",700,500);
		hZY2D_sf->Draw("colz");
		hZY2D_dyn[i]->Draw("same");
		c6->SaveAs(Form("dyn/Z_Y_2D_dyn_%d.png",i) ); //= new TH2D(Form("Z-Y-2D-dyn-%d",i),Form("Z-Y-2D-dyn-%d;Z(mm);Y (mm)",i),100,-5,30,100,-15,15);
	}
*/

	//hZY2D_dyn[0]->Draw("colz");

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
