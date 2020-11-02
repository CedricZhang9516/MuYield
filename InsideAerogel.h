#include "MuYield.h"

bool InsideAerogel(double x, double y, double z){


	switch (MCtype){

		case 1001:
			if( z<0 && z>-Thick){
				if(y < 28 && y > -28 && x < 25 && x > -25) return true;
			}
			return false;

		case 1002:

			if( z<0 && z>-Thick){
			if(y < 150 && y > -150 && x < 150 && x > -150) return true;
			}
			return false;

		case 3:

			if( z<0 && z>-Thick){
				if(y < 28 && y > -28 && x < 25 && x > -25) return true;
			}

			return false;

		case 5:

			if( z<0 && z>-Thick){
				if(y < 20 && y > 12) return true;
				if(y < 4 && y > -4) return true;
				if(y < -12 && y > -20) return true;
			}

			if( z>0 && z<Thick){

				if(y < 28 && y > 20)return true;
				if(y < 12 && y > 4)return true;
				if(y < -4 && y > -12)return true;
				if(y < -20 && y > -28)return true;
			}

			return false;

		case 6:

			if(x>25 || x<-25)return false;

			if( z<0 && z>-Thick){
				if(y < 10 && y > 6) return true;
				if(y < 2 && y > -2) return true;
				if(y < -6 && y > -10) return true;
			}

			if( z>0 && z<Thick){

				if(y < 14 && y > 10)return true;
				if(y < 6 && y > 2)return true;
				if(y < -2 && y > -6)return true;
				if(y < -10 && y > -14)return true;
			}

			return false;


		case 7:


			if( z<0 && z>-Thick && y < 4 && y > -4) return true;

			if( z>0 && z<Thick){
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
			}

			if( z>Thick && z<2*Thick){
			if(y < 20 && y > 12)return true;
			if(y < -12 && y > -20)return true;
			}

			if( z>2*Thick && z<3*Thick){
			if(y < 28 && y > 20)return true;
			if(y < -20 && y > -28)return true;
			}

			return false;



		case 8:

			if(x>25 || x<-25)return false;

			if( z<0 && z>-Thick){
				if(y < 26 && y > 22) return true;
				if(y < 18 && y > 14) return true;
				if(y < 10 && y > 6) return true;
				if(y < 2 && y > -2) return true;
				if(y < -6 && y > -10) return true;
				if(y < -14 && y > -18) return true;
				if(y < -22 && y > -26) return true;
			}

			if( z>0 && z<Thick){

				if(y < 30 && y > 26)return true;
				if(y < 22 && y > 18)return true;
				if(y < 14 && y > 10)return true;
				if(y < 6 && y > 2)return true;
				if(y < -2 && y > -6)return true;
				if(y < -10 && y > -14)return true;
				if(y < -18 && y > -22)return true;
				if(y < -26 && y > -30)return true;

			}

			return false;


		case 9:

			if( z>0 && z<Thick){
				if(y < 20 && y > 12) return true;
				if(y < 4 && y > -4) return true;
				if(y < -12 && y > -20) return true;
			}
			if( z<0 && z>-Thick){
				if(y < 12 && y > 4)return true;
				if(y < -4 && y > -12)return true;
			}

			return false;

		case 3004:
		case 3002:

			if( z>0 && z<Thick){
				if(y < 20 && y > 12) return true;
				if(y < 4 && y > -4) return true;
				if(y < -12 && y > -20) return true;
			}
			if( z<0 && z>-Thick){
				if(y < 12 && y > 4)return true;
				if(y < -4 && y > -12)return true;
			}

			return false;


		case 3005:

			if( z>0 && z<Thick){
				if(y < 20 && y > 12) return true;
				if(y < 4 && y > -4) return true;
				if(y < -12 && y > -20) return true;
			}
			if( z<0 ){
				if(y < 12 && y > 4)return true;
				if(y < -4 && y > -12)return true;
			}

			return false;


		case 3006:

			if( z<0 && z>-14){
				if(y < 20 && y > 12) return true;
				if(y < 4 && y > -4) return true;
				if(y < -12 && y > -20) return true;
			}

			if( z>0 && z<Thick){

				if(y < 28 && y > 20)return true;
				if(y < 12 && y > 4)return true;
				if(y < -4 && y > -12)return true;
				if(y < -20 && y > -28)return true;
			}

			return false;


		case 3011:

			if( z>0 && z<Thick){
				if(y < 18 && y > 14) return true;
				if(y < 10 && y > 6) return true;
				if(y < 2 && y > -2) return true;
				if(y < -6 && y > -10) return true;
				if(y < -14 && y > -18) return true;
			}

			if( z<0 && z>-14){

				if(y < 14 && y > 10)return true;
				if(y < 6 && y > 2)return true;
				if(y < -2 && y > -6)return true;
				if(y < -10 && y > -14)return true;
			}

			return false;


		case 3012:

			if( z<0 && z>-Thick){
				//if(y < 26 && y > 22) return true;
				if(y < 18 && y > 14) return true;
				if(y < 10 && y > 6) return true;
				if(y < 2 && y > -2) return true;
				if(y < -6 && y > -10) return true;
				if(y < -14 && y > -18) return true;
				//if(y < -22 && y > -26) return true;
			}

			if( z>0 && z<Thick){

				//if(y < 30 && y > 26)return true;
				if(y < 22 && y > 18)return true;
				if(y < 14 && y > 10)return true;
				if(y < 6 && y > 2)return true;
				if(y < -2 && y > -6)return true;
				if(y < -10 && y > -14)return true;
				if(y < -18 && y > -22)return true;
				//if(y < -26 && y > -30)return true;

			}

			return false;


		case 10:

			if(x>25 || x<-25)return false;

			if( z>0 && z<Thick){
				if(y < 26 && y > 22) return true;
				if(y < 18 && y > 14) return true;
				if(y < 10 && y > 6) return true;
				if(y < 2 && y > -2) return true;
				if(y < -6 && y > -10) return true;
				if(y < -14 && y > -18) return true;
				if(y < -22 && y > -26) return true;
			}

			if( z<0 && z>-Thick){

				//if(y < 30 && y > 26)return true;
				if(y < 22 && y > 18)return true;
				if(y < 14 && y > 10)return true;
				if(y < 6 && y > 2)return true;
				if(y < -2 && y > -6)return true;
				if(y < -10 && y > -14)return true;
				if(y < -18 && y > -22)return true;
				//if(y < -26 && y > -30)return true;

			}

			return false;


		case 12:
		case 2001:

			if(z < 0 && z > -9)return true;
			if(z < 15 && z > 7)return true;
			if(z < 30 && z > 22)return true;

			return false;

		default:

			if( ( z <= 0 && z >= -7.12 ) ) return true;
			else return false;

	}

}


