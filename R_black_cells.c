#include <stdio.h>
#define N 100

int main() {
	int n, sum = 0;
	char line[N + 1];
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%100s", line);
		for (j = 0; j < n; j++) {
			if (line[j] == '*')
				sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
