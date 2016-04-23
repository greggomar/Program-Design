#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 
#include <math.h>
#include "Fraction.h"

int gcd(int a, int b)
{
   if (a == 0 && b == 0) {
      printf("Illegal args to gcd: %d, %d\n",a,b);
      exit(1);
   }
   int aa = abs(a);
   int bb = abs(b);
   if (aa == 0)
      return bb;
   if (bb == 0)
      return aa;
   return gcd(bb,aa%bb);
}

Fraction string_to_fraction(const char *S)
{
   Fraction result = {0,1};
   /* Place your code here to initialize the Fraction result
   as specified in the string S (using sscanf)
   */
   sscanf(S, "%d/%d", &result.numer, &result.denom);

   reduce_fraction(&result);

   return result;
}

void fraction_to_string(Fraction R, char repr[])
{
   repr[0] = 0;
   /* Place your code here to place the string representation
   of the Fraction R in the character array repr using
   sprintf.
   */
   reduce_fraction(&R);

   if(R.denom != 1)
   {
      sprintf(repr, "%d/%d", R.numer, R.denom);
   }
   else
   {
      sprintf(repr, "%d", R.numer);
   }

}

int compare_fractions(Fraction L, Fraction R)
{
 /*
 * Returns -1 if L < R, 0 if L equals R and 1 if L > R 
 * Note that this is the same behavior as strcmp     
 */
   reduce_fraction(&L);
   reduce_fraction(&R);

   if (identicalFractions(L, R)) 
   {
      return 0;
   }
   
   L.numer *= R.denom;
   R.numer *= L.denom;

   return ((L.numer > R.numer)? 1: -1);

}

void reduce_fraction(Fraction *R)
{
   /* Place your code here to modify the Fraction being passed
   in by reference so that it is reduced according to the
   specifications in Instructions.pdf
   */

   if(R->denom < 0)
   {
      R->numer = -R->numer;
      R->denom = -R->denom;
   }

   int divisor = gcd(R->numer, R->denom);

   R->numer /= divisor;
   R->denom /= divisor;

}

Fraction add_fractions(Fraction L, Fraction R)
{
   Fraction result = {0,1};
   /* Place your code here to make result a reduced
   Fraction representing the sum of the Fractions L and R
   */

   L.numer *= R.denom;
   R.numer *= L.denom;
   L.denom *= R.denom;

   result.numer = L.numer + R.numer;
   result.denom = L.denom;

   reduce_fraction(&result);

   return result;

}