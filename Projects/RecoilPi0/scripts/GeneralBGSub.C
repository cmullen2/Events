#include <vector>
#include <string>

// To change from angular and kin bins to just kin bins, change hbins to a TH1F and change all the casting for it. Also commment out the getYaxis bits including the loop as this is the angles.


//TH1F* hbins;
TH2F* hbins;

TFile* infile=new TFile("HelicityNDiff/Perp/2Angular10Kin.root");

void Run(){

  
  TIter next(gDirectory->GetListOfKeys());
  TKey *key;
  while(key=(TKey*)next()){
	TString hType= key->GetClassName();
	TString hName = key->GetTitle();
	if(hType=="TH1F"){
		
	Int_t lenhName = hName.Length();
//	TString s2= orig(lenorig-6 ,lenorig );

	TH1F* histoPrompt = (TH1F*)infile->Get(TString(hName));
	TString checkPrompt = hName(lenhName-6,lenhName )

	cout << lenorig << s2 << endl;
	
}
	else if( hType=="TH2F") {
//	TH2F* histoPrompt = (TH2F*)infile->Get(TString(hName));

	



	//cout << hType<<  endl; //Gives HistoType
	//cout <<  key->GetTitle()   << endl; //Gives HistoName

}
}

//Dilemma is that need to be able to use the random version of each histo to BGSub but I am currently looping over all of the histos inc. randoms
//Possible choices are taking the prompt one and subtracting off the last 6 letters and adding random on and grabbing that too so can do BGsub, 
//This would require that I use some sort of if for the last six letters being random so don't do anything for these ones

//check to see if prompt or random, if random ignore else if prompt then reconstruct the random using hName(0,lenhName-6) and add on Random to this
//********************* CHECK TO MAKE SURE THE NUMBER OF CHARACTERS IS CORRECT, there is likely an underscore or some pish in there.


}















/*

//  TFile* outfile=new TFile("HelicityNDiff/Para/BGSub2Angular10Kin.root","recreate");
  TFile* outfile=new TFile("HelicityNDiff/Perp/BGSub2Angular10Kin.root","recreate");
//  hbins=(TH1F*) infile->Get("Bins");
    hbins=(TH2F*) infile->Get("Bins");
  for (int j=0;j<Arraysize;j++){
	AppendNames(HistoArray[j]);
}

  outfile->Close();
  
  NeutronSub(HistoArray[7]);
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

   	TString getHistP1=hisname+Form("PromptEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
	TString getHistP = getHistP1 + Form("_");
	getHistP = getHistP +Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) +  Form("_"); //Angular
    	TString getHistR1=hisname+Form("RandomEBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
	TString getHistR = getHistR1 + Form("_");
	getHistR = getHistR +Form("ThetaAngle%1.2f",hbins->GetYaxis()->GetBinCenter(l)) +  Form("_"); //Angular


	cout << getHistP <<endl;
	cout << getHistR << endl;

	TH1F* histoPrompt = (TH1F*)infile->Get(TString(getHistP));
	TH1F* histoRandom = (TH1F*)infile->Get(TString(getHistR));
	histoRandom->Write();
	histoPrompt->Write();	
	BackgroundSub(histoPrompt,histoRandom,getHistP);
		

	

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

} */
