#include <stdlib.h>
#include "cos.h"
#include "power.h"
#include "factorial.h"

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

    for (int i = 1; i < precision; i++) {
	    terms[i] = terms[i-1] * (-x * x) / ((2*i - 1) * (2*i));
	}

    for (int i = precision - 1; i >= 0; i--) {
        result += terms[i];
    }
	
	free(terms);    
	return result;
}
