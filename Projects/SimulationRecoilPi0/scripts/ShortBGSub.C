TFile *_filesb = TFile::Open("TEST/Physics_CBTaggTAPS_14920.root");

void BGSub(){
	TFile* file = new TFile("Bullshit.root","recreate");
	
	MakeHist("NoCut");

	file->Close();

}


void MakeHist(TString name){

//Add all the histos you want for each option here 
	
	TH1F* hProtonPromptInv=(TH1F*)_filesb->Get(TString("InvMassProtonPrompt_All"));
	TH1F* hProtonRandomInv=(TH1F*)_filesb->Get(TString("InvMassProtonRandom_All"));
	TH1F* hNeutronPromptInv=(TH1F*)_filesb->Get(TString("InvMassNeutronPrompt_All"));
	TH1F* hNeutronRandomInv=(TH1F*)_filesb->Get(TString("InvMassNeutronRandom_All"));

	hProtonPromptInv->Add(hProtonRandomInv,-0.5);
	hNeutronPromptInv->Add(hNeutronRandomInv,-0.5);
	hProtonPromptInv->Write();     
	hNeutronPromptInv->Write();

    }

