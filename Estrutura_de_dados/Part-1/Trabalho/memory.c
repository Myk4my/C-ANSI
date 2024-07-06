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

struct block *init(void)	{ // Cria o bloco principal 
	struct block *MEMORY = (struct block *) malloc(sizeof(struct block));

	MEMORY->usage = 0; // usado ou não
	MEMORY->name = '-'; // nome 
	MEMORY->start = 0; // 
	MEMORY->size = MEM; // tamanho ocupado
	MEMORY->next = MEMORY; // ponteiro para o próximo 

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
		if(aux->usage == 0 && aux->size >= size) { // Encontra o primeiro bloco vazio 
			new = aux;
			break;
		}
		aux = aux->next;
	} while(aux != ini);
	
	do	{
		if(aux->usage == 0 && aux->size >= size && aux->size > new->size) new = aux; // Pega o maior deles
		aux = aux->next;
	} while(aux != ini);

	 
	if(new->next == ini && new->size >= size)	{  // Se for o principal cria dele
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
	
	else if(new->usage == 0 && new->size >= size) { // Se não cria do livre e guarda o resto
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

void show(struct block *mem)	{ // Mostra os blocos lindamente 
	struct block *ini;
	ini = mem;

	do
	{
		printf("\nMemory block %c\n", mem->name);
		printf("[%d\t%c\t%d\t%d\t%p]\n",mem->usage, mem->name, mem->start, mem->size, mem->next);
		mem = mem->next;
	} while (mem != ini);
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
		else if(new->usage == 0 && new->size > size)	{ // Cria e toma o cuidado de atualizar o fim/início da memória
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
	if(new->size > 0 && new->size >= size)	{ // Cria do bloco principal
		new->size -= size;
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
	else printf("Falha de segmentação [!]\nTamanho ESGOTADO libere memória\n");
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
		if(l->usage == 0 && l->size >= size)	{ // Pega o primeiro bloco livre
			aux = l;
			l = l->next;
			break;
		}
	}

	for(;l->next != ini; l = l->next)	{ // Encontra o menor
		if(l->usage == 0 && l->size < aux->size && l->size >= size) aux = l;
	}

	if(aux)	{ // Se há blocos livres e ele é o menor possível, faz a mágica.
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
	else if (l->size > 0 && l->size >= size)	{ // Se não há blocos livres, cria um da memória principal
		proc = (struct block *) malloc(sizeof(struct block));
		proc->usage = 1;
		proc->size = size;
		proc->start = l->start;
		proc->next = ini;
		proc->name = name;
		ini->ant = proc;
		proc->ant = l; 
		l->start += size;
		l->size -= size;
		l->next = proc;
		return proc;
	}
	else printf("Falha de segmentação [!]\nTamanho ESGOTADO libere memória\n");

	return ini;
}

void desfrag(struct block *mem)	{
	struct block *aux, *ini, *tmp;
	int size = 0;
	ini = mem;
	aux = mem->next;

	if (mem!=aux)	{
		do
		{
			if(aux->usage == 0)	{
				tmp = aux;
				for(aux = aux->ant; aux != ini->ant; aux = aux->ant) aux->start -= tmp->size; // Atualiza o valor de início dos blocos
				aux = tmp;
				tmp = aux->ant;
				tmp->next = aux->next;
				aux->next->ant = tmp;
				size += aux->size;
				tmp = aux;
				aux = aux->next;
				free(tmp);
				continue;
			}
			else	aux = aux->next;
		} while (aux->next != ini);

		if(size>0)	{ // Se há blocos livre, atualize a memória
			aux = ini->ant;
			aux->size += size;
			aux->start -= size;
		}

	}
}

struct block *freemem(struct block *mem, char name)	{

	struct block *aux, *rm, *ini;
	ini = mem;
	for(; mem->name!=name && mem->next != ini; mem=mem->next);
	aux = mem;

	if(mem->name == name)	{

		if(!mem->ant->usage && !mem->next->usage)	{ // Libera ambos os blocks adjacentes 
			if(mem->ant->next != ini)	{
				aux = mem->ant;
				rm = mem->next;
				aux->size += mem->size;
				aux->size += rm->size;
				aux->next = rm->next;
				aux->start = rm->start;
				rm->next->ant = aux;
				free(rm);
				free(mem);
			}
			else	{ // Caso seja o bloco principal, atualiza a a memória
				aux = mem->ant;
				rm = mem->next;
				ini = rm->next;
				aux->start -= (mem->size + rm->size);
				aux->size += (mem->size + rm->size);
				aux->next = ini;
				ini->ant = aux;
				free(mem);
				free(rm);

			}
		}
		
		else if (!mem->ant->usage)	{  // Se somente o bloco a esquerda estiver livre e for diferente do bloco principal 
			if(mem->ant->next != ini)	{
				aux = mem->ant;
				aux->next = mem->next;
				mem->next->ant = aux;
				aux->size += mem->size; 
				aux->start = mem->start;
				free(mem);
			}
			else	{ // Se for o Principal, atualiza os valores
				aux = mem->ant;
				aux->size += mem->size;
				aux->start -= mem->size;
				aux->next = mem->next;
				ini = mem->next;
				ini->ant = aux;
				free(mem);
			}
		}
		else if (!mem->next->usage)	{ // Se somente o bloco a direita estiver livre e for diferente do bloco principal
			if(mem->next->next != ini)	{
				aux = mem->next;
				aux->size += mem->size;
				aux->ant = mem->ant;
				mem->ant->next = aux;
				free(mem);
			}
			else	{ // Se for o Principal, atualiza os valores

				aux = mem->next;
				rm = mem->ant;
				aux->start -= mem->size;
				aux->size += mem->size;
				rm->next = aux;
				aux->ant = rm;
				rm = ini;
				
				for(;rm != aux; rm = rm->next) rm->start -= mem->size; // Atualiza o valor dos blocos
			}
		}
		else { // Se for único libera o coitado
			aux->usage = 0;
			aux->name = '-';
		}
	}
	else printf("Processo não encontrado [!]\n\n");
	return ini;

}

int main()	{
	setlocale(LC_ALL,"Portuguese"); // Corrige o erro do code blocks não mostrar caracteres especiais.
	struct block *MEMORY;
	MEMORY = init();
	int choice;
	int sistema = detectar_sistema_operacional(); // Detecta o S.O Para limpar a tela
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

		while(scanf("%d", &choice)!= 1) { // Inteiro por favor
    		printf("Entrada inválida. Por favor, insira um número inteiro.\n ===> ");
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
				MEMORY = freemem(MEMORY, name);
				sleep(1);
				break;
			case 5:
				if (sistema==1)	system("clear");
				else if(sistema==2) system("cls");
				show(MEMORY);
				sleep(3); // Dalay da tela para mostrar blocos. PARA VISUALIZAR POR MAIS TEMPO SEM AUMENTAR DIGITE 5 VÁRIAS VEZES 
						 // Ao menos em sistemas UNIX funciona.
				break;
			case 6:
				printf("Desfragmentando memória... [-]\n"); 
				while (getchar() != '\n');
				desfrag(MEMORY); // Remove os blocos livres e atualiza a memória
				break;
			case 0:
				break;
			default:
				printf("Escolha uma opção válida [!]\n");
				break;
		}
	} while (choice!=0);
	free(MEMORY);
	return 0;
}
