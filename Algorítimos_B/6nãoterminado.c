#include <stdio.h>

#define MAX 10

void encontraMAX(int numero, int vetor[])	{
	int max = vetor[0];
	int Maior;
		
	for (int i=0;i<MAX;i++)	{
		if (vetor[i]>max)	{
			max = vetor[i];
		}
	}

	Maior = max;

	while (numero-1>0)	{
		
	}
		
	
}

int main()	{
	
	int n;
	int vet[MAX];
	printf("Digite o valor de n [n < 500]: ");
	scanf("%d", &n);
	printf("Digite os valores do vetor\n");
	
	for (int i=0;i<MAX;i++)	{
		printf("%d = ", i+1);
		scanf("%d", &vet[i]);
	}
	encontraMAX(n, vet);

	return 0;
}