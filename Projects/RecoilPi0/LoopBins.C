TH1F* hbins;
TFile* infile=new TFile("TestingOutput/Physics_CBTaggTAPS_14917.root");

void Run(){
  hbins=(TH1F*) infile->Get("Bins");
  MakeHist("pionPhi");
}
void MakeHist(TString hisname){
  for(Int_t i=0;i<hbins->GetNbinsX();i++){
    TString getHist=hisname+Form("Eg%1.2f",hbins->GetXaxis()->GetBinCenter(i));
    cout<<getHist<<endl;
  }

}








