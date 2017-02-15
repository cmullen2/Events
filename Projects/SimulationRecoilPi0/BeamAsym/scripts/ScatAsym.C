//Chris Mullen 29/9/16


TFile *infile = TFile::Open("../Output/Scattered/Test/NegPol.root");
TFile *infile2 = TFile::Open("../Output/Scattered/Test/PosPol.root");
//TFile *infile = TFile::Open("../Output/Scattered/NegPol.root");
//TFile *infile2 = TFile::Open("../Output/Scattered/PosPol.root");
//TFile *infile = TFile::Open("HelicityNDiff/60files/DiffCut/Para/BGSub2Angular10Kin.root");





void DoAsym(){

TFile *outfile = new TFile("../Output/Scattered/Test/ScatAsym.root","recreate");
//TFile *outfile = new TFile("HelicityNDiff/60files/DiffCut/Para/Asym60Para.root","recreate");

TString hel1name = "ScatteredPhi";



TString hel1 = hel1name + "ProtonPrompt_All";



TH1F* hHel1 = (TH1F*)infile->Get(TString(hel1));
TH1F* hHel0 = (TH1F*)infile2->Get(TString(hel1));


TH1F* Asym = hHel1->GetAsymmetry(hHel0);

TF1* fit = new TF1("sinphi", "[0]+ [1]*sin(TMath::DegToRad()*(x+[2]))",-180,180);

Asym->Fit("sinphi");
Asym->Write();
outfile->Close();


}







