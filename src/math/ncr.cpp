/*
  koder : melkor
  TASK  : Efficient calculation of nCr
*/

int nCr ( int n, int r ) {

  int ncr = n;
  int k = 1;
  int r1 = n - r;

  /* Handle special cases */
  if ( r1 < 0 ) return 0;    // Invalid value
  if ( r1 < r ) r = r1;      // nCr = nC(n-r)
  if ( r == 0 ) return 1;    // nC0 = 1

  /* To avoid integer overflow, divide as early as possible */
  while ( ++k <= r ) {
    ncr *= --n;
    ncr /= k;
  }

  return ncr;
}
