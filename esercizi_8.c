#include <stdio.h>
#include <stdlib.h>
    
int * removedupl(int a[], int n){
    int *p = (int *)malloc(sizeof(int));
    *p = a[0];
    int counter = 0;

    for (int i=1; i<n; i++){
        int notdupl = 0;
        for (int j=i-1; j>=0; j--)
            if (a[i]==a[j]) notdupl = 1;
        if (notdupl == 0){
            counter += 1;
            *(p+counter) = a[i];
        }
    }
    return p;
}

int counter(int a[], int n){
    int x = 1;

    for (int i=1; i<n; i++){
        int notdupl = 0;
        for (int j=i-1; j>=0; j--)
            if (a[i]==a[j]) notdupl = 1;
        if (notdupl == 0) x +=1;
        }
    return x;
}
    
void main(){
    int tst[4] = {5,2,5,7};
    int *a = removedupl(tst, 4);
    int x = counter(tst, 4);
    
    for (int i=0; i<x; i++)
        printf("%d", *(a+i));
}
