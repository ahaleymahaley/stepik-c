#include <stdio.h>
#define WEEK (7 * 24 * 60)
#define DAY (24 * 60)

void min2time(int mm, int *d, int *h, int *m) {
	*d = mm / DAY;
	mm %= DAY; 
	*h = mm / 60;
	*m = mm % 60;
}

void sum(int *h, int *m, int hh, int mm) {
	*m += mm;
	if (*m >= 60) {
		*m %= 60;
		*h += 1;
	}
	*h = (*h + hh) % 12;
}

void norm(int *h, int *m) {
	*m = (*m + 60) % 60;
	*h = (*h + 12 - (*m % 60 > 0)) % 12;
}

int main() {
	int hb, minb, hm, minm, hbf, minbf, nb, hmb, minmb, nm;
	scanf("%d:%d %d %d:%d", &hb, &minb, &nb, &hbf, &minbf);
	scanf("%d:%d %d %d:%d", &hm, &minm, &nm, &hmb, &minmb);
	int mm = 0;
	hmb = - hmb;
	minmb = - minmb;
       	norm(&hmb, &minmb);
	while (mm <= WEEK) {
		if (mm % nb == 0) {
			sum(&hb, &minb, hbf, minbf);	
		}
		if (mm % nm == 0) {
			sum(&hm, &minm, hmb, minmb);
		}
		if (hb == hm && minb == minm) {
			int d, h, m;
			min2time(mm, &d, &h, &m);
			printf("%d %02d:%02d\n", d, h, m);
			break;
		}
		mm++;	
	}
	if (mm > WEEK)
		printf("NO\n");
	return 0;
}
