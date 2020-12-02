#ifndef __INSIDELASERREGION_H__
#define __INSIDELASERREGION_H__

void TRIUMFVacuumRegion(TTree * tree, TCanvas * c = NewTCanvas("c_intrnl","c_intrnl",1000,1000,2,2) )
{
	c->cd(1);
	tree->Draw("DecayT","DecayZ<40 && DecayZ>-8");
	c->cd(2);
	tree->Draw("DecayT","DecayZ<20 && DecayZ>10");
	c->cd(3);
	tree->Draw("DecayT","DecayZ<30 && DecayZ>20");
	c->cd(4);
	tree->Draw("DecayT","DecayZ<40 && DecayZ>30");


}

bool InsideLaserRegion(double x, double y, double z, int MCtype){

	double Thick = 25;

	switch(MCtype){

		case 1001:
			if( z <= 6 && z>= 1 && y<20 && y>-20 && x<20 && x>-20)return true;
			return false;

		case 1002:
			if( z <= 6 && z>= 1 )return true;
			return false;

		case  2001:

			if( z <= 6 && z>= 1 && y<20 && y>-20 )return true;
			if( z <= 21 && z>= 16 && y<20 && y>-20 )return true;

			return false;


		case 3006:
			Thick = 25;
			if( z>=1 && z<=(Thick+1)){  /// _3.png

				if(y < 19 && y > 13) return true;
				if(y < 3 && y > -3) return true;
				if(y < -13 && y > -19) return true;
			}
			return false;


		case 3003:

			Thick = 7.12;

			if( z>=1 && z<=(Thick+1)){  /// _3.png
				if(y < 11 && y > 5) return true;
				if(y < -5 && y > -11) return true;
			}

			return false;



		case 3004:

			Thick = 14;

			if( z>=1 && z<=(Thick+1)){  /// _3.png
				if(y < 11 && y > 5) return true;
				if(y < -5 && y > -11) return true;
			}

			return false;

		case 3002:

			Thick = 25;

			if( z>=1 && z<=(Thick+1)){  /// _3.png
				if(y < 11 && y > 5) return true;
				if(y < -5 && y > -11) return true;
			}

			return false;

		case 3005:

			Thick = 25;

			if( z>=1 && z<=(Thick+1)){  /// _3.png
				if(y < 11 && y > 5) return true;
				if(y < -5 && y > -11) return true;
			}

			return false;

		case 3012:

			Thick = 25;
			if( z>=1 && z<=(Thick+1)){

				if(y < 17 && y > 15) return true;
				if(y < 9 && y > 7) return true;
				if(y < 1 && y > -1) return true;
				if(y < -7 && y > -9) return true;
				if(y < -15 && y > -17) return true;

			}
			return false;


		case 3011:

			Thick = 25;

			if( z>=1 && z<=(Thick+1)){

				if(y < 13 && y > 11) return true;
				if(y < 5 && y > 3) return true;
				if(y < -3 && y > -5) return true;
				if(y < -11 && y > -13) return true;
			}

			return false;

		case 4001:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -0.5 && y < 0.5)return true;
			}

			return false;

		case 4002:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -1 && y < 1)return true;
			}

			return false;
		case 4003:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -1.5 && y < 1.5)return true;
			}

			return false;
		case 4004:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -2 && y < 2)return true;
			}

			return false;
		case 4005:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -2.5 && y < 2.5)return true;
			}

			return false;
		case 4006:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -3 && y < 3)return true;
			}

			return false;
		case 4007:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -3.5 && y < 3.5)return true;
			}

			return false;
		case 4008:

			Thick =  25;

			if( z>0 && z<Thick){
				if(y > -4 && y < 4)return true;
			}

			return false;
		case 3021:

			Thick = 25;
			if( z>=0 && z<=(Thick+1)){

				if(y < 13 && y > 11) return true;
				if(y < 5 && y > 3) return true;
				if(y < -3 && y > -5) return true;
				if(y < -11 && y > -13) return true;
			}

			return false;

		default:
			if( z <= 6 && z>= 1 && y<20 && y>-20 && x<20 && x>-20)return true;
			return false;



	}
}

/*
// Type 1001
bool InsideLaserRegionTDR(double x, double y, double z){ // t = t0 + tbeam

	//if( (fabs(x)>20 || fabs(y)>20) )return false;

	if( z <= 6 && z>= 1 && y<20 && y>-20 && x<20 && x>-20)return true;
	//if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
	return false;
}

bool InsideLaserRegionTDRnoXlimit(double x, double y, double z){ // t = t0 + tbeam

	//if( (fabs(x)>20 || fabs(y)>20) )return false;

	//if( z <= 6 && z>= 1 && y<20 && y>-20 )return true;
	if( z <= 6 && z>= 1 )return true;
	//if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
	return false;
}

bool InsideLaserRegion_2001(double x, double y, double z){ // t = t0 + tbeam


	if( z <= 6 && z>= 1 && y<20 && y>-20 )return true;
	if( z <= 21 && z>= 16 && y<20 && y>-20 )return true;

	return false;
}


bool InsideLaserRegionNewGeo_8mm(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){ /// _1.png
	if( z>=1 && z<=(Thick+1)){  /// _3.png


		if(y < 19 && y > 13) return true;
		if(y < 3 && y > -3) return true;
		if(y < -13 && y > -19) return true;

		//if(y < 20 && y > 12) return true;
		//if(y < 4 && y > -4) return true;
		//if(y < -12 && y > -20) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}

//3006
bool InsideLaserRegion_3006(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 25;


	if( z>=1 && z<=(Thick+1)){  /// _3.png

		if(y < 19 && y > 13) return true;
		if(y < 3 && y > -3) return true;
		if(y < -13 && y > -19) return true;

	}

//	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}



// 3003
bool InsideLaserRegionNewGeo_8mmSHIFTED(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){  /// _3.png

		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;

	}

	//if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}

bool InsideLaserRegion_3003(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	if( z>=1 && z<=(Thick+1)){  /// _3.png
		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;
	}

	return false;

}


bool InsideLaserRegion_3004(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 14;

	if( z>=1 && z<=(Thick+1)){  /// _3.png
		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;
	}

	return false;

}


bool InsideLaserRegion_3002(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 25;

	if( z>=1 && z<=(Thick+1)){  /// _3.png
		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;
	}

	return false;

}

bool InsideLaserRegion_3005(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 25;

	if( z>=1 && z<=(Thick+1)){  /// _3.png
		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;
	}

	return false;

}

bool InsideLaserRegionNewGeo_4mm(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){


		//if(y < 10 && y > 6) return true;
		//if(y < 2 && y > -2) return true;
		//if(y < -6 && y > -10) return true;

		if(y < 9 && y > 7) return true;
		if(y < 1 && y > -1) return true;
		if(y < -7 && y > -9) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;

	return false;

}

*/

