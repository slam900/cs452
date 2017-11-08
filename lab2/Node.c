#include <stdio.h>
#include <string.h>
#include <math.h>

#include "uwecSocket.h"
#include "bit.h"

int main() {
	// Segfault if you input the address name
	/* printf("Server address: "); */
	/* char *addr[30]; */
	/* scanf("%[^\n]s", addr); // %[^\n]s allows scanf to take in empty string */

	/* if (addr[0] == '\0') // Empty string */
	/* 	printf("Don't do that.\n"); */
	/* else { */


	int socket = callServer("thing0.cs.uwec.edu", 9595);

	// Determine primes in [0, max]
    int max = 100000;

	// Server needs to know
	writeInt(max, socket);

	// One int has 32 bits, each representing one number ending
	// with the given max prime. 0s are the sieved composites.
	// Further potential optimization (not in this program) is
	// the 0 bits can be freed, e.g leave out all evens right
	// away.
	int lenInts = (max / 32) + 1;
	int ints[lenInts];
	memset(ints, 0, sizeof(ints));

	int i;

	// All numbers are potentially prime until sieved. Set to 1
	for (i = 2; i <= max; ++i)
		setBit(ints, i);

	// Display
	/* int bitsInInt = 8 * sizeof(int); */
	/* for (i = 0; i < bitsInInt * lenInts; ++i) { */
	/* 	printf("%d", getBit(ints, i)); */
		
	/* 	// Separate each int with newline */
	/* 	if (i % 32 == 31) */
	/* 		printf("\n"); */
	/* } */
	/* printf("\n"); */

	// Send to server
	for (i = 0; i < lenInts; ++i)
		writeInt(ints[i], socket);
	
	int botPrime;

	// Read from server
	while (botPrime < sqrt(max)) {
		// Unset multiples of botPrime, except botPrime
		// Advance botPrime
		// Write to server
		// Read from server
	}

	return 0;
}
