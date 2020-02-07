void DrawAerogelGeo(){
	//TBox *aerogel = new TBox(-2,-7.05,0.0,-5.15);
	TBox *aerogel = new TBox(-2,-15,0.0,20);
	//TBox *aerogel = new TBox(-0.5,-8.3,0.0,-7.7);
	//TBox *LaserRegion = new TBox(1,-7.05,6.0,-5.15);
	TBox *LaserRegion = new TBox(1,-15,6.0,20);
	TBox *LaserRegion2 = new TBox(-8,-15,-3,20);

	aerogel->SetFillStyle(3002);
	aerogel->SetFillColor(1);
	LaserRegion->SetFillStyle(3004);
	LaserRegion->SetFillColor(3);
	LaserRegion2->SetFillStyle(3004);
	LaserRegion2->SetFillColor(3);


	DiffusionTrack->GetXaxis()->SetRangeUser(-2.0,11.0);
	//DiffusionTrack->GetYaxis()->SetRangeUser(-7.05,-5.15);
	//DiffusionTrack->GetYaxis()->SetRangeUser(-8.3,-7.7);
	DiffusionTrack->GetYaxis()->SetRangeUser(-15,35);
	DiffusionTrack->GetXaxis()->SetLimits(-11,11);

	TCanvas *c6 = new TCanvas("c6","c6",800,600);
	DiffusionTrack->SetMarkerStyle(20);
	DiffusionTrack->SetMarkerSize(0.4);
	DiffusionTrack->SetMarkerColor(2);
	DiffusionTrack->SetLineColor(2);


	DiffusionTrack->Draw("ALP");
	LaserRegion->Draw();
	LaserRegion2->Draw();
	aerogel->Draw();

}