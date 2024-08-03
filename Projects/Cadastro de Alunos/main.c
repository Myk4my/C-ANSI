#include <stdio.h>

struct dados {
	char name[30];
	char curso[30];
	int idade;
};

void list(FILE *banco)	{
	struct dados Pessoas[1];
	printf("\n--------------------------------------------------------------------------\n");
	printf("\t\t\tAlunos Cadastrados");
	printf("\n--------------------------------------------------------------------------\n");
	while(1)	{
		fscanf(banco, "%[^,],", Pessoas->name);
		fscanf(banco, "%[^,],", Pessoas->curso);
		fscanf(banco, "%d,", &Pessoas->idade);
		if(feof(banco))	{
			printf("\n");
			break;
		}
		printf("\n\tAluno: %s\tIdade: %d\tCurso: %s\n", Pessoas->name, Pessoas->idade, Pessoas->curso);	
	}
	printf("--------------------------------------------------------------------------\n\n");

}

void add()	{
	FILE *db2;
	db2 = fopen("banco.db", "a");

	struct dados Pessoa[1];
	printf("Digite o nome do Aluno #: ");
	scanf("%s", Pessoa->name);
	printf("Digite a idade Aluno #: ");
	scanf("%d", &Pessoa->idade);
	printf("Digite o curso do Aluno #: ");
	getchar();
	scanf("%[^\n]", Pessoa->curso);
	fprintf(db2, "%s,%s,%d,", Pessoa->name, Pessoa->curso, Pessoa->idade);
	fclose(db2);
}

void save(FILE *);

int menu()	{
	int indice;

	printf("-----------------------------------\n");
	printf("|\tSistema de Cadastro\t  |\n");
	printf("-----------------------------------\n");
	printf("\nSelecione uma das opções a seguir\n");
	printf("-----------------------------------\n");
	printf("| 1 = Adicionar Aluno\t\t  |\n");
	printf("| 2 = Listar Alunos\t\t  |\n");
	printf("| 3 = Exportar Banco de Dados\t  |\n");
	printf("| 0 = Sair do Programa\t\t  |\n");
	printf("-----------------------------------\n\n");
	printf("#: ");
	scanf("%d", &indice);
	printf("\033[2J\033[1;1H");
	return indice;
}

int main()	{
	FILE *db = NULL;
	int indice;
	char c;
	db = fopen("banco.db", "r");
	indice = 1;

	while(indice)	{
		indice = menu();
		switch(indice)	{
			case 0:
				indice = 0;
				break;
			case 1:
				add(db);
				break;
			case 2:
				list(db);
				fseek(db, 0, SEEK_SET);
				break;
			case 3:
				printf("Criando arquivo YAML.\n");
				save(db);
				fseek(db, 0, SEEK_SET);
				break;
			default:
				printf("Opção inválida! %d\n", indice);
				break;
		}
	}
	fclose(db);
	return 0;
}	

void save(FILE *arquivo)	{
	FILE *exp;
	struct dados export[1];

	exp = fopen("Alunosdb.yaml", "w");
	fprintf(exp,"# Alunos cadastrados\n");
	fprintf(exp,"Alunos:\n");

	while(1)	{
		fscanf(arquivo, "%[^,],", export->name);
		fscanf(arquivo, "%[^,],", export->curso);
		fscanf(arquivo, "%d,", &export->idade);

		if(feof(arquivo))	{
			printf("\n");
			break;
		}
		
		fprintf(exp, "-\tname: %s\n\tage: %d\n\tcourse: %s\n", export->name, export->idade, export->curso);
		printf("Exportanto o Aluno %s\n", export->name);
	}

	printf("Exportação concluida!\n");
	fclose(exp);

}