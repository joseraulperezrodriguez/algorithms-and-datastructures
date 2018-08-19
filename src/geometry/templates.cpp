/*
  koder : melkor
  TASK  : Templates for geometry problems
*/

#include <complex>

using namespace std;

#define X(p) real(p)
#define Y(p) imag(p)

const double EPSILON = 1e-8;
const double oo = 1e12;

typedef complex< double > point;

namespace std {
  bool operator < ( const point& a, const point& b ) {
    return X(a) !=  X(b) ? X(a) < X(b) : Y(a) < Y(b);
  }
}

template< typename T >
T sqr( T x ) { return x * x; }

double dist( const point& a, const point& b ) {
  return sqrt( sqr( X(a) - X(b) ) + sqr( Y(a) - Y(b) ) );
}

double cross( const point& a, const point& b ) {
  return imag( conj( a ) * b );
}
double dot( const point& a, const point& b ) {
  return real( conj( a ) * b );
}

int main() {
  return 0;
}//melkor
