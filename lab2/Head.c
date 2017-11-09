#include <stdio.h>
#include <string.h>
#include <math.h>

#include "uwecSocket.h"
#include "bit.h"

int main(int argc, char **argv) {
	int portno = 9595;
	char num = 2;

	int server = setupServerSocket(portno);
	int client = serverSocketAccept(server);

	// Client knows max
	int max = readInt(client);
	double sqrtMax = sqrt((double)max);
	int lenInts = (max / 32) + 1;
	int ints[lenInts];
	memset(ints, 0, sizeof(ints));

	int i;

	// Display
	/* int bitsInInt = 8 * sizeof(int); */
	/* for (i = 0; i < bitsInInt * lenInts; ++i) { */
	/* 	printf("%d", getBit(ints, i)); */
		
	/* 	// Separate each int with newline */
	/* 	if (i % 32 == 31) */
	/* 		printf("\n"); */
	/* } */
	/* printf("\n"); */

	// Read from server
	int botPrime = readInt(client);
	for (i = 0; i < lenInts; ++i)
		ints[i] = readInt(client);
			
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

	while (botPrime <= sqrtMax) {
		// Clear multiples of botPrime, except botPrime
		for (i = botPrime * 2; i <= max; i += botPrime)
			clearBit(ints, i);

		// Advance botPrime
		do
			botPrime++;
		while (!getBit(ints, botPrime));

		// Write to client
		writeInt(botPrime, client);
		for (i = 0; i < lenInts; ++i)
			writeInt(ints[i], client);

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
			// Read from client unless you just wrote it
			// a botPrime > sqrt(max)
			botPrime = readInt(client);
			for (i = 0; i < lenInts; ++i)
				ints[i] = readInt(client);
			
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
