#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100

typedef struct {
	char s[N];
	int count;
} Data;

struct Node {
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node * tree_add(struct Node * tree, char * x) {
    if (tree == NULL) {
        tree = malloc(sizeof(struct Node));
        strcpy(tree->val.s, x);
	tree->val.count = 1;
        tree->left = NULL;
        tree->right = NULL;
    } else if (strcmp(x, tree->val.s) < 0) {
        tree->left = tree_add(tree->left, x);
    } else if (strcmp(x, tree->val.s) > 0) {
        tree->right = tree_add(tree->right, x);
    } else {
    	tree->val.count++;
    }
    return tree;
}

void tree_print(struct Node * tree) {
    if (tree != NULL) {
        tree_print(tree->left);
        printf("%s %d \n", tree->val.s, tree->val.count);
        tree_print(tree->right);
    }
}

void tree_destroy(struct Node * tree) {
    if (tree != NULL) {
        tree_destroy(tree->left);
        tree_destroy(tree->right);
        free(tree);
    }
}

int tree_count_elements(struct Node * tree, int count) {
	if (tree != NULL) {
        	count++;
        	count = tree_count_elements(tree->left, count);
        	count = tree_count_elements(tree->right, count);
    	}
	return count;
}

int tree_to_massiv(struct Node * tree, Data * nodes, int words) {
    if (tree != NULL) {
        nodes[--words] = tree->val;
        words = tree_to_massiv(tree->left, nodes, words);
        words = tree_to_massiv(tree->right, nodes, words);
    }
    return words;
}

int compare(const void * a, const void * b) {
	Data * word1 = (Data *)a;
       	Data * word2 = (Data *)b;
	int res;

	if (word1->count > word2->count)
		res = 1;
	else if (word1->count < word2->count)
		res = -1;
	else
		res = -strcmp(word1->s, word2->s);	
	
	return res;
}

int main() {
    struct Node * tree = NULL;
    char s[N];
    char c[N];
    while (1 == scanf("%s", s))  {
	    int i, j;
	    for (i = 0, j = 0; s[i] != '\0'; i++) {
		    if (!isalpha(s[i])) {
    			    continue;
		    }
    		    s[i] = tolower(s[i]);
		    c[j] = s[i];
		    j++;		    
	    }
	    if (j > 0) { 
	    	c[j] = '\0';
    	    	tree = tree_add(tree, c);
	    }
    }
    int words = tree_count_elements(tree, 0);
    Data * nodes = malloc(words * sizeof(nodes[0]));
    tree_to_massiv(tree, nodes, words);
    qsort(nodes, words, sizeof(Data), compare);
    while (--words >= 0) {
    	printf("%s %d \n", nodes[words].s, nodes[words].count);
    }
    free(nodes);
    tree_destroy(tree);
    return 0;
}

