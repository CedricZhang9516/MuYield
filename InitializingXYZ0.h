#include "MuYield.h"

void InitializingXYZ0(int index){

	//double* X0, double* Y0, double* Z0

	//beam xy: uniformed or gaussian from tdr
	//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index+xStep/2;
	//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;
	double Thick =  7.12;

	switch(MCtype){

		// 1001: TDR fig reproduction
		case 1001:

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
			break;

		case 1002:

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
			break;

		/////// My own MC
		case 1:

			Thick =  7.12;

			Z0 = - ((double) rand() / (RAND_MAX)) * Thick;    // z0=-0.0~-7.12mm
			X0 = GenerateGaus(0,31.96);//
			Y0 = GenerateGaus(0,14.36);//2mm
			break;
			//y0 = GenerateHlineY(hY0tgt_hline);//only for test

			///NEW GEOMETRY here!!!!
			//tempZ = ((double) rand() / (RAND_MAX));
			//if( tempZ <=(1.0/3) )Z0 = Z0 + (7+Thick) ;
			//if( tempZ >=(2.0/3) )Z0 = Z0 - (7+Thick) ;


		//if(flag_newGeo == 1 && fabs(Y0)>20)continue;

		// for TRIUMF case z
		case 2:

			X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index+xStep/2;
			Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
			Z0 = GenerateGaus(0,1.69);//2mm
			if( Z0 > 0) Z0 = - Z0;
			break;

		////// H-line
		case 3:

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
			break;

		///////// S-line
		case 4:

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
			break;

		// MCType = 5; New Geometry inspired by Uetake-san and Mibe-san

		case 5:

			Thick =  25;
			InputTree->GetEntry(index);
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
			break;


		case 6:

			Thick =  25;
			InputTree->GetEntry(index);
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
			break;

		case 7: //Yannis

			Thick =  8;
	 		InputTree->GetEntry(index);
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
		break;

		case 8:
			Thick =  25;
			InputTree->GetEntry(index);
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
			break;

		case 9:
		case 3003:

			Thick =  25;

			InputTree->GetEntry(index);
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
			break;

		case 3004:
		case 3002:

			Thick =  25;

			InputTree->GetEntry(index);
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
			break;


		case 3005:
		case 3006:
		case 3011:
		case 3012:
		case 4001:
		case 4002:
		case 4003:
		case 4005:
		case 4006:
		case 4007:
		case 3021:
		case 3022:
		case 3023:
		case 5001://3012
		case 5002://3012
		case 5003://3012
		case 5004://3012

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;
			break;

		case 10:

			Thick =  25;

			InputTree->GetEntry(index);
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
			break;

		case 11:

			Thick =  25;

			InputTree->GetEntry(index);
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
			break;


		case 12:
		case 2001:


			double interval = 7;
			// Thick = 8;
			Thick =  8;

			InputTree->GetEntry(index);
			X0 = x_dec;
			Y0 = y_dec;
			Z0 = z_dec;

			if(Z0 < 0 && Z0 > -8)Z0 = Z0 + 30;
			if(Z0 < -8 && Z0 > -16)Z0 = Z0 + 23;//2*Thick + interval;
			if(Z0 < -16 && Z0 > -25)Z0 = Z0 + 16;//Z0 + 3*Thick + 2*interval + 9;

			break;
	}

}
/*
	// 1001: TDR fig reproduction
	if(MCtype == 1001){
		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	if(MCtype == 1002){
		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

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
		X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index+xStep/2;
		Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
		Z0 = GenerateGaus(0,1.69);//2mm
		if( Z0 > 0) Z0 = - Z0;
	}

	////// H-line
	if(MCtype == 3){
		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	///////// S-line
	if(MCtype == 4){
		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}

	// MCType = 5; New Geometry inspired by Uetake-san and Mibe-san

	if(MCtype == 5){
		InputTree->GetEntry(index);
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
		InputTree->GetEntry(index);
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
 		InputTree->GetEntry(index);
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
		InputTree->GetEntry(index);
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

	if(MCtype == 9 || MCtype == 3003){
		InputTree->GetEntry(index);
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

	if(MCtype == 3004 || MCtype == 3002){
		InputTree->GetEntry(index);
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


	if(MCtype == 3005 ||
		MCtype == 3011 ||
		MCtype == 3012 ||
		MCtype == 3006
		){
		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;
	}




	if(MCtype == 10){
		InputTree->GetEntry(index);
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
		InputTree->GetEntry(index);
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

	if(MCtype == 12 || MCtype == 2001){ // 2001

		double interval = 7;
		// Thick = 8;

		InputTree->GetEntry(index);
		X0 = x_dec;
		Y0 = y_dec;
		Z0 = z_dec;

		if(Z0 < 0 && Z0 > -8)Z0 = Z0 + 30;
		if(Z0 < -8 && Z0 > -16)Z0 = Z0 + 23;//2*Thick + interval;
		if(Z0 < -16 && Z0 > -25)Z0 = Z0 + 16;//Z0 + 3*Thick + 2*interval + 9;

	}


}
*/