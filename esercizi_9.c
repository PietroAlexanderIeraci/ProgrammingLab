#include <stdio.h>
#include <stdlib.h>

struct element{
    int value;
    struct element* next;
};
typedef struct element Element;
typedef Element* Elementpointer;

void llprint(Elementpointer head){
    Elementpointer current = head;
    while(current->next){
        printf("%d, ", current->value);
        current = current->next;
        }
    printf("%d", current->value);
}

Elementpointer makelist(Elementpointer element){
    int x;
    if(scanf("%d", &x) == 1 && x != -1){
        element = malloc(sizeof(Element));
        element->value = x;
        element->next = makelist(element->next);
        }
    return element;
}

int llelementcounter(Elementpointer head){
    Elementpointer current = head;
    int count = 1;
    while (current->next){
        count +=1;
        current = current->next;
        }
    return count;
}

Elementpointer joiner(Elementpointer a, Elementpointer b, int j){
    Elementpointer first;
    Elementpointer second;
    if(j>0){
        first = a;
        second = b;
        }
    else{
        first = b;
        second = a;
        }

    Elementpointer current = first;
    while(current->next){
        current = current->next;
        }
    current->next = second;

    return first;
}

Elementpointer orderedinsert(Elementpointer head, int n){
    Elementpointer node = malloc(sizeof(Element));
    node->value = n;
    //adding at the top of the list
    if(n <= head->value){
        node->next = head;
        return node;
        }

    //adding at end of the list
    Elementpointer previous;
    Elementpointer current = head;
    while(n > current->value){
        if(!current->next){
            current->next = node;
            return head;
        }
        previous = current;
        current = current->next;
    }
    
    //adding at midpoint of the list
    previous->next = node;
    node->next = current;
    return head;
}

void main(){
    int start;
    Elementpointer x = malloc(sizeof(Element));
    if(scanf("%d", &start) == 1 ) x->value = start;
    llprint(x);
    int f = 0;
    while(f == 0){
        int y;
        if(scanf("%d", &y) == 1) x = orderedinsert(x, y);
        llprint(x);
        printf("\nCTRL + Z to exit.\n");
        }
    llprint(x);

}
