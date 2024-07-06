#include <stdio.h>
#include <stdlib.h>


/*Escreva uma função para mesclar duas listas duplamente encadeadas, ordenadas de forma crescente,
recebidas como parâmetros, ou seja, transformar as duas em uma mantendo a ordenação. A mescla deve
ser feita percorrendo as duas listas, e não concatenando uma no fim da outra e então ordenando. Além
disso, nenhum novo elemento deve ser alocado.*/


struct elemento	{
	char id;
	struct elemento *prox, *ant;
};

struct elemento *criaCirc(struct elemento *list, char id)	{
	struct elemento *aux;
	aux = (struct elemento *) malloc(sizeof(struct elemento));
	aux->id = id;
	aux->prox = list;

	if (list != NULL)	{
		list->ant = aux;
	}
	return aux;
}


struct elemento *mesclaOrd(struct elemento *l1, struct elemento *l2)	{
	struct elemento *aux, *l3;

	if(!l1 && !l2) return NULL;
	else if(!l1) return l2;
	else if(!l2) return l1;

	for(; l1->ant; l1 = l1->ant);
	for(; l2->ant; l2 = l2->ant);

	//l3 = (l1->id < l2->id) ? l1 : l2;
	
	if (l1->id<l2->id)	{
		l3 = l1;
		l1 = l1->prox;
		aux = l3;
	}
	else {
		l3 = l2;
		aux = l2->prox;
		l2 = l1;
		l1 = aux;
		aux = l3;
	}
	printf("\n");
	if(l1)	{
		while(l3)	{
			if((l1 && l2) && l1->id<l2->id)	{
				l3->prox = l1;
				l1->ant = l3;
				l1 = l1->prox;
				l3 = l3->prox;
			}
			else if(l2)	{
				l3->prox = l2;
				l2->ant = l3;
				l2 = l2->prox;
				l3 = l3->prox;
			}
			else if(l1)	{
				l3->prox = l1;
				l1->ant = l3;
				l1 = l1->prox;
				l3 = l3->prox;
			}
			else	{
				l3->prox = NULL;
				l3 = l3->prox;
			}
		}
	}
	
	return aux;

}

struct elemento *criaOrd(struct elemento *list, char id)   {
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
	} while (lista);

}


int main ()	{
	struct elemento *lista1, *lista2, *lista3;
	lista1 = lista2 = lista3 = NULL;

	lista1 = criaOrd(lista1, 'A');
	lista1 = criaOrd(lista1, 'B');
	lista1 = criaOrd(lista1, 'A');
	lista1 = criaOrd(lista1, 'C');
	lista1 = criaOrd(lista1, 'B');
	lista1 = criaOrd(lista1, 'C');
	lista1 = criaOrd(lista1, 'A');

	lista2 = criaOrd(lista2, 'D');
	lista2 = criaOrd(lista2, 'C');
	lista2 = criaOrd(lista2, 'E');
	lista2 = criaOrd(lista2, 'F');
	lista2 = criaOrd(lista2, 'D');
	lista2 = criaOrd(lista2, 'M');
	lista2 = criaOrd(lista2, 'L');
	
	printf("Normal 1:\n");
	mostra(lista1);
	printf("\nNormal 2:\n");
	mostra(lista2);

	lista3 = mesclaOrd(lista1, lista2);

	printf("\nMesclada 3:\n");
	mostra(lista3);

	return 0;
}
