#include <stdio.h>
#include <stdlib.h> // malloc

int *sieve(int);

int main(int argc, char **argv) {
	printf("argc: %d\n", argc);
	printf("argv: ");
	for (int i = 0; i < argc; ++i)
		printf("%s ", argv[i]);

	printf("\n");
	printf("\n");
	
	int size;
	if (argc > 1) {
		// First argument is size
		char *str = argv[1];
		size = atoi(str);
	} else
		size = 10;
	
	int *s = sieve(size);
	for (int i = 0; i <= size; ++i)
		printf("%d: %d\n", i, s[i]);
	
	return 0;
}

int *sieve(int n) {
	int *nums = (int*)malloc(n * sizeof(int) + 1);
	nums[0] = 0;
	nums[1] = 0;
	for (int i = 2; i <= n; ++i)
		nums[i] = 1;
	
	int p = 2;
	while (p * p <= n) {
		int j = p * p;
		while (j <= n) {
			nums[j] = 0;
			j = j + p;
		}
		do
			++p;
		while (nums[p] != 1);
	}
	
	return nums;
}