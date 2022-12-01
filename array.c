#include <stdio.h>

void arr_create(int *a, int dim){
    //popola un array di dimensione dim da input di tastiera
    for (int i=0; i<dim; i++)
    {
        int x;
        if (scanf("%d", &x) ==1)
            a[i] = x;
    }   
}

int array_sum(int *a, int dim){
    //calcola somma di tutti gli elementi dell'array
    int s  = 0;
    for (int i=0; i<dim; i++)
        s += a[i];
    return s;
}

void tradiz_swap(int *a, int dim, int x, int y){
    //scambia gli elementi x e y
    if (x>0 && x<dim && y>0 && y<dim){
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
}

void swap(int *a, int dim, int x, int y){
    //scambia gli elementi x e y con aritmetica dei puntatori
    if (x>0 && x<dim && y>0 && y<dim){
        int temp = *(a+x);
        *(a+x) = *(a+y);
        *(a+y) = temp;
    }
}

int elemento_iesimo(int *a, int dim, int i){
    return *(a+i);
}

void print_arr(int *a, int dim){
    //printa l'array
    for (int i=0; i<dim; i++)
        {
            int x = elemento_iesimo(a, dim, i);
            printf("%d", x);
        }
    printf("\n");
}

int is_member(int *a, int dim, int x){
    //trova l'elemento x nell'array: -1 = False, 0 = True
    for (int i=0; i<dim; i++)
        if (a[i]==x) return i;
    return -1;
}

void trad(int val){
    //un simpatico traduttore
    if (val>=0) printf("True");
    else printf("False");
    printf("\n");
}

void location (int *a, int dim, int x){
    int temp = is_member(a, dim, x);
    if(temp >=0)
        printf("%d is in position %d", x, temp);
    else printf("%d is not in the array", x);
}

void selection_sort(int *a, int dim){
    for (int i=0; i<dim; i++)
    {
        int min = i;
            for (int j = (i+1); j<dim; j++)
                if (a[j]<a[min]) min = j;
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void main(){
    //creo array di prova
    int n = 5;
    int a[5];
    
    arr_create(a, n);
    print_arr(a, n);
    selection_sort(a, n);
    print_arr(a, n);
}