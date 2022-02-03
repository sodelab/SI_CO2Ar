# for now use the following command
# after compiling the executable to run it
# on mac: export DYLD_LIBRARY_PATH='fullpath'
# on unix: export LD_LIBRARY_PATH='fullpath'
# 
# would be great to fix this eventually fix 
# this by hardcoding the full path of the 
# shared library into the executable

CXX = g++

CXXFLAGS = -O3 -I../../library/
SYSLIB = -L../../library/ -lmbCO2AR

EVAL_OBJ = eval.o

all: eval.x

eval.x: $(EVAL_OBJ)
	$(CXX) $(LINKFLAGS) -o $@ $^ $(SYSLIB) $(CXXFLAGS)

clean:
	rm -rf $(EVAL_OBJ) eval *.dSYM

# Compilation rules

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(DEPS) -c $<

.PHONY: all clean
