void save(FILE *, FILE *);
int addbook();
int retirar(char *);
int devolve(char *);
void list();
void add();
void listbooks();
int bytes_to(unsigned int);
int verifica(int, char *);

#define TAM 250
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define NORMAL "\x1b[m"

struct alunos {
	char name[TAM];
	char curso[TAM];
	char tell[TAM];
	unsigned int id;
};

struct livros {
	char name[TAM];
	char autor[TAM];
	unsigned int pub;
	unsigned int copias;
};


void list()	{
	FILE *banco;
	banco = fopen("alunos.db", "r");
	struct alunos Pessoas;

	printf("\n---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tAlunos Cadastrados");
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	
	while(1)	{
		fscanf(banco, "%[^,],", Pessoas.name);
		fscanf(banco, "%[^,],", Pessoas.curso);
		fscanf(banco, "%[^,],", Pessoas.tell);
		fscanf(banco, "%u,", &Pessoas.id);

		if(feof(banco))	{
			printf("\n");
			break;
		}
		printf(BLUE);
		printf("\n\tAluno: %s\tId: %u\tTelefone: %s\tCurso: %s\n", Pessoas.name, Pessoas.id, Pessoas.tell, Pessoas.curso);	
		printf(NORMAL);
	}

	printf("\n---------------------------------------------------------------------------------------------------------\n\n");
	getchar();
	fclose(banco);
}

void add()	{
	FILE *db2;
	struct alunos Pessoa;
	db2 = fopen("alunos.db", "a");

	printf("Digite o nome do Aluno #: ");
	scanf("%s", Pessoa.name);
	getchar();
	printf("Digite o telefone do Aluno #: ");
	scanf("%[^\n]", Pessoa.tell);
	printf("Digite o curso do Aluno #: ");
	getchar();
	scanf("%[^\n]", Pessoa.curso);
	printf("Digite o numero de identificação do Aluno #: ");
	scanf("%u", &Pessoa.id);
	
	while(1)	{
		if(Pessoa.id <= 0)	{
			printf("Número de Id inválido digite o valor correto: ");
			scanf("%u", &Pessoa.id);
		}
		else	{
			struct alunos paux;
			FILE *db3 = fopen("alunos.db", "r");
			while(!feof(db3))	{
				fscanf(db3,"%[^,],%[^,],%[^,],%d,", paux.name, paux.curso, paux.tell, &paux.id);
				if(paux.id == Pessoa.id)	{
					while(paux.id == Pessoa.id)	{
						printf("Este ID já existe no banco de dados\nPor favor digite outro valor: ");
						scanf("%u", &Pessoa.id);
					}
					break;
				}
			}
			fclose(db3);
			break;
		}

	}
	fprintf(db2, "%s,%s,%s,%u,", Pessoa.name, Pessoa.curso, Pessoa.tell, Pessoa.id);
	fclose(db2);
}

void listbooks()	{
	FILE *livro;
	struct livros liv;

	livro = fopen("livros.db","r");
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tLivros Cadastrados");
	printf("\n---------------------------------------------------------------------------------------------------------\n");

	while(1)	{
		fscanf(livro, "%[^,],", liv.name);
		fscanf(livro, "%[^,],", liv.autor);
		fscanf(livro, "%u,", &liv.pub);
		fscanf(livro, "%u,", &liv.copias);

		if(feof(livro))	{
			printf("\n");
			break;
		}
		printf(RED);
		printf("\n  Nome: %s\t  Autor: %s\t Ano de publicação: %u\t  Cópias: %u\n", liv.name, liv.autor, liv.pub, liv.copias);	
		printf(NORMAL);
	}

	printf("---------------------------------------------------------------------------------------------------------\n\n");
	fclose(livro);
}

void save(FILE *student, FILE *book)	{
	FILE *exp;

	struct alunos aluno;
	struct livros livro;

	exp = fopen("Alunos.yaml", "w");
	fprintf(exp,"# Alunos cadastrados\n");
	fprintf(exp,"Alunos:\n");

	while(1)	{
		fscanf(student, "%[^,],", aluno.name);
		fscanf(student, "%[^,],", aluno.curso);
		fscanf(student, "%[^,],", aluno.tell);
		fscanf(student, "%u,", &aluno.id);

		if(feof(student))	{
			printf("\n");
			break;
		}
		
		fprintf(exp, "-\tname: %s\n\tid: %u\n\tcourse: %s\n\ttell: %s\n\n", aluno.name, aluno.id, aluno.curso, aluno.tell);
		printf("Exportanto o Aluno %s\n", aluno.name);
	}
	fclose(exp);

	exp = fopen("Livros.yaml", "w");
	fprintf(exp,"# Livros cadastrados\n");
	fprintf(exp,"Livros:\n");

	while(1)	{
		fscanf(book, "%[^,],", livro.name);
		fscanf(book, "%[^,],", livro.autor);
		fscanf(book, "%u,", &livro.pub);
		fscanf(book, "%u,", &livro.copias);

		if(feof(book))	{
			printf("\n");
			break;
		}
		fprintf(exp, "-\tname: %s\n\tautor: %s\n\tcópias: %u\n\tano: %u\n\n", livro.name, livro.autor, livro.copias, livro.pub);
		printf("Exportanto Livro %s\n", livro.name);
		
	}
	fclose(exp);
	
	printf("Exportação concluida!\n");
	getchar();
}

