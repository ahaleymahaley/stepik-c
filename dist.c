#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2);

int main()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("%f", dist(x1, y1, x2, y2));
	return 0;
}

float dist(int x1, int y1, int x2, int y2)
{
	float res;
	res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return res;
}
