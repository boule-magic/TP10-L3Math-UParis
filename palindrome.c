#include <stdio.h>
#include <string.h>

int palindrome(const char* s);

int
main(int argc, char *argv[]) {
    char s[61];
    printf("Donnez une phrase (pas plus de 60 car.) : ");
    fgets(s, 61, stdin);
    s[strlen(s)-1]='\0';
    if(palindrome(s) == 1) {
	printf("\"%s\" est un palindrome\n", s);
    } else {
	printf("\"%s\" n'est pas un palindrome\n", s);
    }
}

int palindrome(const char* s) {
    int len = strlen(s);
    int j = 0;
    char s2[len];
    for(int i = 0 ; i < len ; i++) {
	if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '\0') {
	    s2[j] = s[i];
	    j++;
	}
    }
    len = strlen(s2);
    for(int i = 0 ; i < len/2 ; i++) {
	if(s2[i] != s2[len-1-i] && s2[i] != s2[len-1-i]+'A'-'a' && s2[i] != s2[len-1-i]+'a'-'A') {
	    return 0;
	}
    }
    return 1;
}

