#include <stdio.h>

int main() {
	char d, i = 0;
	int k;
	scanf("%hhd", &d);
	scanf("%d", &k);
	printf("%hhd %d ", d, k);
	while (k > 0) {
		if (k % 10 == d)
			i++;
		k /= 10;
	}
	printf("%hhd\n", i);
	return 0;
}
