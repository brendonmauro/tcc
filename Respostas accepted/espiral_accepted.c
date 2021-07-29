#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int lli;
int main(void) {
  lli delta, ci, an, b,n, s, pulos = 0, l = 1, c = 1,  ai, bi, x1, x2;
  scanf("%lli %lli", &n, &b);

  b--;

  ai = -1; bi = n; ci = (lli) b / 4;
  ci = -ci;
  delta = (bi* bi) - 4 * ai * ci;
  delta =(lli) ceil(sqrtl(delta));
  x1 =(lli) (delta- bi)/(2*ai);
  //x2 = (lli)(-delta- bi)/(2*ai);
  
  pulos = x1;
  an =(n-1) - 2*(pulos-1);
  s = (lli) (((n-1)+ an) *pulos)/2;
  s *= 4;
  b -= s;

  l += pulos;
  c += pulos;
  n--;
  n -= 2*pulos;
  if(n > 0)
    c += b - n >= 0? n : b;b -= b - n >= 0? n : b;
  
  if(n > 0)
    l += b - n >= 0? n : b;b -= b - n >= 0? n : b;
  
  if(n > 0)
    c -= b - n >= 0? n : b;b -= b - n >= 0? n : b;
  
  n--;
  
  if(n > 0)
    l -= b - n >= 0? n : b;b -= b - n >= 0? n : b;    

  printf("%lli %lli\n", l, c);



  return 0;
}