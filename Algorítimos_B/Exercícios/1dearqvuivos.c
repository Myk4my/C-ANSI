#include <stdio.h>

int main()	{
	FILE *file, *file2;	
	char  c, c2;
	int i=0;

	if((file = fopen("arq1", "r")) != NULL)	printf("Arquivo 1 aberto\n");
	else printf("Erro ao abrir arquivo");
	if((file2 = fopen("arq2", "r")) != NULL)	printf("Arquivo 2 aberto\n");
	else printf("Erro ao abrir arquivo");

	while(!feof(file) && !feof(file2))	{
		c = getc(file);
		c2 = getc(file2);
		i++;
		if(c!=c2) break;
	}

	if(!feof(file) && feof(file2))	printf("O primeiro arquivo acobou antes do segundo\n");
	else if(feof(file) && !feof(file2)) 	printf("O segundo rquivo acobou antes do primeiro\n");
	else if(!feof(file) && !feof(file2))	printf("Ocorreu uma diferênça em [%c] com {%c} na posição (%d)\n", c, c2, i);
	else printf("Os dois são iguais!\n");
	fclose(file);
	fclose(file2);
	return 0;
}
