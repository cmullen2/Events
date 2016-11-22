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
 // add data members to class for scattering angle stuff Tick, complete the TH2F properly for the one thats set up CMangel Tick
	//and add in the TH1F and TH2F for the scattering angle stuff Tick, run the sims on the desktop for the four Tick and change the paths for the baselfarmstuff


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
//   fHisbins=new TH2F("Bins","Bins",10,300,1300,2,0,180);
   if(fHisbins) fOutput->Add(fHisbins);
//   fHisbins->SetXTitle("EBeam");//give useful axis name
//   fHisbins->SetYTitle("ThetaAngle");//give useful axis name
   THSHisto::ChangeNames();
 //  THSHisto::LoadCut("Cut1");
   THSHisto::LoadCut("ProtonPrompt");
   THSHisto::LoadCut("NeutronPrompt");
   THSHisto::LoadCut("ProtonRandom");
   THSHisto::LoadCut("NeutronRandom");
  
  // THSHisto::LoadCut("ProtonEsum>60");
  // THSHisto::LoadCut("NeutronEsum>60");
  // THSHisto::LoadCut("ProtonEsum>80");
  // THSHisto::LoadCut("NeutronEsum>80");
  // THSHisto::LoadCut("ProtonEsum>100");
  // THSHisto::LoadCut("NeutronEsum>100");
  // THSHisto::LoadCut("ProtonEsum>120");
  // THSHisto::LoadCut("NeutronEsum>120");
   //THSHisto::LoadCut("pionCMAngle");


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
   

//The problem is that some of the participants (protons) are identified only from wc and pid hits and hence have no components to their 4vector.
// The solution to this is, that when all 4 components are zero, we set up a dummy Tlorentzvector and with the angles from the wc hits probably
// from the target centre to wc1 so as not to exclude scattering events. Need to look at Doms function and see what it does with the energy of the 
// Proton. Also need to use the dummy variable for the boosting as well as this will be the only one with components in the px py pz.
// Doms function doesn't depend upon the energy of the participant at all so the prev value of it effects no one. 

 
  //std::cout << "here" <<std::endl;

   Double_t beamEnergy = Ebeam_;
   TVector3 targetPosition;
   targetPosition.SetXYZ(0.,0.,0);   //NEEDS CHANGING since target cell is moved like -6.5cm, see wc.dat files see a2geant.

  
   p4Pion.SetPxPyPzE(Pion_fP_fX,Pion_fP_fY,Pion_fP_fZ,Pion_fE);  

   Double_t massTarget = 1875.612;
   Double_t massProton = 938.272; //in this case the participant
   Double_t massNeutron = 939.565;

   TLorentzVector p4Participant;
   p4Participant.SetPxPyPzE(ProtonCandidate_fP_fX,ProtonCandidate_fP_fY,ProtonCandidate_fP_fZ,ProtonCandidate_fE);

if (p4Participant.X() == 0 && p4Participant.Y() == 0 && p4Participant.Z() == 0 && p4Participant.E() == 0){
	TVector3 WC1;
	WC1.SetXYZ(Chamber1_fX,Chamber1_fY,Chamber1_fZ);
	TVector3 tarCentToWC1= WC1 - targetPosition;	//using wc info as these only have wc and/or pid hit no cb hit
	p4Participant.SetPxPyPzE(tarCentToWC1.X(),tarCentToWC1.Y(),tarCentToWC1.Z(),1039);  //need to set this so can be used for the cmvector stuff, 

}



   Double_t protonLabEnergy = CalcQFThreeBodyRecoilPartT(beamEnergy, p4Pion, p4Participant, massTarget, massProton, massNeutron);
   TLorentzVector p4Proton =  p4Participant;		
   p4Proton.SetE(protonLabEnergy);
//HERE REMEMBER THE PID PHI has -1 if no pid hit

   TLorentzVector CMvec =p4Proton + p4Pion; 
   TLorentzVector boostedProton =CMVector(p4Proton,CMvec);
   TLorentzVector boostedPion =CMVector(p4Pion,CMvec);

   pionCMAngle = (boostedPion.Angle(CMvec.Vect()))*TMath::RadToDeg(); //This vs Ebeam.
   pionPhi = (boostedPion.Phi())*TMath::RadToDeg();; //This vs Ebeam.
   Double_t protonCMAngle = (boostedProton.Angle(CMvec.Vect()))*TMath::RadToDeg();; 

  //Pid coincidence
  
  Double_t pidPhiDiff =Phidiff_ ;

  //Scattering angles

  TVector3 chamber1_Vec;
  TVector3 chamber2_Vec;
  TVector3 pVector1;
  TVector3 pVector2;

  chamber1_Vec.SetXYZ(Chamber1_fX,Chamber1_fY,Chamber1_fZ);
  chamber2_Vec.SetXYZ(Chamber2_fX,Chamber2_fY,Chamber2_fZ); //These are the same.

 // chamber2_Vec.RotateZ(-1.2*TMath::DegToRad()); //*********MUY IMPORTANTE*******

