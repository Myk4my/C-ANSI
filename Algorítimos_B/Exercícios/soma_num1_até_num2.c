#include <stdio.h>

int somatorio(int num1, int num2)	{
	int soma = 0;

	if (num1 != num2)	{
		for(int i = num1;i<=num2;i++)	{
			soma += i;
		}
		return soma;
	}
	return num1+num2;
}


int main()	{

	int num1, num2;
	printf("Digite os dois números\n1º = ");
	scanf("%d", &num1);
	printf("2º = ");
	scanf("%d", &num2);
	
	if (num1 < num2)	{
		printf("O somatório dos valores entre %d e %d é = %d\n\n", num1, num2, somatorio(num1, num2));
	}
	else {
		printf("O somatório dos valores entre %d e %d é = %d\n\n", num2, num1, somatorio(num2, num1));
	}

	return 0;
}