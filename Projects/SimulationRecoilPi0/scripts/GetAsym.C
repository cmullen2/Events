//TFile *parafile = TFile::Open("NoKinBins/BGPara.root");
//TFile *perpfile =TFile::Open ("NoKinBins/BGPerp.root");


//TFile *parafile = TFile::Open("ParaAngBins/BGSubPara20RunsAngBin.root");
//TFile *perpfile =TFile::Open ("PerpAngBins/BGSubPerp20RunsAngBin.root");
//TFile *origfile = TFile::Open("ParaAngBins/Para20RunsAngBin.root");


//TFile *parafile = TFile::Open("HelicityNDiff/Para/BGSub2Angular10Kin.root");
//TFile *perpfile =TFile::Open ("HelicityNDiff/Perp/BGSub2Angular10Kin.root");
//TFile *origfile = TFile::Open("HelicityNDiff/Para/2Angular10Kin.root");



TFile *parafile = TFile::Open("HelicityNDiff/60files/DiffCut/Para/BGSub2Angular10Kin.root");
TFile *perpfile =TFile::Open ("HelicityNDiff/60files/DiffCut/Perp/BGSub2Angular10Kin.root");
TFile *origfile = TFile::Open("HelicityNDiff/60files/DiffCut/Para/2Angular10Kin.root");



void GetAsymNone(){

 TFile* outfile = new TFile("HelicityNDiff/60files/DiffCut/Para/Asym60Runs.root","recreate");
 
 TString hname ="pionPhiProtonPrompt_All" ;
 TH1F* hParaPiPhi=(TH1F*)parafile->Get(TString(hname));
 TH1F* hPerpPiPhi=(TH1F*)perpfile->Get(TString(hname));


 TH1F* Asym = hParaPiPhi->GetAsymmetry(hPerpPiPhi); 
 Asym->Write(); 
 outfile->Close();
}

void GetAsymbins(){
 //TFile* outfile = new TFile("Para/AsymBins.root","recreate");

 TFile* outfile = new TFile("VectTest.root","recreate");
 TH1F* hbins=(TH1F*) origfile->Get("Bins");

 const int Numpoints = 10; 
 double a0[Numpoints];
 double a1[Numpoints];
 double a2[Numpoints];
 double b0[Numpoints];
 double b1[Numpoints];
 double b2[Numpoints];
 double energy[Numpoints];

 for(Int_t i=0;i<hbins->GetNbinsX();i++){

 TString hname1 = "pionPhiProtonPrompt" ;
 TString hname2 = hname1 + Form("Eg%1.2f",hbins->GetXaxis()->GetBinCenter(i)) ;
 TString hname = hname2 + Form("_BGSub");
 TH1F* hParaPiPhi=(TH1F*)parafile->Get(TString(hname));
 TH1F* hPerpPiPhi=(TH1F*)perpfile->Get(TString(hname));

 TH1F* Asym = hParaPiPhi->GetAsymmetry(hPerpPiPhi); 

 TF1* fit=new TF1("cos2phi","[0]+[1]*cos(TMath::DegToRad()*(2*x+[2]))",-180,180); 

 fit->SetParLimits(2,80,100);

 Asym->Fit("cos2phi");
 
 a0[i] = fit->GetParameter(0);
 a1[i] =  fit->GetParameter(1);
 a2[i] =  fit->GetParameter(2);

 b0[i] = fit->GetParError(0) ;
 b1[i] = fit->GetParError(1) ;
 b2[i] = fit->GetParError(2);

 energy[i] = hbins->GetXaxis()->GetBinCenter(i);
 Asym->Write(); 
}


 TString hTitle0 ="Fit Parameter 0 (ParaVPerp)Vs bin Energy" ;
 TString hTitle1 ="Fit Parameter 1 (Sigma*LinPol)Vs bin Energy" ;
 TString hTitle2 ="Fit Parameter 2 (Angular Offset)Vs bin Energy" ;

 MakeErrorGraph(a0,b0,energy,Numpoints,hTitle0);
 MakeErrorGraph(a1,b1,energy,Numpoints,hTitle1);
 MakeErrorGraph(a2,b2,energy,Numpoints,hTitle2);

 
 outfile->Close();


}


