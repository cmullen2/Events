//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 28 21:59:52 2016 by ROOT version 5.34/28
// from TTree Selected/Event selection tree
// found on file: /scratch/chris/RealData/ChrisGoatOut/Para/Physics_CBTaggTAPS_14919.root
//////////////////////////////////////////////////////////

#ifndef TempRecoil_h
#define TempRecoil_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>
#include <TObject.h>
#include <TVector3.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxPion = 1;
   const Int_t kMaxChamber1 = 1;
   const Int_t kMaxChamber2 = 1;
   const Int_t kMaxPhidiff = 1;
   const Int_t kMaxEbeam = 1;
   const Int_t kMaxESum = 1;
   const Int_t kMaxMultiplicity = 1;
   const Int_t kMaxInv_Mass_Pion = 1;
   const Int_t kMaxPidIndex = 1;
   const Int_t kMaxEventno = 1;
   const Int_t kMaxPIDPhi = 1;
   const Int_t kMaxChamber1Phi = 1;
   const Int_t kMaxProtonCandidate = 1;
   const Int_t kMaxMissingMass = 1;
   const Int_t kMaxBeamHelicity = 1;
   const Int_t kMaxTaggedTime = 1;
   const Int_t kMaxTestChamber = 1;

class TempRecoil : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
 //TLorentzVector  *Pion_;
   UInt_t          Pion_TObject_fUniqueID;
   UInt_t          Pion_TObject_fBits;
   UInt_t          Pion_fP_fUniqueID;
   UInt_t          Pion_fP_fBits;
   Double_t        Pion_fP_fX;
   Double_t        Pion_fP_fY;
   Double_t        Pion_fP_fZ;
   Double_t        Pion_fE;
 //TVector3        *Chamber1_;
   UInt_t          Chamber1_TObject_fUniqueID;
   UInt_t          Chamber1_TObject_fBits;
   Double_t        Chamber1_fX;
   Double_t        Chamber1_fY;
   Double_t        Chamber1_fZ;
 //TVector3        *Chamber2_;
   UInt_t          Chamber2_TObject_fUniqueID;
   UInt_t          Chamber2_TObject_fBits;
   Double_t        Chamber2_fX;
   Double_t        Chamber2_fY;
   Double_t        Chamber2_fZ;
   Double_t        Phidiff_;
   Double_t        Ebeam_;
   Double_t        ESum_;
   Int_t           Multiplicity_;
   Double_t        Inv_Mass_Pion_;
   Int_t           PidIndex_;
   Int_t           Eventno_;
   Double_t        PIDPhi_;
   Double_t        Chamber1Phi_;
 //TLorentzVector  *ProtonCandidate_;
   UInt_t          ProtonCandidate_TObject_fUniqueID;
   UInt_t          ProtonCandidate_TObject_fBits;
   UInt_t          ProtonCandidate_fP_fUniqueID;
   UInt_t          ProtonCandidate_fP_fBits;
   Double_t        ProtonCandidate_fP_fX;
   Double_t        ProtonCandidate_fP_fY;
   Double_t        ProtonCandidate_fP_fZ;
   Double_t        ProtonCandidate_fE;
   Double_t        MissingMass_;
   Double_t        BeamHelicity_;
   Double_t        TaggedTime_;
 //TVector3        *TestChamber_;
   UInt_t          TestChamber_TObject_fUniqueID;
   UInt_t          TestChamber_TObject_fBits;
   Double_t        TestChamber_fX;
   Double_t        TestChamber_fY;
   Double_t        TestChamber_fZ;

   // List of branches
   TBranch        *b_Pion_TObject_fUniqueID;   //!
   TBranch        *b_Pion_TObject_fBits;   //!
   TBranch        *b_Pion_fP_fUniqueID;   //!
   TBranch        *b_Pion_fP_fBits;   //!
   TBranch        *b_Pion_fP_fX;   //!
   TBranch        *b_Pion_fP_fY;   //!
   TBranch        *b_Pion_fP_fZ;   //!
   TBranch        *b_Pion_fE;   //!
   TBranch        *b_Chamber1_TObject_fUniqueID;   //!
   TBranch        *b_Chamber1_TObject_fBits;   //!
   TBranch        *b_Chamber1_fX;   //!
   TBranch        *b_Chamber1_fY;   //!
   TBranch        *b_Chamber1_fZ;   //!
   TBranch        *b_Chamber2_TObject_fUniqueID;   //!
   TBranch        *b_Chamber2_TObject_fBits;   //!
   TBranch        *b_Chamber2_fX;   //!
   TBranch        *b_Chamber2_fY;   //!
   TBranch        *b_Chamber2_fZ;   //!
   TBranch        *b_Phidiff_;   //!
   TBranch        *b_Ebeam_;   //!
   TBranch        *b_ESum_;   //!
   TBranch        *b_Multiplicity_;   //!
   TBranch        *b_Inv_Mass_Pion_;   //!
   TBranch        *b_PidIndex_;   //!
   TBranch        *b_Eventno_;   //!
   TBranch        *b_PIDPhi_;   //!
   TBranch        *b_Chamber1Phi_;   //!
   TBranch        *b_ProtonCandidate_TObject_fUniqueID;   //!
   TBranch        *b_ProtonCandidate_TObject_fBits;   //!
   TBranch        *b_ProtonCandidate_fP_fUniqueID;   //!
   TBranch        *b_ProtonCandidate_fP_fBits;   //!
   TBranch        *b_ProtonCandidate_fP_fX;   //!
   TBranch        *b_ProtonCandidate_fP_fY;   //!
   TBranch        *b_ProtonCandidate_fP_fZ;   //!
   TBranch        *b_ProtonCandidate_fE;   //!
   TBranch        *b_MissingMass_;   //!
   TBranch        *b_BeamHelicity_;   //!
   TBranch        *b_TaggedTime_;   //!
   TBranch        *b_TestChamber_TObject_fUniqueID;   //!
   TBranch        *b_TestChamber_TObject_fBits;   //!
   TBranch        *b_TestChamber_fX;   //!
   TBranch        *b_TestChamber_fY;   //!
   TBranch        *b_TestChamber_fZ;   //!

   TempRecoil(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~TempRecoil() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TempRecoil,0);
};

