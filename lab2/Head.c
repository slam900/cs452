#include <stdio.h>
#include "uwecSocket.h"

int main() {
	int portno = 9595;
	char num = 2;

	int server = setupServerSocket(portno);
	int client = serverSocketAccept(server);

	writeChar(10, client);
	
	writeChar(12, client);
	sleep(3);
	/* while (num < 10) { */
	/* 	writeChar(num, client); */
	/* 	printf("Wrote %d\n", num); */
	/* 	num++; */
	/* } */
	return 0;
}
