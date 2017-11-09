#include <stdio.h>
#include <string.h> // memset()
#include <math.h>   // sqrt()
#include <ctype.h>  // isdigit()

#include "uwecSocket.h"
#include "bit.h"

int main(int argc, char **argv) {
	// Segfault if you input the address name
	/* printf("Server address: "); */
	/* char *addr[30]; */
	/* scanf("%[^\n]s", addr); // %[^\n]s allows scanf to take in empty string */

	/* if (addr[0] == '\0') // Empty string */
	/* 	printf("Don't do that.\n"); */
	/* else { */

	// argv[1] is max

	int socket = callServer("thing0.cs.uwec.edu", 9595);
	int isNumber = 1;
	int i = 0;
	while (argc > 1 && argv[1][i] != 0 && isNumber) {
		isNumber = isdigit(argv[1][i]);
		++i;
	}

	// Determine primes in [0, max]
	int max = 25;
	if (argc > 1 && isNumber)
		max = atoi(argv[1]);

	double sqrtMax = sqrt((double)max);

	// Server needs to know max
	writeInt(max, socket);

	// One int has 32 bits, each representing one number ending
	// with the given max prime. 0s are the sieved composites.
	// Further potential optimization (not in this program) is
	// the 0 bits can be freed, e.g leave out all evens right
	// away.
	int lenInts = (max / 32) + 1;
	int ints[lenInts];
	memset(ints, 0, sizeof(ints));

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

	// Set botPrime (should be 2)
	int botPrime = 0;
	while (!getBit(ints, botPrime))
		botPrime++;

	//printf("botPrime: %d\n", botPrime);

	while (botPrime <= sqrtMax) {
		// Clear multiples of botPrime, except botPrime
		for (i = botPrime * 2; i <= max; i += botPrime)
			clearBit(ints, i);

		// Advance botPrime
		do
			botPrime++;
		while (!getBit(ints, botPrime));

		// Write to server
		writeInt(botPrime, socket);
		for (i = 0; i < lenInts; ++i)
			writeInt(ints[i], socket);

		printf("Sent: ");
		i = botPrime;
		int primesFound = 0;
		while (i <= max && primesFound < 3) {
			if (getBit(ints, i)) {
				printf("%d,", i);
				++primesFound;
			}
			++i;
		}
		if (primesFound >= 3) {
			printf("\b ... ");
			i = max;
			primesFound = 0;
			while (i >= botPrime && primesFound < 3) {
				if (getBit(ints, i)) {
					printf("%d,", i);
					++primesFound;
				}
				--i;
			}
		}
		printf("\b!\n");

		if (botPrime <= sqrtMax) {
			// Read from server unless you just wrote it
			// a botPrime > sqrt(max)
			botPrime = readInt(socket);
			for (i = 0; i < lenInts; ++i)
				ints[i] = readInt(socket);

			printf("Recd: ");
			i = botPrime;
			int primesFound = 0;
			while (i <= max && primesFound < 3) {
				if (getBit(ints, i)) {
					printf("%d,", i);
					++primesFound;
				}
				++i;
			}
			// I should fix this so the last 3 don't print
			// backwards. Save in a string and print later?
			if (primesFound >= 3) {
				printf("\b ... ");
				i = max;
				primesFound = 0;
				while (i >= botPrime && primesFound < 3) {
					if (getBit(ints, i)) {
						printf("%d,", i);
						++primesFound;
					}
					--i;
				}
			}
			printf("\b!\n");
		}
	}
	// Done
	printf("Done!\n");

	return 0;
}