#endif

#ifdef TempRecoil_cxx
void TempRecoil::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Pion.TObject.fUniqueID", &Pion_TObject_fUniqueID, &b_Pion_TObject_fUniqueID);
   fChain->SetBranchAddress("Pion.TObject.fBits", &Pion_TObject_fBits, &b_Pion_TObject_fBits);
   fChain->SetBranchAddress("Pion.fP.fUniqueID", &Pion_fP_fUniqueID, &b_Pion_fP_fUniqueID);
   fChain->SetBranchAddress("Pion.fP.fBits", &Pion_fP_fBits, &b_Pion_fP_fBits);
   fChain->SetBranchAddress("Pion.fP.fX", &Pion_fP_fX, &b_Pion_fP_fX);
   fChain->SetBranchAddress("Pion.fP.fY", &Pion_fP_fY, &b_Pion_fP_fY);
   fChain->SetBranchAddress("Pion.fP.fZ", &Pion_fP_fZ, &b_Pion_fP_fZ);
   fChain->SetBranchAddress("Pion.fE", &Pion_fE, &b_Pion_fE);
   fChain->SetBranchAddress("Chamber1.TObject.fUniqueID", &Chamber1_TObject_fUniqueID, &b_Chamber1_TObject_fUniqueID);
   fChain->SetBranchAddress("Chamber1.TObject.fBits", &Chamber1_TObject_fBits, &b_Chamber1_TObject_fBits);
   fChain->SetBranchAddress("Chamber1.fX", &Chamber1_fX, &b_Chamber1_fX);
   fChain->SetBranchAddress("Chamber1.fY", &Chamber1_fY, &b_Chamber1_fY);
   fChain->SetBranchAddress("Chamber1.fZ", &Chamber1_fZ, &b_Chamber1_fZ);
   fChain->SetBranchAddress("Chamber2.TObject.fUniqueID", &Chamber2_TObject_fUniqueID, &b_Chamber2_TObject_fUniqueID);
   fChain->SetBranchAddress("Chamber2.TObject.fBits", &Chamber2_TObject_fBits, &b_Chamber2_TObject_fBits);
   fChain->SetBranchAddress("Chamber2.fX", &Chamber2_fX, &b_Chamber2_fX);
   fChain->SetBranchAddress("Chamber2.fY", &Chamber2_fY, &b_Chamber2_fY);
   fChain->SetBranchAddress("Chamber2.fZ", &Chamber2_fZ, &b_Chamber2_fZ);
   fChain->SetBranchAddress("Phidiff.", &Phidiff_, &b_Phidiff_);
   fChain->SetBranchAddress("Ebeam.", &Ebeam_, &b_Ebeam_);
   fChain->SetBranchAddress("ESum.", &ESum_, &b_ESum_);
   fChain->SetBranchAddress("Multiplicity.", &Multiplicity_, &b_Multiplicity_);
   fChain->SetBranchAddress("Inv_Mass_Pion.", &Inv_Mass_Pion_, &b_Inv_Mass_Pion_);
   fChain->SetBranchAddress("PidIndex.", &PidIndex_, &b_PidIndex_);
   fChain->SetBranchAddress("Eventno.", &Eventno_, &b_Eventno_);
   fChain->SetBranchAddress("PIDPhi.", &PIDPhi_, &b_PIDPhi_);
   fChain->SetBranchAddress("Chamber1Phi.", &Chamber1Phi_, &b_Chamber1Phi_);
   fChain->SetBranchAddress("ProtonCandidate.TObject.fUniqueID", &ProtonCandidate_TObject_fUniqueID, &b_ProtonCandidate_TObject_fUniqueID);
   fChain->SetBranchAddress("ProtonCandidate.TObject.fBits", &ProtonCandidate_TObject_fBits, &b_ProtonCandidate_TObject_fBits);
   fChain->SetBranchAddress("ProtonCandidate.fP.fUniqueID", &ProtonCandidate_fP_fUniqueID, &b_ProtonCandidate_fP_fUniqueID);
   fChain->SetBranchAddress("ProtonCandidate.fP.fBits", &ProtonCandidate_fP_fBits, &b_ProtonCandidate_fP_fBits);
   fChain->SetBranchAddress("ProtonCandidate.fP.fX", &ProtonCandidate_fP_fX, &b_ProtonCandidate_fP_fX);
   fChain->SetBranchAddress("ProtonCandidate.fP.fY", &ProtonCandidate_fP_fY, &b_ProtonCandidate_fP_fY);
   fChain->SetBranchAddress("ProtonCandidate.fP.fZ", &ProtonCandidate_fP_fZ, &b_ProtonCandidate_fP_fZ);
   fChain->SetBranchAddress("ProtonCandidate.fE", &ProtonCandidate_fE, &b_ProtonCandidate_fE);
   fChain->SetBranchAddress("MissingMass.", &MissingMass_, &b_MissingMass_);
   fChain->SetBranchAddress("BeamHelicity.", &BeamHelicity_, &b_BeamHelicity_);
   fChain->SetBranchAddress("TaggedTime.", &TaggedTime_, &b_TaggedTime_);
   fChain->SetBranchAddress("TestChamber.TObject.fUniqueID", &TestChamber_TObject_fUniqueID, &b_TestChamber_TObject_fUniqueID);
   fChain->SetBranchAddress("TestChamber.TObject.fBits", &TestChamber_TObject_fBits, &b_TestChamber_TObject_fBits);
   fChain->SetBranchAddress("TestChamber.fX", &TestChamber_fX, &b_TestChamber_fX);
   fChain->SetBranchAddress("TestChamber.fY", &TestChamber_fY, &b_TestChamber_fY);
   fChain->SetBranchAddress("TestChamber.fZ", &TestChamber_fZ, &b_TestChamber_fZ);
}

Bool_t TempRecoil::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef TempRecoil_cxx
