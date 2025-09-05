#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef char Data;
typedef struct {
        Data * a;
        unsigned int n;
        unsigned int size;
} Stack;

void stack_init(Stack * s) {
        s->a = malloc(N * sizeof(Data));
        s->n = 0;
        s->size = N;
}

void stack_push(Stack * s, Data x) {
        if (s->n == s->size) {
                s->size *= N;
                s->a = realloc(s->a, s->size * sizeof(Data));
        }
        s->a[s->n++] = x;
}

Data stack_pop(Stack * s) {
        Data res = s->a[--s->n];
        if (N * s->n < s->size && s->size != N) {
                s->size /= N;
                s->a = realloc(s->a, s->size * sizeof(Data));
        }
        return res;
}

Data stack_get(Stack * s) {
        return s->a[s->n - 1];
}

int is_stack_empty(Stack * s) {
        return s->n == 0;
}

void stack_destroy(Stack * s) {
        free(s->a);
}

int main() {
        char * line = NULL;
        size_t n = 0;
        int read;
        int is_correct = 1;
        if ((read = getline(&line, &n, stdin)) != -1) {
                const char * bra[] = {"()", "[]", "{}", "<>", NULL};
                char c;
                Stack s;
                stack_init(&s);
                int i;
                if (line[read - 1] == '\n') {
                    read--;
                }
                for (i = 0; i < read && is_correct; i++) {
                        c = line[i];
                        int j = 0;
                        char brac[3];
                        while (bra[j] != NULL && is_correct) {
                                strcpy(brac, bra[j]);
                                if (brac[0] == c) {
                                        stack_push(&s, c);
                                        break;
                                } else if (brac[1] == c) {
                                        if (is_stack_empty(&s)) {
                                            is_correct = 0;
                                        } else if (stack_get(&s) == brac[0]) {
                                                stack_pop(&s);
                                                break;
                                        } else {
                                                is_correct = 0;
                                        }
                                } else {
                                        j++;
                                }
                        }
                }
                if (!is_stack_empty(&s)) {
                        is_correct = 0;
                }
                stack_destroy(&s);
        }
        free(line);
        printf("%s", is_correct ? "YES\n" : "NO\n");
        return 0;
}