/*


	// 1001: TDR fig reproduction

	if(MCtype == 1001){
		if( z<0 && z>-Thick){
			if(y < 28 && y > -28 && x < 25 && x > -25) return true;
		}

		return false;
	}

	if(MCtype == 1002){
		if( z<0 && z>-Thick){
			if(y < 150 && y > -150 && x < 150 && x > -150) return true;
		}

		return false;
	}


	if(MCtype == 3){

		//if(x>25 || x<-25)return false;

		if( z<0 && z>-Thick){
			if(y < 28 && y > -28 && x < 25 && x > -25) return true;
			//if(y < 150 && y > -150 && x < 150 && x > -150) return true;
			//if(y < 28 && y > -28) return true;
			//if(y < 150 && y > -150) return true;
			//if(x < 50 && x > -50) return true;
			//if(x < 150 && x > -150) return true;
		}

		return false;
	}
	else if(MCtype <5){
		if( ( z <= 0 && z >= -7.12 ) ) return true;
		else return false;
	}





	if(MCtype == 5){

		//if(x>25 || x<-25)return false;

		if( z<0 && z>-Thick){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}

		if( z>0 && z<Thick){

			if(y < 28 && y > 20)return true;
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
			if(y < -20 && y > -28)return true;
		}

		return false;
	}




	if(MCtype == 6){

		if(x>25 || x<-25)return false;

		if( z<0 && z>-Thick){
			if(y < 10 && y > 6) return true;
			if(y < 2 && y > -2) return true;
			if(y < -6 && y > -10) return true;
		}

		if( z>0 && z<Thick){

			if(y < 14 && y > 10)return true;
			if(y < 6 && y > 2)return true;
			if(y < -2 && y > -6)return true;
			if(y < -10 && y > -14)return true;
		}

		return false;
	}

	if(MCtype == 7){ ///Yannis

 		//if(x>25 || x<-25)return false;

 		if( z<0 && z>-Thick && y < 4 && y > -4) return true;

 		if( z>0 && z<Thick){
 			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
 		}

 		if( z>Thick && z<2*Thick){
 			if(y < 20 && y > 12)return true;
			if(y < -12 && y > -20)return true;
 		}

 		if( z>2*Thick && z<3*Thick){
 			if(y < 28 && y > 20)return true;
			if(y < -20 && y > -28)return true;
 		}

 		return false;

	}

	if(MCtype == 8){

		if(x>25 || x<-25)return false;

		if( z<0 && z>-Thick){
			if(y < 26 && y > 22) return true;
			if(y < 18 && y > 14) return true;
			if(y < 10 && y > 6) return true;
			if(y < 2 && y > -2) return true;
			if(y < -6 && y > -10) return true;
			if(y < -14 && y > -18) return true;
			if(y < -22 && y > -26) return true;
		}

		if( z>0 && z<Thick){

			if(y < 30 && y > 26)return true;
			if(y < 22 && y > 18)return true;
			if(y < 14 && y > 10)return true;
			if(y < 6 && y > 2)return true;
			if(y < -2 && y > -6)return true;
			if(y < -10 && y > -14)return true;
			if(y < -18 && y > -22)return true;
			if(y < -26 && y > -30)return true;

		}

		return false;
	}

	if(MCtype == 9 || MCtype == 3003){

		if( z>0 && z<Thick){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}
		if( z<0 && z>-Thick){
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
		}

		return false;
	}

	if(MCtype == 3004 || MCtype == 3002){

		if( z>0 && z<Thick){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}
		if( z<0 && z>-Thick){
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
		}

		return false;
	}

	if(MCtype == 3005){

		if( z>0 && z<Thick){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}
		if( z<0 ){
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
		}

		return false;
	}

	if(MCtype == 3006){


		if( z<0 && z>-14){
			if(y < 20 && y > 12) return true;
			if(y < 4 && y > -4) return true;
			if(y < -12 && y > -20) return true;
		}

		if( z>0 && z<Thick){

			if(y < 28 && y > 20)return true;
			if(y < 12 && y > 4)return true;
			if(y < -4 && y > -12)return true;
			if(y < -20 && y > -28)return true;
		}

		return false;
	}


	if(MCtype == 3011){ // reference from Type 10

		if( z>0 && z<Thick){
			if(y < 18 && y > 14) return true;
			if(y < 10 && y > 6) return true;
			if(y < 2 && y > -2) return true;
			if(y < -6 && y > -10) return true;
			if(y < -14 && y > -18) return true;
		}

		if( z<0 && z>-14){

			if(y < 14 && y > 10)return true;
			if(y < 6 && y > 2)return true;
			if(y < -2 && y > -6)return true;
			if(y < -10 && y > -14)return true;
		}

		return false;
	}

	if(MCtype == 3012){ // reference from Type 10

		if( z<0 && z>-Thick){
			//if(y < 26 && y > 22) return true;
			if(y < 18 && y > 14) return true;
			if(y < 10 && y > 6) return true;
			if(y < 2 && y > -2) return true;
			if(y < -6 && y > -10) return true;
			if(y < -14 && y > -18) return true;
			//if(y < -22 && y > -26) return true;
		}

		if( z>0 && z<Thick){

			//if(y < 30 && y > 26)return true;
			if(y < 22 && y > 18)return true;
			if(y < 14 && y > 10)return true;
			if(y < 6 && y > 2)return true;
			if(y < -2 && y > -6)return true;
			if(y < -10 && y > -14)return true;
			if(y < -18 && y > -22)return true;
			//if(y < -26 && y > -30)return true;

		}

		return false;
	}

	if(MCtype == 10){

		if(x>25 || x<-25)return false;

		if( z>0 && z<Thick){
			if(y < 26 && y > 22) return true;
			if(y < 18 && y > 14) return true;
			if(y < 10 && y > 6) return true;
			if(y < 2 && y > -2) return true;
			if(y < -6 && y > -10) return true;
			if(y < -14 && y > -18) return true;
			if(y < -22 && y > -26) return true;
		}

		if( z<0 && z>-Thick){

			//if(y < 30 && y > 26)return true;
			if(y < 22 && y > 18)return true;
			if(y < 14 && y > 10)return true;
			if(y < 6 && y > 2)return true;
			if(y < -2 && y > -6)return true;
			if(y < -10 && y > -14)return true;
			if(y < -18 && y > -22)return true;
			//if(y < -26 && y > -30)return true;

		}

		return false;
	}


	if(MCtype == 12 || MCtype == 2001){ // 2001

		//double interval = 10;

		//InputTree->GetEntry(index_m);

		if(z < 0 && z > -9)return true;
		if(z < 15 && z > 7)return true;
		if(z < 30 && z > 22)return true;

		return false;
	}


	cout<<"Wrong MCtype!"<<endl;
	return false;


}
*/