//bool InsideLaserRegionNewGeo_yannis(double x, double y, double z){ // t = t0 + tbeam

//	double Thick = 7.12;
/*
	if( z>0 && z<Thick){
		//if(y < 10 && y > 6) return true;
		if(y < 2 && y > -2) return true;
		//if(y < -6 && y > -10) return true;
	}
	if( z>Thick && z<2*Thick){
		if(y < 6 && y > 2) return true;
		//if(y < 2 && y > -2) return true;
		if(y < -2 && y > -6) return true;
	}
	if( z>0 && z<Thick){
		//if(y < 10 && y > 6) return true;
		if(y < 2 && y > -2) return true;
		//if(y < -6 && y > -10) return true;
	}
*/

 	//if( z<6 && z>1 && y < 3 && y > -3) return true;
 	//if( z<(Thick+6) && z>(Thick+1) && y < 11 && y > -11) return true;
 	//if( z<(2*Thick+6) && z>(2*Thick+1) && y < 19 && y > -19) return true;
 	//if( z<(3*Thick+6) && z>(3*Thick+1) ) return true;

// 	if( z<(Thick+1) && z>1 && y < 3 && y > -3) return true;
// 	if( z<(2*Thick+1) && z>(Thick+1) && y < 11 && y > -11) return true;
// 	if( z<(3*Thick+1) && z>(2*Thick+1) && y < 19 && y > -19) return true;
// 	if( z<(3*Thick+6) && z>(3*Thick+1) ) return true;
//
//	return false;
//
//}

/*
bool InsideLaserRegionNewGeo_7_4mm(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){

		if(y < 25 && y > 23) return true;
		if(y < 17 && y > 15) return true;
		if(y < 9 && y > 7) return true;
		if(y < 1 && y > -1) return true;
		if(y < -7 && y > -9) return true;
		if(y < -15 && y > -17) return true;
		if(y < -23 && y > -25) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;

	return false;

}

bool InsideLaserRegion_3012(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 25;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){

	//	if(y < 25 && y > 23) return true;
		if(y < 17 && y > 15) return true;
		if(y < 9 && y > 7) return true;
		if(y < 1 && y > -1) return true;
		if(y < -7 && y > -9) return true;
		if(y < -15 && y > -17) return true;
	//	if(y < -23 && y > -25) return true;

	}

	//if( z>=(Thick+1) && z <=(Thick+6) )return true;

	return false;

}


bool InsideLaserRegionNewGeo_7_4mmSHIFTED(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){

		if(y < 21 && y > 19) return true;
		if(y < 13 && y > 11) return true;
		if(y < 5 && y > 3) return true;
		//if(y < 1 && y > -1) return true;
		if(y < -3 && y > -5) return true;
		if(y < -11 && y > -13) return true;
		if(y < -19 && y > -21) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;

	return false;

}


bool InsideLaserRegion_3011(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 25;

	if( z>=1 && z<=(Thick+1)){

		if(y < 13 && y > 11) return true;
		if(y < 5 && y > 3) return true;
		if(y < -3 && y > -5) return true;
		if(y < -11 && y > -13) return true;

	}

	return false;

}

bool InsideLaserRegionNewGeo_8mm_10mmthick(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 10;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){ /// _1.png
	if( z>=1 && z<=(Thick+1)){  /// _3.png


		if(y < 19 && y > 13) return true;
		if(y < 3 && y > -3) return true;
		if(y < -13 && y > -19) return true;

		//if(y < 20 && y > 12) return true;
		//if(y < 4 && y > -4) return true;
		//if(y < -12 && y > -20) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}


bool InsideLaserRegionNewGeo_8mm_14mmthick(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 14;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){ /// _1.png
	if( z>=1 && z<=(Thick+1)){  /// _3.png


		if(y < 19 && y > 13) return true;
		if(y < 3 && y > -3) return true;
		if(y < -13 && y > -19) return true;

		//if(y < 20 && y > 12) return true;
		//if(y < 4 && y > -4) return true;
		//if(y < -12 && y > -20) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}

bool InsideLaserRegionNewGeo_8mm_12mmthick(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 12;

	//if( z>0 && z<Thick){
	//if( z>=1 && z<=6){ /// _1.png
	if( z>=1 && z<=(Thick+1)){  /// _3.png


		if(y < 19 && y > 13) return true;
		if(y < 3 && y > -3) return true;
		if(y < -13 && y > -19) return true;

		//if(y < 20 && y > 12) return true;
		//if(y < 4 && y > -4) return true;
		//if(y < -12 && y > -20) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

	return false;

}
*/

#endif
