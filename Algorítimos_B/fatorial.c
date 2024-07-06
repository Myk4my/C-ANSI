#include <stdio.h>

int fator(int numero)	{
	int resp = numero;

	for (int i=numero-1; i>=2; i--)	{
		resp *= i; 
	}
	return resp;
}

int main()	{
	int num;
	printf("Digite um número para calcular o fatorial: ");
	scanf("%d", &num);
	printf("O fatorial de %d é = %d\n", num, fator(num));

	return 0;
}