#include <stdio.h>


int volume(int nume)	{
	return nume*nume*nume;
}

int perime(int nume)	{
	return nume*12;
}

int main() 	{
	int num;
	printf("Entre o valor da aresta: ");
	scanf("%d", &num);
	printf("\nO Volume = %d\nO perímetro = %d\n", volume(num), perime(num));
	return 0;
}