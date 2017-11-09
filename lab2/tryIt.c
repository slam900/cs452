#include <stdio.h>
#include <math.h>
#include "bit.h"

int main() {
	double dbl = sqrt(50);
	int i;
	for (i = 0; i < 10; ++i) {
		int boo = (i <= dbl);
		printf("%d <= %f: %d\n", i, dbl, boo);
	}

	/* char b = 6;     // ... 0110 */
	/* char and = 3;   // ... 0011 */
	/* char or = 3;    // ... 0011 */
	/* char right = 1; // ... 0001 */
	/* char left = 1;  // ... 0001 */

	/* char ans = b & and; */
	/* printf("%d & %d: %d\n", b, and, ans); */

	/* ans = b | or; */
	/* printf("%d | %d: %d\n", b, or, ans); */

	/* ans = b >> right; */
	/* printf("%d >> %d: %d\n", b, right, ans); */

	/* ans = b << left; */
	/* printf("%d << %d: %d\n", b, left, ans); */

	/* int bits[1] = {-1}; */

	/* int i; */
	/* for (i = 0; i < 8 * sizeof(int); ++i) { */
	/* 	clearBit(bits, i); */
	/* 	printf("%d: ", bits[0]); */

	/* 	int j; */
	/* 	for (j = 8 * sizeof(int) - 1; j >= 0; --j) */
	/* 		printf("%d", getBit(bits, j)); */

	/* 	printf("\n"); */
	/* } */

	/* printf("\n"); */

	return 0;
}
