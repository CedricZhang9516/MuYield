#include "../../CZhang/CZhangNew.h"
#include "../InsideAerogel.h"
#include "InsideLaserRegion.h"

#include "macro_MuYieldAna.h"


double D = 87000;// diffussion coefficient mm^2/s
double T = 322;
double lifeMu = 2.2e-6; //s
double k = 8.62e-11 ; //Boltzmann constant, MeV/K
double PI = 3.1415926;
double vel0_avrg = 1000*sqrt(8*k*T/(PI*massMu));

const double mmu = 105.658;
//const double light = 299792458; // m/s
//const double massMu = 106.16/light/light; // MeV/c2

double tempX, tempY, tempZ;

void macro_ReflectionModel(TString filename = "MuYield.root", double Lasertime = 1.35);

void ReflectionModel(double &x, double &y, double &z, double &T,
	double &vx, double &vy, double &vz, double delT, int MCtype){

	double L = 0;
	double t = 0;

	double  vel0 = sqrt(vx*vx+vy*vy+vz*vz);

	double Lmfp = 12*D/(PI * vel0_avrg);//mm



	tempX = TMath::ACos(-1 + 2 * ((double)rand()/(RAND_MAX)) );
	tempY = ((double) rand()/(RAND_MAX)) * 2* PI;

	double theta = tempX;  // [0,+PI] radians
	double phi = tempY; //[0,+2PI] radians

	vx = vel0 * sin(theta) * cos(phi);
	vy = vel0 * sin(theta) * sin(phi);
	vz = vel0 * cos(theta);

	do{

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

		if( InsideAerogel(x, y, z, MCtype) && (t < delT))
		{

			tempX = TMath::ACos(-1 + 2 * ((double)rand()/(RAND_MAX)) );
			tempY = ((double) rand()/(RAND_MAX)) * 2* PI;

			theta = tempX;  // [0,+PI] radians
			phi = tempY; //[0,+2PI] radians

			vx = vel0 * sin(theta) * cos(phi);
			vy = vel0 * sin(theta) * sin(phi);
			vz = vel0 * cos(theta);
		}

		//N++;

		//DiffusionVertexX->push_back(x);
		//DiffusionVertexY->push_back(y);
		//DiffusionVertexZ->push_back(z);
		//DiffusionVertexT->push_back(t);

		//cout<<DiffusionVertexX->size()<<endl;
		//cout<<"t "<<t<<" DecayT:"<<DecayT<<endl;


	}while(InsideAerogel(x,y,z,MCtype) && (t < delT));

	if(t>DecayT)t = DecayT;

	T = T + t;

}
