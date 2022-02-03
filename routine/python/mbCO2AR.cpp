#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <iostream>     
#include <algorithm>    
#include <vector>       
#include <math.h>       
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

//#include <Windows.h>
#include <cmath>

#include "mbCO2AR.h"

static PyObject *
MBCO2AR(PyObject *self, PyObject *args) {

    //declare arguments
    double r0;
    double R;
    double theta;

    //import arguments from Python
    if (!PyArg_ParseTuple(args, "ddd", &r0, &R, &theta))
        return NULL; 

    double crd[18];

    double a0[3] = {   0.0,   0.0,   0.0};
    double c1[3] = {   0.0,     R,   0.0};
    double o2[3] = {r0*sin(theta*M_PI/180.),
                    r0*cos(theta*M_PI/180.),
                    0.0};
    double o3[3] = {-o2[0],-o2[1],   0.0};

    o2[1] += R;
    o3[1] += R;

    std::copy(a0 + 0, a0 + 3, crd + 0);
    std::copy(c1 + 0, c1 + 3, crd + 3);
    std::copy(o2 + 0, o2 + 3, crd + 6);
    std::copy(o3 + 0, o3 + 3, crd + 9);

    return PyFloat_FromDouble(nrg(crd));

}

static char MBCO2AR_docs[] =
   "MBCO2AR(double rCO, double R, double thetaa): Report the energy of CO2-Ar complex in kcal/mol\n";

static PyMethodDef CO2_methods[] = {
    {"MBCO2AR", MBCO2AR, METH_VARARGS, MBCO2AR_docs },
    {NULL, NULL, 0, NULL}
};

// Module definition
// The arguments of this structure tell Python what to call your extension,
// what it's methods are and where to look for it's method definitions
static struct PyModuleDef CO2AR =
{
    PyModuleDef_HEAD_INIT,
    "CO2AR", /* name of module */
    "usage: CO2AR.mbCO2(lstSortableItems, comboSize)\n", /* module documentation, may be NULL */
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    CO2_methods
};

// Module initialization
// Python calls this function when importing your extension. It is important
// that this function is named PyInit_[[your_module_name]] exactly, and matches
// the name keyword argument in setup.py's setup() call.
PyMODINIT_FUNC PyInit_CO2AR(void)
{
    return PyModule_Create(&CO2AR);
}

