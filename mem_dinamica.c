#include <stdio.h>
#include <stdlib.h>

void main(){
    int x;
    if (scanf("%d", &x) == 1);
    else printf("Error.");
    
    int *a = (int *)malloc(x*sizeof(int));
    for (int i=0; i<x; i++){
        *(a+i) = i; 
    }
    
    for (int i=0; i<x; i++){
        printf("%d", *(a+i)); 
    }
}
