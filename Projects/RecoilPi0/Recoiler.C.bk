#define Recoiler_cxx
// The class definition in Recoiler.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Recoiler.C")
// Root > T->Process("Recoiler.C","some options")
// Root > T->Process("Recoiler.C+")
//

#include "Recoiler.h"
#include <TH2.h>
#include <TStyle.h>


void Recoiler::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Recoiler::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
  //if you want kinematic bins you must define fHisbins here
   //fHisbins=new TH*()
   if(fHisbins) fOutput->Add(fHisbins);
   //fHisbins->SetXTitle();//give useful axis name
   //fHisbins->SetYTitle();//give useful axis name
   THSHisto::ChangeNames();
   THSHisto::LoadCut("Cut1");
   THSHisto::LoadCut("Proton");
   THSHisto::LoadCut("Neutron");
   THSHisto::LoadCut("ProtonEsum>60");
   THSHisto::LoadCut("NeutronEsum>60");
   THSHisto::LoadCut("ProtonEsum>80");
   THSHisto::LoadCut("NeutronEsum>80");
   THSHisto::LoadCut("ProtonEsum>100");
   THSHisto::LoadCut("NeutronEsum>100");
   THSHisto::LoadCut("ProtonEsum>120");
   THSHisto::LoadCut("NeutronEsum>120");
   THSHisto::LoadHistograms();
}

Bool_t Recoiler::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Recoiler::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   GetEntry(entry); //lazy and slow, you can speed the code up by getting the branches you need to use instead
   //Ready to do some analysis here, before the Fill
   




   Double_t beamEnergy = Ebeam_;
   TLorentzVector p4Pion;
   p4Pion.SetPxPyPzE(Pion_fP_fX,Pion_fP_fY,Pion_fP_fZ,Pion_fE);  

   Double_t massTarget = 1875.612;
   Double_t massProton = 938.272; //in this case the participant
   Double_t massNeutron = 939.565;

   TLorentzVector p4Participant;
   p4Participant.SetPxPyPzE(ProtonCandidate_fP_fX,ProtonCandidate_fP_fY,ProtonCandidate_fP_fZ,ProtonCandidate_fE);

   Double_t protonLabEnergy = CalcQFThreeBodyRecoilPartT(beamEnergy, p4Pion, p4Participant, massTarget, massProton, massNeutron);
   TLorentzVector p4Proton =  p4Participant;
   p4Proton.SetE(protonLabEnergy);


   TLorentzVector CMvec =p4Proton + p4Pion; 
   TLorentzVector boostedProton =CMVector(p4Proton,CMvec);
   TLorentzVector boostedPion =CMVector(p4Pion,CMvec);

   Double_t pionCMAngle = boostedPion.Angle(CMvec.Vect()); //This vs Ebeam.
   Double_t protonCMAngle = boostedProton.Angle(CMvec.Vect()); 

  //Pid coincidence
  
  Double_t pidPhiDiff =Phidiff_ ;

  //Scattering angles

  TVector3 chamber1_Vec;
  TVector3 chamber2_Vec;
  TVector3 targetPosition;
  TVector3 pVector1;
  TVector3 pVector2;

  chamber1_Vec.SetXYZ(Chamber1_fX,Chamber1_fY,Chamber1_fZ);
  chamber2_Vec.SetXYZ(Chamber2_fX,Chamber2_fY,Chamber2_fZ);
//missing mass too. TICK

  targetPosition.SetXYZ(0.,0.,-6.5);   //NEEDS CHANGING since target cell is moved like -6.5cm, see wc.dat files see a2geant.
  pVector1 = chamber1_Vec - targetPosition;
  pVector2 = chamber2_Vec - chamber1_Vec;
//These are the vector which will go into Reconstruct. 

  TVector3 chamberScatterVec =ScatteredVector(pVector1,pVector2);

  Double_t scatteredPhi = chamberScatterVec.Phi()*TMath::RadToDeg();  //Look at these, plots 1D and 2D. Plot of this vs WC1 theta.  
  Double_t scatteredTheta = chamberScatterVec.Theta()*TMath::RadToDeg();

//For all do 60,80,100,120 cuts in Esum, do prot and neut for all, if greater Esum than 60 etc for both proton and neut

  Double_t Esum = ESum_;



  if (pidPhiDiff < 15){		//15 degrees is pid element separation. Can put this down then?

   FillHistograms("Proton",0);
  if (Esum > 60){
     FillHistograms("ProtonEsum>60",0);
}
  
 if (Esum > 80){
     FillHistograms("ProtonEsum>80",0);
}
 if (Esum > 100){
     FillHistograms("ProtonEsum>100",0);
}
 if (Esum > 120){
     FillHistograms("ProtonEsum>120",0);
}

}//pidphidiff if close

  else{
 FillHistograms("Neutron",0);
 if (Esum > 60){
     FillHistograms("NeutronEsum>60",0);
}

if (Esum > 80){
   FillHistograms("NeutronEsum>80",0);
}


if (Esum > 100){
   FillHistograms("NeutronEsum>100",0);
}

if (Esum > 120){
   FillHistograms("NeutronEsum>120",0);
}


}//pidphidiff else close



   //Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
   FillHistograms("Cut1",0);
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void Recoiler::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Recoiler::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void Recoiler::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
  //end of histogram list
  
  fOutput->Add(MapHist(new TH1F("InvMass"+sLabel,"M_{Inv}"+sLabel,100,100,250)));
  fOutput->Add(MapHist(new TH1F("MissingMass"+sLabel,"M_{mass}"+sLabel,100,100,250)));
  //fOutput->Add(MapHist(new TH1F("InvMass"+sLabel,"M_{Inv}"+sLabel,100,100,250)));



  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Recoiler::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());
  FindHist("InvMass")->Fill(Inv_Mass_Pion_);
  FindHist("MissingMass")->Fill(Missing_Mass_);
  //FindHist("")->Fill();
}
