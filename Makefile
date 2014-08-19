# SQLiter - Makefile
# Author:- Rohit Rangan
#
# Makefile for the C++ code.

CXX=c++
CXXFLAGS= -Wall -Wextra
CXXSRCS=src/main.cpp src/parse_input.cpp src/string_util.cpp src/logic.cpp
CXXOBJS=$(CXXSRCS:.cpp=.o)
LIBS=
INCLUDES=-I./include
TARGET=resolution
#DEBUGFLAGS=-g -ggdb -O0 -fno-inline

# Required for the target clean.
RM=rm -rf

CXXFLAGS+=$(DEBUGFLAGS) $(INCLUDES) $(LIBS)

all : $(CXXSRCS) $(CXXOBJS) $(TARGET)

$(TARGET) : $(CXXOBJS)
	$(CXX) $(CXXOBJS) -o $(TARGET)

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) src/*.o src/*.dSYM $(TARGET)

depend : .depend

.depend : $(CXXSRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF ./.depend

.PHONY : clean

include .depend
