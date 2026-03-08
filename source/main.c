#include <stdio.h>
#include "my_lib.h"
#include <math.h> 

#define N 1000000

int main() {
	// zakres testu [-20Pi, 20Pi]
	double min = -20 * M_PI;
	double max =  20 * M_PI;
	double step = (max - min) / N;
	int precision = 10;

   FILE *file = fopen("cos_data.csv","w");
    fprintf(file,"x,cos_lib,V1,V2,V3,V4\n");

	for (int i = 0; i < N; i++) {
    	double x = min + i * step;
		
		double cos_lib = cos(x);
        double v1 = cos_taylor(x, precision);
        double v2 = cos_taylor_reverse(x, precision);
        double v3 = cos_recursive(x, precision);
        double v4 = cos_recursive_reverse(x, precision);	

		fprintf(file,"%lf,%lf,%lf,%lf,%lf,%lf\n", x, cos_lib, v1, v2, v3, v4);	
	}

	fclose(file);
	return 0;
}


