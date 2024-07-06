/*Escreva uma função que receba como parâmetro uma lista encadeada circular e elimine todos os
elementos que estejam repetidos, mantendo apenas a primeira ocorrência de cada, ou seja, de todos
os elementos que possuírem o mesmo conteúdo, deve ficar apenas o primeiro*/

#include <stdio.h>
#include <stdlib.h>

struct elemento	{
	char id;
	struct elemento *prox;
};

struct elemento *removeIgual(struct elemento *list)	{
	struct elemento *aux, *igual, *ini, *remover;
	ini = aux = list;
	igual = list->prox;
	
	do
	{
		while(igual!=ini)	{
			if(aux->id == igual->prox->id)	{
				remover = igual->prox;
				igual->prox = remover->prox;
				free(remover);
			}
			igual = igual->prox;
		}
		aux = aux->prox;
		igual = aux; 

	} while (aux != ini);

	return ini;

}

struct elemento *circular(struct elemento *list, char id)	{
	struct elemento *aux, *ini;
	aux = (struct elemento *) malloc(sizeof(struct elemento));
	aux->id = id;
	ini = list;

	if(!list)	{
		aux->prox = aux;
		return aux;
	}

	for(;list->prox != ini; list = list->prox);
	list->prox = aux;
	aux->prox = ini;
	return aux;
}

void mostra(struct elemento *lista)	{
	struct elemento *aux = lista;
	do
	{
		printf("%c", aux->id);
		aux = aux->prox;
	} while (aux != lista);

}


int main ()	{
	struct elemento *lista;
	lista = NULL;
	lista = circular(lista, 'A');
	lista = circular(lista, 'B');
	lista = circular(lista, 'A');
	lista = circular(lista, 'D');
	lista = circular(lista, 'E');
	lista = circular(lista, 'B');
	lista = circular(lista, 'A');

	printf("Normal:\n");
	mostra(lista);
	lista = removeIgual(lista);
	printf("\nModificada:\n");
	mostra(lista);

	return 0;
}