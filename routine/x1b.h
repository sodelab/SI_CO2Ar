#include <sstream>
#include <cmath>
#include "poly-1b.h"
#include "kit.h"

////////////////////////////////////////////////////////////////////////////////
namespace x1b {

const unsigned num_nonlinear_params = 2;
const unsigned num_linear_params = 49;
const unsigned num_vars = 3;
const double m_k_OO_intra = 5.640303274294849e-01;
const double m_k_CO_intra = 1.069946028125781e+00;
const double d0_intra_CO = 1.180200000000000e+00;
const double d0_intra_OO = 2.360500000000000e+00;

const double poly[num_linear_params] = { 
 4.841047260763718e+02, 1.103704424372119e+03,-1.726487379953372e+03,-1.175337123599199e+03, 
-7.704321594500650e+02,-4.342418290868871e+02, 9.433902933745533e+02, 7.564456845015286e+02,
 5.466618184056481e+02, 5.293320525004016e+02, 9.103036646183365e+02, 5.077662303188253e+02,
-1.787389532900472e+02,-5.483753559133519e+02,-2.165023480076572e+02,-2.490311524226809e+02,
-3.044961325101216e+02,-9.652464155252865e+01,-1.988149822981667e+02,-7.212001300041976e+02,
-3.042230786757059e+02, 5.774080649144697e-01, 2.837087168278449e+02,-6.576189589495336e+02,
 1.550222591772852e+02, 1.963371917892080e+02, 1.013382096364843e+02, 7.219126905144130e+02,
 2.787472041668694e+02, 2.675176029393922e+02,-2.085107761403887e+02,-1.151966030998639e+02,
-2.030500932024477e+02, 1.230450996655730e+01, 1.263265724273545e+02,-1.120934993674255e+02,
 7.332216255906052e+01,-2.477239661081954e+02,-4.066954312204908e+01, 8.278566564168167e+01,
-1.871193788121291e+02,-9.398392506237796e+01,-1.811701251916488e+02, 2.696902141450475e+02,
-5.990246468460447e+01, 3.218389600386994e+02,-8.632605197101314e+01,-6.185292238375930e+01,
 7.296517459265571e+01
};

inline double var_intra(const double& d0, const double& k, const double& d)
{
    return std::exp(k*(d0 - d));
}

void cart_to_vars(const double xyz[9], double* vars);
double value(const double xyz[9]);

}
////////////////////////////////////////////////////////////////////////////////