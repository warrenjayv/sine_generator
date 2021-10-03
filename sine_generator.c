/*
 * author      : github.com/warrenjayv
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
 	 *  3 : option              
 	 *      ~ option is used to remove indexing from output file. 
 	 */

	int samples; 
        int cycles; 
	int option; 

	/// file ptrs ///
	FILE *out; 

	/* we need 0.1 step accuracy per sample */ 
	int samples_max; // samples * 10;  
	double iter; 		 

	/// assert input ///
	if (argc < 3) {
		printf("please enter # of samples and # of cycles.\n");
		printf("./a.exe <samples> <cycles> <1 or 0 (optional)>\n"); 
		return 0; 
	}

	/// obtain user input parameters ///
	printf("input: %d %d\n", atoi(argv[1]), atoi(argv[2]));
	
	samples = atoi(argv[1]); 
	cycles = atoi(argv[2]); 

	if (! argv[1] || ! argv[2] ) { return 0; }

	/// determine cycles in radians ///
	const double pi = 22.0 / 7.0;
	double cycle = (double) cycles * 2 * pi; // each cyle is a period of 2pi

	/// all set, open a file ///
	out = fopen("sine_wave.txt", "w"); 
	if (! out) { printf("failed to open file.\n"); return 0; }

	/// generator ///
	samples_max = samples * 10; 
	printf("generating data, %d iterations\n", samples_max ); 

	/// assert option /// 
	if (argc > 3) {
			option = atoi(argv[3]); 
	}
	
	int i; iter = 0; 
	for ( i = 0; i < samples_max; i ++ ) {

		  // assert cycle //
		  if ( iter > cycle ) {
				break; 
			}
		
			// non-indexed //
			if ((option) && (option == 1)) {
				fprintf( out, "\n%f", sin ( iter )); 
				iter+= 0.1; 
				continue; 
			}	
	
			// indexed //
			fprintf( out, "\n%f %f", iter, sin ( iter )); 
			iter += 0.1; 


	}//for(){} 

	fclose(out); 

	return 0; 

}
