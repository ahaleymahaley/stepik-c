#include <stdio.h>
#define N 100
int main() {
	unsigned long long int a[N] = {1}, b[N] = {1, 1}, *temp, *pa, *pb;
	pa = a;
	pb = b;
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 2; i <= n + 1; i++) {
		for (j = 1; j <= i; j++) {
			pb[j] = pa[j - 1] + pa[j];
		}
		temp = pa;
		pa = pb;
		pb = temp;
	}
	for (i = 0; i < n + 1; i++) {
		printf("%llu ", *(pa + i));
	}
	printf("\n");
	return 0;
}
