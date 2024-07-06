#include <stdio.h>

void inverte(char *str, char *inv)	{
	char *ini, *iniv;
	ini = str;
	iniv = inv;

	for(; *str; str++);
	str--;
	printf("STR = %p\n", str);
	for(; str>=ini; str--)	{
		*inv = *str;
		inv++;
	}
	printf("INV = %p\n", inv);
	*inv = '\0';
}


int main()	{
	char palavra[10];
	char invertida[10];

	printf("Digite a palavra a ser invertida: ");
	gets(palavra);

	inverte(palavra, invertida);
	printf("Palavra = %s\nInvertida = %s\n\n", palavra, invertida);

	return 0;
}
