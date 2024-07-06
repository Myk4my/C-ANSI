#include <stdio.h>
#include <stdlib.h>

void elimina(FILE *legend, char *nome)	{ // Elimina os índices e escreve em outro arquivo.
	FILE *legenda2;
	legenda2 = NULL;
	int indice1, indice2, num, num1;
	char str[250];

	printf("Digite o índice inicial: ");
	scanf("%d", &indice1);
	printf("Digite o índice final: ");
	scanf("%d", &indice2);

	if(indice1>0 && indice2>0)	{
		legenda2 = fopen("legend", "w");
		if(indice1>indice2)	{
			num = indice1;
			indice1 = indice2;
			indice2 = num;
		}
		num1 = indice1;

		fgets(str, sizeof(str), legend);
		num = atoi(&str);
		fseek(legend, 0, SEEK_SET);

		while(indice1 > num && !feof(legend))	{
			fgets(str, sizeof(str), legend);
			fputs(str, legenda2);
			num = atoi(&str);
		}

		while(indice2 > num && !feof(legend))	{
			fgets(str, sizeof(str), legend);
			num = atoi(&str);
		}

		if(num1==1)	{
			fseek(legenda2, -3L, SEEK_CUR);
			fprintf(legenda2, "%d\n", num1);
			++num1;
		}

		while(!feof(legend))	{
			fgets(str, sizeof(str), legend);
			num = atoi(&str);
		
			if(num-indice2>=1)	{ // Muda o número dos índices novos
				fseek(legenda2, -2L, SEEK_CUR);
				fprintf(legenda2, "\n\n%d\n", ++indice1);
			}
			else fputs(str, legenda2);
		}
	}

	if(legenda2!=NULL)	{	// Elimina o arquivo original e renomeia o novo.
		fclose(legenda2);
		fclose(legend);
		remove(nome);
		rename("legend", nome);
	}
}

int menu(void)	{
	int resp = 0;
	printf("\033[2J\033[1;1H");
	printf("-------------------------\n");
	printf("|     Edita Legendas    |\n");
	printf("-------------------------\n");
	printf("\nEscolha uma das opções\n\n");
	printf("-------------------------\n");
	printf("| [1] - Arquivo\t\t|\n");
	printf("| [2] - Acrescentar\t|\n");
	printf("| [3] - Diminuir\t|\n");
	printf("| [4] - Eliminar\t|\n");
	printf("| [0] - Sair\t\t|\n");
	printf("-------------------------\n");
	printf("===> ");
	scanf("%d", &resp);
	return resp;
}

void diminui(FILE *legend)	{
	int seg, mili, numint, count=0, min=0, segaux=0, minaux=0;
	char c;
	char num[250]; 
	char linha[250];

	printf("Digite os segundos a serem removidos: ");
	scanf("%d", &seg);
	printf("Digite os milisegundos a serem removidos: ");
	scanf("%d", &mili);


	while(!feof(legend))	{   // Loop para fazer as alterações dos valores
		while ((c = fgetc(legend)) != '\n')	{
			if (c == ':') {
				count++;
				if (count%2==0) { // Está uma casa antes dos segundos 
				    fgets(num, 3, legend);
				    fseek(legend, -3L, SEEK_CUR);
					numint = atoi(&num);
					numint -= seg; 

					if(numint<0)	{  // ficou negativo? sub min e add 60 seg!
						fseek(legend, -2L, SEEK_CUR);
						fgets(num, 3, legend);
						minaux = atoi(&num);
						minaux--;
						fseek(legend, -3L, SEEK_CUR);
						fprintf(legend, ":%02d", minaux);
						numint += 60;
					}

					fprintf(legend, ":%02d",numint);
					c = fgetc(legend);

					if (c == ',' && mili > 0)	{
						// Está uma casa antes dos milisegundos
						fgets(num, 4, legend);
						fseek(legend, -4L, SEEK_CUR);
						numint = atoi(&num);
						numint -= mili;

						if(numint<0)	{  // ficou negativo? sub seg e add 1000 mili!
							fseek(legend, -2L, SEEK_CUR);
							fgets(num, 3, legend);
							segaux = atoi(&num);
							segaux--;
							fseek(legend, -3L, SEEK_CUR);
							fprintf(legend, ":%02d",segaux);
							numint += 1000;
						} 
						fprintf(legend, ",%03d",numint);
				    }
				}
			}
			if (feof(legend))	break;
		}
		count = 0;
	}
	fseek(legend, 0, SEEK_SET);

}

