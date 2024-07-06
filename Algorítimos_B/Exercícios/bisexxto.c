#include <stdio.h>

int bi(int ano)	{
	if (((ano%100==0) && (ano%400==0)) ||  (!(ano%100==0) && (ano%4==0)))	{
		return 1;
	}
	
	return 0;	

}





int main()	{
	int ano;
	printf("Digite um ano para verificcar: ");
	scanf("%d", &ano);

	if (bi(ano))	{
		printf("O %d é Bissexto\n", ano);
	}
	else {
		printf("O %d Não é Bissexto\n", ano);
	}

	return 0;
}