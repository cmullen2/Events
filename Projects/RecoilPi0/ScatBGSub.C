//Chris Mullen 29/9/16


TFile *infile = TFile::Open("HelicityNDiff/Testing/Perp/2Angular10Kin.root");
//TFile *infile = TFile::Open("HelicityNDiff/Testing/Para/2Angular10Kin.root");



void DoBGSub(){

TFile *outfile = new TFile("HelicityNDiff/Testing/Perp/BGSub2Angular10Kin.root","recreate");
//TFile *outfile = new TFile("HelicityNDiff/Testing/Para/BGSub2Angular10Kin.root","recreate");

TString hel1name = "ScatteredWCPhiHel1";
TString hel0name = "ScatteredWCPhiHel0";


TString hel1 = hel1name + "ProtonPrompt_All" ;
TString hel0 = hel0name + "ProtonPrompt_All";

TString hel1R = hel1name + "ProtonRandom_All";
TString hel0R = hel0name + "ProtonRandom_All";



TH1F* hHel1 = (TH1F*)infile->Get(TString(hel1));
TH1F* hHel0 = (TH1F*)infile->Get(TString(hel0));

TH1F* hHel1R = (TH1F*)infile->Get(TString(hel1R));
TH1F* hHel0R = (TH1F*)infile->Get(TString(hel0R));


hHel1->Add(hHel1R,-0.5);

hHel0->Add(hHel0R,-0.5);


TString HistName1 = hel1 + "BGSub";
TString HistName0 = hel0 + "BGSub";

hHel1->SetName(HistName1);
hHel0->SetName(HistName0);


hHel1->Write();
hHel0->Write();
outfile->Close();


}



