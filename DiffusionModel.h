//#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
//#include "../CZhang/CZhang.cxx"
#include "TPoint.h"
#include "MuYield.h"

void DiffusionModel(
		//double* X0, double* Y0, double* Z0,
		//double Vx0, double Vy0, double Vz0, double theta0, double phi0,
		bool (*GeometryFunction)(double, double, double))
		//std::vector<double>* DiffusionVertexX,
		//std::vector<double>* DiffusionVertexY,
		//std::vector<double>* DiffusionVertexZ,
		//std::vector<double>* DiffusionVertexT)
		//double DecayT, double Thick,
		//double* DiffusionT,
		//double* X_sf, double* Y_sf, double* Z_sf,
		//double* VX_sf, double* VY_sf, double* VZ_sf,
		//double* theta_sf, double* phi_sf
	{

	//double TPoint* MCLmfp(){

	//* DiffusionT = 0;



	double t = 0;
	double z  = Z0;
	double x  = X0;
	double y  = Y0;
	double vx = Vx0;
	double vy = Vy0;
	double vz = Vz0;

	double theta = theta0;
	double phi = phi0;

	double L = 0;
	int N = 0; // only for debug



	do{

		//if(flag_DiffusionTrack==1){DiffusionTrack->SetPoint(N,z,y);}//cout<<"filling track"<<N<<endl;}

		// generate the L step lenth according to Lmfp exp. distri.
		do {
			tempX = ((double) rand() / (RAND_MAX)) * 5;  // l=0~0.01 mm
			tempY = ((double) rand() / (RAND_MAX)) * 1/Lmfp;
		} while (tempY>1/Lmfp*exp(-tempX/Lmfp) );

		L = tempX;

		//cout<<"L "<<L<<endl;
		//cout<<"vel0 "<<vel0<<"mm/s"<<endl;

		t = t + L/vel0;
		x = x + vx * (L/vel0);
		y = y + vy * (L/vel0);
		z = z + vz * (L/vel0);

		if( GeometryFunction(x, y, z) && (t < DecayT))
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

		DiffusionVertexX->push_back(x);
		DiffusionVertexY->push_back(y);
		DiffusionVertexZ->push_back(z);
		DiffusionVertexT->push_back(t);

		//cout<<DiffusionVertexX->size()<<endl;
		//cout<<"t "<<t<<" DecayT:"<<DecayT<<endl;


	}while(GeometryFunction(x,y,z) && (t < DecayT));


	//if( MCtype != 2 && (fabs(y)>130 || fabs(x)>130) ) t = 100000;

	double Nhits = N;

	//if(N!=1)cout<<"event "<<Index_M<<" N in the diffusion "<<N<<endl;

	if(t>DecayT){
		//cout<<Index_M<<" "<<DecayT<<endl;
		t = DecayT;
	}// t - L/vel0;


	DiffusionT = t;
	X_sf = x;
	Y_sf = y;
	Z_sf = z;
	VX_sf = vx;
	VY_sf = vy;
	VZ_sf = vz;
	theta_sf = theta;
	phi_sf = phi;
	//return ResultDiff;
}