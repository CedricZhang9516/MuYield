#include "MuYield.h"

void InitializingXYZ0(int index_m){

	//double* X0, double* Y0, double* Z0

	//beam xy: uniformed or gaussian from tdr
	//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index_m+xStep/2;
	//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;


	/////// My own MC
	if(MCtype == 1){

		Z0 = - ((double) rand() / (RAND_MAX)) * Thick;    // z0=-0.0~-7.12mm
		X0 = GenerateGaus(0,31.96);//
		Y0 = GenerateGaus(0,14.36);//2mm
		//y0 = GenerateHlineY(hY0tgt_hline);//only for test

		///NEW GEOMETRY here!!!!
		//tempZ = ((double) rand() / (RAND_MAX));
		//if( tempZ <=(1.0/3) )Z0 = Z0 + (7+Thick) ;
		//if( tempZ >=(2.0/3) )Z0 = Z0 - (7+Thick) ;
	}

	//if(flag_newGeo == 1 && fabs(Y0)>20)continue;

	// for TRIUMF case z
	if(MCtype == 2){
		X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index_m+xStep/2;
		Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
		Z0 = GenerateGaus(0,1.69);//2mm
		if( Z0 > 0) Z0 = - Z0;
	}

	////// H-line
	if(MCtype == 3){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	///////// S-line
	if(MCtype == 4){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	// MCType = 5; New Geometry inspired by Uetake-san and Mibe-san

	if(MCtype == 5){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		//cout<<X0<<" "<<Y0<<" "<<Z0<<endl;

		if(Y0 < 28 && Y0 > 20)Z0 = Z0 + Thick;
		//if(Y0 < 20 && Y0 > 12) Z0 = Z0 + Thick;
		if(Y0 < 12 && Y0 > 4)Z0 = Z0 + Thick;
		//if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		if(Y0 < -4 && Y0 > -12)Z0 = Z0 + Thick;
		//if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		if(Y0 < -20 && Y0 > -28)Z0 = Z0 + Thick;
		//cout<<X0<<" "<<Y0<<" "<<Z0<<endl;
	}


	if(MCtype == 6){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 14 && Y0 > 10)Z0 = Z0 + Thick;
		//if(Y0 < 10 && Y0 > 6) Z0 = Z0 + Thick;
		if(Y0 < 6 && Y0 > 2)Z0 = Z0 + Thick;
		//if(Y0 < 2 && Y0 > -2) Z0 = Z0 + Thick;
		if(Y0 < -2 && Y0 > -6)Z0 = Z0 + Thick;
		//if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		if(Y0 < -10 && Y0 > -14)Z0 = Z0 + Thick;
	}

	if(MCtype == 7){ //Yannis
 		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 28 && Y0 > 20)Z0 = Z0 + 3*Thick;
		if(Y0 < 20 && Y0 > 12) Z0 = Z0 + 2*Thick;
		if(Y0 < 12 && Y0 > 4)Z0 = Z0 + Thick;
		//if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		if(Y0 < -4 && Y0 > -12)Z0 = Z0 + Thick;
		if(Y0 < -12 && Y0 > -20)Z0 = Z0 + 2*Thick;
		if(Y0 < -20 && Y0 > -28)Z0 = Z0 + 3*Thick;
	}

	if(MCtype == 8){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 30 && Y0 > 26)Z0 = Z0 + Thick;
		if(Y0 < 22 && Y0 > 18)Z0 = Z0 + Thick;
		if(Y0 < 14 && Y0 > 10)Z0 = Z0 + Thick;
		//if(Y0 < 10 && Y0 > 6) Z0 = Z0 + Thick;
		if(Y0 < 6 && Y0 > 2)Z0 = Z0 + Thick;
		//if(Y0 < 2 && Y0 > -2) Z0 = Z0 + Thick;
		if(Y0 < -2 && Y0 > -6)Z0 = Z0 + Thick;
		//if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		if(Y0 < -10 && Y0 > -14)Z0 = Z0 + Thick;
		if(Y0 < -18 && Y0 > -22)Z0 = Z0 + Thick;
		if(Y0 < -26 && Y0 > -30)Z0 = Z0 + Thick;
	}

	if(MCtype == 9){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		//if(Y0 < 28 && Y0 > 20)Z0 = Z0 + Thick;
		if(Y0 < 20 && Y0 > 12) Z0 = Z0 + Thick;
		//if(Y0 < 12 && Y0 > 4)Z0 = Z0 + Thick;
		if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		//if(Y0 < -4 && Y0 > -12)Z0 = Z0 + Thick;
		if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		//if(Y0 < -20 && Y0 > -28)Z0 = Z0 + Thick;
	}


	if(MCtype == 10){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 26 && Y0 > 22)Z0 = Z0 + Thick;
		if(Y0 < 18 && Y0 > 14)Z0 = Z0 + Thick;
		if(Y0 < 10 && Y0 > 6) Z0 = Z0 + Thick;
		//if(Y0 < 6 && Y0 > 2)Z0 = Z0 + Thick;
		if(Y0 < 2 && Y0 > -2) Z0 = Z0 + Thick;
		//if(Y0 < -2 && Y0 > -6)Z0 = Z0 + Thick;
		if(Y0 < -6 && Y0 > -10) Z0 = Z0 + Thick;
		if(Y0 < -14 && Y0 > -18)Z0 = Z0 + Thick;
		if(Y0 < -22 && Y0 > -26)Z0 = Z0 + Thick;
		//if(Y0 < -22 && Y0 > -30)Z0 = Z0 + Thick;
	}

	if(MCtype == 11){
		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Y0 < 28 && Y0 > 20)Z0 = Z0 + Thick;
		//if(Y0 < 20 && Y0 > 12) Z0 = Z0 + Thick;
		if(Y0 < 12 && Y0 > 4)Z0 = Z0 + Thick;
		//if(Y0 < 4 && Y0 > -4) Z0 = Z0 + Thick;
		if(Y0 < -4 && Y0 > -12)Z0 = Z0 + Thick;
		//if(Y0 < -12 && Y0 > -20) Z0 = Z0 + Thick;
		if(Y0 < -20 && Y0 > -28)Z0 = Z0 + Thick;
	}

	if(MCtype == 12){

		double interval = 10;

		InputTree->GetEntry(index_m);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Z0 < 28 && Z0 > 20)Z0 = Z0 + Thick + interval;
		//if(Z0 < 20 && Z0 > 12) Z0 = Z0 + Thick;
		if(Z0 < 12 && Z0 > 4)Z0 = Z0 + Thick + interval;
		//if(Z0 < 4 && Z0 > -4) Z0 = Z0 + Thick;
		if(Z0 < -4 && Z0 > -12)Z0 = Z0 + Thick + interval;
		//if(Z0 < -12 && Z0 > -20) Z0 = Z0 + Thick;
		if(Z0 < -20 && Z0 > -28)Z0 = Z0 + Thick + interval;
	}





}