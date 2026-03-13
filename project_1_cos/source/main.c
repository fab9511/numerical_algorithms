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
	
	if (!file) {
    	perror("fopen");
    	return 1;
	}
	// testy 4 funkcji cos
	for (int i = 0; i < N; i++) {
    	double x = min + i * step;
		
		double cos_lib = cos(x);
        double v1 = cos_taylor(x, precision);
        double v2 = cos_taylor_reverse(x, precision);
        double v3 = cos_recursive(x, precision);
        double v4 = cos_recursive_reverse(x, precision);	

		fprintf(file,"%.17g,%.17g,%.17g,%.17g,%.17g,%.17g\n", x, cos_lib, v1, v2, v3, v4);	
	}

	fclose(file);
	
	FILE *file_2 = fopen("cos_data_2.csv","w");

	if (!file_2) {
		perror("fopen drugi plik");
		return 1;
	}

    fprintf(file_2,"precision,x,cos_lib,V1,V2,V3,V4\n");

    double x = M_PI / 2;
	int max_precision = 30;
	double cos_x = cos(x);
	//testy precyzji dla danego x	
	for (int i = 1; i < max_precision; i++) {
		double v1 = cos_taylor(x, i);
        double v2 = cos_taylor_reverse(x, i);
        double v3 = cos_recursive(x, i);
        double v4 = cos_recursive_reverse(x, i);

        fprintf(file_2,"%d,%.17g,%.17g,%.17g,%.17g,%.17g,%.17g\n", i, x, cos_x, v1, v2, v3, v4);
    }
	
	fclose(file_2);
	return 0;
}