void GetAsymAnglebins(){

 TFile* outfile = new TFile("HelicityNDiff/60files/DiffCut/Para/AsymAngBins.root","recreate");
 TH1F* hbins=(TH1F*) origfile->Get("Bins");
 
 const int Numpoints = 48 ; //Change to num bins X * Num bins Y //Currently 4Ang * 12 Kin
 double a0[Numpoints];
 double a1[Numpoints];
 double a2[Numpoints];
 double b0[Numpoints];
 double b1[Numpoints];
 double b2[Numpoints];
 double energy[Numpoints];



// TString hname = "pionPhiProtonPrompt" ;
 //TString hel1name = "ScatteredWCPhiHel1ProtonPrompt" ;
// TString hel0name = "ScatteredWCPhiHel0ProtonPrompt" ;
 
 for(Int_t j = 0; j<(hbins->GetNbinsY() +2) ;j++) { 
 for(Int_t i=0;i<(hbins->GetNbinsX() +2) ;i++) {



 TString hname = "pionPhiProtonPrompt" ;
 TString hel1name = "ScatteredWCPhiHel1ProtonPrompt" ;
 TString hel0name = "ScatteredWCPhiHel0ProtonPrompt" ;


 hname = hname + Form("EBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
 hname = hname  +Form("_") + Form("ThetaAngle%1.2f", hbins->GetYaxis()->GetBinCenter(j)) + Form("_BGSub") ;
 
 hel1name = hel1name + Form("EBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
 hel1name = hel1name  +Form("_") + Form("ThetaAngle%1.2f", hbins->GetYaxis()->GetBinCenter(j)) + Form("_BGSub") ;
 hel0name = hel0name + Form("EBeam%1.2f",hbins->GetXaxis()->GetBinCenter(i));
 hel0name = hel0name  +Form("_") + Form("ThetaAngle%1.2f", hbins->GetYaxis()->GetBinCenter(j)) + Form("_BGSub") ;


 TH1F* hParaPiPhi=(TH1F*)parafile->Get(TString(hname));
 TH1F* hPerpPiPhi=(TH1F*)perpfile->Get(TString(hname));

 TH1F* hhel1Para=(TH1F*)parafile->Get(TString(hel1name));
 TH1F* hhel0Para=(TH1F*)parafile->Get(TString(hel0name));
 TH1F* hhel1Perp=(TH1F*)perpfile->Get(TString(hel1name));
 TH1F* hhel0Perp=(TH1F*)perpfile->Get(TString(hel0name));




cout << hname << endl;
cout << hel1name << endl;


 TH1F* ScatAsymPara = hhel1Para->GetAsymmetry(hhel0Para);
 TH1F* ScatAsymPerp = hhel1Perp->GetAsymmetry(hhel0Perp);

 TF1* scatfit = new TF1("sinphi","[0]+[1]*sin(TMath::DegToRad()*(x+[2]))",-180,180); 

 ScatAsymPara->Fit("sinphi");
 ScatAsymPerp->Fit("sinphi");
 

 TString Parahel = hel1name + "Para";
 TString Perphel = hel1name + "Perp";

 ScatAsymPara->SetName(Parahel);
 ScatAsymPerp->SetName(Perphel);

 ScatAsymPara->Write();
 ScatAsymPerp->Write();

 
 TH1F* Asym = hParaPiPhi->GetAsymmetry(hPerpPiPhi); 

 TF1* fit=new TF1("cos2phi","[0]+[1]*cos(TMath::DegToRad()*(2*x+[2]))",-180,180); 
 Asym->Fit("cos2phi");
 
 Int_t counter = j*10 + i ;

 a0[counter] =  fit->GetParameter(0);
 a1[counter] =  fit->GetParameter(1);
 a2[counter] =  fit->GetParameter(2);

 b0[counter] = fit->GetParError(0) ;
 b1[counter] = fit->GetParError(1) ;
 b2[counter] = fit->GetParError(2);

 energy[counter] = hbins->GetXaxis()->GetBinCenter(i);
 Asym->Write(); 


}
}


 cout <<"YOOOOOO"<<"  " << a0[10] << "   " << hbins->GetNbinsX()<< "          " << hbins->GetNbinsY() <<endl;


 TString hTitle0 ="Fit Parameter 0 (ParaVPerp)Vs bin Energy" ;
 TString hTitle1 ="Fit Parameter 1 (Sigma*LinPol)Vs bin Energy" ;
 TString hTitle2 ="Fit Parameter 2 (Angular Offset)Vs bin Energy" ;

 MakeErrorGraph(a0,b0,energy,Numpoints,hTitle0);
 MakeErrorGraph(a1,b1,energy,Numpoints,hTitle1);
 MakeErrorGraph(a2,b2,energy,Numpoints,hTitle2);

 outfile->Close();

}


void MakeErrorGraph(double *param, double *error, double *energy, Int_t NumBins, TString hTitle){

 //cout << hbins->GetNbinsX() << hbins->GetNbinsY() <<endl;

 double energyerror[48] = {0};  //THIS needs to be changed to the number of bins used so no. points in the TGraphErrors. (C++ doesn't allow this sort of initialisation using a parameter rather than digit)
 
 TGraph* FitParams = new TGraphErrors(NumBins,energy,param,energyerror,error);

 FitParams->SetMarkerStyle(20);
 FitParams->Draw("AP");
 FitParams->SetTitle(hTitle);

 FitParams->Write();
  

}





