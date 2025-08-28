#include <stdio.h>

int main() {
    int n, i, count_knights = 0;
    scanf("%d", &n);
    int what_speaks, who_speaks = 0;
    for (i = 0; i < n; i ++) {   
        count_knights += who_speaks;
        scanf("%d", &what_speaks);
        who_speaks = !((who_speaks + what_speaks) % 2);
    }
    printf("%d\n", count_knights < n - count_knights ? count_knights : n - count_knights);
    return 0;
}
