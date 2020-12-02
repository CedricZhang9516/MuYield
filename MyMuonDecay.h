//#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
//#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"
#include "../CZhang/CZhangNew.h"


double EMASS = 0.510998950;//daughtermass[0]; MeV/c2
double EMMU = 	105.658;//parentmass; MeV/c2
static const double pi  = 3.14159265358979323846;
static const double twopi  = 2*pi;

/*
static const double h_Planck      = 6.62606896e-34 * joule*s;
static const double hbar_Planck   = h_Planck/twopi;
static const double hbarc         = hbar_Planck * c_light;
static const double e_squared = eplus * eplus;
static const double mu0      = 4*psi*1.e-7 * henry/m;
static const double epsilon0 = 1./(c_squared*mu0);
static const double elm_coupling           = e_squared/(4*pi*epsilon0);
*/

static const double fine_structure_const   = 0.0072973525693;//elm_coupling/hbarc;

TH1F * h_electronmomentum = new TH1F("electronmomentum",
		"electronmomentum;MeV/c;N",120,-5,55);

TH1F * h_theta = new TH1F("theta",
		"theta (50 MeV/c);rad;N",100,-3.14,3.14);

TH1F * h_ctheta = new TH1F("ctheta",
		"ctheta (50 MeV/c);costheta;N",100,-1,1);


double R_c(double x){

  int n_max = (int)(100.*x);

  if(n_max<10)n_max=10;

  double L2 = 0.0;

  for(int n=1; n<=n_max; n++){
    L2 += std::pow(x,n)/(n*n);
  }

  double omega = std::log(EMMU/EMASS);

  double r_c;

  r_c = 2.*L2-(pi*pi/3.)-2.;
  r_c = r_c + omega * (1.5+2.*std::log((1.-x)/x));
  r_c = r_c - std::log(x)*(2.*std::log(x)-1.);
  r_c = r_c + (3.*std::log(x)-1.-1./x)*std::log(1.-x);

  return r_c;
}

double F_c(double x, double x0)
{
  double omega = std::log(EMMU/EMASS);

  double f_c;

  f_c = (5.+17.*x-34.*x*x)*(omega+std::log(x))-22.*x+34.*x*x;
  f_c = (1.-x)/(3.*x*x)*f_c;
  f_c = (6.-4.*x)*R_c(x)+(6.-6.*x)*std::log(x) + f_c;
  f_c = (fine_structure_const/twopi) * (x*x-x0*x0) * f_c;

  return f_c;
}

double F_theta(double x, double x0)
{
  double omega = std::log(EMMU/EMASS);

  double f_theta;

  f_theta = (1.+x+34*x*x)*(omega+std::log(x))+3.-7.*x-32.*x*x;
  f_theta = f_theta + ((4.*(1.-x)*(1.-x))/x)*std::log(1.-x);
  f_theta = (1.-x)/(3.*x*x) * f_theta;
  f_theta = (2.-4.*x)*R_c(x)+(2.-6.*x)*std::log(x)-f_theta;
  f_theta = (fine_structure_const/twopi) * (x*x-x0*x0) * f_theta;

  return f_theta;
}

double G4UniformRand(){

	return (double) rand() / (RAND_MAX);
}


