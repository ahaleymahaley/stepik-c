#include <stdio.h>
#define N 100

int square(char a[N][N], int n, int i, int j) {
	int sq = 0, h, w;
	h = i;
	while (a[h][j] != '.') {
		h++;
		if (h == n)
			break;
	}
	w = j;
	while (a[i][w] != '.') {
		w++;
		if (w == n)
			break;
	}
	h -= i;
	w -= j;
	sq = h * w;
	return sq;
}

int max_square(char a[N][N], int n) {
	int max = 0, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] == '*') {
				int sq = square(a, n, i, j);
				max = sq > max ? sq : max;
			}
		}
	}
	return max;
}

int main() {
        int n;
        char a[N][N];
        scanf("%d", &n);
        int i;
        for (i = 0; i < n; i++) {
                scanf("%100s", a[i]);
        }
	printf("%d\n", max_square(a, n));
        return 0;
}
