#ifndef FGG_MELA_FRIENDTREE_HH
#define FGG_MELA_FRIENDTREE_HH

#include "interface/FggTreeBase.hh"
//#include "interface/MelaOutputTree.hh"

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

};

#endif


