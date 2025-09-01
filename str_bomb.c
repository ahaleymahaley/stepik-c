#include <stdio.h>
#include <string.h>
#define N 1000
#define _STR(X) #X
#define STR(X) _STR(X)
int main() {
	char a[N + 1], b[] = "bomb", ans[5] = "NO\n";
	while (1 == scanf("%" STR(N) "s", a)) {
		if (strcmp(a, b) == 0) {
			strcpy(ans, "YES\n");
			break;
		}
	}
	printf("%s", ans);
	return 0;
}
