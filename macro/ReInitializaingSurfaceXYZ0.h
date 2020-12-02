void ReInitializaingSurfaceXYZ0(
	double &x, double &y, double &z,int MCtype){

	//this is only used for reflection study and input should only be 3012 surface!

	double Thick =  7.12;

	double X  = x;
	double Y  = y;
	double Z  = z;

	switch(MCtype){

		// 1001: TDR fig reproduction
		case 4001:

			if(Y < 7 && Y > 0) Y = Y-1.5;
			if(Y < 0 && Y > -7) Y = Y+1.5;
			break;

		case 4002:

			if(Y < 7 && Y > 0) Y = Y-1;
			if(Y < 0 && Y > -7) Y = Y+1;
			break;

		case 4003:

			if(Y < 7 && Y > 0) Y = Y-0.5;
			if(Y < 0 && Y > -7) Y = Y+0.5;
			break;

		case 4004:

			if(Y < 7 && Y > 0) Y = Y-0;
			if(Y < 0 && Y > -7) Y = Y+0;
			break;

		case 4005:

			if(Y < 7 && Y > 0) Y = Y+0.5;
			if(Y < 0 && Y > -7) Y = Y-0.5;
			break;

		case 4006:

			if(Y < 7 && Y > 0) Y = Y+1.0;
			if(Y < 0 && Y > -7) Y = Y-1.0;
			break;

		case 4007:

			if(Y < 7 && Y > 0) Y = Y+1.5;
			if(Y < 0 && Y > -7) Y = Y-1.5;
			break;

		case 4008:

			if(Y < 7 && Y > 0) Y = Y+2;
			if(Y < 0 && Y > -7) Y = Y-2;
			break;
	}

	x = X;
	y = Y;
	z = Z;



}