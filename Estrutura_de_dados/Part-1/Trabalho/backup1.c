#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MEM 1024


int detectar_sistema_operacional() {
    #ifdef __linux__
        return 1; // Retorna 1 para Linux
    #elif defined(_WIN32)
        return 2; // Retorna 2 para Windows
    #else
        return 0; // Retorna 0 para outros sistemas
    #endif
}

struct block	{
	short int usage;
	char name;
	int start;
	int size;
	struct block *next;
	struct block *ant;
};

struct block *init(void)	{
	struct block *MEMORY = (struct block *) malloc(sizeof(struct block));

	MEMORY->usage = 0; // usado ou  não
	MEMORY->name = '-'; // nome 
	MEMORY->start = 0; // 
	MEMORY->size = MEM; // tamanho ocupado
	MEMORY->next = MEMORY; // ponteiro para o próximo 
	//Obs: não tem anterior pois é o primeiro

	return MEMORY;
} 

struct block *worstfit(struct block *new)	{
	struct block *proc, *ini, *aux;
	int size, rest;
	char name;
	proc = (struct block *) malloc(sizeof(struct block));
	ini = aux = new;
	
	printf("Digite o nome do processo: ");
	name = getchar();
	while (getchar() != '\n');	
	printf("Digite o tamanho de memória necessária: ");
	scanf("%d", &size);

	do	{
		if(aux->usage == 0 && aux->size >= size) {
			new = aux;
			break;
		}
		aux = aux->next;
	} while(aux != ini);
	
	do	{
		if(aux->usage == 0 && aux->size >= size && aux->size > new->size) new = aux;
		aux = aux->next;
	} while(aux != ini);

	 
	if(new->next == ini && new->size >= size)	{  
			proc->usage = 1;
			proc->size = size;
			proc->start = new->start;
			proc->next = ini;
			proc->name = name;
			ini->ant = proc;
			proc->ant = new; 
			new->start += size;
			new->size -= size;
			new->next = proc;
			return proc;
	}
	
	else if(new->size >= size) {
		rest = new->size - size;
		new->usage = 1;
		new->size = size;
		new->name = name;
		proc->usage = 0;
		proc->name = '-';
		proc->size = rest;
		proc->start = new->start + new->size;
		proc->next = new;
		proc->ant = new->ant;

		if(new->ant->next == ini) {
			new->ant->next = proc;
			new->ant = proc;
			return proc;
		}
		new->ant->next = proc;
		new->ant = proc;
		return ini;
	}

	else	{
		printf("\nTamanho ESGOTADO libere memória\n");
		return ini;
	}
}

void show(struct block *mem)	{
	struct block *ini;
	ini = mem;

	do
	{
		printf("\nMemory block %c\n", mem->name);
		printf("[%d\t%c\t%d\t%d\t%p]\n",mem->usage, mem->name, mem->start, mem->size, mem->next);
		mem = mem->next;
	} while (mem != ini);
}

void freemem(struct block *mem, char name)	{

	struct block *aux, *rm, *ini;
	ini = mem;
	for(; mem->name!=name && mem->next != ini; mem=mem->next);
	aux = mem;

	if(mem->name == name)	{

		if(!mem->ant->usage && !mem->next->usage)	{ 
			if(mem->next->next != ini)	{
				aux = mem->ant;
				aux->size += mem->size;
				rm = mem->next;
				aux->size += rm->size;
				aux->next = rm->next;
				aux->start = rm->start;
				if(rm->next->ant != ini) rm->next->ant = aux;
				free(rm);
				free(mem);
			}
			else	{
				aux = mem->ant;
				mem->size += aux->size;
				aux->ant->next = mem;
				mem->ant = aux->ant;
				mem->name = '-';
				free(aux);
			}
		}
		
		else if (!mem->ant->usage)	{ 
			aux = mem->ant;
			aux->next = mem->next;
			mem->next->ant = aux;
			aux->size += mem->size; 
			aux->start = mem->start;
			free(mem);
		}
		else if (!mem->next->usage)	{ 
			if(mem->next->next != ini)	{
				aux = mem->next;
				aux->size += mem->size;
				aux->ant = mem->ant;
				mem->ant->next = aux;
				free(mem);
			}
			else	{
				aux->usage = 0;
				aux->name = '-';
			}
		}
		else {
			aux->usage = 0;
			aux->name = '-';
		}
	}
	else printf("Processo não encontrado!\n\n");

}

struct block *firstfit(struct block *new)	{
	struct block *ini, *proc;
	int size, rest;
	char name;
	ini = new;
	
	printf("Digite o nome do processo: ");
	name = getchar();
	while (getchar() != '\n');	
	printf("Digite o tamanho de memória necessária: ");
	scanf("%d", &size);

