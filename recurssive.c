# include <stdio.h>


void printsh(int count);

int main(){
printsh(5);
return 0;
}

void printsh(int count){

    if(count == 0 ){
        return;
    }

    printf("hello world\n");
    printsh(count-1);

}