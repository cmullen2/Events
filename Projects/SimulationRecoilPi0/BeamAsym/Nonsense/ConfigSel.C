{
  //You need to have the enviroment variable HSANA defined to link to the THS source
  TString HSANA(gSystem->Getenv("HSANA"));
  gROOT->LoadMacro(HSANA+"/MakeHSSelector.C");

  //Set arguments for MakeHSSelector
 IsHisto=kTRUE;  //use THSHisto?
 IsAppendTree=kFALSE; //Append branches to the input tree
 IsNewTree=kFALSE;  //Output a brand new tree
 IsHSTree=kFALSE;   //Use THSOuput to THSParticle interface (probably not)
 IsQval=kFALSE;   //Use Qvalue event weighting algorithm
 IsSW=kFALSE;   //Use sWeights event weighting algorithm
 NLPS=0;   //Use Longitudinal phase space class with NLPS particles

//FileName="/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/ProtonMain/ProtonGood/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimProtonGood.root";   // The input filename containing the tree
// FileName="/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/NeutronMain/NeutronGood/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimNeutronGood.root";   //
 //FileName="/scratch/chris/RealData/ChrisGoatOut/Moeller/Physics_CBTaggTAPS_14917.root";   //
// FileName="/scratch/chris/RealData/ChrisGoatOut/Perp/Physics_CBTaggTAPS_*";   //
// FileName="/home/chris/Documents/PhD/GoatOut/DeuteriumTarget/ProtonMain/ProtonBad/chrisPhysicsRun/Physics_POL_PPi0_OutputA2SimProtonBad.root";   //

 FileName="/scratch/chris/Simulations/16d11m16y/Physics_A2OutNegPol.root";   //

 TreeName="Selected";   // The name of the tree
 OutName="HERE";  //The name of the output directory or file
 SelName="Recoiler";    // The name of the selector to be produced

 //IsParent=kTRUE; //use connection with parent tree
 //StepN=0;        // If connecting with parent, which step number is its selector in
 //ParSel="";

 //Make the selector skeleton + control files in this directory 
 //This is based on the info given above
 MakeHSSelector();

}
