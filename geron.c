#include <stdio.h>
#include <math.h>

float area(int x1, int y1, int x2, int y2, int x3, int y3);
float dist(int x1, int y1, int x2, int y2);


int main()
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%.3f", area(x1, y1, x2, y2, x3, y3));
	return 0;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float res;
	float a, b, c, p;
	a = dist(x1, y1, x2, y2);  
	b = dist(x1, y1, x3, y3);  
	c = dist(x2, y2, x3, y3);  
	p = (a + b + c) / 2;
	res = sqrt(p  * (p - a) * (p - b) * (p - c));
	return res;
}

float dist(int x1, int y1, int x2, int y2)
{
        float res;
        res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        return res;
}
