/*
 * author			 : github.com/warrenjayv
 * description : sine wave generator  
 */


#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 

int main (int argc, char *argv[]) {

	/// parameters ///
	
 	/*  1 : number of samples
 	 *  2 : number of cycles
 	 */

	int samples; 
  int cycles; 

	/// file ptrs ///
	FILE *out; 

	/* we need 0.1 step accuracy per sample */ 
	int samples_max; // samples * 10;  
	double iter; 		 

	/// assert input ///
	if (argc < 2) {
		printf("please enter # of samples and # of cycles.\n");
		printf("./a.exe <samples> <cycles>\n"); 
		return 0; 
	}

	/// obtain user input parameters ///
	printf("input: %d %d\n", atoi(argv[1]), atoi(argv[2]));
	
	samples = atoi(argv[1]); 
	cycles = atoi(argv[2]); 

	if (! argv[1] || ! argv[2] ) { return 0; }

	/// convert cycles to radians ///
	const double pi = 22.0 / 7.0;
	double cycle = (double) cycles * pi; 

	/// all set, open a file ///
	out = fopen("sine_wave.txt", "w"); 
	if (! out) { printf("failed to open file.\n"); return 0; }

	/// generator ///
	samples_max = samples * 10; 
	printf("generating data, %d iterations\n", samples_max ); 
	
	int i; iter = 0; 
	for ( i = 0; i < samples_max; i ++ ) {
			fprintf( out, "\n%f %f", iter, sin ( iter )); 
			iter += 0.1; 
	}//for(){} 

	fclose(out); 

	return 0; 

}
