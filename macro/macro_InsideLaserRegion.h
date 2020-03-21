
bool InsideLaserRegionTDR(double x, double y, double z){ // t = t0 + tbeam

	//if( (fabs(x)>20 || fabs(y)>20) )return false;

	if( z <= 6 && z>= 1 && y<20 && y>-20 && x<20 && x>-20)return true;
	//if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
	return false;
}
bool InsideLaserRegionTDRnoXlimit(double x, double y, double z){ // t = t0 + tbeam

	//if( (fabs(x)>20 || fabs(y)>20) )return false;

	if( z <= 6 && z>= 1 && y<20 && y>-20 )return true;
	//if( z >= (-6-Thick) && z <= (-1-Thick) && flag_newGeo == 1)return true;
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


bool InsideLaserRegionNewGeo_8mmSHIFTED(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	//if( z>=1 && z<=6){
	if( z>=1 && z<=(Thick+1)){  /// _3.png

		if(y < 11 && y > 5) return true;
		if(y < -5 && y > -11) return true;

	}

	if( z>=(Thick+1) && z <=(Thick+6) )return true;  //// _2.png

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


bool InsideLaserRegionNewGeo_yannis(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;
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

 	if( z<(Thick+1) && z>1 && y < 3 && y > -3) return true;
 	if( z<(2*Thick+1) && z>(Thick+1) && y < 11 && y > -11) return true;
 	if( z<(3*Thick+1) && z>(2*Thick+1) && y < 19 && y > -19) return true;
 	if( z<(3*Thick+6) && z>(3*Thick+1) ) return true;

	return false;

}


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