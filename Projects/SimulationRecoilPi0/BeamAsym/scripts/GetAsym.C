TFile *parafile = TFile::Open("../Output/NegPol/NegPol.root");
TFile *perpfile =TFile::Open ("../Output/PosPol/PosPol.root");
//TFile *origfile = TFile::Open("HelicityNDiff/60files/DiffCut/Para/2Angular10Kin.root");



void GetAsymNone(){

 TFile* outfile = new TFile("../Output/BeamAsyms.root","recreate");
 
 TString hname ="pionPhiProtonPrompt_All" ;
 TH1F* hParaPiPhiPro=(TH1F*)parafile->Get(TString(hname));
 TH1F* hPerpPiPhiPro=(TH1F*)perpfile->Get(TString(hname));

 TString hnameN ="pionPhiNeutronPrompt_All" ;
 TH1F* hParaPiPhiNeu=(TH1F*)parafile->Get(TString(hnameN));
 TH1F* hPerpPiPhiNeu=(TH1F*)perpfile->Get(TString(hnameN));

 TString hname ="pionPhiAllTest_All" ;
 TH1F* hParaPiPhiAll=(TH1F*)parafile->Get(TString(hname));
 TH1F* hPerpPiPhiAll=(TH1F*)perpfile->Get(TString(hname));


 TH1F* AsymPro = hParaPiPhiPro->GetAsymmetry(hPerpPiPhiPro); 
 TH1F* AsymNeu = hParaPiPhiNeu->GetAsymmetry(hPerpPiPhiNeu); 
 TH1F* AsymAll = hParaPiPhiAll->GetAsymmetry(hPerpPiPhiAll); 

 TF1* fit=new TF1("cos2phi","[0]+[1]*cos(TMath::DegToRad()*(2*x+[2]))",-180,180); 

 fit->SetParLimits(2,80,100);

 AsymPro->Fit("cos2phi");



 AsymPro->Write(); 
 AsymNeu->Write(); 
 AsymAll->Write();
 outfile->Close();
}

