COMPILEPATH          = $(PWD)/
BASEINCLUDE          = $(COMPILEPATH)/../
MELADIR              = $(BASEINCLUDE)JHUGenMELA/MELA/
MELALIBDIR           = $(MELADIR)/data/${SCRAM_ARCH}
MELACANDIDATEDIR     = $(BASEINCLUDE)MelaAnalytics/CandidateLOCaster/
MELACANDIDATELIBDIR  = $(MELACANDIDATEDIR)src/
INCLUDEDIR           = $(COMPILEPATH)interface/
SRCDIR               = $(COMPILEPATH)src/
LIBDIR               = $(COMPILEPATH)lib/

ROOTCFLAGS    = $(shell root-config --cflags) -Lrootlib
ROOTLIBS      = $(shell root-config --libs) -Lrootlib
ROOTGLIBS     = $(shell root-config --glibs) -lTMVA

ARCH         := $(shell root-config --arch)
PLATFORM     := $(shell root-config --platform)

CXX           = g++
CXXFLAGS      = -g -fPIC -Wno-deprecated -O -ansi -D_GNU_SOURCE -g -O2 $(ROOTCFLAGS) -I$(ROOFITSYS)/include/ -I$(INCLUDEDIR) -I$(BASEINCLUDE) -I$(MELADIR)/interface/ -L$(MELALIBDIR) -L$(MELACANDIDATELIBDIR)
LINKERFLAGS   = -Wl,-rpath=$(LIBDIR),-soname

LDFLAGS       = -g
SOFLAGS       = -shared


NLIBS         = $(ROOTLIBS)
# Hack here, because RooFit is removed from ROOT:
NLIBS        += -L $(ROOFITSYS)/lib/ -lMinuit -lRooFitCore -lRooFit #-lboost_regex
# Libraries for common user packages
NLIBS        += -lJHUGenMELAMELA -lcollier
# Filter out libNew because it leads to floating-point exceptions in versions of ROOT prior to 6.08.02
# See the thread https://root-forum.cern.ch/t/linking-new-library-leads-to-a-floating-point-exception-at-startup/22404
LIBS          = $(filter-out -lNew, $(NLIBS))


.SUFFIXES: .cc,.C,.hh,.h
.PREFIXES: ./lib/

FggMelaFriend: $(SRCDIR)FggMela.cc \
	$(LIBDIR)FggTreeBase.o \
	$(LIBDIR)FggMelaFriendTree.o
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ldl -o FggMelaFriend $(LIBDIR)/*.o $(LIBS) $(LDFLAGS) $ $<

$(LIBDIR)FggTreeBase.o: $(SRCDIR)FggTreeBase.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(LIBDIR)FggTreeBase.o $<

$(LIBDIR)FggMelaFriendTree.o: $(SRCDIR)FggMelaFriendTree.cc \
	$(LIBDIR)FggTreeBase.o \
	$(MELACANDIDATELIBDIR)MELACandidateRecaster.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(LIBDIR)FggMelaFriendTree.o $(LIBS) $<

clean:
	rm -f lib/*o
	rm -f FggMelaFriend
