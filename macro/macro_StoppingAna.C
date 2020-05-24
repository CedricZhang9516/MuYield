#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_StoppingAna(){

	TString FileName(
		//"../Root/SimBeamStop_25mm_DG360.root"
		//"../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root"
		"../Root/hline_SimBeamStop_GM_7.12mm.root"
		);



	TFile * f = new TFile(FileName.Data());

	TTree * t = (TTree*)f->Get("position");
	//TTree * t = (TTree*)f->Get("101");

	//TH1F * h = TreeToTH1F(t,"z_dec",100,-30,10);
	TH1F * h = TreeToTH1F(t,"z",100,-30,10);


}