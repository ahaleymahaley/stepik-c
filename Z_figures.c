#include <stdio.h>
#define N 100

void color_figure(char a[N + 2][N + 2], char color, int i, int j) {
	a[i][j] = color;
	int temp = i + 1;
	while (a[temp][j] == '*') {
		color_figure(a, color, temp, j);
		temp++;
	}
	temp = i - 1;
	while (a[temp][j] == '*') {
		color_figure(a, color, temp, j);
		temp--;
	}
	temp = j + 1;
	while (a[i][temp] == '*') {
		color_figure(a, color, i, temp);
		temp++;
	}
	temp = j - 1;
	while (a[i][temp] == '*') {
		color_figure(a, color, i, temp);
		temp--;
	}
}

int main() {
        int n;
        char a[N + 2][N + 2];
        scanf("%d", &n);
        int i;
        for (i = 1; i < n + 1; i++) {
                scanf("%100s", &a[i][1]);
        }
	for (i = 0; i < n + 2; i++) {
		a[0][i] = '.';
		a[n + 1][i] = '.';
		a[i][0] = '.';
		a[i][n + 1] = '.';
	}
	char color = 0;
	int j;
	for (i = 0; i < n + 2; i++) {
		for (j = 0; j < n + 2; j++) {
			if (a[i][j] == '*') {
				color_figure(a, color, i, j);
				color++;
			}
		}
	}
	printf("%d\n", color);
        return 0;
}
