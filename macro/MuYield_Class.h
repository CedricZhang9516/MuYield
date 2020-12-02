//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep  4 22:42:55 2020 by ROOT version 6.16/00
// from TTree tree/MuYield event
// found on file: 200421_HorizontalMulti_8mmShifted_25mm-v-14mm_tree_Type3006_D87000_T322_Nrepeat5182075_H_line1_Thick25.00_NewGeo0.root
//////////////////////////////////////////////////////////

#ifndef MuYield_Class_h
#define MuYield_Class_h

//#define TrackTime
//#define TrackEventTime

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

class MuYield_Class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   TString         filename;
   TTree          *tree;
   Int_t           MCtype;

   Int_t           Nentries;
   Int_t           OutputLaserIonization = 0;

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        TBeam;
   Double_t        DecayT;
   Double_t        X0;
   Double_t        Y0;
   Double_t        Z0;
   Double_t        vel0;
   Double_t        theta0;
   Double_t        phi0;
   Double_t        Vz0;
   Double_t        Vx0;
   Double_t        Vy0;
   Double_t        Lmfp;
   Double_t        t0;
   Double_t        DiffusionT;
   Double_t        X_sf;
   Double_t        Y_sf;
   Double_t        Z_sf;
   Double_t        VX_sf;
   Double_t        VY_sf;
   Double_t        VZ_sf;
   Double_t        theta_sf;
   Double_t        phi_sf;
   vector<double>  *DiffusionVertexX;
   vector<double>  *DiffusionVertexY;
   vector<double>  *DiffusionVertexZ;
   vector<double>  *DiffusionVertexT;
   Double_t        DecayX;
   Double_t        DecayY;
   Double_t        DecayZ;
   Double_t        SpinX;
   Double_t        SpinY;
   Double_t        SpinZ;
   Double_t        DecayPositronMomtX;
   Double_t        DecayPositronMomtY;
   Double_t        DecayPositronMomtZ;
//   Double_t        LaserX;
//   Double_t        LaserY;
//   Double_t        LaserZ;
   Double_t        LaserE;
//   Double_t        LaserXp;
//   Double_t        LaserYp;
//   Double_t        MeshEk;
//   Double_t        MeshE;
//   Double_t        MeshT;
//   Double_t        MeshT_ab;
//   Double_t        MeshX;
//   Double_t        MeshY;
//   Double_t        MeshZ;
//   Double_t        MeshXp;
//   Double_t        MeshYp;
//   Double_t        MeshBeta;
//   Double_t        MeshVY;
//   Double_t        MeshVX;
//   Double_t        MeshVZ;
//   Double_t        DriftT;
//   Double_t        DriftT_ab;
//   Double_t        DriftX;
//   Double_t        DriftY;
//   Double_t        DriftZ;

   // List of branches
   TBranch        *b_TBeam;   //!
   TBranch        *b_DecayT;   //!
   TBranch        *b_X0;   //!
   TBranch        *b_Y0;   //!
   TBranch        *b_Z0;   //!
   TBranch        *b_vel0;   //!
   TBranch        *b_theta0;   //!
   TBranch        *b_phi0;   //!
   TBranch        *b_Vz0;   //!
   TBranch        *b_Vx0;   //!
   TBranch        *b_Vy0;   //!
   TBranch        *b_Lmfp;   //!
   TBranch        *b_t0;   //!
   TBranch        *b_DiffusionT;   //!
   TBranch        *b_X_sf;   //!
   TBranch        *b_Y_sf;   //!
   TBranch        *b_Z_sf;   //!
   TBranch        *b_VX_sf;   //!
   TBranch        *b_VY_sf;   //!
   TBranch        *b_VZ_sf;   //!
   TBranch        *b_theta_sf;   //!
   TBranch        *b_phi_sf;   //!
   TBranch        *b_DiffusionVertexX;   //!
   TBranch        *b_DiffusionVertexY;   //!
   TBranch        *b_DiffusionVertexZ;   //!
   TBranch        *b_DiffusionVertexT;   //!
   TBranch        *b_DecayX;   //!
   TBranch        *b_DecayY;   //!
   TBranch        *b_DecayZ;   //!
   TBranch        *b_SpinX;   //!
   TBranch        *b_SpinY;   //!
   TBranch        *b_SpinZ;   //!
   TBranch        *b_DecayPositronMomtX;   //!
   TBranch        *b_DecayPositronMomtY;   //!
   TBranch        *b_DecayPositronMomtZ;   //!
