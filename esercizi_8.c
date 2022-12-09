#include <stdio.h>
#include <stdlib.h>
    
int * removedupl(int a[], int n, int x){
    int *p = (int *)malloc(x*sizeof(int));
    *p = a[0];
    int counter = 1;

    for (int i=1; i<n; i++){
        int notdupl = 0;
        for (int j=i-1; j>=0; j--)
            if (a[i]==a[j]) notdupl = 1;
        if (notdupl == 0){
            p[counter] = a[i];
            counter ++;
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
    int tst[6] = {9,23,679,8,8,9};
    int x = counter(tst, 6);
    int *a = removedupl(tst, 6, x);
    
    for (int i=0; i<x; i++)
        printf("%d ", *(a+i));
}
