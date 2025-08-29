#include <stdio.h>

int main() {
    long long int N;
    scanf("%lld", &N);
    int digits = 2, i;
    long long int sum = N >= 10 ? 9 : N % 10, number = 90;
    N -= 9;
    i = 0;
    while (N > 0) {
        if (N - number > 0) {
            sum += number * digits;
        } else {
            sum += N * digits;
        }
        N -= number;
        number *= 10;
        digits++;
        i++;
    }
    printf("%d %lld\n", i, sum);
    return 0;
}
