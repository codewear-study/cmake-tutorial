#include "MathFunctions.hh"
#if defined(HAVE_CXX_STD_LOG) && defined(HAVE_CXX_STD_EXP)
#include <cmath>
#include <iostream>
#endif

auto mysqrt(double x) -> double
{
#if defined(HAVE_CXX_STD_LOG) && defined(HAVE_CXX_STD_EXP)
    double result = std::exp(std::log(x) * 0.5);
    std::cout << "Computing sqrt of " << x << " to be " << result
                << " using std::log and std::exp in cmath" << std::endl;
#else
    double result = x;
#endif

    return result;
}