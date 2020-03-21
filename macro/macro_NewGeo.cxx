#include "/Users/zhangce/WorkArea/CZhang/CZhangNew.h"

void macro_NewGeo(){

	gSystem->Load("libGeom");
	//TGeoBBox * aerogel = new TGeoBBox("aerogel",8,150,150);
	/*
	TBRIK *aerogel  = new TBRIK("aerogel","aerogel","void",8,150,150);
	aerogel->SetLineColor(kRed);
	aerogel->SetFillColor(kRed);
	//aerogel->Divide("SLICE",1,100);
	//aerogel->Draw();

	TNode *node1 = new TNode("NODE1","NODE1","aerogel");
   	node1->cd();
   	//node1->Draw("gl");
	*/

	char no_Block[100];
	int F = 0;
	int N = 0;

	TGeoManager *geom = new TGeoManager("geom","My First 3D Geometry");

	// Materials
	TGeoMaterial *Vacuum = new TGeoMaterial("vacuum",1,1,1);
	TGeoMaterial *Fe = new TGeoMaterial("Fe",55.845,26,7.87);

	// Media
	TGeoMedium *Air = new TGeoMedium("Air",1,Vacuum);
	TGeoMedium *Iron = new TGeoMedium("Iron",0,Fe);

	// Volume
	//TGeoVolume *aerogel = geom->MakeBox("1",Air,8,150,150);
	TGeoVolume *aerogel = geom->MakeBox("Top",Air,80,80,80);
	geom->SetTopVolume(aerogel);
	geom->SetTopVisible(0);

	TGeoVolume *mBlocks;
	mBlocks = geom->MakeBox("2",Air,150,8,8);
    mBlocks->SetLineColor(kYellow-1);

    sprintf(no_Block, "B1_F%d_%d", F, ++N);
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,0,0));

    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-2);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,16,16));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,16,0));
    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-3);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,32,0));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,32,0));
    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-4);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,48,16));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,48,0));
    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-5);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,64,0));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,64,0));
    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-5);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,-16,16));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,-16,0));
    mBlocks = geom->MakeBox("2",Air,150,8,8);
    //mBlocks->SetLineColor(kYellow-5);
    mBlocks->SetLineColor(kYellow-1);
    //aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,80,16));
    aerogel->AddNodeOverlap(mBlocks,1, new TGeoTranslation(0,80,0));

	//geom->SetTopVisible(0);
    geom->CloseGeometry();

	aerogel->SetVisibility(0);
	//aerogel->SetLineColor(1);
   	aerogel->Draw("ogl");



}