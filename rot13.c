#include <stdio.h>

char *rot13(char *dest, size_t dsize, const char *src);

int
main(int argc, char *argv[]) {
    char s[31];
    for(int i = 1 ; i < argc ; i++) {
	printf("%s ", rot13(s, 31, argv[i]));
    }
    printf("\n");
}

char *rot13(char *dest, size_t dsize, const char *src) {
    int i = 0;
    while(src[i] != '\0') {
	if(i >= dsize) {
	    return NULL;
	}
	if(src[i] >= 'A' && src[i] <= 'Z') {
	    dest[i] = (src[i] - 'A' + 13) %26 + 'A';
	} else if(src[i] >= 'a' && src[i] <= 'z') {
	    dest[i] = (src[i] - 'a' + 13) %26 + 'a';
	} else {
	    dest[i] = src[i];
	}
	i++;
    }
    dest[i] = '\0';
    return dest;
}