if (chamber1_Vec.X() > -990 ){
  chamber1Theta  = chamber1_Vec.Theta()*TMath::RadToDeg();
  pVector1 = chamber1_Vec - targetPosition;
  pVector2 = chamber2_Vec - chamber1_Vec; 
//These are the vector which will go into Reconstruct. 
  angleWCProton = (pVector1.Angle(pVector2))*TMath::RadToDeg();
 
  //secondpVec2 = chamber2_Vec - targetPosition;
 // secondthetaWC = secondpVec2. ; 
  
  thetaProtonWC = (pVector1.Theta())*TMath::RadToDeg();
  phiProtonWC = (pVector1.Phi())*TMath::RadToDeg();
  phiWC = (pVector2.Phi())*TMath::RadToDeg();
  thetaWC = (pVector2.Theta())*TMath::RadToDeg();
  TVector3 chamberScatterVec =ScatteredVector(pVector1,pVector2);
  scatteredPhi = (chamberScatterVec.Phi())*TMath::RadToDeg();    
  scatteredTheta = chamberScatterVec.Theta()*TMath::RadToDeg();
}

else{

  chamber1Theta  = -1000;
  pVector1.SetXYZ(-1000,-1000,-1000);
  pVector2.SetXYZ(-1000,-1000,-1000);
  angleWCProton =-1000;
  thetaProtonWC = -1000;
  phiProtonWC = -1000;
  phiWC = -1000;
  TVector3 chamberScatterVec;
  chamberScatterVec.SetXYZ(-1000,-1000,-1000);
  scatteredPhi = -1000;    
  scatteredTheta = -1000;


}


//if(scatteredTheta >8 && scatteredTheta < 30){
//if(BeamHelicity_ == 1) {
//ScatteredWCPhiHel1 = scatteredPhi;
//ScatteredWCPhiHel0 =-666;
//}

//else{
//ScatteredWCPhiHel1 = -666;
//ScatteredWCPhiHel0 = scatteredPhi ;
//}

//}
//else {
//ScatteredWCPhiHel1 = -2000 ;
//ScatteredWCPhiHel0 = -2000;
//}


if(chamber1Theta != -1000){
MarkThetadiff = thetaWC - thetaProtonWC  ;
MarkPhidiff = phiWC - phiProtonWC  ;
}

else{

MarkThetadiff = -1000;
MarkPhidiff = -1000;

}



//if(scatteredTheta >8 && scatteredTheta < 30){
if((MarkThetadiff >5 || MarkThetadiff < -5  )){
// && (MarkPhidiff>5 || MarkThetadiff <-5) && (MarkThetadiff != -1000 || MarkPhidiff != -1000 )     ){
if (MarkPhidiff >5 || MarkPhidiff <-5){
if (MarkPhidiff != -1000 && MarkThetadiff != -1000){


ScatPhiCut = scatteredPhi ;
ScatThetaCut = scatteredTheta;


if(BeamHelicity_ == 1) {
ScatteredWCPhiHel1 = scatteredPhi;
ScatteredWCPhiHel0 =-666;
}

else{
ScatteredWCPhiHel1 = -666;
ScatteredWCPhiHel0 = scatteredPhi ;
}

}
}
}
else {
ScatteredWCPhiHel1 = -2000 ;
ScatteredWCPhiHel0 = -2000;
ScatPhiCut = -2000;
ScatThetaCut = -2000;
}









  Double_t Esum = ESum_;
  Double_t TagTime = TaggedTime_;

  Int_t kinBin=GetKinBin(Ebeam_,pionCMAngle);//if fHisbins is defined need to give this meaningful arguments


