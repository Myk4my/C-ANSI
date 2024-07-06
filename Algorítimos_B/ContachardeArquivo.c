#include <stdio.h>

int main()	{
	FILE *file;	
	char name[20], c, c2;
	int cont=0;

	printf("Digite o nome do arquivo: ");
	scanf("%s", name);

	if((file = fopen(name,"r")) != NULL)	{
		printf("Arquivo aberto");
		printf("\nDigite o caractere a ser contado: ");
		scanf(" %c", &c2);

		for(;!feof(file); c = getc(file)) if(c == c2) cont++;
		printf("\nO caractere %c aparece o arquivo %d vezes\n\n", c2, cont);
	}
	else printf("Não funfou\n");

	

	return 0;
}