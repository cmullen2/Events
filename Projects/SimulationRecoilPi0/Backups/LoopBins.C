#include <vector>
#include <string>


// To change from angular and kin bins to just kin bins, change hbins to a TH1F and change all the casting for it. Also commment out the getYaxis bits including the loop as this is the angles.



//TH1F* hbins;
TH2F* hbins;
//TFile* infile=new TFile("TestingOutput/Physics_CBTaggTAPS_14917.root");
//TFile* infile=new TFile("PerpAngBins/Perp20RunsAngBin.root");

//TFile* infile=new TFile("HelicityNDiff/Para/2Angular10Kin.root");
TFile* infile=new TFile("HelicityNDiff/Perp/2Angular10Kin.root");



void Run(){

//  TFile* outfile=new TFile("PerpAngBins/BGSubPerp20RunsAngBin.root","recreate");

//  TFile* outfile=new TFile("HelicityNDiff/Para/BGSub2Angular10Kin.root","recreate");
  TFile* outfile=new TFile("HelicityNDiff/Perp/BGSub2Angular10Kin.root","recreate");


//  hbins=(TH1F*) infile->Get("Bins");
    hbins=(TH2F*) infile->Get("Bins");
  char* HistoArray[] = {"InvMass","MissingMass","pionCMAngle","pionCMAngleVsE","ScatteredPhiVWCTheta","pionPhiVsE","ScatteredPhiVScatTheta","angleWCProton","phiProtonWC","phiWC","pionPhi","pionPhiVsphiWC","pionPhiVsphiProtonWC","phiWCVsphiProtonWC","ScatteredWCPhiHel1","ScatteredWCPhiHel0","MarkThetadiff","MarkPhidiff","thetaWC","phiWCagain","thetaProtonWC","phiProtonWCagain","MarkThetadiffVsMarkPhidiff"} ;
  int Arraysize = sizeof(HistoArray)/sizeof(HistoArray[0]);
  for (int j=0;j<Arraysize;j++){
	AppendNames(HistoArray[j]);
}

  outfile->Close();
  
  NeutronSub(HistoArray[7]);
  //GetAsym(HistoArray[10]);

}



void AppendNames(TString histoname){

  char* PartArray[] = {"Proton","Neutron"};
  int PartArraysize = sizeof(PartArray)/sizeof(PartArray[0]);

  for(int k=0; k<PartArraysize; k++){
		TString halfname = histoname + PartArray[k] ;
		MakeHist(halfname,histoname);


}

}


void MakeHist(TString hisname, TString origname){
  
  //char* THF2List[] = {"pionCMAngleVsE","ScatteredPhiVWCTheta","pionPhiVsE","ScatteredPhiVScatTheta"};

  for(Int_t l=0;l<(hbins->GetNbinsY())+2;l++ ){
  for(Int_t i=0;i<(hbins->GetNbinsX()+2);i++){

   	TString getHistP1=hisname+Form("PromptEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
	TString getHistP = getHistP1 + Form("_");
	getHistP = getHistP +Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) +  Form("_"); //Angular
    	TString getHistR1=hisname+Form("RandomEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
	TString getHistR = getHistR1 + Form("_");
	getHistR = getHistR +Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) +  Form("_"); //Angular


	cout << getHistP <<endl;
	cout << getHistR << endl;

//	if (origname == THF2List[0] || origname == THF2List[1] || origname == THF2List[2] ||   origname == THF2List[3] ){

//	TString *foo = std::find(std::begin(THF2List), std::end(THF2List),origname);
//	if (foo != std::end(THF2List)){
	// found in array so TH2F!
//}
//	else

//	TH2F* histoPrompt2 = (TH2F*)infile->Get(TString(getHistP));
//	TH2F* histoRandom2 = (TH2F*)infile->Get(TString(getHistR));
//	histoRandom2->Write();
//	histoPrompt2->Write();	
//	BackgroundSub(histoPrompt2,histoRandom2,getHistP);	
//}
//	else{		//Why does this work when some of them are TH2F?? Is it casting? If so, what effect does this have on my final histo!!!
	//****************************************************************************IMPLICIT CASTING, Use the if statement and complete the array.

	TH1F* histoPrompt = (TH1F*)infile->Get(TString(getHistP));
	TH1F* histoRandom = (TH1F*)infile->Get(TString(getHistR));
	histoRandom->Write();
	histoPrompt->Write();	
	BackgroundSub(histoPrompt,histoRandom,getHistP);
		
//}
	

}
}
}