	for(;new->next != ini; new = new->next)	{
		if(new->usage == 0 && new->size == size)	{
			new->usage = 1;
			new->size = size;
			new->name = name;
			return ini;
		}
		else if(new->usage == 0 && new->size > size)	{
			rest = new->size - size;
			new->usage = 1;
			new->size = size;
			new->name = name;
			proc = (struct block *) malloc(sizeof(struct block));
			proc->usage = 0;
			proc->name = '-';
			proc->size = rest;
			proc->start = new->start + new->size;
			proc->next = new;
			proc->ant = new->ant;
			if(new->ant->next == ini) {
				new->ant->next = proc;
				new->ant = proc;
				return proc;
			}
			new->ant->next = proc;
			new->ant = proc;
			return ini;
		}
	}
	if((new->size -= size) > 0)	{
		proc = (struct block *) malloc(sizeof(struct block));
		proc->usage = 1;
		proc->size = size;
		proc->start = new->start;
		proc->next = ini;
		proc->name = name;
		ini->ant = proc;
		new->start += size;
		new->next = proc;
		return proc;
	}
	else printf("Falha de segmentação!\n");
	return ini;
}

struct block *bestfit(struct block *l)	{
	struct block *ini, *aux, *proc;
	int size, rest;
	char name;
	ini = l;
	aux = NULL;
	
	printf("Digite o nome do processo: ");
	name = getchar();
	while (getchar() != '\n');	
	printf("Digite o tamanho de memória necessária: ");
	scanf("%d", &size);

	for(;l->next != ini; l = l->next)	{
		if(l->usage == 0 && l->size >= size)	{
			aux = l;
			l = l->next;
			break;
		}
	}

	for(;l->next != ini; l = l->next)	{
		if(l->usage == 0 && l->size < aux->size && l->size >= size) aux = l;
	}

	if(aux)	{
		if(aux->size == size){
			aux->usage = 1;
			aux->name = name;
			return ini;
		}
		else {
			rest = aux->size - size;
			aux->usage = 1;
			aux->size = size;
			aux->name = name;
			proc = (struct block *) malloc(sizeof(struct block));
			proc->usage = 0;
			proc->name = '-';
			proc->size = rest;
			proc->start = aux->start + aux->size;
			proc->next = aux;
			proc->ant = aux->ant;

			if(aux->ant->next == ini) {
				aux->ant->next = proc;
				aux->ant = proc;
				return proc;
			}
			aux->ant->next = proc;
			aux->ant = proc;
			return ini;
		}
	}
	else	printf("Não há blocos Livres!\n");
	return ini;
}


int main()	{
	setlocale(LC_ALL,"portuguese");
	struct block *MEMORY;
	MEMORY = init();
	int choice;
	int sistema = detectar_sistema_operacional();
	char name;

	do
	{
		sleep(1);
		if (sistema==1)	system("clear");
		else if(sistema==2) system("cls");
		printf("-------------------------------------\n"); 
		printf("|     MEMORY MANANGEMENT SYSTEM\t    |\n");
		printf("-------------------------------------\n");
		printf("| Opções:\t\t\t    |\n");
		printf("-------------------------------------\n");
		printf("| 1 Criar bloco com firstfit\t    |\n");
		printf("| 2 Criar bloco com bestfit\t    |\n");
		printf("| 3 Criar bloco com worstfit\t    |\n");
		printf("| 4 Liberar bloco(s)\t\t    |\n");
		printf("| 5 Mostrar blocos\t\t    |\n");
		printf("| 6 Desfragmentar memória\t    |\n");
		printf("| 0 Sair\t\t\t    |\n");
		printf("-------------------------------------\n");
		printf(" ===> ");

		while(scanf("%d", &choice)!= 1) {
    		printf("Entrada inválida. Por favor, insira um número inteiro.\n");
    		while(getchar()!= '\n'); // Limpando o buffer de entrada
		}

		switch(choice)	{
			case 1:
				while (getchar() != '\n');
				MEMORY = firstfit(MEMORY);
				break;
			case 2:
				while (getchar() != '\n');
				MEMORY = bestfit(MEMORY);
				break;
			case 3:
				while (getchar() != '\n');
				MEMORY = worstfit(MEMORY);
				break;
			case 4:
				printf("\nDigite o nome do bloco que deseja excluir: ");
				while (getchar() != '\n');
				name = getchar();
				while (getchar() != '\n');
				freemem(MEMORY, name);
				sleep(1);
				break;
			case 5:
				if (sistema==1)	system("clear");
				else if(sistema==2) system("cls");
				show(MEMORY);
				sleep(3);
				break;
			case 6:
				while (getchar() != '\n');
				//desfrag(MEMORY);
				break;
			case 0:
				break;
			default:
				printf("Escolha uma opção válida!\n");
				break;
		}
	} while (choice!=0);
	free(MEMORY);
	return 0;
}