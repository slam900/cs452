#include "primes.h"

int countPrimes(int start, int end) { //[start, end)
	int primeCount = 0;
	int i;
	for (i = start; i < end; i++)
		if (isPrime(i))
			primeCount++;
	return primeCount;
}

int isPrime(int n) {
	int isPrime = 1;
	int i = 2;
	if (n < 2)
		isPrime = 0;
	while (isPrime && i < n) {
		isPrime = n % i != 0;
		i++;
	}
	return isPrime;
}
