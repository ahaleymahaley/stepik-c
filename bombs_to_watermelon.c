#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char * replace (const char * src) {
    	char *a = NULL;
    	size_t n = strlen(src);
    	a = malloc((n + 1) * sizeof(a[0]));
    	strncpy(a, src, n + 1);
	size_t wmlen = strlen("watermelon");
	size_t blen = strlen("bomb");
	size_t extralen = wmlen - blen;
	while (NULL != strstr(a, "bomb")) {
		char * temp;
		temp = realloc(a, (strlen(a) + extralen + 1) * sizeof(a[0]));
		a = temp;
		temp = strstr(a, "bomb");
		memmove(temp + wmlen, temp + blen, strlen(temp + blen) + 1);
		strncpy(temp, "watermelon", wmlen);
	}
    	return a;
}

int main()
{
    char s[N];   // нужно объявить переменную - место для читаемой строки
    char * d;    // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);                          // тут память освобождаем
    }
    return 0;
}

