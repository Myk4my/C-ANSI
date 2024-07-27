/* Construa uma função em C que receba como parâmetro um ponteiro apontando para a raiz
de uma árvore binária e retorne 1 se todo nó não folha tem valor maior que seu(s) filho(s), e 0
caso contrário.*/



/*Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore
binária e retorne a altura da árvore.*/


/* Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore
binária e um valor inteiro g (cujos valores possíveis são 0, 1 ou 2), e retorne o número de nós
da árvore que têm grau igual a g. (grau = número de subárvores)*/


#include <stdio.h>
#include <stdlib.h> 

struct no {
    int valor;
    struct no *fdir, *fesq;
};

void mostrar(struct no *arvore, int nivel) {
    int i;
    if (!arvore) {
        for (i = nivel; i > 0; i--)
            printf("   ");
            printf("-\n");
        return NULL;
    }
    mostrar(arvore->fdir, nivel+1);
    for (i = nivel; i > 0; i--) printf("   ");
    printf("%d\n", arvore->valor);
    mostrar(arvore->fesq, nivel+1);
}


struct no *alocar (int n, int *armazenada, int ultimoValido) {
    struct no *novo;
    if (n <= ultimoValido && armazenada[n]!=-1) { /* n tambem deve ser > 0 */
        novo = (struct no *) malloc (sizeof(struct no));
        novo->valor = armazenada[n];
        novo->fdir = alocar(n*2+1, armazenada, ultimoValido);
        novo->fesq = alocar(n*2, armazenada, ultimoValido);
        return novo;
    }
    return NULL;
}

struct no *localizar(struct no *aux, int valor) {
    while (aux && aux->valor != valor) {
        if (aux->valor > valor) aux = aux->fesq;
        else    aux = aux->fdir;
    }
    return aux;
}

struct no *localizarRec(struct no *aux, int valor) {
    if (!aux)   return NULL;
    if (aux->valor == valor)    return aux;
    if (aux->valor < valor) return localizarRec(aux->fdir, valor);
    else    return localizarRec(aux->fesq, valor);
}

int nomaior(struct no *raiz)    {
    int retesc, retdir;
    retdir = retesc = 1;
    if(!raiz) return 0;

    printf("\nValor corrente no nó: %d\n\n", raiz->valor);
    if(raiz->fesq && raiz->fdir)    {
        if(raiz->valor > raiz->fesq->valor && raiz->valor > raiz->fdir->valor) {
            retesc = nomaior(raiz->fesq);
            if(retesc)  retdir = nomaior(raiz->fdir);
            else retdir = 0;
        }
        else    {
            retesc = retdir = 0;
        }
    }
    else if(raiz->fesq) {
        if(raiz->valor > raiz->fesq->valor) retesc = nomaior(raiz->fesq);
        else retesc = 0;
    }
    else if(raiz->fdir) {
        if(raiz->valor > raiz->fdir->valor) retdir = nomaior(raiz->fdir);
        else retdir = 0;
    }
    else return 1;

    if(retdir && retesc) return 1;
    else return 0;
}

int somafolha(struct no *aux)   {
    int sum;
    sum = 0;
    if(!aux) return 0;
    if(!aux->fdir && !aux->fesq) return aux->valor;
    sum += somafolha(aux->fesq);
    sum += somafolha(aux->fdir);
    return sum;
}


int graus(struct no *arv, int g)   {
    if(!arv) return 0;
    int num = 0;
    if(!g)  {
        num += graus(arv->fesq, g);
        num += graus(arv->fdir, g);
        if(!arv->fdir && !arv->fesq) {
            //printf("VALOR = %d\n", arv->valor);
            num += 1;
            return num;
        }
    }
    else if(g == 1) {
        num += graus(arv->fesq, g);
        num += graus(arv->fdir, g);
        if((arv->fdir && !arv->fesq) || (arv->fesq && !arv->fdir)){
            //printf("VALOR = %d\n", arv->valor);
            num += 1;
            return num;
        }
    }
    else if(g == 2) {
        num += graus(arv->fesq, g);
        num += graus(arv->fdir, g); 
        if(arv->fdir && arv->fesq)  {
            //printf("VALOR = %d\n", arv->valor);
            num += 1;
            return num;
        }
    }
    return  num;
}

struct no *menor(struct no *pai)   {
    struct no *node, *tmp;
    node = NULL;
    if(!pai) return NULL;
    if(!pai->fdir && !pai->fesq) return pai;
    tmp = menor(pai->fesq);
    node = (tmp && (pai->valor < tmp->valor)) ? pai : tmp;
    tmp = menor(pai->fdir);
    node = ((tmp && node) && (tmp->valor < node->valor)) ? tmp : node;
    
    if(node) return node;
    return tmp;
}

int altura (struct no *arv) {
    int result, aux;
    result = 0;
    if(!arv) return 0;
    if(!arv->fdir && !arv->fesq)  return 0;
    
    result = 1 + altura(arv->fesq);
    aux = 1 + altura(arv->fdir);

    if(result > aux) return result;
    return aux;
}

int main (void) {
    struct no *arvore = NULL, *aux;
    int ret;
    int arvCont[] = { -1, 100, 83, 90, 18, 15, 1, 29, 40, -1, 3, 8, -1, -1, -1, 5 };
    arvore = alocar(1, arvCont, 15);

    if(nomaior(arvore)) printf("\nO nós filhos tem valores MENORES que seus pais\n");
    else printf("\nO nós filhos tem valores MAIORES que seus pais\n");

    mostrar(arvore, 0);

    printf("O somatório dos valores dos nos folhas é = %d\n", somafolha(arvore));
    aux = menor(arvore);
    
    if(aux) printf("O valor do menor elemento na arvore é: %d\n", aux->valor);
    printf("A altura da árvore é: %d\n", altura(arvore));
    printf("O número de nós com grau %d é: %d\n", 0, graus(arvore, 0));
    return 0;
}