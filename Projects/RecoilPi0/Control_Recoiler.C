{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("Selected","datachain");
  // tree->Add("/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/ProtonMain/ProtonGood/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimProtonGood.root");
   //tree->Add("/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/NeutronMain/NeutronGood/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimNeutronGood.root");
   tree->Add("/scratch/chrism/RealData/ChrisGoatOut/Run14920/Physics_CBTaggTAPS_14920.root");
  
   tree->Add("/scratch/chrism/RealData/ChrisGoatOut/Run14922/Physics_CBTaggTAPS_14922.root");
   tree->Add("/scratch/chrism/RealData/ChrisGoatOut/Run14917/Physics_CBTaggTAPS_14917.root");
 //tree->Add("/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/ProtonMain/ProtonBad/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimProtonBad.root");
   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   gSystem->Setenv("HSOUT",
		   "TestingOutput");
   
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
