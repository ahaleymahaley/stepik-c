#include <stdio.h>
#include <math.h>
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;    // начало отрезка
    Point b;    // конец отрезка
    float len;  // длина отрезка
} Line;

float distance(Point a, Point b) {
	float res;
	res = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return res;
}
void scanLine(Line * t) {
	scanf("%d%d%d%d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
	t->len = distance(t->a, t->b);
}

void printLine(Line t) {
	printf("%d %d %d %d %.3f\n", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}
void rotRLine(Line * t) {	
	int temp;

	temp = t->a.x;
	t->a.x = -t->a.y;
	t->a.y = temp;
	
	temp = t->b.x;
	t->b.x = -t->b.y;
	t->b.y = temp;
}

int main() {
    Line t;

    scanLine(&t);
    // тут должен быть вызов функции rotRLine
    rotRLine(&t);
    printLine(t);

    return 0;
}
