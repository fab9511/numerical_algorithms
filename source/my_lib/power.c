#include "power.h"

double power(double base, int exp) {
    double result = base;
	if (exp == 0) 
		return 1;

	for (int i = 1; i < exp; i++) {
		result *= base;
	}

    return result;
}
