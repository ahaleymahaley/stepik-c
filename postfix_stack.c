#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int Data;

typedef struct {
	Data * a;
	unsigned int n;
	unsigned int size;
} Stack;

void stack_init(Stack * s) {
	s->a = malloc(N * sizeof(s->a[0]));
	s->n = 0;
	s->size = N;
}

void stack_push(Stack * s, Data x) {
	if (s->size == s->n) {
		s->size *= N;
		s = realloc(s, s->size * sizeof(s->a[0]));
	}
	s->a[s->n++] = x;
}

Data stack_pop(Stack * s) {
	Data res;
	res = s->a[--s->n];
	if (N * s->n < s->size && s->size != N) {
		s->size /= N;
		s = realloc(s, s->size * sizeof(s->a[0]));
	}
	return res;
}

void stack_destroy(Stack * s) {
	free(s->a);
}

void stack_no(Stack * s) {
	Data a = stack_pop(s);
	stack_push(s, !a);
}

void stack_and(Stack * s) {
	Data b = stack_pop(s);
	Data a = stack_pop(s);
	stack_push(s, a && b);
}

void stack_or(Stack * s) {
	Data b = stack_pop(s);
	Data a = stack_pop(s);
	stack_push(s, a || b);
}

int main() {
	char * line = NULL;
	size_t n = 0;
	int read;
	int res = 0;
	if (-1 != (read = getline(&line, &n, stdin))) {
		int i;
		char c;
		Stack s;
		Stack * ps = &s;
		stack_init(ps);
		for (i = 0; i < read; i++) {
			c = line[i];
			if (c == '0' || c == '1') {
				stack_push(ps, c - '0');
				continue;
			}
			if (c == '!') {
				stack_no(ps);
				continue;
			}	
			if (c == '&') {
				stack_and(ps);
				continue;
			}
			if (c == '|') {
				stack_or(ps);
				continue;
			}
			if (c == '=') {
				res = stack_pop(ps);
				break;
			}		
		}
		stack_destroy(ps);
	}
	free(line);
	printf("%d\n", res);
	return 0;
}

