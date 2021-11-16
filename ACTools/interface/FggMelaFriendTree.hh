#ifndef FGG_MELA_FRIENDTREE_HH
#define FGG_MELA_FRIENDTREE_HH

#include "FggTreeBase.hh"
#include "MelaAnalytics/CandidateLOCaster/interface/MELACandidateRecaster.h"
#include "MelaAnalytics/GenericMEComputer/interface/MELAOptionParser.h"
#include "MelaAnalytics/GenericMEComputer/interface/MELACluster.h"
#include "MelaAnalytics/GenericMEComputer/interface/MELAHypothesis.h"
#include "MelaAnalytics/GenericMEComputer/interface/MELABranch.h"

class FggMelaFriendTree : public FggTreeBase {
public: 
  FggMelaFriendTree(TTree *tree);
  virtual ~FggMelaFriendTree() { }

  //! configure the needed stuff
  virtual void BeginJob();
  //! close the needed stuff
  virtual void EndJob();
  //! set the output file name
  void setOutputFile(std::string file) { outputFileName_ = file; }

  void init(TTree* tree = 0);
  void Loop();

protected:
  std::string outputFileName_;

private:

  void buildMELABranches();
  // void computeMELABranches(MELACandidate* cand);
  // void updateMELAClusters_Common(const string clustertype);
  // void updateMELAClusters_NoInitialQ(const string clustertype);
  // void updateMELAClusters_NoInitialG(const string clustertype);
  // void updateMELAClusters_NoAssociatedG(const string clustertype);
  // void updateMELAClusters_NoInitialGNoAssociatedG(const string clustertype);
  // void updateMELAClusters_BestLOAssociatedZ(const string clustertype);
  // void updateMELAClusters_BestLOAssociatedW(const string clustertype);
  // void updateMELAClusters_BestLOAssociatedVBF(const string clustertype);
  // void updateMELAClusters_BestNLOVHApproximation(const string clustertype);
  // void updateMELAClusters_BestNLOVBFApproximation(const string clustertype);
  // void pushRecoMELABranches(const pat::CompositeCandidate& cand);
  // void pushLHEMELABranches();
  // void clearMELABranches();

  Mela mela;
  std::vector<std::string> recoMElist;
  std::vector<MELAOptionParser*> recome_originalopts;
  std::vector<MELAOptionParser*> recome_copyopts;
  std::vector<std::string> lheMElist;
  //std::vector<MELAOptionParser*> lheme_originalopts;
  std::vector<MELAOptionParser*> lheme_copyopts;
  std::vector<MELAHypothesis*> lheme_units;
  std::vector<MELAHypothesis*> lheme_aliased_units;
  std::vector<MELAComputation*> lheme_computers;
  std::vector<MELACluster*> lheme_clusters;

};

#endif


