#include <stdio.h>

int encontra(int m, int n)	{
	int resp; 
	int digit = 10;

	for(int i=1;i<=n;i++)	{
		resp = m%digit;
		m /= digit;
	}
	return resp;
}


int main()	{
	int m, n;
	printf("Digite o número a ser verificado: ");
	scanf("%d", &m);
	printf("Digite o dígito a ser buscado: ");
	scanf("%d", &n);
	printf("O %dº digito do número %d é o %d", n, m, encontra(m, n));

	return 0;
}