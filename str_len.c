#include <stdio.h>
#include <string.h>
#define N 1000
#define _STR(X) #X
#define STR(X) _STR(X)

int main() {
	char str[N + 1], longest[N + 1];
	strcpy(longest, "");
	while (1 == scanf("%" STR(N) "s", str)) {
		if (strlen(str) > strlen(longest)) {
			strcpy(longest, str);
		}
	}
	printf("%s %zu\n", longest, strlen(longest));
	return 0;
}
