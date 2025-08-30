#include <stdio.h>
#define N 100

int is_equal_numbers(int *a, int n) {
	int res = 1;
	int i;
	for (i = 1; i < n; i++) {
		if (a[i] != a[0]) {
			res = 0;
			break;
		}
	}
	return res;
}

int main() {
	int a[N];
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int saved = 0;
	while (!is_equal_numbers(a, n)) {
		for (i = 0; i < n; i++) {
			int sum = a[i] + a[(i + 1) % n];
			a[i] = sum / 2;
			a[(i + 1) % n] = sum / 2;
			saved += sum % 2;
		}	
	}
	printf("%d %d\n", saved, a[0]);
	return 0;
}