//   TBranch        *b_LaserX;   //!
//   TBranch        *b_LaserY;   //!
//   TBranch        *b_LaserZ;   //!
//   TBranch        *b_LaserE;   //!
//   TBranch        *b_LaserXp;   //!
//   TBranch        *b_LaserYp;   //!
//   TBranch        *b_MeshEk;   //!
//   TBranch        *b_MeshE;   //!
//   TBranch        *b_MeshT;   //!
//   TBranch        *b_MeshT_ab;   //!
//   TBranch        *b_MeshX;   //!
//   TBranch        *b_MeshY;   //!
//   TBranch        *b_MeshZ;   //!
//   TBranch        *b_MeshXp;   //!
//   TBranch        *b_MeshYp;   //!
//   TBranch        *b_MeshBeta;   //!
//   TBranch        *b_MeshVY;   //!
//   TBranch        *b_MeshVX;   //!
//   TBranch        *b_MeshVZ;   //!
//   TBranch        *b_DriftT;   //!
//   TBranch        *b_DriftT_ab;   //!
//   TBranch        *b_DriftX;   //!
//   TBranch        *b_DriftY;   //!
//   TBranch        *b_DriftZ;   //!


   TH1D* hT_sf;// = new TH1D("hT_sf","hT_sf;T[s];N",nbinT,0,nbinT*Tstep);
   TH2D *hZY2D_sf;// = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",500,-10,40,500,-40,40);
   TH2D *hZX2D_sf;// = new TH2D("Z-X-2D_sf","Z-X-2D_sf; Z(mm);X (mm)",500,-40,40,500,-40,40);
   TH2D *hXY2D_sf;// = new TH2D("X-Y-2D_sf","X-Y-2D_sf; X(mm);Y (mm)",500,-40,40,500,-40,40);

   TH3D *hZXY3D_sf;// = new TH3D("ZXY-3D_sf","ZXY-3D_sf;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);

   TH2D *hZT2D;// = new TH2D("Z-T-2D","Z-T-2D; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);
   TH2D *hZY2D;// = new TH2D("Z-Y-2D","Z-Y-2D; Z(mm);Y (mm)",100,0,30,60,-30,30);
   TH2D *hZX2D;// = new TH2D("Z-X-2D","Z-X-2D; Z(mm);X (mm)",100,-40,40,100,-40,40);
   TH2D *hXY2D;// = new TH2D("X-Y-2D","X-Y-2D; X(mm);Y (mm)",100,-80,80,60,-30,30);

   TH3D *hXYT3D;// = new TH3D("ZX-T-3D","ZX-T-3D; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);
   TH3D *hZXY3D;// = new TH3D("ZXY-3D","ZXY-3D;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);

   TH1D* hT;// = new TH1D("hT","hT;T[s];N",nbinT,0,nbinT*Tstep);

   TH2D *hZY2D_0;// = new TH2D("Z-Y-2D-0","Z-Y-2D-0; Z(mm);Y (mm)",100,0,30,60,-30,30);
   TH2D *hZX2D_0;// = new TH2D("Z-X-2D-0","Z-X-2D-0; Z(mm);X (mm)",100,-40,40,100,-40,40);
   TH2D *hXY2D_0;// = new TH2D("X-Y-2D-0","X-Y-2D-0; X(mm);Y (mm)",100,-80,80,60,-30,30);
   TH1D *hZ1D_0;
   TH1D *hX1D_0;
   TH1D *hY1D_0;

   TH2D *hZY2D_laser;// = new TH2D("Z-Y-2D-laser","Z-Y-2D-laser; Z(mm);Y (mm)",100,0,30,60,-30,30);
   TH2D *hZX2D_laser;// = new TH2D("Z-X-2D-laser","Z-X-2D-laser; Z(mm);X (mm)",100,-40,40,100,-40,40);
   TH2D *hXY2D_laser;// = new TH2D("X-Y-2D-laser","X-Y-2D-laser; X(mm);Y (mm)",100,-80,80,60,-30,30);
   TH1D *hZ1D_laser;
   TH1D *hX1D_laser;
   TH1D *hY1D_laser;

   //// currently not used in the new class

   TH1D* hXXp;// = new TH1D("hXXp","hXXp",100,-16,16);
   TH1D* hXp2;// = new TH1D("hXp2","hXp2",100,0,0.0016);
   TH1D* hX2;// = new TH1D("hX2","hX2",100,0,1e4);
   TH1D* hYYp;// = new TH1D("hYYp","hYYp",100,-16,16);
   TH1D* hYp2;// = new TH1D("hYp2","hYp2",100,0,0.0016);
   TH1D* hY2;// = new TH1D("hY2","hY2",100,0,1e4);
   TH1D* hBetaGamma;// = new TH1D("hBetaGamma","hBetaGamma",100,0.0012,0.0019);

   TH2D* EmissionX;// = new TH2D("EmissionX","EmissionX;X;X'",240,-120,120,320,0.16,0.16); // mm
   TH2D* EmissionY;// = new TH2D("EmissionY","EmissionY;Y;Y'",500,-25,25,320,0.16,0.16); // mm

   TH2D* CorrMeshTE;// = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,30e-9,80e-9,100,0.185e-3,0.21e-3);

   TH2D *hZT2D_sf;// = new TH2D("Z-T-2D_sf","Z-T-2D_sf; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);
   TH3D *hXYT3D_sf;// = new TH3D("ZX-T-3D_sf","ZX-T-3D_sf; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);


   int nbinT = 7000; /// 8 us
   double Tstep = 1e-9; /// 1 ns
   double lasertime = -1;

   TGraph * g_track;// = new TGraph();
   TGraph * g_track_reflection;// = new TGraph();

   TCanvas * c;// = NewTCanvas("c_intrnl","c_intrnl",1000,1000,2,2)

   TCanvas * c1;
   TCanvas * c2;
   TCanvas * c3;
   TCanvas * c4;

   MuYield_Class(TString name = "MuYield.root", int mctype = 1002);
   virtual ~MuYield_Class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);

   virtual void     SetLasertime(double Lasertime);
   virtual bool     IsInsideLaserRegion(Int_t Nevent = 1, double Lasertime = -1);

   virtual void     Surface();
   virtual void     LoopEvent();
   virtual void     LoopEventWithReflection(int N_track_event = -1, TString Outputfilename = "");
   virtual void     LoopTime();
   virtual TGraph*  Track(Int_t Nevent);
   virtual TGraph*  TrackWithReflection(Int_t Nevent = 1);

   virtual void     QuickLaserIonization(double Lasertime = -1, TString Outputfilename = "");
   virtual void     SavePlots();

   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual double   GetDecayT(int Nevent);
   virtual double   GetTBeam (int Nevent);

};

