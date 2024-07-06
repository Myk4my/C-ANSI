#include <stdio.h>

int soma(int numero)	{
	int resposta = 0;

	for(int i=1;i<=numero;i++)	{
		resposta += i;
	}
	return resposta;

}



int main()	{
	int num, resp;

	printf("Entre com o número: ");
	scanf("%d", &num);

	printf("O resultado é %d\n", soma(num));


	return 0;
}