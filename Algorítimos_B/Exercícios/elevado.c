#include <stdio.h>

int elevado(int x, int y)	{
	int result = x;

	for(int i=1;i<y;i++)	{
		result *= x;
	}
	
	return result;
}


int main()	{
	int x, y, valor;

	printf("Entre com os valores de X e Y\n\nX: ");
	scanf("%d", &x);
	printf("Y: ");
	scanf("%d", &y);

	valor = elevado(x, y);
	
	printf("\n%d elevado a %d = %d\n", x, y, valor);

	return 0;
}