#endif

#ifdef MuYield_Class_cxx
//MuYield_Class::MuYield_Class(TTree *tree) : fChain(0)
MuYield_Class::MuYield_Class(TString name = "MuYield.root", int mctype = 1002) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   filename = name;
   filename.ReplaceAll(".root","");

   TFile * f = new TFile( (filename + ".root").Data() );

   if (!f || !f->IsOpen()) {
      cout<<"no files found, using MuYield.root"<<endl;
      f = new TFile("MuYield.root");
   }
   f->GetObject("tree",tree);

   MCtype = mctype;

   Init(tree);
}

MuYield_Class::~MuYield_Class()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MuYield_Class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MuYield_Class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MuYield_Class::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   DiffusionVertexX = 0;
   DiffusionVertexY = 0;
   DiffusionVertexZ = 0;
   DiffusionVertexT = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("TBeam", &TBeam, &b_TBeam);
   fChain->SetBranchAddress("DecayT", &DecayT, &b_DecayT);
   fChain->SetBranchAddress("X0", &X0, &b_X0);
   fChain->SetBranchAddress("Y0", &Y0, &b_Y0);
   fChain->SetBranchAddress("Z0", &Z0, &b_Z0);
   fChain->SetBranchAddress("vel0", &vel0, &b_vel0);
   fChain->SetBranchAddress("theta0", &theta0, &b_theta0);
   fChain->SetBranchAddress("phi0", &phi0, &b_phi0);
   fChain->SetBranchAddress("Vz0", &Vz0, &b_Vz0);
   fChain->SetBranchAddress("Vx0", &Vx0, &b_Vx0);
   fChain->SetBranchAddress("Vy0", &Vy0, &b_Vy0);
   fChain->SetBranchAddress("Lmfp", &Lmfp, &b_Lmfp);
   fChain->SetBranchAddress("t0", &t0, &b_t0);
   fChain->SetBranchAddress("DiffusionT", &DiffusionT, &b_DiffusionT);
   fChain->SetBranchAddress("X_sf", &X_sf, &b_X_sf);
   fChain->SetBranchAddress("Y_sf", &Y_sf, &b_Y_sf);
   fChain->SetBranchAddress("Z_sf", &Z_sf, &b_Z_sf);
   fChain->SetBranchAddress("VX_sf", &VX_sf, &b_VX_sf);
   fChain->SetBranchAddress("VY_sf", &VY_sf, &b_VY_sf);
   fChain->SetBranchAddress("VZ_sf", &VZ_sf, &b_VZ_sf);
   fChain->SetBranchAddress("theta_sf", &theta_sf, &b_theta_sf);
   fChain->SetBranchAddress("phi_sf", &phi_sf, &b_phi_sf);
   fChain->SetBranchAddress("DiffusionVertexX", &DiffusionVertexX, &b_DiffusionVertexX);
   fChain->SetBranchAddress("DiffusionVertexY", &DiffusionVertexY, &b_DiffusionVertexY);
   fChain->SetBranchAddress("DiffusionVertexZ", &DiffusionVertexZ, &b_DiffusionVertexZ);
   fChain->SetBranchAddress("DiffusionVertexT", &DiffusionVertexT, &b_DiffusionVertexT);
   fChain->SetBranchAddress("DecayX", &DecayX, &b_DecayX);
   fChain->SetBranchAddress("DecayY", &DecayY, &b_DecayY);
   fChain->SetBranchAddress("DecayZ", &DecayZ, &b_DecayZ);
   fChain->SetBranchAddress("SpinX", &SpinX, &b_SpinX);
   fChain->SetBranchAddress("SpinY", &SpinY, &b_SpinY);
   fChain->SetBranchAddress("SpinZ", &SpinZ, &b_SpinZ);
   fChain->SetBranchAddress("DecayPositronMomtX", &DecayPositronMomtX, &b_DecayPositronMomtX);
   fChain->SetBranchAddress("DecayPositronMomtY", &DecayPositronMomtY, &b_DecayPositronMomtY);
   fChain->SetBranchAddress("DecayPositronMomtZ", &DecayPositronMomtZ, &b_DecayPositronMomtZ);

   fChain->SetBranchAddress("MUONID",&MUONID);
   //fChain->SetBranchAddress("LaserX", &LaserX, &b_LaserX);
   //fChain->SetBranchAddress("LaserY", &LaserY, &b_LaserY);
   //fChain->SetBranchAddress("LaserZ", &LaserZ, &b_LaserZ);
   //fChain->SetBranchAddress("LaserE", &LaserE, &b_LaserE);
   //fChain->SetBranchAddress("LaserXp", &LaserXp, &b_LaserXp);
   //fChain->SetBranchAddress("LaserYp", &LaserYp, &b_LaserYp);
   //fChain->SetBranchAddress("MeshEk", &MeshEk, &b_MeshEk);
   //fChain->SetBranchAddress("MeshE", &MeshE, &b_MeshE);
   //fChain->SetBranchAddress("MeshT", &MeshT, &b_MeshT);
   //fChain->SetBranchAddress("MeshT_ab", &MeshT_ab, &b_MeshT_ab);
   //fChain->SetBranchAddress("MeshX", &MeshX, &b_MeshX);
   //fChain->SetBranchAddress("MeshY", &MeshY, &b_MeshY);
   //fChain->SetBranchAddress("MeshZ", &MeshZ, &b_MeshZ);
   //fChain->SetBranchAddress("MeshXp", &MeshXp, &b_MeshXp);
   //fChain->SetBranchAddress("MeshYp", &MeshYp, &b_MeshYp);
   //fChain->SetBranchAddress("MeshBeta", &MeshBeta, &b_MeshBeta);
   //fChain->SetBranchAddress("MeshVY", &MeshVY, &b_MeshVY);
   //fChain->SetBranchAddress("MeshVX", &MeshVX, &b_MeshVX);
   //fChain->SetBranchAddress("MeshVZ", &MeshVZ, &b_MeshVZ);
   //fChain->SetBranchAddress("DriftT", &DriftT, &b_DriftT);
   //fChain->SetBranchAddress("DriftT_ab", &DriftT_ab, &b_DriftT_ab);
   //fChain->SetBranchAddress("DriftX", &DriftX, &b_DriftX);
   //fChain->SetBranchAddress("DriftY", &DriftY, &b_DriftY);
   //fChain->SetBranchAddress("DriftZ", &DriftZ, &b_DriftZ);

   //hMeshEk = new TH1D("hMeshEk","hMeshEk;MeV",100,0.07e-3,0.20e-3);
   //hMeshT = new TH1D("hMeshT","hMeshT;s",100,20e-9,34e-9);
   //hMeshT_ab = new TH1D("hMeshT_ab","hMeshT_ab;s",100,1.32e-6,1.334e-6);
   //hMeshX = new TH1D("hMeshX","hMeshX;mm",200,-150,150);
   //hMeshY = new TH1D("hMeshY","hMeshY;mm",200,-25,25);
   //hMeshZ = new TH1D("hMeshZ","hMeshZ;mm",200,-100,100);
   //hMeshXp = new TH1D("hMeshXp","hMeshXp",100,-0.04,0.04);
   //hMeshYp = new TH1D("hMeshYp","hMeshYp",100,-0.05,0.05);
