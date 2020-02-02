#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
#include "TPoint.h"

void DiffusionModel(
		double X0, double Y0, double Z0,
		void (*GeometryFunction)(double, double, double),
		std::vector<double> DiffusionVertexX,
		std::vector<double> DiffusionVertexY,
		std::vector<double> DiffusionVertexZ,
		double DiffusionT,
		double X_sf, double Y_sf, double Z_sf,
		double VX_sf, double VY_sf, double VZ_sf,
		double theta_sf, double phi_sf)
	{





//double TPoint* MCLmfp(){

	DiffusionT = 0;

	t = 0;
	z = Z0;
	x = X0;
	y = Y0;
	vx = Vx0;
	vy = Vy0;
	vz = Vz0;
	theta = theta0;
	phi = phi0;

	double L;
	int N = 0; // only for debug

	//static double ResultDiff[9];
	static double DiffusionTrak[2];

	do{

		//if(flag_DiffusionTrack==1){DiffusionTrack->SetPoint(N,z,y);}//cout<<"filling track"<<N<<endl;}

		// generate the L step lenth according to Lmfp exp. distri.
		do {
			tempX = ((double) rand() / (RAND_MAX)) * 5;  // l=0~0.01 mm
			tempY = ((double) rand() / (RAND_MAX)) * 1/Lmfp;
		} while (tempY>1/Lmfp*exp(-tempX/Lmfp) );

		L = tempX;

		t = t + L/vel0;
		x = x + vx * (L/vel0);
		y = y + vy * (L/vel0);
		z = z + vz * (L/vel0);

		if( (z <= 0 && z >= -Thick) || (z <= -9 && z >= -11) || (z <= 9 && z >= 7) )//(z <= 14.12 && z >= 7) )//(z <= -9 && z >= -11) || (z <= 9 && z >= 7) )
		{

			tempX = TMath::ACos(-1 + 2 * ((double)rand()/(RAND_MAX)) );
			tempY = ((double) rand()/(RAND_MAX)) * 2* PI;

			theta = tempX;  // [0,+PI] radians
			phi = tempY; //[0,+2PI] radians

			vx = vel0 * sin(theta) * cos(phi);
			vy = vel0 * sin(theta) * sin(phi);
			vz = vel0 * cos(theta);
		}
		N++;

	}while( (z <= 0 && z >= -Thick && t<DecayT)
		|| (z <= -9 && z >= -11 && t<DecayT)
		|| (z <= 9 && z >= 7 && t<DecayT)
		);

	if( MCtype != 2 && (fabs(y)>130 || fabs(x)>130) ) t = 100000;

	Nhits = N;

	if(t>DecayT)t = t - L/vel0;

	ResultDiff[0] = t;
	ResultDiff[1] = x;
	ResultDiff[2] = y;
	ResultDiff[3] = z;
	ResultDiff[4] = vx;
	ResultDiff[5] = vy;
	ResultDiff[6] = vz;
	ResultDiff[7] = theta;
	ResultDiff[8] = phi;
	return ResultDiff;
}