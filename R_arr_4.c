#include <stdio.h>
#define N 1300000


void fill_prime(char *prime) {
	int i;
	for (i = 2; i < N; i++) {
		prime[i] = 1;
	}
	int k = 2;
	while (k * k < N) {
		for (i = 2 * k; i < N; i += k) {
			prime[i] = 0;
		}
		for (i = k + 1; prime[i] == 0; i++)
			;		
		k = i;
	}
}

int main() {
	char prime[N] = {};
	fill_prime(prime);
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		int number;
		scanf("%d", &number);
		if (prime[number])
			printf("%d ", number);
	}
	printf("\n");
	return 0;
}
