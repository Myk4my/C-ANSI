#include <stdio.h>

void muda_int(int *x, int *y)	{
	float media;
	int resto;
	media = ((float) (*x+*y)/2);
	resto = ((int) (media*10))%10;
	
	if(resto == 0) *x = *y = (int) media;
	
	else	{
		*x = (int) media;
		*y = (int) media+1;
	}
}



int main()	{
	int x, y;

	printf("Digite o valor de x: ");
	scanf("%d", &x);
	printf("Digite o valor de x: ");
	scanf("%d", &y);
	printf("Antes da função x = %d e y = %d\n", x, y);
	muda_int(&x, &y);
	printf("Depois da função x = %d e y = %d\n", x, y);
	return 0;
}
