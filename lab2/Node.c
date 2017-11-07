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


	int socket = callServer("thing0.cs.uwec.edu", 9555);
	printf("\n");

	int msg;
	while (msg < 10) {
		msg = readInt(socket);
		printf("Read %d\n", msg);
		msg++;
		writeInt(msg, socket);
	}
	return 0;
}
