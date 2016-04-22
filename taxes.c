/* In-Class Programming Assignment - Taxes 
   Author:   Greg O'Marah 
   Date: Jan. 18, 2015              */

//includes
#include <stdio.h>

//program code
int main(void)
{
//declare and initialize
   int i, num_clients = 0, client_id = 0, dependents = 0;
   double gross = 0.0, net = 0.0, taxable = 0.0, tax = 0.0, effective = 0.0;

//get number of clients
   scanf("%d", &num_clients);

//for loop to carry out iterations
   for (i = 0; i < (num_clients); i++) {

//get input
      scanf("%d %lf %d", &client_id, &gross, &dependents);

//calculations
      net = gross - 1000 * dependents;
      if (net < 0.0) { // prevent negative net income
      	net = 0.0;
      }
      taxable = .85 * net;

      if (taxable <= 15000){
      	tax = .1 * taxable;
      }
      else if (taxable <= 35000){
      	tax = 1500 + .2 * (taxable - 15000);
      }
      else {
      	tax = 1500 + 4000 + .3 * (taxable - 35000);
      }
      effective = tax / gross * 100;

//output
      printf("%d %.0lf %4.1lf\n", client_id, tax, effective);
   }
   return 0;
}
