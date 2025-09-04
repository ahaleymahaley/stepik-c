#include <stdio.h>
#define N 8

typedef int Data;

typedef struct {
	Data a[N];
	unsigned int n;
} Stack;

void stack_init(Stack * s) {
	s->n = 0;
}
void stack_push(Stack * s, Data x) {
	s->a[s->n++] = x;
}
Data stack_pop(Stack * s) {
	return s->a[--s->n];
}
Data stack_get(Stack * s) {
	return s->a[s->n - 1];
}
void stack_clear(Stack * s) {
	s->n = 0;
}
void stack_print(Stack * s) {
	int i;
	for (i = 0; i < (int)s->n; i++) {
		printf("%d ", s->a[i]);
	}
	printf("\n");
}
int  stack_size(Stack * s) {
	return s->n;
}
int  stack_is_empty(Stack * s) {
	return s->n == 0;
}
int  stack_is_full(Stack * s) {
	return s->n == sizeof(s->a) / sizeof(s->a[0]);
}


int main() {
	Data test[N] = {1, 5, 65, 15, -15, -6, 0, 1};
	Stack s;
	Stack * ps = &s;
	stack_init(ps);
	stack_print(ps);
	int i;
	for (i = 0; i < N; i++) {
		stack_push(ps, test[i]);
	}
	stack_print(ps);
	for (i = 0; i < N; i++) {
		Data p = stack_pop(ps);
		printf("popped: %d\n", p);
	}
	stack_print(ps);
	return 0;
}
