/*
Program assignment name: Octal

Author:  Greg O'Marah
Date:		Jan. 17, 2015
*/

// includes
#include <stdio.h>
// program code
int main() {
	// declarations
	int num = 0;
	int octal = 0;
	int place = 1;
	// get user input
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &num);
	// validate input
	if ((num > 32767) || (num < 0)) { 					
		printf("Invalid number, exiting.\n");
	}
	else {
	// while loop does calculations
		while (num > 0) {					
			octal += ((num % 8) * (place));
			num /= 8;
			place *= 10;
		}
		// output result to screen
		printf("In octal, your number is: %05d\n", octal); 	
	} 
	return 0;
}	