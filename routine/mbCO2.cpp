#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "x1b.h"
#include "kit.h"

const double Eh_J = 4.35974434e-18; // CODATA 2010
const double Na = 6.02214129e+23; // CODATA 2010

const double kcal_J = 4184.0;
const double Eh_kcalmol = Eh_J*Na/kcal_J;

#define Eh_J 4.35974434e-18
#define Na 6.02214129e+23
#define kcal_J 4184.0
#define Eh_kcalmol Eh_J*Na/kcal_J

// The number of coordinates and atoms is set such that
// this shared library will work with CO2-Rg systems as
// a check.
#define Nq 4                            //Number of internal coordinates
#define N 3				//Number of atoms

//
// getN() is a required exported function
// Returns N, the number of atoms
#ifdef _WIN32
__declspec (dllexport)
#endif
extern "C" int getN(){
        return N;
}

// calcSurface(...) is a required exported function
// Returns the value of the PES given the nuclear
// cartesian coordinates (X). The expected atom ordering
// is Ar C O O
#ifdef _WIN32
__declspec (dllexport)
#endif
extern "C" double calcSurface(double *X, int *PERM){

	double mon[9];
 	//std::copy(X + 3, X +  12, mon + 0);

	double value = 0.0;

        value += x1b::value(X);

        // Return value of PES
	return value*349.75;
}

