/*Escreva uma função que receba como parâmetros um ponteiro
apontando para a raiz de uma árvore binária de pesquisa e um valor inteiro
N. A função deve retornar 1 se existe árvore e a substituição do valor da raiz
pelo valor N mantém a árvore como árvore binária de pesquisa, e 0 caso
contrário.*/


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

int arvbin(struct no *arv, int n)	{
	int val = 0;
	if(!arv)	return 0;
	if(arv->fdir && arv->fesq)	{
		if ((arv->fdir->valor > n) && (arv->fesq->valor < n)) val = 1;
		else val = 0;
	}
	else if(arv->fdir && (arv->fdir->valor > n)) val = 1;
	else if(arv->fesq && (arv->fesq->valor < n)) val = 1;
	else if(!arv->fesq && !arv->fdir) val = 1;
	else val = 0;
	arv->valor = n;
	return val;
}

int *achourec(struct no *filho, int val, int *vet)	{
	if(!filho)	return vet;
	vet[0] += 1;
	if(filho->valor == val)	vet[1] = 1;
	else	{
		vet = achourec(filho->fesq, val, vet);
		if(vet[1] !=1 ) vet = achourec(filho->fdir, val, vet);
		else return	vet;
	}
	return vet;
}

int achou(struct no *arv, int val)	{
	int *resp = (int *) malloc(sizeof(int) * 2);
	resp[0] = 0;
	resp[1] = 0;

	if(!arv)	return -1;
	if(arv->valor == val) return 1;
	if(!arv->fesq)	return -1;
	resp = achourec(arv->fesq, val, resp);
	
	if(resp[1] == 1) return resp[0];
	return -1;
}

int main (void) {
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
  //if(arvbin(arvore, 80))	printf("A árvore permanece binária de pesquisa\n");
  //else printf("Não da!\n");
  mostrar(arvore, 0);
  printf("Achou? %d\n\n", achou(arvore, 15));
  return 0;
}