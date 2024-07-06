#include <stdio.h>

#define TAM 11

int encontra(int vet[])	{
	int yes = 1;

	for(int i=0;i<TAM;i++)	{
		int verifica = vet[i];
		int maior = 0;
		int menor = 0;

		for(int j=0;j<TAM;j++)	{
			if(verifica>vet[j])	{
				maior++;
			}
			else {
				menor++;
			}
			if ((maior > (TAM/2+1)) || (menor > (TAM/2+1)))	{
				break;
			}
		}	
		if ((maior == (TAM/2)) || (menor-1 == (TAM/2))) {
			return i;
		}
	}

}


int main() 	{
	int vet[TAM];
	int ind;

	for (int i=0;i<TAM;i++)	{
		printf("%d: ", i+1);
		scanf("%d", &vet[i]);
	}
	ind = encontra(vet);
	printf("O valor médio do vetor é\n%d\n", vet[ind]);
	return 0;
}