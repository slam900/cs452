#include <stdio.h>
#include <string.h>
#include <math.h>

#include "uwecSocket.h"
#include "bit.h"

int main() {
	int portno = 9595;
	char num = 2;

	int server = setupServerSocket(portno);
	int client = serverSocketAccept(server);

	// Client knows max
	int max = readInt(client);
	int lenInts = (max / 32) + 1;
	int ints[lenInts];
	memset(ints, 0, sizeof(ints));

	int i;

	// Read first wave from client
	for (i = 0; i < lenInts; ++i)
		ints[i] = readInt(client);

	// Display
	/* int bitsInInt = 8 * sizeof(int); */
	/* for (i = 0; i < bitsInInt * lenInts; ++i) { */
	/* 	printf("%d", getBit(ints, i)); */
		
	/* 	// Separate each int with newline */
	/* 	if (i % 32 == 31) */
	/* 		printf("\n"); */
	/* } */
	/* printf("\n"); */

	int botPrime;
	while (botPrime < sqrt(max)) {
		// Unset multiples of botPrime, except botPrime
		// Advance botPrime
		// Write to server
		// Read from server
	}
	// Done

	return 0;
}
