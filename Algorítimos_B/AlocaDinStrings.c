#include <stdio.h>
#include <stdlib.h>

char *trocastr(char *p, char *p2, int num);

#define TAM 10

int main()	{
	char p[TAM], p2[TAM], *p3;
	int num;

	printf("Digite a 1º palavra\n===> ");
	gets(p);
	printf("Digite a 2º palavra\n===> ");
	gets(p2);
	printf("Digite a posição: ");
	scanf("%d", &num);
	
	p3 = trocastr(p, p2, num);
	printf("\nFrase resultante\n===> %s", p3);

	return 0;
}

char *trocastr(char *p, char *p2, int num)	{
	char *ptr, *aux;
	int total=0, i;

	ptr = p;
	for(;*ptr;ptr++, total++);

	ptr = p2;	
	for(;*ptr;ptr++, total++);

	ptr = (char *) malloc(1 * (total+1));
	aux	= ptr;

	for(i=0; *p; p++,ptr++,i++)	{
		// <== pq???
		if(i==num)	for(; *p2; p2++, ptr++)	*ptr = *p2;
		*ptr = *p;
	}

	*ptr = '\0';
	return aux;
}