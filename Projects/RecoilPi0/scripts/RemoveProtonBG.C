TFile *_filesb = TFile::Open("OutputBeamTimeRun14922/Physics_CBTaggTAPS_14922.root");


void RemoveProtonBG(){





TH1F* hisP=angleWCProtonProtonPrompt_All
hisP->Draw()
TH1F* hisN=angleWCProtonNeutronPrompt_All
hisP->Scale(11500./27500) //Change for peak height (need to automate)
hisN->Draw()
hisP->Draw("same")
hisN->Add(hisP,-1)
hisN->Draw()









}
