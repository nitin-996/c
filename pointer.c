# include <stdio.h>

int main(){

    int age = 22;
    int *ptr = &age;
    int _age= *ptr;

// Incrementing the value of age using the pointer
    (*ptr)++;

    // Updating _age after incrementing age
    _age = *ptr;
    printf("%d\n", _age );
    printf("%p\n", &_age );
    printf("%p\n", &age );

    int i = 4;
    int *pointerN = &i;
    int **pointTopointer = &pointerN;

    printf("%d\n", **pointTopointer);
}