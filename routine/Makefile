# ----------------------------------------------- #
# ** Makefile for mbCO2 routine **
# ----------------------------------------------- #

1B = mbCO2
2B = mbCO2AR

CPP = g++
OP = -O2
CPPFLAGS = -fPIC -std=c++0x $(DEGREE)
SONAME = -install_name
INC = -I/usr/include
LIB = -lstdc++

SRC = $(wildcard *.cpp)
INC = $(wildcard *.h)
OBJ = $(SRC:.cpp=.o)

all: $(2B).so $(1B).so

$(1B).so: $(OBJ) $(1B).cpp
	$(CPP) $(OP) -shared -o lib$(1B).so $(1B).o x1b.o poly-1b.o $(LIB) 

$(2B).so: $(OBJ) $(2B).cpp
	$(CPP) $(OP) -shared -o lib$(2B).so $(2B).o x1b.o x2b.o poly-1b.o poly-2b.o $(LIB) 

clean: 
	rm -f *.o *.so

%.o:%.cpp
	$(CPP) $(CPPFLAGS) $(OP) -c $<
