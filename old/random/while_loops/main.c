#include <stdio.h>

int main() {
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i < 10) {
        int num = array[i];
        if (num >= 5 && num < 10) {
            printf("%d\n", num);
        } else if (num > 10) {
            break;
        }
        i++;
    }
    return 0;
}