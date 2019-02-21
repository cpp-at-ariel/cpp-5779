#########################################################
# Student information
#########################################################
# change to your ID as it appears in moodle!
ID=12345678
#########################################################

#########################################################
# compiler stuff 
#########################################################
CC= gcc
CFLAGS= -Wall -Wvla -Werror -g
#COPTFLAGS= -O -DNDEBUG

CXX= g++
CXXFLAGS= $(CFLAGS) -D_GLIBCXX_DEBUG -std=c++11

CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################

#######################
# Classes name
#######################
CLASS1= Matrix
CLASS2= Rational
#######################


#######################
# executables name
#######################
TEST1= $(CLASS1)Test
TEST2= $(CLASS2)Test
#######################

##########################################################
# sources files
##########################################################
HEADER1= $(CLASS1).hpp
HEADER2= $(CLASS2).hpp

# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTEST1NOMAIN= $(CLASS1)Test.cpp
SRCSTEST2NOMAIN= $(CLASS2)Test.cpp
##########################################################
#########################################################
# actions
#########################################################
all: $(TEST1) $(TEST2)

$(TEST1): $(subst .cpp,.o,$(SRCSTEST1NOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

$(TEST2): $(subst .cpp,.o,$(SRCSTEST2NOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

clean:
	rm *.o $(TEST1) $(TEST2) $(ID).zip checkSubmission -fr

depend: $(SRCSTEST1NOMAIN) $(SRCSTEST2NOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

zipfile:
	zip $(ID).zip $(HEADER1) $(HEADER2) $(SRCSTEST1NOMAIN) $(SRCSTEST2NOMAIN)

checkzipfile:
	rm checkSubmission -fr ; \
	mkdir checkSubmission ; \
	cd checkSubmission ; \
	mkdir Examples ; \
	cp ../$(ID).zip . ;\
	unzip $(ID).zip ;\
	cp ../myassert.hpp . ;\
	cp ../Makefile . ;\
	make ;\
	cd ..

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
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

MatrixTest.o: Matrix.hpp myassert.hpp
RationalTest.o: Rational.hpp myassert.hpp
