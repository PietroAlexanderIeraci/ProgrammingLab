#include <stdio.h>

int somma(int a, int b){
    int c = a+b;
    return c;
}

void main(){
    int x,y;
    printf("Insert (x) =  ");
    scanf("%d", &x);
    printf("Insert (y) =  ");
    scanf("%d", &y);
    printf("x+y = %d\n", somma(x,y));
}