void acrecenta(FILE *legend)	{
	int seg, mili, indice, numint, count=0, min=0, segaux=0;
	char c;
	char num[250]; 
	char linha[250];

	printf("Digite os segundos a serem adicionados: ");
	scanf("%d", &seg);
	printf("Digite os milisegundos a serem adicionados: ");
	scanf("%d", &mili);
	printf("Digite o indice a modificar: ");
	scanf("%d", &indice);

	fgets(num, sizeof(num), legend);
	numint = atoi(&num);

	if(indice>0)	{
		while(indice > numint && !feof(legend))	{ // posiciona o ponteiro no mesmo loguar do indice especificado
			fgets(num, sizeof(num), legend);
			numint = atoi(&num);
		}
		if(indice==numint)	{
			while ((c = fgetc(legend)) != '\n') { // Loop para fazer as alterações dos valores
		        if (c == ':') {
		            count++;
		            if (count%2==0) { // Está uma casa antes dos segundos 
		                fgets(num, 3, legend);
		               	fseek(legend, -3L, SEEK_CUR);
						numint = atoi(&num);
						numint += seg;
						
						if (numint>=60)	{ // minutos??? -_-
							min = numint/60;
							numint %= 60;
							fseek(legend, -3L, SEEK_CUR);
							fprintf(legend, ":%02d",min);
						}
						fprintf(legend, ":%02d",numint);
			    		segaux = numint;
			            c = fgetc(legend);

				        if (c == ',' && mili > 0)	{
				        	// Esta uma casa antes dos milisegundos
				        	fgets(num, 4, legend);
				        	fseek(legend, -4L, SEEK_CUR);
							numint = atoi(&num);
							numint += mili;
							
							if (numint >=1000)	{ // segundos? 0_0
								segaux += numint/1000;
								numint = numint%1000;
								fseek(legend, -3L, SEEK_CUR);
								fprintf(legend, ":%02d",segaux);
							} 
							fprintf(legend, ",%03d",numint);
				        }
		            }
		        }
		    }

		}
	}
	fseek(legend, 0, SEEK_SET);

}

int main()	{
	FILE *legenda;
	legenda = NULL;
	char nome[10], c;
	int resp=0;

	resp = menu();

	if(resp>0 || resp<=4)	{
		while (resp) {
			switch(resp)	{
				case 1:
					if (legenda!=NULL) break;

					printf("Digite o nome do arquivo a ser aberto\n#: ");
					scanf("%s", nome);

					if ((legenda = fopen(nome,"r+")) == NULL) {
		    			puts("[-] Erro ao abrir o arquivo");
		    			exit(1);
		    		}
		    		else printf("[+] Arquivo aberto com sucesso!\n");
		    		break;

				case 2:	
					if (legenda!=NULL)	acrecenta(legenda); // Passa o arquivo para a função e acrescenta no índice especificado.
					break;

				case 3:
					if (legenda!=NULL)	diminui(legenda);  // Passa o arquivo para a função e diminui em todos os índices.
					break;	

				case 4:
					if (legenda!=NULL)	elimina(legenda, nome);  // Passa o arquivo para a função e elimina os indices desejados.
					legenda = fopen(nome,"r+");
					break;

				default:
					printf("Algum erro ocorreu\n"); 
					break;
			}
			resp = menu();
		}
	}

	else	{
		printf("É preciso informar uma opção válida"); 
	}

	if(legenda!=NULL)	fclose(legenda);
	return 0;
}