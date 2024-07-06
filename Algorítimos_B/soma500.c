#include <stdio.h>

#define TAM 500

void somatorio(int m, int n, int vetor[])	{
	int somator = 0; 
	
	if(m>TAM-n)	{
		for(int i=n;i<TAM;i++)	{
			somator += vetor[i];
		}
	}
	else {
		for(int i=n;i<(n+m);i++)	{
			somator += vetor[i];
		}
	}
	printf("Total: %d\n", somator);
}


int main() 	{
	int vet[TAM];
	int M, N;

	printf("Entre com o valor de M: ");
	scanf("%d", &M);
	printf("Agora com o valor de N: ");
	scanf("%d", &N);

	printf("Entre com os valores do vetor: ");

	for(int i=0;i<10;i++)	{
		printf("%d = ", i+1);
		scanf("%d", &vet[i]);
	}

	somatorio(M, N, vet);
	
	return 0;
}