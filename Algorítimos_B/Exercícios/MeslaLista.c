#include <stdio.h>
#include <stdlib.h>

struct lista    {
    char id;
    struct lista *prox;
};

struct lista *inserirInicio(struct lista *l, char id) {
    struct lista *aux;
    aux = (struct lista *) malloc (sizeof(struct lista));
    aux->id = id;
    aux->prox = l;
    return aux;
}

struct lista *mesclar(struct lista *, struct lista *);


int main()      {
    struct lista *list1, *list2, *list3;
    list1 = (struct lista *) malloc (sizeof(struct lista));
    list2 = (struct lista *) malloc (sizeof(struct lista));
    list3 = (struct lista *) malloc (sizeof(struct lista));
    
    list1->id = 'H';
    list1->prox = NULL;
    list1 = inserirInicio(list1, 'I');
    list1 = inserirInicio(list1, 'G');
    list1 = inserirInicio(list1, 'T');
    list1 = inserirInicio(list1, 'V');
    list1 = inserirInicio(list1, 'A');

    list2->id = 'M';
    list2->prox = NULL;
    list2 = inserirInicio(list2, 'K');
    list2 = inserirInicio(list2, 'L');
    list2 = inserirInicio(list2, 'J');
    list2 = inserirInicio(list2, 'B');
    list2 = inserirInicio(list2, 'C');

    for(;list1; list1 = list1->prox)    {
        printf("%c ", list1->id);
    }

    printf("\n");
    for(;list2; list2 = list2->prox)    {
        printf("%c ", list2->id);
    }

    list3 = mesclar(list1, list2);
    for(;list3; list3 = list3->prox)    {
        printf("%c ", list3->id);
    }
    return 0;
} 

// A V T G I H
// C B J L K M
// A B C G H I J L M K T V

struct lista *mesclar(struct lista *p1, struct lista *p2)  {
    struct lista *p3, *aux, *ord;

    if(p1->id < p2->id)   {
        aux = ord = p1;
        p1 = p1->prox;
    }
    else   {
        aux = ord = p2;
        p2 = p2->prox;
    }

    for(;p1;p1 = p1->prox)  {
        for(;aux;aux = aux->prox)  {
            if(p2->id < p1->id) {
                aux->prox = p2;
                p2 = p2->prox;
                
            }
            else    {
                aux->prox = p1;
                p2 = p1->prox;
            }
        }
    }
    return ord;