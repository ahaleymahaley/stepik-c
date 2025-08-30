#include <stdio.h>
#define N 100

int is_present(int *div, int num) {
        int res = -1;
        int i;
        for (i = 0; i < N; i++) {
                if (div[i] == num)
                        res = i;
        }
        return res;
}

int main() {
        int num, den;
        scanf("%d%d", &num, &den);
        int i;
        int div[N] = {}; //делимые
        int a[N] = {}; //дробная часть
        int begin; //начало периода
        for (i = 0; i < N; i++) {
            if (num == 0) {
                a[i] = 0;
                a[i + 1] = -1;
                begin = i;
                break;
            }
            begin = is_present(div, num);
            if (begin != -1) {
                a[i] = -1;
                break;
            }
            div[i] = num;
            num *= 10;
            if (num / den < 1) {
                a[i] = 0;
                num *= 10;
            }
            else {
                int digit = num / den;
                a[i] = digit;
                num %= den;
            }
        }
        printf("0,");
        for (i = 0; a[i] != -1; i++) {
                if (i == begin)
                        printf("(");
                printf("%d", a[i]);
        }
        printf(")\n");
        return 0;
}
