#include <stdio.h>
#include <string.h>

/*
    (i < argc -1) ? " " : ""
    the above says "if i is less than argc-1 print a whitespace, otherwise no"
int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf("\n");
    return 0;
}

*/

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int val = strcmp(argv[i], "dog");
        printf("matched: %d\n", val);
     //   printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf("\n");
    return 0;
}