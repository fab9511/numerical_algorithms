#include <stdio.h>
#include "my_lib.h"

int main() {
	printf("2^5: %f", power(2,10));
	printf("\nsilnia: %d", factorial(5));
	printf("\n%lf", cos_taylor(0.38945076923845889371733619555016,15));
	printf("\n%f", cos_taylor(4,10));
	printf("\n%lf", cos_taylor_reverse(0.38945076923845889371733619555016,15));
	printf("\n%lf", cos_recursive(0.38945076923845889371733619555016,15));
	printf("\n%.23ef", cos_recursive_reverse(0.38945076923845889371733619555016,15));

	return 0;
}


