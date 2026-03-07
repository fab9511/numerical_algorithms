#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

// funkcje aprkoksymujące cos
double cos_taylor(double radian, int precision);
double cos_taylor_reverse(double radian, int precision);
double cos_recursive(double radian, int precision);
double cos_recursive_reverse(double radian, int precision);

int main() {
	printf("2^5: %f", power(2,10));
	printf("\nsilnia: %d", factorial(5));
	printf("\n%lf", cos_taylor(0.38945076923845889371733619555016,15));
	printf("\n%f", cos_taylor(4,10));
	printf("\n%lf", cos_taylor_reverse(0.38945076923845889371733619555016,15));
	printf("\n%lf", cos_recursive(0.38945076923845889371733619555016,15));
	printf("\n%lf", cos_recursive_reverse(0.38945076923845889371733619555016,15));

	return 0;
}

				// x is a angle in radians
double cos_taylor(double x, int precision) {
	double result = 0.0;
	
	for (int i = 0; i < precision; i++) {
		int sign = (i & 1) ? -1 : 1;
		result += sign * power(x,(2*i)) / factorial(2*i);
	}

	return result;
}

double cos_taylor_reverse(double x, int precision) {
    double result = 0.0;

    for (int i = precision-1; i >= 0; i--) {
        int sign = (i & 1) ? -1 : 1;
        result += sign * power(x,(2*i)) / factorial(2*i);
    }

    return result;
}

double cos_recursive(double x, int precision) {
    double result = 1.0;
	double term = 1.0;

    for (int i = 0; i < precision; i++) {
        term *= -x * x / ((2*i + 1) * (2*i + 2)); 
		result += term;
    }

    return result;
}

double cos_recursive_reverse(double x, int precision) {
    double result = 0.0;
	double *terms = malloc(sizeof(double)*precision);
	terms[0] = 1.0;

    for (int i = 0; i < precision; i++) {
	    terms[i] = terms[i-1] -x * x / ((2*i + 1) * (2*i + 2));
	}

    for(int i = precision-1; i >= 0; i--) {
        result += terms[i];
    }

	free(terms);    
	return result;
}


