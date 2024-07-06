#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *fdir, *fesq;
};

/****************************************************************************************
            OPERAÇÕES PARA ÁRVORES BINÁRIAS EM GERAL - AULAS ANTERIORES
****************************************************************************************/

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


/****************************************************************************************
            OPERAÇÕES PARA ÁRVORES BINÁRIAS DE BUSCA
****************************************************************************************/

struct no *incluir(struct no *arvore, int valor) {
    struct no *novo, *aux;
    novo = (struct no *) malloc (sizeof(struct no));
    novo->valor = valor;
    novo->fesq = novo->fdir = NULL;
    if (!arvore)    return novo;
    aux = arvore;
    while (1) {
        if (aux->valor > valor) {
            if (aux->fesq) aux = aux->fesq;
            else {
                aux->fesq = novo;
                return arvore;
            }
        }
        else {
            if (aux->fdir)  aux = aux->fdir;
            else {
                aux->fdir = novo;
            return arvore;
            }
        }
    }
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

/****************************************************************************************
                                      MAIN
****************************************************************************************/

void main (void) {
  struct no *arvore = NULL, *aux;

  arvore = incluir(arvore, 50);
  arvore = incluir(arvore, 30);
  arvore = incluir(arvore, 22);
  arvore = incluir(arvore, 43);
  arvore = incluir(arvore, 15);
  arvore = incluir(arvore, 26);
  arvore = incluir(arvore, 75);
  arvore = incluir(arvore, 65);
  arvore = incluir(arvore, 90);
  arvore = incluir(arvore, 68);
  arvore = incluir(arvore, 55);
  arvore = incluir(arvore, 53);
  arvore = incluir(arvore, 23);