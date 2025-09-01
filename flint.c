#include <stdio.h>
#include <string.h>

int main() {
	char s[10];
	int x = 0, y = 0, steps;
	while (1 == scanf("%9s", s)) {
		if (0 == strcmp(s, "Treasure!")) {
			break;
		}
		scanf("%d", &steps);
		if (0 == strcmp(s, "North")) {
			y += steps;
		}
		if (0 == strcmp(s, "South")) {
			y -= steps;
		}
		if (0 == strcmp(s, "East")) {
			x += steps;
		}
		if (0 == strcmp(s, "West")) {
			x -= steps;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}
