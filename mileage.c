/* -------- mileage.c -------------

Compute mileage for several tankfuls of gas, and then the overall mileage
for all tankfuls.

Programmer: Gregory O'Marah

Date: Feb. 11, 2015
*/

// includes 
#include <stdio.h>
//#include <math.h>

// MAIN PROGRAM CODE
int main() {

	// Declare & Initialize VARIABLES: 
	double milesDriven = 0.0, totMiles = 0.0, milesPerGal = 0.0,  gallonsUsed = 0.00001, totGallons = 0.0;

	// Use while loop, set to execute until gallons input a negative value to signal end of inputs.
	while(gallonsUsed > 0) {
		// Print prompt and scan for user input of gallonsUsed (prompt for input -1 to terminate)
		printf("Enter the gallons used (-1 to end):\n");
		scanf("%lf", &gallonsUsed);
		// Exit if gallons used = -1 or any value < 0 (avoid division by zero)
		if(gallonsUsed <= 0){
			printf("\n");
			break;
		}
		// Set totGallons to totGallons plus gallonsUsed to sum gallons used for all tanks of fuel
		totGallons += gallonsUsed;
		// Print prompt and scan for user input of milesDriven
		printf("Enter the miles driven:\n");
		scanf("%lf", &milesDriven);
		// Add milesDriven to totMiles for use later in cumulative calculations. 
		totMiles += milesDriven;
		// Set milesPerGal equal to gallonsUsed divided by milesDriven
		milesPerGal = milesDriven / gallonsUsed;
		// Display miles / gallon for current tankful.
		printf("The miles/gallon for this tank was %f\n", milesPerGal);
		printf("\n");
	}
	// Set milesPerGal equal to totMiles divided by totGallons
	milesPerGal = totMiles / totGallons;
	// Print cumulative miles per gallon across all tankfulls input
	printf("The overall miles/gallon was %f\n", milesPerGal);

	return 0;
}



