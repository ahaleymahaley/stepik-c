#include <stdio.h>
#define N 9

void read_matrix(int a[N][N], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void print_matrix(int a[N][N], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int sum_row(int a[N][N], int n, int irow) {
    int sum = 0;
    for(int j = 0; j < n; j++) {
        sum += a[irow][j];
    }
    return sum;
}

int sum_col(int a[N][N], int m, int icol) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        sum += a[i][icol];
    }
    return sum;
}

int sum_diag(int a[N][N], int m) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        sum += a[i][i];
    }
    return sum;
}

int sum_diag2(int a[N][N], int m) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        sum += a[i][m - 1 - i];
    }
    return sum;
}

int is_matrix_magic(int a[N][N], int m) {	
    int sum = sum_diag(a, m), is_magic = 1;
    if (sum != sum_diag2(a, m))
    	is_magic = 0;
    int i;
    for (i = 0; i < m; i++) {
    	if (sum_row(a, m, i) != sum || sum_col(a, m, i) != sum) {
		is_magic = 0;
		break;
	}
    }
    return is_magic;
}

void number_mult(int k, int m, int n, int a[N][N]) {
	int i, j;
	for (i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = k * a[i][j];
		}
	}
}

void sum(int m, int n, int a[N][N], int b[N][N], int c[N][N]) {
	int i, j;
	for (i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int is_row_solved(int a[N][N], int irow) {
	int res = 1, j;
	int digits[N + 1] = {};
	for (j = 0; j < N; j++) {
		if (digits[a[irow][j]] == 1) {
			res = 0;
			break;
		} else {
			digits[a[irow][j]] = 1;
		}
	}
	return res;
}

int is_col_solved(int a[N][N], int jcol) {
	int res = 1, i;
	int digits[N + 1] = {};
	for (i = 0; i < N; i++) {
		if (digits[a[i][jcol]] == 1) {
			res = 0;
			break;
		} else {
			digits[a[i][jcol]] = 1;
		}
	}
	return res;
}

int is_square_solved(int a[N][N], int isquare) {
	int res = 1;
	int digits[N + 1] = {};
	int ilt = (isquare / 3) * 3, jlt = (isquare % 3) * 3, i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (digits[a[ilt + i][jlt + j]] == 1) {
				res = 0;
				break;
			} else {
				digits[a[ilt + i][jlt + j]] = 1;
			}
		}
	}
	return res;
}

int is_sudoku_solved(int a[N][N]) {
	int res = 1, i;
	for (i = 0; i < N; i++) {
		res = res && is_row_solved(a, i) && is_col_solved(a, i) && is_square_solved(a, i);
		if (res == 0)
			break;
	}
	return res;
}

int main() {
    int a[N][N];
    read_matrix(a, N, N);
    printf(is_sudoku_solved(a) ? "YES\n" : "NO\n");
    return 0;
}

