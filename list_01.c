#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
	Data val;
	struct Node * next;
};

struct Node * list_create() {
	return NULL;
}
void list_push(struct Node ** plist, Data x) {
	struct Node * p = malloc(sizeof(struct Node));
	p->val = x;
	p->next = *plist;
	*plist = p;
}
Data list_pop (struct Node ** plist) {
	struct Node * p = *plist;
	Data res = p->val;
	*plist = p->next;
	free(p);
	return res;
}
Data list_get(struct Node * list) {
	return list->val;
}
void list_print (struct Node * list) {
	struct Node * p;
	for (p = list; p != NULL; p = p->next) {
		printf("%d ", p->val);
	}
	printf("\n");
}
int list_size(struct Node * list) {
	struct Node * p;
	int n = 0;
	for (p = list; p != NULL; p = p->next) {
		n++;
	}
	return n;
}
int  list_is_empty(struct Node * list) {
	return list == NULL;
}
void list_clear(struct Node ** plist) {
	while (!list_is_empty(*plist)) {
		list_pop(plist);
	}
}

int main() {
    struct Node * list = list_create();
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));         // size = 2

    list_clear(&list);
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

	return 0;
}

