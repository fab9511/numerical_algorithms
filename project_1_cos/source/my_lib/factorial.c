#include "factorial.h"
#define MAX_FACTORIAL 100

double factorial(int n) {
    static double tab[MAX_FACTORIAL + 1] = {0.0};
   
	 if (n < 0 || n > MAX_FACTORIAL)
        return -1.0; //błąd

    tab[0] = 1.0;

	if (n == 0 || n == 1)
		return 1;

    for (int i = 1; i <= n; i++)
		if (tab[i] == 0.0)
			tab[i] = tab[i-1] * i;
	
	return tab[n];
}
