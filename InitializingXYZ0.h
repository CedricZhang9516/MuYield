void InitializingXYZ0(
	int index_m,
	double X0, double Y0, double Z0 ){


	Thlinefile->GetEntry(index_m);
		//if (N_DiffusionTrack == index_m) flag_DiffusionTrack = 1;
		//else flag_DiffusionTrack = 0;

		if( MCtype == 3 && (z_dec>0 || z_dec<-Thick) ) continue;


		//for triumf
		if(MCtype == 2) TBeam = 0;
		if(MCtype == 1 || MCtype == 3){
			TBeam = GenerateUniform(0.0e-6,0.2e-6);
			if( ((double) rand() / (RAND_MAX))<=0.5 )TBeam = TBeam + 0.6e-6;
		}

		T0->Fill(TBeam);

		//beam xy: uniformed or gaussian from tdr
		//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index_m+xStep/2;
		//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;

		if(MCtype == 1){

			Z0 = - ((double) rand() / (RAND_MAX)) * Thick;    // z0=-0.0~-7.12mm
			X0 = GenerateGaus(0,31.96);//
			Y0 = GenerateGaus(0,14.36);//2mm
			//y0 = GenerateHlineY(hY0tgt_hline);//only for test
			tempZ = ((double) rand() / (RAND_MAX));
			//if( tempZ <=(1.0/2) )Z0 = Z0 + (7+Thick) ;
			if( tempZ <=(1.0/3) )Z0 = Z0 + (7+Thick) ;
			if( tempZ >=(2.0/3) )Z0 = Z0 - (7+Thick) ;
		}
		//if(flag_newGeo == 1 && fabs(Y0)>20)continue;
		if( fabs(Y0)>20)continue;
		// for triumf case z
		if(MCtype == 2){
			X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index_m+xStep/2;
			Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
			Z0 = GenerateGaus(0,1.69);//2mm
			if(Z0>0)Z0 = -Z0;
		}

		if(MCtype == 3){
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
		}

		hZ0tgt->Fill(Z0);
		hX0tgt->Fill(X0);
		hY0tgt->Fill(Y0);

}