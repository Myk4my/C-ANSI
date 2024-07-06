#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void troca_str(char *ori, char **mud, int a, int b)	{
	int tam = 0;
	char *ini = ori;
	for(;*ori;ori++, tam+=1);
	ori = ini;

	if(a>tam || b>tam)	{
		*mud = (char *) malloc((tam+1) * sizeof(char)); 
		for(;*ori;ori++, (*mud)++)	{
			**mud = *ori;
		}
	}
	else	{
		tam = 0;
		for(ori+=a;ori<(ini+b);ori++, tam++);
		ori = ini;
		*mud = (char *) malloc((tam+1) * sizeof(char)); // Pq quando tam + 1 da erro?
		
		for(ini+=a;ini<=(ori+b);ini++, (*mud)++)	{
			**mud = *ini;
		}
	}
		
	**mud = '\0';
	*mud -= tam;
}

int main()	{
	char palavra[TAM];
	char *mudada = NULL;
	int a, b;

	printf("Digite a palavra: ");
	fgets(palavra, TAM, stdin);
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	printf("Digite o valor de B: ");
	scanf("%d", &b);
	printf("Palavra original = %s\n", palavra);
	troca_str(palavra, &mudada, a, b);
	printf("Palavra modificada = %s", mudada);
	free(mudada);

	return 0;
}
