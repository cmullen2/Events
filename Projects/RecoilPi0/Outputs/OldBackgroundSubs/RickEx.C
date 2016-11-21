#include <vector>
#include <string>
#include "TRandom.h"
#include "RickEx.h" 

//Input data File called infile. (not currently using)
//TFile* infile=new TFile("TestingOutput/Physics_CBTaggTAPS_14917.root");


void Run(){


         //New output file to be created
  TFile* outfile=new TFile("TestExample.root","recreate");

  	// Create Tree
  treeselected =  new TTree("Selected","Event selection tree"); // selected tree   
  //treepid = new TTree("Pid","Event selection tree"); //pid tree
	//Define branches of TTree selected (The . in the names stops naming conflicts when using MakeClass etc. if gives the branches of the TLorentzVectors unique names. )
  treeselected->Branch("Pion.",&PionCan);
  treeselected->Branch("Chamber1X.",&Chamber1_VecX);
  treeselected->Branch("Chamber2.",&Chamber2_Vec);


//Note: define the parameters that will go in your tree in a header file and fill them here. (such as PionCan) 

	//loop for filling dummy variables since not using file at the moment.
	for(Int_t i = 0; i< 2000; i++){ 

        Chamber1_VecX = gRandom->Gaus(5,0.2) ;			//Double_t
	Chamber2_Vec.SetXYZ(gRandom->Gaus(5,0.2),gRandom->Gaus(5,0.2),gRandom->Gaus(5,0.2)); //Tvector3
 	PionCan.SetPxPyPzE(gRandom->Gaus(5,0.2),gRandom->Gaus(7,0.2),gRandom->Gaus(8,0.2),gRandom->Gaus(10,0.2)); //TLorentzVector


	treeselected->Fill();
}

  outfile->Write(); 

//Closing the output file
  outfile->Close();
  
 // NeutronSub(HistoArray[7]);
  //GetAsym(HistoArray[10]);

}


