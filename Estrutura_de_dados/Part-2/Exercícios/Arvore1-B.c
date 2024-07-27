/*Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore de
grau 4 e retorne o nível do nó folha que é atingido por um caminho no qual o sucessor do nó
corrente é sempre o nó de menor valor dentre os nós filhos de corrente.*/

#include <stdio.h>
#include <stdlib.h>

#define GRAU 4

struct elemento {
	int valor;  // campos necessários
	struct elemento *filhos[GRAU];
};

struct elemento *inserir(int valor, struct elemento *arv) {
	struct elemento *novo, *raiz;
	int i, o;
	novo = (struct elemento *) malloc (sizeof(struct elemento));
	novo->valor = valor;
	for (i = 0; i < GRAU; i++)
		novo->filhos[i] = NULL;
	if (!arv)	return novo;
	raiz = arv;
	printf("Ja existe um no raiz na arvore (valor %d).\nEscolha uma subarvore (1 a %d) para a insercao do novo no: ", arv->valor, GRAU);
	scanf("%d", &o);
	o--;
	while(arv->filhos[o] != NULL) {
		arv = arv->filhos[o];
	    printf("Ja existe um no raiz nessa subarvore (valor %d).\nEscolha uma subarvore (1 a %d) para a insercao do novo no: ", arv->valor, GRAU);
	    scanf("%d", &o);
	    o--;
	}
	arv->filhos[o] = novo;
	return raiz;
}

void mostrar(struct elemento *arv, int nivel) {
	int i;
	for (i = 0; i < nivel; i++)
    printf("    ");
  	if (!arv) {
    	printf("-\n");
    	return;
    }
 	printf("%d\n", arv->valor);
 	for (i = 0; i < GRAU; i++)	mostrar(arv->filhos[i], nivel+1);
}


int nivel(struct elemento *raiz) {
	int i, n, next;
	i = n = next = 0;
	
	if(!raiz) return -1;

	for(i; i<GRAU; i++)	{
		if(!n && raiz->filhos[i]) {
			n = raiz->filhos[i]->valor;
			next = i;
		}
		else if(raiz->filhos[i] != NULL && raiz->filhos[i]->valor < n) {
			n = raiz->filhos[i]->valor;
			next = i;
		}
	}
	printf("\nMenor valor em nível atual é %d\n\n", n);
	return 1 + nivel(raiz->filhos[next]);

}

void main (void) {
	struct elemento *arvore;
	arvore = NULL;
	
	arvore = inserir(45, arvore);
	arvore = inserir(90, arvore); // 1
	arvore = inserir(83, arvore); // 3
	arvore = inserir(15, arvore); // 1 3
	arvore = inserir(1, arvore); // 3 1
	arvore = inserir(29, arvore); // 3 3
	arvore = inserir(18, arvore); // 1 1
	arvore = inserir(36, arvore);  // 1 3 2
	arvore = inserir(5, arvore);  // 1 3 1
	arvore = inserir(8, arvore);  // 3 3 3
 
	mostrar(arvore, 0);

	printf("O nível do menor valor atualmente é: %d\n", nivel(arvore));


  }
