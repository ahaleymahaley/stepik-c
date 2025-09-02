#include <stdio.h>
#include <string.h>
#include <stdlib.h>                                                                                                                                                                     
int is_symmetric(const char *str)  {
	int is_str_symmetric = 0;
	char dupstr[101];
	int i, j;
	size_t len = strlen(str);
	for (i = (int)len / 2 - 1, j = 0; i >= 0; i--, j++) {
		dupstr[j] = str[i];
	}
	dupstr[j] = '\0';
	printf("%s %s\n", dupstr, str + len / 2 + len % 2);
	is_str_symmetric = 0 == strcmp(str + len / 2 + len % 2, dupstr);
	return is_str_symmetric;
}

int is_periodic(const char *str, char *sub) {
    	int is_str_periodic = 0;
    	size_t len = strlen(str);
    	if (len == 1) {
		is_str_periodic = 1;
		strcpy(sub, str);
    	} else if (len == 2) {
		is_str_periodic = str[0] == str[1];
		strncpy(sub, str, 1);
		strcpy(sub + 1, "\0");
    	} else {
		int i;
		for (i = (int)len / 2; i >= 1;i--) {
	    		char *dupstr;
	    		char dupsub[51];
	    		dupstr = strdup(str);
	    		strncpy(dupsub, str, i);
	    		strcpy(dupsub + i, "\0");
	    		while (0 == strncmp(dupstr, dupsub, i)) {
				memmove(dupstr, dupstr + i, strlen(dupstr) - i + 1);
	    		}
	    		if (strlen(dupstr) == 0) {
	    			is_str_periodic = 1;
	    			strncpy(sub, str, i);
	    			strcpy(sub + i, "\0");
	    		}
	    		free(dupstr);
		}
    	}
	return is_str_periodic;  
}

int is_jewelry(const char *str, char *sub) {
	return (is_symmetric(str)  && is_periodic(str, sub));
}

int main() {
        char str[101];
        char sub[51];
        scanf("%s", str);
        if (is_jewelry(str, sub)) {
                printf("%s\n", sub);
        } else {
                printf("NO\n");
        }
        return 0;
}                                                                                           