if (chamber1Theta>-1000){

//PionPhi cuts
if ( ((-p4Pion).Phi()*TMath::RadToDeg()-phiWC) < -30 || ((-p4Pion).Phi()*TMath::RadToDeg() -phiWC) > 30    ){
	return kTRUE;
}


if (  ((-p4Pion).Phi()*TMath::RadToDeg() -phiProtonWC) < -30 ||  ((-p4Pion).Phi()*TMath::RadToDeg() -phiProtonWC)  > 30  ){
	return kTRUE;
}

if ( (phiWC - phiProtonWC) < -50 || (phiWC - phiProtonWC) > 50    ){

	return kTRUE;
}



  // FillHistograms("Cut1",kinBin);
 if (TagTime < 25 && TagTime > -25){

  if (pidPhiDiff < 15 && pidPhiDiff > -1){		//15 (14.4 actually) degrees is pid element separation.

//   FillHistograms("ProtonPrompt",kinBin);
   FillHistograms("ProtonPrompt",0);


}//pidphidiff if close

  else{
// FillHistograms("NeutronPrompt",kinBin);
 FillHistograms("NeutronPrompt",0);


} //pid phi else close

} // TagTime if close 

else if(TagTime < 90 && TagTime > 40 || TagTime > -90 && TagTime < -40 ){
  if (pidPhiDiff < 15 && pidPhiDiff > -1){		//15 (14.4 actually) degrees is pid element separation.

//   FillHistograms("ProtonRandom",kinBin);
   FillHistograms("ProtonRandom",0);


}//pidphidiff if close


  else{
// FillHistograms("NeutronRandom",kinBin);
 FillHistograms("NeutronRandom",0);

} // pidphi else close

}// TagTime else close

} //close chamber1theta



 //  Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
 //  FillHistograms("Cut1",kinBin);
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
  fOutput->Add(MapHist(new TH1F("MissingMass"+sLabel,"M_{mass}"+sLabel,100,1700,2100)));
  fOutput->Add(MapHist(new TH1F("pionCMAngle"+sLabel,"Pion_{CMAngle}"+sLabel,1000,0,250)));
  fOutput->Add(MapHist(new TH2F("pionCMAngleVsE"+sLabel,"Pion_{CMAngle}VsE"+sLabel,100,0,180,100,0,1500)));  //6 rather than 3 ints. see browser
  fOutput->Add(MapHist(new TH2F("ScatteredPhiVWCTheta"+sLabel,"PhiVsTheta_{ScatteredVsWC}"+sLabel,1000,-180,180,1000,0,180)));  
  fOutput->Add(MapHist(new TH2F("pionPhiVsE"+sLabel,"pionPhiVsE"+sLabel,1000,-180,180,1000,0,1500))); 
  fOutput->Add(MapHist(new TH2F("ScatteredPhiVScatTheta"+sLabel,"PhiVsTheta_{Scattered}"+sLabel,1000,-180,180,1000,0,180)));  
  fOutput->Add(MapHist(new TH1F("angleWCProton"+sLabel,"angleWCProton"+sLabel,100,0,180)));
  fOutput->Add(MapHist(new TH1F("phiProtonWC"+sLabel,"Phi_{ProtonUsingWC1}"+sLabel,100,-180,180)));
  fOutput->Add(MapHist(new TH1F("phiWC"+sLabel,"phi_{WC}"+sLabel,100,-180,180)));
  fOutput->Add(MapHist(new TH1F("pionPhi"+sLabel,"pionPhi"+sLabel,100,-180,180))); 

  fOutput->Add(MapHist(new TH1F("pionPhiVsphiWC"+sLabel,"pionPhiVsphiWC"+sLabel,1000,-180,180))); 
  fOutput->Add(MapHist(new TH1F("pionPhiVsphiProtonWC"+sLabel,"pionPhiVsphiProtonWC"+sLabel,1000,-180,180))); 
  fOutput->Add(MapHist(new TH1F("phiWCVsphiProtonWC"+sLabel,"phiWCVsphiProtonWC"+sLabel,1000,-180,180))); 


 // fOutput->Add(MapHist(new TH1F("ScatteredNucleonPhiHel1"+sLabel,"ScatteredNucleonPhiHel1"+sLabel,1000,-180,180))); 
  fOutput->Add(MapHist(new TH1F("ScatteredWCPhiHel1"+sLabel,"ScatteredWCPhiHel1"+sLabel,20,-180,180))); 
 // fOutput->Add(MapHist(new TH1F("ScatteredNucleonPhiHel0"+sLabel,"ScatteredNucleonPhiHel0"+sLabel,1000,-180,180))); 
  fOutput->Add(MapHist(new TH1F("ScatteredWCPhiHel0"+sLabel,"ScatteredWCPhiHel0"+sLabel,20,-180,180))); 


  fOutput->Add(MapHist(new TH1F("MarkThetadiff"+sLabel,"MarkThetadiff"+sLabel,20,-200,200))); 
  fOutput->Add(MapHist(new TH1F("MarkPhidiff"+sLabel,"MarkPhidiff"+sLabel,20,-50,50))); 
  fOutput->Add(MapHist(new TH1F("thetaWC"+sLabel,"thetaWC"+sLabel,20,0,180))); 
  fOutput->Add(MapHist(new TH1F("phiWCagain"+sLabel,"phiWCagain"+sLabel,20,-180,180))); 
  fOutput->Add(MapHist(new TH1F("thetaProtonWC"+sLabel,"thetaProtonWC"+sLabel,20,0,180))); 
  fOutput->Add(MapHist(new TH1F("phiProtonWCagain"+sLabel,"phiProtonWCagain"+sLabel,20,-180,180))); 

  fOutput->Add(MapHist(new TH2F("MarkThetadiffVsMarkPhidiff"+sLabel,"Thetadiff_{Mark}VsPhidiff_{Mark}"+sLabel,1000,-180,180,1000,-60,60)));  //6 rather than 3 ints. see browser

  fOutput->Add(MapHist(new TH2F("ScatPhiCutVsScatThetaCut"+sLabel,"ScatPhiVsScatTheta"+sLabel,1000,-180,180,1000,0,180)));  //6 rather than 3 ints. see browser


