#include <stdio.h>

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;


int time2min(TicTac a){
	int res;
	res = a.h * 60 + a.min;
	return res;
}

TicTac min2time(int mm){
	TicTac res;
	mm = (mm + 60 * 12);
	res.h = mm / 60 % 12;
	res.min = mm % 60;
	return res;
}

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min){
	TicTac res;
	int mm = time2min(a) + min;
	res = min2time(mm);
	return res;
}

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac * me, TicTac a){
	int mm = time2min(a);
	*me = after(*me, mm);
}

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac * me, TicTac a){
	int mm = -time2min(a);
	*me = after(*me, mm);
}

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b){
	if (a.h == b.h && a.min == b.min){
		return 1;
	} else {
		return 0;
	}
}

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a){
	printf("%02d:%02d\n", a.h, a.min);
}



int main(){
    TicTac a,b,c;
    int mk;

    scanf("%d:%d", &(a.h), &(a.min));
    scanf("%d", &mk);
    scanf("%d:%d", &(b.h), &(b.min));

    printf("equal: %d\n",isEqualTime(a,b));
    c = after(a, mk);
    printf("after: ");
    printTic(c);

    c = a;
    printf("forward: ");
    forward(&a, b);
    printTic(a);

    printf("backward: ");
    backward(&c, b);
    printTic(c);

    printf("\n");

    return 0;
}

