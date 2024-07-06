#include <stdio.h>
#include <string.h>

#define MAX 256

int elevado(int var, int ele)	{
	int result = 1;

	if(ele>0)	{
		for(int i=1;i<=ele;i++)	{
			result *= var;
		}
	}
	else
		return 1;
	
	return result;
	
}

int conversor(char string[])	{
	int result = 0;
	int aux = 0;
	int i = strlen(string);

	for(i;i>0;i--)	{
		result += (string[i-1] - '0') * elevado(2, aux);
		++aux;
	}

	return result;
}


int main()	{

	int inteiro;
	char string[MAX];

	printf("Entre com o código em bits: ");
	scanf("%s", string);

	inteiro = conversor(string);
	printf("Convertendo...\n%s = %d\n", string, inteiro);

	return 0;
}