int addbook()	{
	struct livros liv;
	char nomel[TAM];
	unsigned int id;

	FILE *livros, *Copias;
	livros = fopen("livros.db", "a");
	Copias = fopen("livros.db", "r+");

	printf("Digite o nome do Livro #: ");
	getchar();
	scanf("%[^\n]", liv.name);
	getchar();

	while(!feof(Copias))	{
		fscanf(Copias, "%[^,],",nomel);

		if(!strcmp(nomel, liv.name))	{
			printf("Livro já existe no banco de dados\nAdicionando cópias\n\n");
			fscanf(Copias, "%[^,],%u,%u,",liv.autor, &liv.pub, &liv.copias);
			printf("Digite a quantidade de cópias #: ");
			scanf("%u", &id);
			liv.copias += id;
			fseek(Copias, -bytes_to(liv.copias), SEEK_CUR);
			fprintf(Copias, "%u,", liv.copias);
			fclose(Copias);
			fclose(livros);
			return 0;
		}
	}

	printf("Digite a autor do Livro #: ");
	scanf("%[^\n]", liv.autor);
	getchar();
	printf("Digite o ano de publicação #: ");
	scanf("%u", &liv.pub);
	printf("Digite a quantidade de cópias #: ");
	scanf("%u", &liv.copias);
	fprintf(livros, "%s,%s,%u,%u,", liv.name, liv.autor, liv.pub, liv.copias);
	fclose(livros);

}

int retirar(char *nome)	{
	FILE *book;
	struct livros retirar;
	book = fopen("livros.db", "r+");

	while(!feof(book))	{
		fscanf(book, "%[^,],", retirar.name);
		if(!strcmp(nome, retirar.name))	{
			fscanf(book, "%[^,],%u,%u,",retirar.autor, &retirar.pub, &retirar.copias);
			
			if(retirar.copias==0)	{
				printf("Impossível retirar uma cópia do livro %s\n", retirar.name);
				printf("Cópias esgotadas\n");
				fclose(book);
				return 0;
			}

			else	{
				int var = 2;
				printf("Digite o ID de usuário: ");
				scanf("%d", &var);
				printf("var = %d", var);
				if(verifica(var, nome)){
					retirar.copias -= 1;
					fseek(book, -bytes_to(retirar.copias), SEEK_CUR);
					fprintf(book, "%u,", retirar.copias);
					printf("Livro retirado com sucesso!\n\n");
					fclose(book);
				}
				else if(verifica(var, nome) == 2) printf("Livro já retirado! Impossível fazer empréstimo\n");
				else printf("Id inexistente!\n");
				
			}

			return 0;
		}
	}

	fclose(book);
}

 int devolve(char *name)	{
	FILE *arq;
	struct livros devolver;
	arq = fopen("livros.db","r+");
	printf("Verificando existência do livro na biblioteca\n");

	while(!feof(arq))	{
		fscanf(arq, "%[^,],", devolver.name);
		if(!strcmp(name, devolver.name))	{
			fscanf(arq, "%[^,],%u,%u,",devolver.autor, &devolver.pub, &devolver.copias);
			printf("%s\n", devolver.name);
			devolver.copias += 1;
		
			fseek(arq, -bytes_to(devolver.copias), SEEK_CUR);
			fprintf(arq, "%u,", devolver.copias);
			printf("Livro %s devolvido com sucesso!\n\n", devolver.name);
			fclose(arq);
			return 0;
		}
		
	}

}

int bytes_to(unsigned int valor)	{
	unsigned int aux = 2;

	while(valor>0)	{
		if(valor/10>0)	{
			aux += 1;
			valor /= 10;
		}
		else	return aux;
	}
}

int verifica(int id, char *nome)	{
	int resp = 0;
	struct alunos aluno;

	FILE *alu, *db;

	alu = fopen("alunos.db", "r");

	while(1)	{
		fscanf(alu, "%[^,],%[^,],%[^,],%u,", aluno.name, aluno.curso, aluno.tell, &aluno.id);

		if(feof(alu))	{
			printf("ID de aluno não encontrado\n\n");
			break;
		}

		if(id == aluno.id)	{
			resp = 1;
			db = fopen("database.yaml", "r+");
			unsigned int ID = 0;
			char titulo[TAM];

			while(1)	{
				fscanf(db,"- ID: %u", &ID);
				if(ID == aluno.id)	{
					fscanf(db,"	name: %[^\n]", titulo);
					if(titulo == nome)	{
						printf("Você está tentando retirar um livro já emprestado, isso não é permitido!\n");
						fclose(db);
						fclose(alu);
						return 2;
					}

					if(feof(db)) {
						fclose(db);
						db = fopen("database.yaml", "r+");
						
						while(1)	{
							fscanf(db,"- ID: %u", &ID);
							if(ID == id) fprintf(db, "\nname: %s", nome);
							if(feof(db)) break;
						}
						fclose(db);
						fclose(alu);
						return resp;
					}
				}
				if(feof(db)) break;
			}
			fclose(db);
			db = fopen("database.yaml", "a");
			fprintf(db, "- ID: %u\n\tname: %s", &id, nome);
			break;
			
		}

	}

	fclose(alu);
	return resp;

}