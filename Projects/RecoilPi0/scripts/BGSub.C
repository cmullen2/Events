TFile *_filesb = TFile::Open("NoKinBins/Perp/Perp20filesNoKins.root");

void BGSub(){
	TFile* file = new TFile("NoKinBins/BGPerp.root","recreate");
	
	MakeHist("NoCut");

	file->Close();

}


void MakeHist(TString name){

//Add all the histos you want for each option here 

	TH1F* hProtonPromptInv=(TH1F*)_filesb->Get(TString("InvMassProtonPrompt_All"));
	TH1F* hProtonRandomInv=(TH1F*)_filesb->Get(TString("InvMassProtonRandom_All"));

	TH1F* hProtonPromptMM=(TH1F*)_filesb->Get(TString("MissingMassProtonPrompt_All"));
	TH1F* hProtonRandomMM=(TH1F*)_filesb->Get(TString("MissingMassProtonRandom_All"));

	TH1F* hProtonPromptPiCMAng=(TH1F*)_filesb->Get(TString("pionCMAngleProtonPrompt_All"));
	TH1F* hProtonRandomPiCMAng=(TH1F*)_filesb->Get(TString("pionCMAngleProtonRandom_All"));

	TH2F* hProtonPromptPiCMAngVE=(TH2F*)_filesb->Get(TString("pionCMAngleVsEProtonPrompt_All"));
	TH2F* hProtonRandomPiCMAngVE=(TH2F*)_filesb->Get(TString("pionCMAngleVsEProtonRandom_All"));

	TH2F* hProtonPromptSPhiVWCTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVWCThetaProtonPrompt_All"));
	TH2F* hProtonRandomSPhiVWCTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVWCThetaProtonRandom_All"));

	TH2F* hProtonPromptPiPhiVE=(TH2F*)_filesb->Get(TString("pionPhiVsEProtonPrompt_All"));
	TH2F* hProtonRandomPiPhiVE=(TH2F*)_filesb->Get(TString("pionPhiVsEProtonRandom_All"));

	TH2F* hProtonPromptSPhiVSTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVScatThetaProtonPrompt_All"));
	TH2F* hProtonRandomSPhiVSTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVScatThetaProtonRandom_All"));

	TH1F* hProtonPromptAngleWCP=(TH1F*)_filesb->Get(TString("angleWCProtonProtonPrompt_All"));
	TH1F* hProtonRandomAngleWCP=(TH1F*)_filesb->Get(TString("angleWCProtonProtonRandom_All"));

	TH1F* hProtonPromptPhiPWC=(TH1F*)_filesb->Get(TString("phiProtonWCProtonPrompt_All"));
	TH1F* hProtonRandomPhiPWC=(TH1F*)_filesb->Get(TString("phiProtonWCProtonRandom_All"));

	TH1F* hProtonPromptPhiWC=(TH1F*)_filesb->Get(TString("phiWCProtonPrompt_All"));
	TH1F* hProtonRandomPhiWC=(TH1F*)_filesb->Get(TString("phiWCProtonRandom_All"));

	TH1F* hProtonPromptPiPhi=(TH1F*)_filesb->Get(TString("pionPhiProtonPrompt_All"));
	TH1F* hProtonRandomPiPhi=(TH1F*)_filesb->Get(TString("pionPhiProtonRandom_All"));

	TH1F* hProtonPromptPiPhiVPhiWC=(TH1F*)_filesb->Get(TString("pionPhiVsphiWCProtonPrompt_All"));
	TH1F* hProtonRandomPiPhiVPhiWC=(TH1F*)_filesb->Get(TString("pionPhiVsphiWCProtonRandom_All"));
	
	TH1F* hProtonPromptPiPhiVPhiWCP=(TH1F*)_filesb->Get(TString("pionPhiVsphiProtonWCProtonPrompt_All"));
	TH1F* hProtonRandomPiPhiVPhiWCP=(TH1F*)_filesb->Get(TString("pionPhiVsphiProtonWCProtonRandom_All"));
	
	TH1F* hProtonPromptPhiWCVPhiWCP=(TH1F*)_filesb->Get(TString("phiWCVsphiProtonWCProtonPrompt_All"));
	TH1F* hProtonRandomPhiWCVPhiWCP=(TH1F*)_filesb->Get(TString("phiWCVsphiProtonWCProtonRandom_All"));







	TH1F* hNeutronPromptInv=(TH1F*)_filesb->Get(TString("InvMassNeutronPrompt_All"));
	TH1F* hNeutronRandomInv=(TH1F*)_filesb->Get(TString("InvMassNeutronRandom_All"));

	TH1F* hNeutronPromptMM=(TH1F*)_filesb->Get(TString("MissingMassNeutronPrompt_All"));
	TH1F* hNeutronRandomMM=(TH1F*)_filesb->Get(TString("MissingMassNeutronRandom_All"));
	
	TH1F* hNeutronPromptPiCMAng=(TH1F*)_filesb->Get(TString("pionCMAngleNeutronPrompt_All"));
	TH1F* hNeutronRandomPiCMAng=(TH1F*)_filesb->Get(TString("pionCMAngleNeutronRandom_All"));
	
	TH2F* hNeutronPromptPiCMAngVE=(TH2F*)_filesb->Get(TString("pionCMAngleVsENeutronPrompt_All"));
	TH2F* hNeutronRandomPiCMAngVE=(TH2F*)_filesb->Get(TString("pionCMAngleVsENeutronRandom_All"));
	
	TH2F* hNeutronPromptSPhiVWCTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVWCThetaNeutronPrompt_All"));
	TH2F* hNeutronRandomSPhiVWCTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVWCThetaNeutronRandom_All"));
	
	TH2F* hNeutronPromptSPhiVSTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVScatThetaNeutronPrompt_All"));
	TH2F* hNeutronRandomSPhiVSTheta=(TH2F*)_filesb->Get(TString("ScatteredPhiVScatThetaNeutronRandom_All"));

	TH1F* hNeutronPromptAngleWCP=(TH1F*)_filesb->Get(TString("angleWCProtonNeutronPrompt_All"));
	TH1F* hNeutronRandomAngleWCP=(TH1F*)_filesb->Get(TString("angleWCProtonNeutronRandom_All"));

	TH2F* hNeutronPromptPiPhiVE=(TH2F*)_filesb->Get(TString("pionPhiVsENeutronPrompt_All"));
	TH2F* hNeutronRandomPiPhiVE=(TH2F*)_filesb->Get(TString("pionPhiVsENeutronRandom_All"));

	TH1F* hNeutronPromptPhiPWC=(TH1F*)_filesb->Get(TString("phiProtonWCNeutronPrompt_All"));
	TH1F* hNeutronRandomPhiPWC=(TH1F*)_filesb->Get(TString("phiProtonWCNeutronRandom_All"));

	TH1F* hNeutronPromptPhiWC=(TH1F*)_filesb->Get(TString("phiWCNeutronPrompt_All"));
	TH1F* hNeutronRandomPhiWC=(TH1F*)_filesb->Get(TString("phiWCNeutronRandom_All"));

	TH1F* hNeutronPromptPiPhi=(TH1F*)_filesb->Get(TString("pionPhiNeutronPrompt_All"));
	TH1F* hNeutronRandomPiPhi=(TH1F*)_filesb->Get(TString("pionPhiNeutronRandom_All"));
	
	TH1F* hNeutronPromptPiPhiVPhiWC=(TH1F*)_filesb->Get(TString("pionPhiVsphiWCNeutronPrompt_All"));
	TH1F* hNeutronRandomPiPhiVPhiWC=(TH1F*)_filesb->Get(TString("pionPhiVsphiWCNeutronRandom_All"));
	
	TH1F* hNeutronPromptPiPhiVPhiWCP=(TH1F*)_filesb->Get(TString("pionPhiVsphiProtonWCNeutronPrompt_All"));
	TH1F* hNeutronRandomPiPhiVPhiWCP=(TH1F*)_filesb->Get(TString("pionPhiVsphiProtonWCNeutronRandom_All"));
	
	TH1F* hNeutronPromptPhiWCVPhiWCP=(TH1F*)_filesb->Get(TString("phiWCVsphiProtonWCNeutronPrompt_All"));
	TH1F* hNeutronRandomPhiWCVPhiWCP=(TH1F*)_filesb->Get(TString("phiWCVsphiProtonWCNeutronRandom_All"));






	hProtonPromptInv->Add(hProtonRandomInv,-0.5);
	hProtonPromptMM->Add(hProtonRandomMM,-0.5);
	hProtonPromptPiCMAng->Add(hProtonRandomPiCMAng,-0.5);
	hProtonPromptPiCMAngVE->Add(hProtonRandomPiCMAngVE,-0.5);
	hProtonPromptSPhiVWCTheta->Add(hProtonRandomSPhiVWCTheta,-0.5);
	hProtonPromptPiPhiVE->Add(hProtonRandomPiPhiVE,-0.5);
	hProtonPromptSPhiVSTheta->Add(hProtonRandomSPhiVSTheta,-0.5);
	hProtonPromptAngleWCP->Add(hProtonRandomAngleWCP,-0.5);
	hProtonPromptPhiPWC->Add(hProtonRandomPhiPWC,-0.5);
	hProtonPromptPhiWC->Add(hProtonRandomPhiWC,-0.5);
	hProtonPromptPiPhi->Add(hProtonRandomPiPhi,-0.5);
	
	hProtonPromptPiPhiVPhiWC->Add(hProtonRandomPiPhiVPhiWC,-0.5);
	hProtonPromptPiPhiVPhiWCP->Add(hProtonRandomPiPhiVPhiWCP,-0.5);
	hProtonPromptPhiWCVPhiWCP->Add(hProtonRandomPhiWCVPhiWCP,-0.5);




	hNeutronPromptInv->Add(hNeutronRandomInv,-0.5);
	hNeutronPromptMM->Add(hNeutronRandomMM,-0.5);
	hNeutronPromptPiCMAng->Add(hNeutronRandomPiCMAng,-0.5);
	hNeutronPromptPiCMAngVE->Add(hNeutronRandomPiCMAngVE,-0.5);
	hNeutronPromptSPhiVWCTheta->Add(hNeutronRandomSPhiVWCTheta,-0.5);
	hNeutronPromptPiPhiVE->Add(hNeutronRandomPiPhiVE,-0.5);
	hNeutronPromptSPhiVSTheta->Add(hNeutronRandomSPhiVSTheta,-0.5);
	hNeutronPromptAngleWCP->Add(hNeutronRandomAngleWCP,-0.5);
	hNeutronPromptPhiPWC->Add(hNeutronRandomPhiPWC,-0.5);
	hNeutronPromptPhiWC->Add(hNeutronRandomPhiWC,-0.5);
	hNeutronPromptPiPhi->Add(hNeutronRandomPiPhi,-0.5);

	hNeutronPromptPiPhiVPhiWC->Add(hNeutronRandomPiPhiVPhiWC,-0.5);
	hNeutronPromptPiPhiVPhiWCP->Add(hNeutronRandomPiPhiVPhiWCP,-0.5);
	hNeutronPromptPhiWCVPhiWCP->Add(hNeutronRandomPhiWCVPhiWCP,-0.5);



	//TH2F* hPiPhiVPhiWC=; 





    hProtonPromptInv->Write();     
    hProtonPromptMM->Write();     
    hProtonPromptPiCMAng->Write();     
    hProtonPromptPiCMAngVE->Write();     
    hProtonPromptSPhiVWCTheta->Write();     
    hProtonPromptPiPhiVE->Write();     
    hProtonPromptSPhiVSTheta->Write();     
    hProtonPromptAngleWCP->Write();     
    hProtonPromptPhiPWC->Write();     
    hProtonPromptPhiWC->Write();     
    hProtonPromptPiPhi->Write();     
  
    hProtonPromptPiPhiVPhiWC->Write();
    hProtonPromptPiPhiVPhiWCP->Write();
    hProtonPromptPhiWCVPhiWCP->Write();





    hNeutronPromptInv->Write();
    hNeutronPromptMM->Write();
    hNeutronPromptPiCMAng->Write();
    hNeutronPromptPiCMAngVE->Write();
    hNeutronPromptSPhiVWCTheta->Write();
    hNeutronPromptPiPhiVE->Write();
    hNeutronPromptSPhiVSTheta->Write();
    hNeutronPromptAngleWCP->Write();
    hNeutronPromptPhiPWC->Write();
    hNeutronPromptPhiWC->Write();
    hNeutronPromptPiPhi->Write();

    hNeutronPromptPiPhiVPhiWC->Write();
    hNeutronPromptPiPhiVPhiWCP->Write();
    hNeutronPromptPhiWCVPhiWCP->Write();

//   TCanvas *c1 = new TCanvas("c1","c1",600,400);
//   TH1F* hisP=hProtonPromptAngleWCP;//angleWCProtonProtonPrompt_All"));
//   hisP->Draw();
 //  TH1F* hisN=hNeutronPromptAngleWCP;
  // hisP->Scale(11500./27500); //Change for peak height (need to automate)
//   hisN->Draw();
//   hisP->Draw("same");
//   hisP->SetLineColor(kRed);

  // TCanvas *c2 = new TCanvas("c2","c2",600,400);
  // c2->cd();

 //  hisN->Add(hisP,-1);
//   hisN->Draw();

//   hisN->Write();
//   hisP->Write();

    }

