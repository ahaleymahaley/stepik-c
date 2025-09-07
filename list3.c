#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};

void list_init(struct Node * list) {
	list->next = list;
	list->prev = list;
}

void list_insert(struct Node * list, struct Node * t) {
	struct Node * q = list->next;
	list->next = t;
	t->next = q;
	t->prev = list;
	q->prev = t;
}
void list_insert_before(struct Node * list, struct Node * t) {
	list_insert(list->prev, t);
}
void list_remove(struct Node * t) {
	struct Node * p = t->prev;
	struct Node * q = t->next;
	p->next = q;
	q->prev = p;
}

struct Node * list_push_front(struct Node * list, Data d) {
	struct Node * t = malloc(sizeof(struct Node));
	t->data = d;
	list_insert(list, t);
	return t;
}
struct Node * list_push_back(struct Node * list, Data d) {
	return list_push_front(list->prev, d);
}

Data list_delete(struct Node * t) {
	Data res = t->data;
	list_remove(t);
	free(t);
	return res;
}

Data list_pop_front(struct Node * list) {
	return list_delete(list->next);
}
Data list_pop_back(struct Node * list) {
	return list_delete(list->prev);
}

void list_print (struct Node * list) {
	struct Node * p;
	for (p = list->next; p != list; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}
int list_is_empty(struct Node * list) {
	return list == list->prev && list == list->next;
}

void list_clear(struct Node * list) {
	while (!list_is_empty(list)) {
		list_pop_front(list);
	}
}

int main() {
	struct Node * list1 = malloc(sizeof(struct Node));
	struct Node * list2 = malloc(sizeof(struct Node));
	list_init(list1);
	list_init(list2);
	int i;
	int d;
	for (i = 0; i < 5; i++) {
		scanf("%d", &d);
		list_push_back(list1, d);
	}
	for (i = 0; i < 5; i++) {
		scanf("%d", &d);
		list_push_back(list2, d);
	}
	i = 0;
	while (i < 1000000 && !list_is_empty(list1) && !list_is_empty(list2)) {
		Data p = list_pop_front(list1), q = list_pop_front(list2);
		struct Node * win;
		if (p == 0 && q == 9) {
			win = list1;
		} else if (p == 9 && q == 0) {
			win = list2;
		} else if (p > q) {
			win = list1;
		} else {
			win = list2;
		}
		list_push_back(win, p);
		list_push_back(win, q);
		i++;
	}
	if (i == 1000000)
		printf("%s\n", "botva");
	else
		printf("%s %d\n", list_is_empty(list1) ? "second" : "first", i);
	list_clear(list1);
	list_clear(list2);
	free(list1);
	free(list2);
	return 0;
}
