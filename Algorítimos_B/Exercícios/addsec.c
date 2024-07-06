#include <stdio.h>

struct tempo	{
	int hora;
	int min;
	int sec;
};

struct tempo ajusta(int hora, int min, int sec, int acre)	{
	struct tempo ajustado;
	int	aux = sec+acre;

	if (aux >= 60)	{
		int minutos = 0;

		while (aux>=60)	{
			aux -= 60;
			minutos += 1;
		}

		ajustado.sec = aux;
		ajustado.min = min + minutos;
		ajustado.hora = hora;
	}

	else	{
		ajustado.hora = hora;
		ajustado.min = min;
		ajustado.sec = aux;
	}

	return ajustado;
}

int main()	{
	struct tempo tmp;
	int sec;

	printf("Digite hora: ");
	scanf("%d", &tmp.hora);
	printf("Digite minutos: ");
	scanf("%d", &tmp.min);
	printf("Digite segundos: ");
	scanf("%d", &tmp.sec);
	printf("Digite os segundos para acrecentar: ");
	scanf("%d", &sec);

	tmp = ajusta(tmp.hora, tmp.min, tmp.sec, sec);
	
	printf("\nA hora ajustada é: %d:%d:%d\n", tmp.hora, tmp.min, tmp.sec);
	
	return 0;
}