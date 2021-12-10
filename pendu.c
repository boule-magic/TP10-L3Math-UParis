#include <stdio.h>
#include <string.h>

int char_in(char c, const char *f, int n);
int partial_display(const char *s, const char *f, int n);

int
main(int argc, char *argv[]) {
    if(argc != 2) {
	fprintf(stderr, "Usage : %s [string]\n", argv[0]);
	return 1;
    }
    
    char letters[11], ch;
    int i = 0;
    
    while (i < 10) {
	printf("Saisissez une lettre : ");
	scanf("%c", &ch); //On prend le premier char
	while (getchar () != '\n'); //Et on ignore tout le reste jusqu'au '\n'
	letters[i] = ch;
	i++;
	if(partial_display(argv[1], letters, 11) == 0) {
	    printf("Gagné !\n");
	    return 0;
	}
    }
    printf("Perdu !\n");
    return 0;
}

int char_in(char c, const char *f, int n) {
    char * ch = (char*) memchr (f, c, n);
    if (ch == NULL) {
	return 0;
    }
    return 1;
}

int partial_display(const char *s, const char *f, int n) {
    int asterix = 0, i;
    char obelix[strlen(s)];
    for(i = 0 ; i < strlen(s) ; i++) {
	if(char_in(s[i], f, n) == 1) {
	    obelix[i] = s[i];
	} else {
	    obelix[i] = '*';
	    asterix++;
	}
    }
    obelix[i] = '\0';
    printf("%s\n", obelix);
    return asterix;
}
