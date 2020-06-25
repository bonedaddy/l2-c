#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int numGrades = 0;
    printf("enter number of grades to calculate: ");
    scanf("%i", &numGrades);
    int grades[numGrades];
    for (int i = 0; i < numGrades; i++) {
        printf("\nenter grade: ");
        scanf("%i", &grades[i]);
    }
    int total = 0;
    int sum = 0;
    for (int i = 0; i < numGrades; i++) {
        total += grades[i];
    }
    sum = (float) total / numGrades;
    printf("grade average %i\n", sum);
}