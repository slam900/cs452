#include <stdio.h>
#include "uwecSocket.h"

int main() {
	// Segfault if you input the address name
	/* printf("Server address: "); */
	/* char *addr[30]; */
	/* scanf("%[^\n]s", addr); // %[^\n]s allows scanf to take in empty string */

	/* if (addr[0] == '\0') // Empty string */
	/* 	printf("Don't do that.\n"); */
	/* else { */


	int socket = callServer("thing0.cs.uwec.edu", 9595);
	printf("\n");

	char num = 0;
	char nums[10];
	int i;

	num = readChar(socket);
	printf("Read %d\n", num);
	num = readChar(socket);
	printf("This time read %d\n", num);
	num = readChar(socket);
	printf("This time read %d\n", num);


	/* for (i = 0; i < 10; ++i) { */
	/* 	num = readChar(socket); */
	/* 	nums[i] = num; */
	/* 	printf("Read %d\n", num); */
	/* } */
	/* for (i = 0; i < 10; ++i) */
	/* 	printf("%d\n", nums[i]); */
	//writeChar(nums, socket);

	return 0;
}
