#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_ModStoppingfile(){

	TString FileName(
		"../Root/hline_SimBeamStop_25mm_DG360.root"
		//"../Root/hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root"
		//"../Root/hline_SimBeamStop_GM_7.12mm.root"
		);
	TFile * f1 = new TFile(FileName.Data());

	TTree * t1 = (TTree*)f1->Get("position");
	const auto nentries = t1->GetEntries();

	double x, y, z;
	t1->SetBranchAddress("x", &x);
	t1->SetBranchAddress("y", &y);
	t1->SetBranchAddress("z", &z);

	TFile newfile("../Root/hline_SimBeamStop_25mm_DG360_Zshifted.root", "recreate");
	auto newtree = t1->CloneTree(0);

	for (auto i : ROOT::TSeqI(nentries)) {
		t1->GetEntry(i);
		z = z + 25;
		newtree->Fill();
	}

	newtree->Print();
	newfile.Write();

}