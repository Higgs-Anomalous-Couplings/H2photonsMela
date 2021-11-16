#include <iostream>

#include "MelaAnalytics/CandidateLOCaster/interface/MELACandidateRecaster.h"

#include "FggMelaFriendTree.hh"


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
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    std::cout << "nLHE part = " << nLHEPart << std::endl;
    std::cout << "npu = " << npu << std::endl;
  }
}

void FggMelaFriendTree::buildMELABranches(){
  // /***********************/
  // /***********************/
  // /**   Reco branches   **/
  // /***********************/
  // /***********************/
  // for (unsigned int it=0; it<recoMElist.size(); it++){
  //   MELAOptionParser* me_opt = new MELAOptionParser(recoMElist.at(it));
  //   if (recoMElist.at(it).find("Copy")!=string::npos) recome_copyopts.push_back(me_opt);
  //   else recome_originalopts.push_back(me_opt);
  // }
  // // Resolve original options
  // for (unsigned int it=0; it<recome_originalopts.size(); it++){
  //   MELAOptionParser* me_opt = recome_originalopts.at(it);
  //   myTree->BookMELABranches(me_opt, false, 0);
  // }
  // // Resolve copy options
  // for (unsigned int it=0; it<recome_copyopts.size(); it++){
  //   MELAOptionParser* me_opt = recome_copyopts.at(it);
  //   MELAOptionParser* original_opt=0;
  //   // Find the original options
  //   for (unsigned int ih=0; ih<recome_originalopts.size(); ih++){
  //     if (me_opt->testCopyAlias(recome_originalopts.at(ih)->getAlias())){
  //       original_opt = recome_originalopts.at(ih);
  //       break;
  //     }
  //   }
  //   if (original_opt==0) continue;
  //   else me_opt->pickOriginalOptions(original_opt);
  //   myTree->BookMELABranches(me_opt, false, 0);
  // }

  // /**********************/
  // /**********************/
  // /**   LHE branches   **/
  // /**********************/
  // /**********************/
  // for (unsigned int it=0; it<lheMElist.size(); it++){
  //   MELAOptionParser* lheme_opt;
  //   // First find out if the option has a copy specification
  //   // These copy options will be evaulated in a separate loop
  //   if (lheMElist.at(it).find("Copy")!=string::npos){
  //     lheme_opt = new MELAOptionParser(lheMElist.at(it));
  //     lheme_copyopts.push_back(lheme_opt);
  //     continue;
  //   }

  //   // Create a hypothesis for each option
  //   MELAHypothesis* lheme_hypo = new MELAHypothesis(&mela, lheMElist.at(it));
  //   lheme_units.push_back(lheme_hypo);

  //   lheme_opt = lheme_hypo->getOption();
  //   if (lheme_opt->isAliased()) lheme_aliased_units.push_back(lheme_hypo);

  //   // Create a computation for each hypothesis
  //   MELAComputation* lheme_computer = new MELAComputation(lheme_hypo);
  //   lheme_computers.push_back(lheme_computer);

  //   // Add the computation to a named cluster to keep track of JECUp/JECDn, or for best-pWH_SM Lep_WH computations
  //   GMECHelperFunctions::addToMELACluster(lheme_computer, lheme_clusters);

  //   // Create the necessary branches for each computation
  //   myTree->BookMELABranches(lheme_opt, true, lheme_computer);
  // }
  // // Resolve copy options
  // for (unsigned int it=0; it<lheme_copyopts.size(); it++){
  //   MELAOptionParser* lheme_opt = lheme_copyopts.at(it);
  //   MELAHypothesis* original_hypo=0;
  //   MELAOptionParser* original_opt=0;
  //   // Find the original options
  //   for (unsigned int ih=0; ih<lheme_aliased_units.size(); ih++){
  //     if (lheme_opt->testCopyAlias(lheme_aliased_units.at(ih)->getOption()->getAlias())){
  //       original_hypo = lheme_aliased_units.at(ih);
  //       original_opt = original_hypo->getOption();
  //       break;
  //     }
  //   }
  //   if (original_opt==0) continue;
  //   else lheme_opt->pickOriginalOptions(original_opt);
  //   // Create a new computation for the copy options
  //   MELAComputation* lheme_computer = new MELAComputation(original_hypo);
  //   lheme_computer->setOption(lheme_opt);
  //   lheme_computers.push_back(lheme_computer);

  //   // The rest is the same story...
  //   // Add the computation to a named cluster to keep track of JECUp/JECDn, or for best-pWH_SM Lep_WH computations
  //   GMECHelperFunctions::addToMELACluster(lheme_computer, lheme_clusters);

  //   // Create the necessary branches for each computation
  //   myTree->BookMELABranches(lheme_opt, true, lheme_computer);
  // }
  // // Loop over the computations to add any contingencies to aliased hypotheses
  // for (unsigned int it=0; it<lheme_computers.size(); it++) lheme_computers.at(it)->addContingencies(lheme_aliased_units);

  // if (DEBUG_MB){
  //   std::vector<MELABranch*>* lheme_branches = myTree->getLHEMELABranches();
  //   for (unsigned int ib=0; ib<lheme_branches->size(); ib++) lheme_branches->at(ib)->Print();
  //   for (unsigned int icl=0; icl<lheme_clusters.size(); icl++) cout << "LHE ME cluster " << lheme_clusters.at(icl)->getName() << " is present in " << lheme_clusters.size() << " clusters with #Computations = " << lheme_clusters.at(icl)->getComputations()->size() << endl;
  // }
}