// No real need for a templated class as TH2F inherits from TH1F
template <class T>
void BackgroundSub(T Prompt, T Random, TString Promptname){

	Prompt->Add(Random,-0.5); //Need to make the number a parameter so can make the ratio general.
	TString HistName = Promptname + Form("BGSub");

	Prompt->SetName(HistName);
	Prompt->Write();

}

// Cannot get asym here as will need to have the para and perp files 
//void GetAsym(Tstring origname){


//  TFile* asymin = new TFile("Para/BGSubPara20Runs.root"); 
//  TFile* asymout = new TFile("FirstAttemptTestAsym.root","recreate"); 

 // for(Int_t i=0;i<hbins->GetNbinsX();i++){

	//Make this into a function with Proton, neutron param too, called make name
//	TString hProtonname = origname + Form("Proton") + Form("PromptEg%1.2f",hbins->GetXaxis()->GetBinCenter(i)) + Form("_")+ Form("BGSub");


//}


void NeutronSub(TString origname){

//  TFile* neutronin = new TFile("PerpAngBins/BGSubPerp20RunsAngBin.root"); 
//  TFile* neutronout = new TFile("PerpAngBins/ProSubBGSubPerp20RunsAngBin.root","recreate"); 
 

 // TFile* neutronin = new TFile("HelicityNDiff/Para/BGSub2Angular10Kin.root"); 
//  TFile* neutronout = new TFile("HelicityNDiff/Para/ProSubBGSub2Angular10Kin.root","recreate"); 

  TFile* neutronin = new TFile("HelicityNDiff/Perp/BGSub2Angular10Kin.root"); 
  TFile* neutronout = new TFile("HelicityNDiff/Perp/ProSubBGSub2Angular10Kin.root","recreate"); 


 
  for(Int_t l=0;l<(hbins->GetNbinsY()+2);l++){
  for(Int_t i=0;i<(hbins->GetNbinsX()+2);i++){

//	TString hNeutronname = origname + Form("Neutron") + Form("PromptEg%1.2f",hbins->GetXaxis()->GetBinCenter(i)) + Form("_")+ Form("BGSub");
//	TString hProtonname = origname + Form("Proton") + Form("PromptEg%1.2f",hbins->GetXaxis()->GetBinCenter(i)) + Form("_")+ Form("BGSub");
	
	//Angular
	TString hNeutronname = origname + Form("Neutron") + Form("PromptEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i)) + Form("_")+ Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) + Form("_")  + Form("BGSub");
	TString hProtonname = origname + Form("Proton") + Form("PromptEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i)) + Form("_")+Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) + Form("_") + Form("BGSub");


	TH1F* hNeutron = (TH1F*)neutronin->Get(TString(hNeutronname));
	TH1F* hProton = (TH1F*)neutronin->Get(TString(hProtonname));
	Double_t maxProtonbin = hProton->GetBinContent(hProton->GetMaximumBin());
	Double_t maxNeutronbin = hNeutron->GetBinContent(hNeutron->GetMaximumBin());
	
	TString PHistName = hProtonname + Form("Scaled");
	hProton->SetName(PHistName);

	hProton->Scale(maxNeutronbin/maxProtonbin);

	TString NHistName = hNeutronname + Form("ProSubtrac");
	hNeutron->SetName(NHistName);
	
	hNeutron->Add(hProton,-1);
	
	neutronout->cd();
	hNeutron->Write();
	hProton->Write();
	cout << NHistName << endl;
}
}


neutronout->Close();

}
