#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const double MuonID(){

	double Time, N, LastMuonID, MuonID;

	ifstream MuonIDtxt( "MuonID.txt" );
	MuonIDtxt>>Time>>N>>LastMuonID;

	time_t now = time(0);

	//cout << "the second from 1970 to now:" << now << endl;

	tm *ltm = localtime(&now);

	double year = 1900 + ltm->tm_year;

	double month = 1 + ltm->tm_mon;

	double day = ltm->tm_mday;

	double hour = ltm->tm_hour;

	double min = ltm->tm_min;

	double sec = ltm->tm_sec;

	double NewTime = (year-2019)*1e6 + month*1e4 + day*1e2 + hour;

	//cout<<fixed<<Time<<" "<<NewTime<<" "<<(NewTime - Time)<<endl;

	if( (NewTime - Time) < 1){
		N++;
	}

	else{
		N = 0;
	}

	//cout<<N<<endl;

	MuonID = NewTime*1e8 + N;

	MuonIDtxt.close();

	//cout<<fixed<<setprecision(0)<<NewTime<<" "<<N<<" "<<setprecision(0)<<MuonID<<endl;

	ofstream NewMuonIDtxt;
	NewMuonIDtxt.open("MuonID.txt",ios::trunc);
	NewMuonIDtxt << fixed << setprecision(0)<<NewTime<<" "<<N<<" "<<setprecision(0)<<MuonID<<endl;
	//fixed<<NewTime << " " <<setw(8)<< N << " " << MuonID << endl;
	NewMuonIDtxt.close();



	return MuonID;
}


/*

#include "MuonID.h"

void testMuonID(){

	double MUONID = 0;

	for(int i = 0; i<1; i++){

		MUONID = MuonID();
		cout<<fixed<<setprecision(0)<<MUONID<<endl;

	}


}

*/
