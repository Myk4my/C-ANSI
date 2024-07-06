/* 1 Eliminar penúltimo elemento da lista */
/* 2 Eliminar primeiro e utlimo */
/* 3 Deslocar elementos de valor N para o iníco da lista. */

#include <stdio.h>
#include <stdlib.h>

struct elemento	{
	char id;
	struct elemento *prox;
};

/*struct elemento *removeIgual(struct elemento *list)	{
	struct elemento *aux, *igual, *ini;
	ini = igual = list;

	do
	{
		while(aux != list)	{
			if(aux->id == igual->prox->id)	{
				struct elemento *remove;
				remove = igual->prox;
				igual->prox = remove->prox;
				free(remove);
			}
			igual = igual->prox;
		}
		aux = aux->prox;
	} while (aux == ini);

}*/

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
	return ini;
}

void mostra(struct elemento *lista)	{
	struct elemento *aux = lista;
	do
	{
		printf("%c", aux->id);
		aux = aux->prox;
	} while (aux != lista);

}

struct elemento *rmpu(struct elemento *l)	{
	struct elemento *aux, *pen;
	int count = 1;
	aux = l->prox;
	//printf("Aqui");
	for(; l != aux; aux = aux->prox) count++;
	aux = l;
	for(; count>3; count--) aux = aux->prox;
	pen = aux->prox;
	aux->prox = pen->prox;
	free(pen);
	return l;
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
	//lista = removeIgual(lista);
	lista = rmpu(lista);
	printf("\n\nModificada:\n");
	mostra(lista);
	printf("\n");

	return 0;
}
