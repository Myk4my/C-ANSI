#include <stdio.h>

int main()	{
	FILE *file;
	int line = 0, count = 0, maiorc = 0, maiorl = 0;
	char c, name[20];

	printf("Digite o nome do Arquivoa ser aberto\n==: ");
	scanf("%s", name);
	
	if((file = fopen(name, "r"))!=NULL)	{
		printf("Arquivo, %s aberto com sucesso.\n", name);
		while(!feof(file))	{
			line++;
			for(; c!='\n'; c = getc(file))	{
				count++; 
				printf("%c",c);
			}
			printf("\n");
			if(count>maiorc){
				maiorc = count;
				maiorl = line;
			}
			count = 0;
			c = getc(file);
			printf("%c\n",c);
		}
	}	else printf("Arquivo, %s não foi aberto.\n", name);

	printf("A linha com mais caracteres foi a %d e possui %d caracteres\n\n", maiorl, maiorc);
	fclose(file);
	return 0;
}