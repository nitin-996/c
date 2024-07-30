#include <stdio.h>

int main() {
    int marks[3];
    printf("Print the number 1: ");
    scanf("%d", &marks[0]);

    printf("Number is %d\n", marks[0]);

    int year[] = {2020, 2021, 2022};

    // Printing the elements of the year array
   
    for (int i = 0; i < 3; i++) {
        printf("years %d \n", year[i]);
    }
    printf("\n");

    return 0;
}