//
//   //hMeshBeta = new TH1D("hMeshBeta","hMeshBeta",100,0.0012,0.0019);
//   //hMeshVY = new TH1D("hMeshVY","hMeshVY;mm/s",100,-15e6,15e6);
//   //hMeshVX = new TH1D("hMeshVX","hMeshVX;mm/s",100,-20e6,20e6);
//   //hMeshVZ = new TH1D("hMeshVZ","hMeshVZ;mm/s",100,360e6,560e6);
//
//   //hDriftT = new TH1D("hDriftT","hDriftT;s",100,0.8e-6,1.4e-6);
//   //hDriftT_ab = new TH1D("hDriftT_ab","hDriftT_ab;s",100,2.2e-6,2.7e-6);
//   //hDriftX = new TH1D("hDriftX","hDriftX;mm",200,-150,150);
//   //hDriftY = new TH1D("hDriftY","hDriftY;mm",200,-40,40);
   //hDriftZ = new TH1D("hDriftZ","hDriftZ;mm",200,-100,600);

   hXXp = new TH1D("hXXp","hXXp",100,-16,16);
   hXp2 = new TH1D("hXp2","hXp2",100,0,0.0016);
   hX2 = new TH1D("hX2","hX2",100,0,1e4);
   hYYp = new TH1D("hYYp","hYYp",100,-16,16);
   hYp2 = new TH1D("hYp2","hYp2",100,0,0.0016);
   hY2 = new TH1D("hY2","hY2",100,0,1e4);
   hBetaGamma = new TH1D("hBetaGamma","hBetaGamma",100,0.0012,0.0019);

   hT = new TH1D("hT","hT;T[s];N",nbinT,0,nbinT*Tstep);
   hT_sf = new TH1D("hT_sf","hT_sf;T[s];N",nbinT,0,nbinT*Tstep);


   EmissionX = new TH2D("EmissionX","EmissionX;X;X'",240,-120,120,320,0.16,0.16); // mm
   EmissionY = new TH2D("EmissionY","EmissionY;Y;Y'",500,-25,25,320,0.16,0.16); // mm

   CorrMeshTE = new TH2D("CorrMeshTE","CorrMeshTE;T(s);Ek(MeV)",100,30e-9,80e-9,100,0.185e-3,0.21e-3);

   hZT2D = new TH2D("Z-T-2D","Z-T-2D; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);

   hZY2D = new TH2D("Z-Y-2D","Z-Y-2D; Z(mm);Y (mm)",100,0,30,60,-30,30);
   hZX2D = new TH2D("Z-X-2D","Z-X-2D; Z(mm);X (mm)",100,-40,40,100,-40,40);
   hXY2D = new TH2D("X-Y-2D","X-Y-2D; X(mm);Y (mm)",100,-80,80,60,-30,30);

   hZT2D_sf = new TH2D("Z-T-2D_sf","Z-T-2D_sf; t(us);Z (mm)",nbinT,0e-9,nbinT*Tstep,1000,1,10);

   hZY2D_sf = new TH2D("Z-Y-2D_sf","Z-Y-2D_sf; Z(mm);Y (mm)",500,-10,40,500,-40,40);
   hZX2D_sf = new TH2D("Z-X-2D_sf","Z-X-2D_sf; Z(mm);X (mm)",500,-40,40,500,-40,40);
   hXY2D_sf = new TH2D("X-Y-2D_sf","X-Y-2D_sf; X(mm);Y (mm)",500,-40,40,500,-40,40);
   hZY2D_0 = new TH2D("Z-Y-2D-0","Z-Y-2D-0; Z(mm);Y (mm)",100,0,30,60,-30,30);
   hZX2D_0 = new TH2D("Z-X-2D-0","Z-X-2D-0; Z(mm);X (mm)",100,-40,40,100,-40,40);
   hXY2D_0 = new TH2D("X-Y-2D-0","X-Y-2D-0; X(mm);Y (mm)",100,-80,80,60,-30,30);

   hX1D_0 = new TH1D("X-1D-0","X-1D-0; ;X(mm)",100,-40,40);
   hY1D_0 = new TH1D("Y-1D-0","Y-1D-0; ;Y(mm)",100,0,10);
   hZ1D_0 = new TH1D("Z-1D-0","Z-1D-0; ;Z(mm)",100,-5,30);


   hZY2D_laser = new TH2D("Z-Y-2D-laser","Z-Y-2D-laser; Z(mm);Y (mm)",100,0,30,60,-30,30);

   hZX2D_laser = new TH2D("Z-X-2D-laser","Z-X-2D-laser; Z(mm);X (mm)",100,-5,30,100,-40,40);
   hXY2D_laser = new TH2D("X-Y-2D-laser","X-Y-2D-laser; X(mm);Y (mm)",100,-40,40,60,-30,30);

   hX1D_laser = new TH1D("X-1D-laser","X-1D-laser; ;X(mm)",100,-40,40);
   hY1D_laser = new TH1D("Y-1D-laser","Y-1D-laser; ;Y(mm)",100,-30,30);
   hZ1D_laser = new TH1D("Z-1D-laser","Z-1D-laser; ;Z(mm)",100,-5,30);

   hXYT3D_sf = new TH3D("ZX-T-3D_sf","ZX-T-3D_sf; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);
   hZXY3D_sf = new TH3D("ZXY-3D_sf","ZXY-3D_sf;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);
   hXYT3D = new TH3D("ZX-T-3D","ZX-T-3D; t(us); x (mm); y (mm)",nbinT,0e-9,nbinT*Tstep,100,-40,40,100,-40,40);
   hZXY3D = new TH3D("ZXY-3D","ZXY-3D;   z(mm); x (mm); y (mm)",100,-1,10,100,-40,40,100,-40,40);

   Notify();

   Nentries = fChain->GetEntriesFast();

   c = NewTCanvas("c_intrnl","c_intrnl",1000,1000,2,2);
}

void MuYield_Class::SetLasertime(double Lasertime){
   lasertime = Lasertime;
}

double MuYield_Class::GetDecayT(int Nevent){
   tree->GetEntry(Nevent);
   return DecayT;
}

double MuYield_Class::GetTBeam(int Nevent){
   tree->GetEntry(Nevent);
   return TBeam;
}


bool MuYield_Class::IsInsideLaserRegion(Int_t Nevent = 1, double Lasertime = -1){

   tree->GetEntry(Nevent);

   lasertime = Lasertime;

   double x, y, z, vx, vy, vz, t, muonid;

   const double mmu = 105.658;
   const double light = 299792458; // m/s
   const double massMu = 106.16/light/light; // MeV/c2

   double delT = DecayT - DiffusionT;



   if(
         lasertime == -1 ||
         ( DecayT <= (lasertime*1e-6  - TBeam) )  ||
         (lasertime*1e-6 - TBeam - DiffusionT) < 0
   )return false;


   t = DiffusionT + TBeam;

   x = X_sf;
   y = Y_sf;
   z = Z_sf;
   vx = VX_sf;
   vy = VY_sf;
   vz = VZ_sf;

   LaserE = 0.5 * massMu * 1e-6 * (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV

   t = DiffusionT + TBeam;
   x = X_sf;
   y = Y_sf;
   z = Z_sf;

   x = x + vx * (lasertime*1e-6 - TBeam - DiffusionT);
   y = y + vy * (lasertime*1e-6 - TBeam - DiffusionT);
   z = z + vz * (lasertime*1e-6 - TBeam - DiffusionT);
   t = lasertime*1e-6;

   if(InsideLaserRegion(x,y,z, MCtype))return true;

   return false;

}

Bool_t MuYield_Class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MuYield_Class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MuYield_Class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MuYield_Class_cxx
