#include <stdio.h>
#define N 3

void read_matrix(int a[N][N]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void print_matrix(int a[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int sum_row(int a[N][N], int irow) {
    int sum = 0;
    for(int j = 0; j < N; j++) {
        sum += a[irow][j];
    }
    return sum;
}

int sum_col(int a[N][N], int icol) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i][icol];
    }
    return sum;
}

int sum_diag(int a[N][N]) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i][i];
    }
    return sum;
}

int sum_diag2(int a[N][N]) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i][N - 1 - i];
    }
    return sum;
}


int main() {
    int a[N][N];
    read_matrix(a);
    print_matrix(a);
    int sum = sum_diag(a), is_magic = 1;
    if (sum != sum_diag2(a))
    	is_magic = 0;
    int i;
    for (i = 0; i < N; i++) {
    	if (sum_row(a, i) != sum || sum_col(a, i) != sum) {
		is_magic = 0;
		break;
	}
    }
    printf(is_magic ? "MAGIC\n" : "NO\n");
    return 0;
}

