ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lTMVA

CXX           = g++
CXXFLAGS      = -g -fPIC -Wno-deprecated -O -ansi -D_GNU_SOURCE -g -O2
LD            = g++
LDFLAGS       = -g
SOFLAGS       = -shared


ARCH         := $(shell root-config --arch)
PLATFORM     := $(shell root-config --platform)


CXXFLAGS      += $(ROOTCFLAGS)
#CXX           += -I./
LIBS           = $(ROOTLIBS) 

NGLIBS         = $(ROOTGLIBS) 
NGLIBS        += -lMinuit 
GLIBS          = $(filter-out -lNew, $(NGLIBS))


INCLUDEDIR           = ./
OUTLIB               = ./lib/

.SUFFIXES: .cc,.C,.hh,.h
.PREFIXES: ./lib/

FggMelaFriend: $(INCLUDEDIR)/src/FggMela.cc \
	$(OUTLIB)FggTreeBase.o \
	$(OUTLIB)FggMelaFriendTree.o
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ldl -o FggMelaFriend $(OUTLIB)/*.o $(GLIBS) $(LDFLAGS) $ $<

$(OUTLIB)FggTreeBase.o: $(INCLUDEDIR)/src/FggTreeBase.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)FggTreeBase.o $<

$(OUTLIB)FggMelaFriendTree.o: $(INCLUDEDIR)/src/FggMelaFriendTree.cc \
	$(OUTLIB)FggTreeBase.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)FggMelaFriendTree.o $<

clean:
	rm -f lib/*o
	rm -f FggMelaFriend
