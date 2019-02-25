MAINNAME= Stk

#########################################################
# compiler stuff 
#########################################################
CC= gcc
CFLAGS= -Wall -Wvla -Werror -g
#COPTFLAGS= -O -DNDEBUG

CXX= g++
CXXFLAGS= $(CFLAGS) -std=c++11

CEXELINKFLAGS=
##########################################################


##########################################################
# sources files
##########################################################
SRCSEXENOMAIN= 
SRCSEXEMAIN= $(MAINNAME)Main.cpp
##########################################################


#######################
# executables name
#######################
EXE= $(MAINNAME)Demo
#######################


#########################################################
# actions
#########################################################
all: $(EXE)
	@read -p "Press [Enter] key to start memory check of executable..." MEMCHK
	valgrind --leak-check=full -v ./$(EXE)

$(EXE): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSEXEMAIN)) 
	$(CXX) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

clean:
	rm *.o $(EXE) -f

depend: $(SRCSEXENOMAIN) $(SRCSEXEMAIN) 
	makedepend -Y -- $(CXXFLAGS) -- $^

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

StkMain.o: Stk.hpp
