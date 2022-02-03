#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "io-xyz.h"
#include "mbCO2AR.h"

int main(int argc, char** argv)
{
    if (argc != 2) {
	std::cerr << "usage: eval.x test.xyz" << std::endl;
	return 0;
    }

    std::cout << std::scientific << std::setprecision(9);

    std::vector<std::string> elements;
    std::vector<double> crd;

    try {
	++argv;
       	--argc;

	std::ifstream ifs(*argv);

	if(!ifs)
	    throw std::runtime_error("could not open the XYZ file");

	std::string comment;
        size_t natoms = 4;
        kit::loadxyz(ifs, natoms, comment, elements, crd);
    } catch (const std::exception& e) {
	std::cerr << " ** Error ** : " << e.what() << std::endl;
	return 1;
    }

    double* xyz = &crd[0]; 
    double E = 0.0;

    E += nrg(xyz);

    std::cout << E << std::endl;

    return 0;
}


