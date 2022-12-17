#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void ordina(int *a, int n){
    int j = 0;
    int loc;
    int sw = 0;
    while (j<n){
        int min = a[j];
        for (int i=j+1; i<n; i++){
            if (a[i] < min){
                min = a[i];
                loc = i;
                sw = 1;
            }
        }
        if (sw == 1) swap(a, j, loc);
        j++;
        sw = 0;
    }
}

void printarr(int *a, int n){
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int funz2(int *a, int n){
    int x = 0;
    for (int i=0; i<n-1; i++){
        x += a[i]*a[i+1];
    }
    return x;
}

int* funz3(int *a, int n){
    int *b = (int*)malloc(n*sizeof(int));
    int skip = 0;
    
    for (int i=0; i<n; i++){
        for (int j=i-1; j>=0; j--){
            if (a[j]==a[i]) skip = 1;
        }
        if (skip == 0){
            int count = 0;
            int mem = a[i];
            for (int k=0;  k<n; k++){
                if (a[k] == mem) count ++;
            }
            b[i]=count;
        }
        skip = 0;
    }
    return b;
}

void main(){
    int a [7] = {13,45,1,-12,0,1,0};
    int n = 7;
    printarr(a,n);
    printf("\n");
    ordina(a,n);
    printarr(a,n);

    printf("\n\n\nEsercizio A2\n");
    int b[6] = {1, 2, 3, 4, 5, 6};
    int m = 6;
    int x = funz2(b,m);
    printf("%d", x);

    printf("\n\n\nEsercizio A1\n");
    int c[6] = {4, 1, 1, 4, 1, 2};
    int l = 6;
    int* d = funz3(c,l);
    printarr(d,l);   
}