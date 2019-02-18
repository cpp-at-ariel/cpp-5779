MAINNAME= IntBuffer

#########################################################
# compiler stuff 
#########################################################
CC=clang++-5.0
CFLAGS=-std=c++17 -Wall -Wvla -Werror -g
#COPTFLAGS= -O -DNDEBUG

CXX=clang++-5.0
CXXFLAGS=$(CFLAGS) 

CEXELINKFLAGS=
CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
SRCSEXENOMAIN=  $(MAINNAME).cpp
SRCSEXEMAIN=    $(MAINNAME)Demo.cpp

# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTESTNOMAIN= $(MAINNAME)Test.cpp 
##########################################################


#######################
# executables name
#######################
EXE= $(MAINNAME)Demo
TEST= $(MAINNAME)Test
#######################


#########################################################
# actions
#########################################################
all: $(EXE) $(TEST)

$(EXE): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSEXEMAIN)) 
	$(CXX) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

$(TEST): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

clean:
	rm *.o $(EXE) $(TEST) -f

depend: $(SRCSEXENOMAIN) $(SRCSEXEMAIN) $(SRCSTESTNOMAIN)
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

IntBuffer.o: IntBuffer.hpp
IntBufferDemo.o: IntBuffer.hpp
IntBufferTest.o: IntBuffer.hpp
