void InitializingXYZ0(
	int MCtype,
	double* X0, double* Y0, double* Z0 ){

	//beam xy: uniformed or gaussian from tdr
	//x0=((double) rand() / (RAND_MAX))*40;//0-20mm;index_m+xStep/2;
	//y0=((double) rand() / (RAND_MAX))*40;//0-20mm;

	if(MCtype == 1){

		* Z0 = - ((double) rand() / (RAND_MAX)) * Thick;    // z0=-0.0~-7.12mm
		* X0 = GenerateGaus(0,31.96);//
		* Y0 = GenerateGaus(0,14.36);//2mm
		//y0 = GenerateHlineY(hY0tgt_hline);//only for test

		///NEW GEOMETRY here!!!!
		//tempZ = ((double) rand() / (RAND_MAX));
		//if( tempZ <=(1.0/3) )Z0 = Z0 + (7+Thick) ;
		//if( tempZ >=(2.0/3) )Z0 = Z0 - (7+Thick) ;
	}

	//if(flag_newGeo == 1 && fabs(Y0)>20)continue;
	// for triumf case z
	if(MCtype == 2){
		* X0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;index_m+xStep/2;
		* Y0 = -5 + ((double) rand() / (RAND_MAX))*10;//0-20mm;
		* Z0 = GenerateGaus(0,1.69);//2mm
		if( *Z0 > 0) *Z0 = - *Z0;
	}


}