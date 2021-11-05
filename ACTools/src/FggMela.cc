// C++ includes
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// ROOT includes
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "interface/FggMelaFriendTree.hh"

using namespace std;

int main(int argc, char* argv[]) {

  char inputFileName[500];
  char outputFileName[500];
  if ( argc < 3 ){
    std::cout << "missing argument: insert at least inputFile with list of root files and the output file w/o .root" << std::endl; 
    std::cout << "VecbosApp inputFile outputFile" << std::endl;
    return 1;
  }
  strcpy(inputFileName,argv[1]);
  strcpy(outputFileName,argv[2]);

  // -------------------------
  // Loading the file
  TChain *theChain = new TChain("vbfTagDumper/trees/vbf_125_13TeV_GeneralDipho");
  char Buffer[500];
  char MyRootFile[2000];
  std::cout << "input: " << inputFileName << std::endl;
  ifstream *inputFile = new ifstream(inputFileName);
  char tmpFileName[256];
  vector<string> filesToRemove;
  while( !(inputFile->eof()) ){
    inputFile->getline(Buffer,500);
    if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer)))
      {
        sscanf(Buffer,"%s",MyRootFile);
        theChain->Add(TString(MyRootFile));
        std::cout << "chaining " << MyRootFile << std::endl;
      }
  }
  inputFile->close();
  delete inputFile;

  cout << "Will put the output in file = " << outputFileName << endl;

  FggMelaFriendTree friendTree(theChain);
  friendTree.setOutputFile(outputFileName);
  friendTree.BeginJob();
  friendTree.Loop();
  friendTree.EndJob();

}
