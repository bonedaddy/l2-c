#include <stdio.h>
/*
    (i < argc -1) ? " " : ""
    the above says "if i is less than argc-1 print a whitespace, otherwise no"
*/
int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf("\n");
    return 0;
}

