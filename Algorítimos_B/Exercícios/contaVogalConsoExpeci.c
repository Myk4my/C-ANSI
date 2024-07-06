#include <stdio.h>

void conta(char *str, int *v, int *c, int *ex)	{

	for(; *str; str++)	{
		if((int) *(str) >= 65 && (int) *(str) <= 90)	{
			if(*(str) == 'A' || *(str) == 'E' || *(str) == 'I' || *(str) == 'O' || *(str) == 'U')	{
				*v += 1;
			}
			else *c += 1;	
		}
		else if((int) *(str) >= 97 && (int) *(str) <= 122)	{
			if(*(str) == 'a' || *(str) == 'e' || *(str) == 'i' || *(str) == 'o' || *(str) == 'u')	{
				*v += 1;
			}
			else *c += 1;
		}
		else *ex += 1;
	}
}



int main()	{
	char plv[40];
	int vogais, cons, espe;
	vogais = cons = espe = 0;

	printf("Digite a palavra: ");
	fgets(plv, 40, stdin);
	conta(plv, &vogais, &cons, &espe);
	printf("\nA frase %spossui:\n%d - Vogais\n%d - Consoantes\n%d - Caracteres epeciais\n\n", plv, vogais, cons, espe-1);

	return 0;
}
