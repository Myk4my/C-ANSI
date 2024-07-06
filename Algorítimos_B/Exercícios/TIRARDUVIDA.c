#include <stdio.h>

#define TAM 4

void somatorio(int m, int n, int matriz[][TAM])	{
	int somator = 0;

	if(m>n)	{
		for(int i=n;i<(n+m);i++)	{
			for(int j=n;j<(n+m);j++)	{
				somator += matriz[i][j];
				printf(" ----- %d\n", somator);
			}
		}
	}
	else {
		for(int i=m;i<(n+m);i++)	{
			for(int j=m;j<(n+m);j++)	{
				somator += matriz[i][j];
				printf(" ----- %d\n", somator);
			}
		}
	}
	printf("Total: %d\n", somator);
}

int main() 	{
	int matriz[TAM][TAM];
	int M, N;
	printf("Digite os valores de M e N entre 0 e 49: ");
	scanf("%d%d", &M, &N);
	printf("Insira os valores da matriz\n");
	
	for(int i=0;i<TAM;i++)	{
		for(int j=0;j<TAM;j++)	{
			printf("matriz[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	for(int i=0;i<TAM;i++)	{
		for(int j=0;j<TAM;j++)	{
			printf("%d\n", matriz[i][j]);
		}
	}

	somatorio(M, N, matriz);
	
	return 0;
}