#include <stdio.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"

int menu()	{
	int indice;

	printf("----------------------------------------------\n");
	printf("|   Sistema de Gerenciamento de Biblioteca   |\n");
	printf("----------------------------------------------\n");
	printf("\n-------------------------------------");
	printf("\n| Selecione uma das opções a seguir |\n");
	printf("-------------------------------------\n");
	printf("\n-----------------------------------\n");
	printf("| 1 = Adicionar Aluno\t\t  |\n");
	printf("| 2 = Listar Alunos\t\t  |\n");
	printf("| 3 = Cadastrar Livro\t\t  |\n");
	printf("| 4 = Listar Livros Disponíveis\t  |\n");
	printf("| 5 = Retirar Livro\t\t  |\n");
	printf("| 6 = Devolver Livro\t\t  |\n");
	printf("| 7 = Exportar Banco de Dados\t  |\n");
	printf("| 0 = Sair do Programa\t\t  |\n");
	printf("-----------------------------------\n\n");
	printf("#: ");
	scanf("%d", &indice);
	printf("\033[2J\033[1;1H");
	return indice;
}

int main()	{
	FILE *books = NULL, *students = NULL;
	int indice;
	char name[TAM];
	books = fopen("livros.db", "r");
	students = fopen("alunos.db", "r");
	
	do  {
		indice = menu();
		switch(indice)	{
			case 0:
				indice = 0;
				break;
			case 1:
				add();
				break;
			case 2:
				list();
				fseek(students, 0, SEEK_SET);
				break;
			case 3:
				addbook();
				break;
			case 4:
				listbooks();
				break;
			case 5:
				getchar();
				printf("Digite o nome do livro a ser retirado: ");
				scanf("%[^\n]", name);
				getchar();
				fclose(books);
				retirar(name);
				books = fopen("livros.db", "r");
				break;
			case 6:
				getchar();
				printf("Digite o nome do livro a ser devolvido: ");
				scanf("%[^\n]", name);
				fclose(books);
				devolve(name);
				books = fopen("livros.db", "r");
				break;
			case 7:
				printf("Criando arquivo YAML.\n");
				save(students, books);
				fseek(students, 0, SEEK_SET);
				fseek(books, 0, SEEK_SET);
				break;
			default:
				printf("Opção inválida! %d\n", indice);
				break;
		}
	} while (indice != 0);
	
	fclose(books);
	fclose(students);
	return 0;
}

// Criar outro arquivo que contenha as informações dos imprestimos com ID:nom do livro ;)
