#include "MathFunctions.hh"

#include <cmath>

#ifdef USE_MYMATH
#  include "mysqrt.hh"
#endif

namespace mathfunctions {
auto sqrt(double x) -> double
{
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}
}
