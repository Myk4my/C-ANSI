/* Construa uma função em C que receba como parâmetro um ponteiro apontando para a raiz
de uma árvore binária e retorne 1 se todo nó não folha tem valor maior que seu(s) filho(s), e 0
caso contrário.*/


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
    // A putaria toda ta aqui
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

void main (void) {
    struct no *arvore = NULL, *aux;
    int ret;
    int arvCont[] = { -1, 100, 83, 90, 18, 15, 36, 29, -1, -1, 5, 1, -1, -1, -1, 8 };
    arvore = alocar(1, arvCont, 15);

    if(nomaior(arvore)) printf("\nO nós filhos tem valores MENORES que seus pais\n");
    else printf("\nO nós filhos tem valores MAIORES que seus pais\n");

    mostrar(arvore, 0);

}