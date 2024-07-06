#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int alocador(int *vetor, int **vet, int var);

int main()	{
	int vet[TAM], i, j;
	int *vetx;
	int var = 0;

	printf("Digite os vlores do vetor\n");

	for(i=0;i<TAM;i++)	{
		printf("\n==> ");
		scanf("%d", &vet[i]);
	}

	for (i=0;i<3;i++)	{
		var = alocador(vet, &vetx, i);
		for(j=0;j<var;j++)	{
			printf("\n==> %d", *(vetx+j));
		}
		printf("\n");
		free(vetx);
	}
	return 0;
}

int alocador(int *vetor, int **vet, int var)	{
	int num, i;
	int *aux;

	aux = vetor;
	num = i = 0;

	for(;i<TAM;i++, vetor++)	{
		if(*vetor%3==var)	{
			num++;
		}
	}
	*vet = (int *) malloc(4 * (num+1));
	vetor = aux;
	aux = *vet;

	for(i=0; i<TAM;i++, vetor++)	{
		if(*vetor%3==var)	{
			**vet = *vetor;
			(*vet)++;
		}
	}
	*vet = aux;
	return num;
}