#include <stdio.h>
#include <stdlib.h>

struct pilha {
	int valor;
	struct pilha *prox;
};


struct pilha *create(struct pilha *p, int var)	{
	struct pilha *aux = (struct pilha *) malloc(sizeof(struct pilha));
	aux->valor = var;
	aux->prox = p;
	return aux;
}

void show(struct pilha *p)	{

	for(; p!=NULL; p = p->prox)	{
		printf("%d\n", p->valor);
	}

}

struct pilha *del(struct pilha *p)	{
	struct pilha *aux = (struct pilha *) malloc(sizeof(struct pilha));
	aux = p->prox;
	free(p);

	return aux;

}

int main ()	{
	struct pilha *topdown = NULL;

	for(int i=1; i<10; i++)	{
		topdown = create(topdown, i);
	}

	show(topdown);
	topdown = del(topdown);
	printf("Depois\n\n");
	show(topdown);
	return 0;
}
