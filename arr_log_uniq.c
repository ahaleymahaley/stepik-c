#include <stdio.h>
#define N 1001
int main() {
	int n, ids[N] = {};
	scanf("%d", &n);
	int i, id;
	for (i = 0; i < n; i++) {
		scanf("%d", &id); //мусор
		scanf("%d", &id); //id
		ids[id] = 1;
		scanf("%d", &id); //мусор
	}
	int count = 0;
	for (i = 0; i < N; i++) {
		count += ids[i];
	}
	printf("%d\n", count);
	return 0;
}
