#########################################################
# Student information
#########################################################
# change to your ID as it appears in moodle!
ID= 12345678
#########################################################

#########################################################
MAINNAME= GrayvalueImage
#########################################################

#########################################################
# compiler stuff 
#########################################################
CC= gcc
CFLAGS= -Wall -Wvla -Werror -g
#CFLAGS= -O -DNDEBUG # uncomment this for optimization

CXX= g++
CXXFLAGS= $(CFLAGS) -std=c++11 
CXXFLAGS += -D_GLIBCXX_DEBUG # comment this for optimization

CEXELINKFLAGS=
CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
SRCSEXENOMAIN= 
SRCSEXEDEMO= $(MAINNAME)Demo.cpp

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

$(EXE): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSEXEDEMO)) 
	$(CXX) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

$(TEST): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@ #--gtest_filter=test_case_name.test_name #TEST(test_case_name, test_name)

clean:
	rm *.o $(EXE) $(TEST) -f

depend: $(SRCSEXENOMAIN) $(SRCSEXEDEMO) $(SRCSTESTNOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

zipfile:
	zip $(ID).zip GrayvalueImage.hpp

checkzipfile:
	rm checkSubmission -fr ; \
	mkdir checkSubmission ; \
	cd checkSubmission ; \
	cp ../dice.hpp . ;\
	cp ../$(ID).zip . ;\
	unzip $(ID).zip ;\
	cp ../$(SRCSEXEDEMO) . ;\
	cp ../$(SRCSTESTNOMAIN) . ;\
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

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall zipfile checkzipfile


# DO NOT DELETE THIS LINE -- make depend depends on it.

GrayvalueImageDemo.o: GrayvalueImage.hpp dice.hpp
GrayvalueImageTest.o: GrayvalueImage.hpp dice.hpp
