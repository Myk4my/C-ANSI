#include <stdio.h>

int contachar(char var[])	{
	int numero_de_char = 0;
	
	for (int i=0;var[i]!='\0';i++)	{
		numero_de_char += 1;
	}
	return numero_de_char;
}


int main()	{
	char estringue[] = "Hack all the things!";
	printf("O tamanho da String = %d\n", contachar(estringue));
	return 0;
}