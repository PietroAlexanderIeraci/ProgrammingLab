#include <stdio.h>
#include <stdlib.h>

int arrmax(int *a, int n){
    int max = a[0];
    for(int i=1; i<n; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

int* arrgen(int n){
    int *a = (int*)malloc(n*sizeof(int));
    return a;
}

int* countingsort(int *a, int n){
    int max = arrmax(a,n)+1;
    int *b = arrgen(max);
    int *output = arrgen(n);
    
    for(int i=0; i<n; i++){
        b[a[i]] += 1;
    }

    for(int i=1; i<=max; i++){
        b[i] += b[i-1];
    }
    
    for(int i=0; i<n; i++){
        output[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
    
    for(int i=max; i<=0; i--){
        free(b+i);
    }

    for(int i=n; i<=0; i--){
        free(a+i);
    }
    
    return output;
}

void arr_create(int *a, int dim){
    for (int i=0; i<dim; i++)
    {
        int x;
        if (scanf("%d", &x) ==1)
            a[i] = x;
    }   
}

void printarr(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

void main(){
    int n = 4;
    int *a = arrgen(n); 
    arr_create(a,n);

    printf("Unsorted array: ");
    printarr(a,n);
    a = countingsort(a,n);
    printf("\nSorted array: ");
    printarr(a,n);
}