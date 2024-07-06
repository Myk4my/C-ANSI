#include <stdio.h>

#define TAM 7

struct tempo	{
	int hora;
	int minuto;
	int segundos;
};

struct tempo retorna_valores(char palavra[])	{
	struct tempo valores;

	valores.hora = palavra[1] - '0' + (palavra[0] - '0')*10;
	valores.minuto =  palavra[4] - '0' + (palavra[3] - '0')*10;
	valores.segundos =  palavra[7] - '0' + (palavra[6] - '0')*10;

	return valores;

}

int main()	{

	char palavra[TAM];
	printf("Entre com O horário: ");
	scanf("%s", palavra);

	struct tempo resultados = retorna_valores(palavra);
	
	printf("\nO resultado é\n%d Horas\t%d Minutos\t %d Segundos\n", resultados.hora, resultados.minuto, resultados.segundos);

	return 0;
}