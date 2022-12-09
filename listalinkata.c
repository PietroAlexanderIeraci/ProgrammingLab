#include <stdio.h>
#include <stdlib.h>

struct element{
    int value;
    struct element* next;
};

typedef struct element Elemento;
typedef Elemento* Lista;

Lista makelistofintegers(Lista lista, int n){
    Lista new = malloc(sizeof(Elemento));
    lista = new;
    for (int i=1; i<n; i++){
        new->value = i;
        new->next = malloc(sizeof(Elemento));
        new = new->next;
    }
    new->value = n;
    new->next = NULL;
    return lista;
}

void llprint(Lista lista){
    Lista current = lista;
    while (current->next){
        printf("%d, ", current->value);
        current = current->next;
    }
    printf("%d.", current->value);
}

void main(){
    int n;
    Lista lista;
    if (scanf("%d", &n) == 1) lista = makelistofintegers(lista, n);
    llprint(lista);
}