TVector3* G4MuonDecay(TVector3 parent_polarization){

	// calcurate electron energy

	double michel_rho   = 0.75; //Standard Model Michel rho
	double michel_delta = 0.75; //Standard Model Michel delta
	double michel_xsi   = 1.00; //Standard Model Michel xsi
	double michel_eta   = 0.00; //Standard Model eta

	double rndm, x, ctheta;

	double FG;
	double FG_max = 2.00;

	double W_mue  = (EMMU*EMMU+EMASS*EMASS)/(2.*EMMU);
	double x0     =           EMASS/W_mue;

	double x0_squared = x0*x0;

	// ***************************************************
	//     x0 <= x <= 1.   and   -1 <= y <= 1
	//
	//     F(x,y) = f(x)*g(x,y);   g(x,y) = 1.+g(x)*y
	// ***************************************************

	// ***** sampling F(x,y) directly (brute force) *****

	do{

		// Sample the positron energy by sampling from F

		rndm = (double) rand() / (RAND_MAX);

		x = x0 + rndm*(1.-x0);

		double x_squared = x*x;

		double F_IS, F_AS, G_IS, G_AS;

		F_IS = 1./6.*(-2.*x_squared+3.*x-x0_squared);
		F_AS = 1./6.*std::sqrt(x_squared-x0_squared)*(2.*x-2.+std::sqrt(1.-x0_squared));

		G_IS = 2./9.*(michel_rho-0.75)*(4.*x_squared-3.*x-x0_squared);
		G_IS = G_IS + michel_eta*(1.-x)*x0;

		G_AS = 3.*(michel_xsi-1.)*(1.-x);
		G_AS = G_AS+2.*(michel_xsi*michel_delta-0.75)*(4.*x-4.+std::sqrt(1.-x0_squared));
		G_AS = 1./9.*std::sqrt(x_squared-x0_squared)*G_AS;

		F_IS = F_IS + G_IS;
		F_AS = F_AS + G_AS;

		// *** Radiative Corrections ***

		double R_IS = F_c(x,x0);

		double F = 6.*F_IS + R_IS/std::sqrt(x_squared-x0_squared);

		// *** Radiative Corrections ***

		double R_AS = F_theta(x,x0);

		rndm = G4UniformRand();

		ctheta = 2.*rndm-1.;

		double G = 6.*F_AS - R_AS/std::sqrt(x_squared-x0_squared);

		FG = std::sqrt(x_squared-x0_squared)*F*(1.+(G/F)*ctheta);

		if(FG>FG_max){
		  cout<<"***Problem in Muon Decay *** : FG > FG_max"<<endl;
		  FG_max = FG;
		}

		rndm = G4UniformRand();

	}while(FG<rndm*FG_max);

	double energy = x * W_mue;

	rndm = G4UniformRand();

	double phi = twopi * rndm;

	if(energy < EMASS) energy = EMASS;

	// calculate daughter momentum
	double daughtermomentum[3];

	daughtermomentum[0] = std::sqrt(energy*energy - EMASS*EMASS);


	//if(daughtermomentum[0]<50.5 && daughtermomentum[0]<49.5)h_theta->Fill(std::acos(ctheta));
	//if(daughtermomentum[0]<26.1 && daughtermomentum[0]>25.9){
	//if(daughtermomentum[0]<50.5 && daughtermomentum[0]>49.5){
		//cout<<ctheta<<" "<<std::acos(ctheta)<<endl;
		//if(ctheta>0.995)
		//h_theta->Fill((G4UniformRand()-0.5)*std::acos(ctheta)/abs((G4UniformRand()-0.5)));
		//h_theta->Fill(std::acos(ctheta));
		//if(ctheta>0.995)
		//h_ctheta->Fill(ctheta);
	//}

	double stheta = std::sqrt(1.-ctheta*ctheta);
	double cphi = std::cos(phi);
	double sphi = std::sin(phi);

	//Coordinates of the decay positron with respect to the muon spin

	double px = stheta*cphi;
	double py = stheta*sphi;
	double pz = ctheta;

	TVector3 * direction0 = new TVector3(px,py,pz);
	//TVector3 parent_polarization(0,0,1);

	direction0->RotateUz(parent_polarization);

	//Angle histogram
	//if(daughtermomentum[0]<26.1 && daughtermomentum[0]>25.9)h_theta->Fill(direction0.Angle(parent_polarization));
	//if(daughtermomentum[0]<50.1 && daughtermomentum[0]>49.9){
	//	h_theta->Fill(direction0.Angle(parent_polarization));
	//	h_ctheta->Fill(ctheta);
	//}
	TVector3 * direction = new TVector3(
		daughtermomentum[0]*direction0->X(),
		daughtermomentum[0]*direction0->Y(),
		daughtermomentum[0]*direction0->Z()
		);

	return direction;

	//return daughtermomentum[0];

}

/*
void MyMuonDecay(){

	for(int Nevent = 0; Nevent<1000000; Nevent++){
		h_electronmomentum->Fill(G4MuonDecay());
	}

	TCanvas * c = new TCanvas("c","c",1000,1000);
	c->Divide(3,1);

	c->cd(1);
	h_electronmomentum->Draw();
	c->cd(2);
	h_theta->Draw();
	c->cd(3);
	h_ctheta->Draw();
}
*/


