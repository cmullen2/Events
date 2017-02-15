{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("Selected","datachain");
  // tree->Add("/w/work14/chris/Run101016/ChrisOutput/Para/Physics_CBTaggTAPS_*.root");
  //tree->Add("/w/work14/chris/Run101016/ChrisOutput/Para/Physics_CBTaggTAPS_14961.root");
  //tree->Add("/scratch/chris/Simulations/16d11m16y/AcquMC/ChrisGoatOut/Deuterium/BeamAsym/NegPolarisation/Physics_A2OutNegPol.root");
  //tree->Add("/scratch/chris/Simulations/16d11m16y/AcquMC/ChrisGoatOut/Deuterium/ScatAsym/Physics_A2OutPolNeg_Pol.root");
  tree->Add("/scratch/chris/Simulations/16d11m16y/AcquMC/NegPol/Physics_TestA2OutPolNeg_Pol.root");
 //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   //gSystem->Setenv("HSOUT",
//		   "/home/chris/Events/Projects/RecoilPi0/HelicityNDiff/Para/2Angular10Kin.root");
 
   gSystem->Setenv("HSOUT",
		   "/home/chris/Events/Projects/SimulationRecoilPi0/BeamAsym/Output/Scattered/Test/NegPol.root");
  
   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kFALSE,kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");

   tree->Process("Recoiler.C++");

   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
