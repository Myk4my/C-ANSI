#include <stdio.h>

int main()	{
	FILE *file, *file2;
	int id;
	float al;
	char nome[20];

	if((file = fopen("arq1", "r"))!=NULL) printf("funfou\n");
	else printf("não funfou\n");

	if((file2 = fopen("arqb", "wb"))!=NULL) printf("funfou\n");
	else printf("não funfou\n");

	while(!feof(file))	{
		fscanf(file, "%s %d %f", nome, &id, &al);
		printf("Dados lidos\nNome = %s\tIdade = %d\tAltura = %.2f\n", nome, id, al);
		fwrite(nome, sizeof(char), 20, file2);
		fwrite(&id, sizeof(int), 1, file2);
		fwrite(&al, sizeof(float), 1, file2);
	}

	fclose(file);
	fclose(file2);

	return 0;
}