#include <stdio.h>
#include <string.h>
int main() {
	int a[] = {5000, 1000, 500, 100, 50, 10, 5, 2, 1};
	int n = sizeof(a) / sizeof(a[0]);
	int b[n];
	memset(b, 0, sizeof(b));
	int x;
	scanf("%d", &x);
	int i;
	for (i = 0; i < n; i++) {
		if (x / a[i] > 0) {
			b[i] = x / a[i];
			x -= (x / a[i]) * a[i];
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d %d\n", a[i], b[i]);
	}
	return 0;
}
