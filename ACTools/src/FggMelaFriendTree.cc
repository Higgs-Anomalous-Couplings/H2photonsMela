#include <iostream>

#include "interface/FggMelaFriendTree.hh"

using namespace std;

FggMelaFriendTree::FggMelaFriendTree(TTree *tree) :
FggTreeBase(tree)
{
  if(tree !=0) init(tree);
  else return;
}

void FggMelaFriendTree::BeginJob() {
  std::cout << "Starting..." << std::endl;
}

void FggMelaFriendTree::init(TTree* tree) {
  if(!tree) return;
  else Init(tree);
}

void FggMelaFriendTree::EndJob() {
  // output->save();
}

void FggMelaFriendTree::Loop() {
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntries();
  
  Long64_t nbytes = 0, nb = 0;
  Int_t cachesize = 30000000; //30 MBytes
  fChain->SetCacheSize(cachesize);
  fChain->SetCacheLearnEntries(5);
  std::cout << "The chain contains " << nentries << " entries " << endl;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    std::cout << "nLHE part = " << nLHEPart << std::endl;
  }
}
