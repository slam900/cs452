#include <stdio.h>
#include "uwecSocket.h"

int main() {
	int portno = 9555;
	int min = 0;
	int max = 100;
	
	int server = setupServerSocket(portno);
	int client = serverSocketAccept(server);
	writeInt(min, client);
	writeInt(max, client);
	int response = readInt(client);
	printf("%d\n", response);
}
