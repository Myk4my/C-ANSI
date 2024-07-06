

#include <stdio.h>
#include <stdlib.h>

struct elemento	{
	char id;
	struct elemento *prox, *ant;
};

struct elemento *criaIni(struct elemento *list, char id)	{
	struct elemento *aux;
	aux = (struct elemento *) malloc(sizeof(struct elemento));
	aux->id = id;
	aux->prox = list;

	if (list != NULL)	{
		list->ant = aux;
	}
	return aux;
}

struct elemento *cria(struct elemento *list, char id)   {
    struct elemento *aux, *posi, *ini;

    aux = (struct elemento *) malloc(sizeof(struct elemento));
    aux->id = id;

	if (list == NULL) {
		aux->prox = NULL;
		aux->ant = NULL;
		return aux;
	}
	else	{
		posi = list;
    	for(;list->ant; list = list->ant);
    	ini = list;
		list = posi;
		
		if (aux->id <= list->id)	{
			for(; (aux->id < list->id) && list->ant; list = list->ant);
			if(list->ant == NULL)	{
				aux->prox = list;
				aux->ant = NULL;
				list->ant = aux;
				return aux;
			}
			else	{
				posi = list->prox;
				list->prox = aux;
				aux->ant = list;
				aux->prox = posi;
				posi->ant = aux;
			}

		}
		else if(aux->id >= list->id)	{
			for(; (aux->id > list->id) && list->prox; list = list->prox);
			if(list->prox == NULL)	{
				list->prox = aux;
				aux->prox = NULL;
				aux->ant = list;
			}
			else	{
				posi = list->ant;
				list->ant = aux;
				aux->ant = posi;
				posi->prox = aux;
				aux->prox = list;
			}
		}
	}

    return ini;
}



void mostra(struct elemento *lista)	{
	do
	{
		printf("%c", lista->id);
		lista = lista->prox;
	} while (lista != NULL);

}


int main ()	{
	struct elemento *lista;
	lista = NULL;
	lista = cria(lista, 'A');
	lista = cria(lista, 'B');
	lista = cria(lista, 'A');
	lista = cria(lista, 'C');
	lista = cria(lista, 'B');
	lista = cria(lista, 'C');
	lista = cria(lista, 'A');

	printf("Normal:\n");
	mostra(lista);

	return 0;
}
