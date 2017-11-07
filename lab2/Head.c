#include <stdio.h>
#include "uwecSocket.h"

int main() {
	int portno = 9555;
	int msg = 2;

	int server = setupServerSocket(portno);
	int client = serverSocketAccept(server);

	while (msg < 10) {
		writeInt(msg, client);
		msg = readInt(client);
		printf("%d\n", msg);
		msg++;
	}
	return 0;
}