//  fOutput->Add(MapHist(new TH1F("pVector2X"+sLabel,"pVector2X"+sLabel,1000,-400,400))); 
//  fOutput->Add(MapHist(new TH1F("pVector2Y"+sLabel,"pVector2Y"+sLabel,1000,-400,400))); 
//  fOutput->Add(MapHist(new TH1F("pVector2Z"+sLabel,"pVector2Z"+sLabel,1000,-400,400))); 


  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Recoiler::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());

  FindHist("InvMass")->Fill(Inv_Mass_Pion_);
  FindHist("MissingMass")->Fill(MissingMass_);
  FindHist("pionCMAngle")->Fill(pionCMAngle);
  ((TH2F*)FindHist("pionCMAngleVsE"))->Fill(pionCMAngle,Ebeam_);
  ((TH2F*)FindHist("ScatteredPhiVWCTheta"))->Fill(scatteredPhi,chamber1Theta);
  ((TH2F*)FindHist("pionPhiVsE"))->Fill(p4Pion.Phi()*TMath::RadToDeg(),Ebeam_);
  ((TH2F*)FindHist("ScatteredPhiVScatTheta"))->Fill(scatteredPhi,scatteredTheta);
  FindHist("angleWCProton")->Fill(angleWCProton);
  FindHist("phiProtonWC")->Fill(phiProtonWC);
  FindHist("phiWC")->Fill(phiWC);
  FindHist("pionPhi")->Fill(p4Pion.Phi()*TMath::RadToDeg());

  ((TH1F*)FindHist("pionPhiVsphiWC"))->Fill((-p4Pion).Phi()*TMath::RadToDeg() - phiWC);
  ((TH1F*)FindHist("pionPhiVsphiProtonWC"))->Fill((-p4Pion).Phi()*TMath::RadToDeg() - phiProtonWC);
  ((TH1F*)FindHist("phiWCVsphiProtonWC"))->Fill(phiWC - phiProtonWC);



//  FindHist("ScatteredNucleonPhiHel1")->Fill();
  FindHist("ScatteredWCPhiHel1")->Fill(ScatteredWCPhiHel1);
  
 // FindHist("ScatteredNucleonPhiHel0")->Fill();
  FindHist("ScatteredWCPhiHel0")->Fill(ScatteredWCPhiHel0);


  FindHist("MarkThetadiff")->Fill(MarkThetadiff);
  FindHist("MarkPhidiff")->Fill(MarkPhidiff);
  FindHist("thetaWC")->Fill(thetaWC);
  FindHist("phiWCagain")->Fill(phiWC);
  FindHist("thetaProtonWC")->Fill(thetaProtonWC);
  FindHist("phiProtonWCagain")->Fill(phiProtonWC);
 
  ((TH2F*)FindHist("MarkThetadiffVsMarkPhidiff"))->Fill(MarkThetadiff,MarkPhidiff);

  ((TH2F*)FindHist("ScatPhiCutVsScatThetaCut"))->Fill(ScatPhiCut,ScatThetaCut);

//  ((TH1F*)FindHist("pVector2X"))->Fill(pVector2.X());
//  ((TH1F*)FindHist("pVector2Y"))->Fill(pVector2.Y());
//  ((TH1F*)FindHist("pVector2Z"))->Fill(pVector2.X());
}



