
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
bool InsideLaserRegionNewGeo(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	if( z>0 && z<Thick){


		if(y < 20 && y > 12) return true;
		if(y < 4 && y > -4) return true;
		if(y < -12 && y > -20) return true;

	}

	if(z>Thick && z< Thick+3)return true;

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

	if( z>0 && z<Thick){


		if(y < 10 && y > 6) return true;
		if(y < 2 && y > -2) return true;
		if(y < -6 && y > -10) return true;

	}

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

 	if( z<Thick && z>0 && y < 4 && y > -4) return true;
 	if( z<2*Thick && z>Thick && y < 12 && y > -12) return true;
 	if( z<3*Thick && z>2*Thick && y < 20 && y > -20) return true;
 	if( z<(3*Thick+2) && z>3*Thick) return true;

	return false;

}


bool InsideLaserRegionNewGeo_7_4mm(double x, double y, double z){ // t = t0 + tbeam

	double Thick = 7.12;

	if( z>0 && z<Thick){

		if(y < 26 && y > 22) return true;
		if(y < 18 && y > 14) return true;
		if(y < 10 && y > 6) return true;
		if(y < 2 && y > -2) return true;
		if(y < -6 && y > -10) return true;
		if(y < -14 && y > -18) return true;
		if(y < -22 && y > -26) return true;

	}

	if(z>Thick && z< Thick+3)return true;

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

