#include "primes.h"
#include "uwecSocket.h"

int main() {
	int socket = callServer("localhost", 7777);
	int min = readInt(socket);
	int max = readInt(socket);
	int primes = countPrimes(min, max);
	writeInt(primes, socket);
	return 0;
}
