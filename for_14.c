#include <stdio.h>

int main() {
        char sum = 0;
        int c;
        while ((c = getchar()) != EOF) {
                if (c == '(')
                        sum++;
                if (c == ')')
                        sum--;
                if (sum < 0)
                        break;
        }
        if (sum == 0)
                printf("YES\n");
        else
                printf("NO\n");

        return 0;
}
