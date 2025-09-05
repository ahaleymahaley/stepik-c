#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct {
    int n;
    int size;
    Data * a;
} Stack;
Stack * stack_create(int size) {
	Stack *s = malloc(sizeof(Stack));
	s->n = 0;
	s->size = size;
	s->a = malloc(size * sizeof(Data));
	return s;
}
void stack_push(Stack * s, Data x) {
	if (s->n == s->size) {
		s->size *= 2;
		s->a = realloc(s->a, s->size * sizeof(Data));
	}
	s->a[s->n++] = x;
}
Data stack_pop(Stack * s) {
	Data res = s->a[--s->n];
	if (2 * s->n < s->size && s->size != 1) {
		s->size /= 2;
		s->a = realloc(s->a, s->size * sizeof(Data));
	}
	return res;	
}
Data stack_get(Stack * s) {
	return s->a[s->n - 1];
}
void stack_print(Stack * s) {
	int i;
	for (i =0; i < s->n; i++) {
		printf("%d ", s->a[i]);
	}
	printf("\n");
}
int  stack_size(Stack * s) {
	return s->n;
}
int  stack_is_empty(Stack * s) {
	return 0 == s->n;
}
void stack_clear(Stack * s) {
	free(s->a);
	s->n = 0;
	s->size = 0;
	s->a = NULL;
}
Stack * stack_destroy(Stack * s) {
	if (s != NULL) {
		free(s->a);
		free(s);
	}
	return NULL;
}
void test0()
{
    Stack * sp = stack_create(3);

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty=1
    printf("size=%d\n", stack_size(sp));            // size=0

    stack_push(sp, 5);
    stack_push(sp, 19);
    stack_push(sp, -2);
    stack_print(sp);                                // 5 19 -2

    stack_push(sp, 27);
    stack_print(sp);                                // 5 19 -2 27

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty=0
    printf("size=%d\n", stack_size(sp));            // size=4

    Data x;
    x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=27

    x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=-2

    stack_print(sp);                                // 5 19

    while (!stack_is_empty(sp)) {
        x = stack_pop(sp);
        printf("x=%d\n", x);
        stack_print(sp);
    }
                                                    // x=19
                                                    // 5
                                                    // x=5
                                                    // пустая строка

    if (NULL == stack_destroy(sp))
        printf("end\n");                           // end
}

int main() {
	test0();
	return 0;
}

