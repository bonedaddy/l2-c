#include <stdio.h>

void set(int *y);

int main() {
    int x = 1;
    int *y;
    y = &x;
    x = 2;
    *y += 1; // increments
    printf("y: %d\n", *y); // should be 3
    set(y);
    printf("y: %d\n", *y);
    int *pa, a[2];
    pa = &a[0];
    a[0] = 1;
    printf("a: %d\n", a[0]);
    printf("pa: %d\n", *pa);
    *pa = 100;
    printf("a: %d\n", a[0]);
    printf("pa: %d\n", *pa);
}

void set(int *y) {
    *y += 1;
}