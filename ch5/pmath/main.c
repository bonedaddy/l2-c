#include <stdio.h>

int main(int argc, int *argv[]) {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pa = numbers;
    printf("%d", *pa); // print 1
    printf("%d", *(pa+1)); // print 2
    printf("%d\n", *(pa+2)); // print 3
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(pa+i));
    }
    *(pa+1) = 69; // set the 2nd element to 69, overridden from 2
    if (*(pa+1) != 69) {
        printf("expected 69 got %d\n", *(pa+1));
        return 1;
    }
    printf("%d\n", *pa+1); // this prints 2???
    printf("%d\n", *(pa+1)); // this prints 69??

    for (int i = 0; i < argc - 1; i++) {
        printf("%p\n", *(argv+i));
    }
    return 0;
}