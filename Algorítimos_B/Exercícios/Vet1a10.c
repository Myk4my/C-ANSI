#include <stdio.h>

/*

7. Escreva um programa em C que leia um vetor de 10 elementos e leia para este vetor valores entre 1 e 10
(inclusive). A seguir, o vetor deve ser enviado para uma função em que seu conteúdo é avaliado para
encontrar números repetidos, cuja primeira ocorrência será mantida. As demais ocorrências de um mesmo
valor devem ser eliminadas, sendo os seus valores substituídos por valores entre 1 e 10 que ainda não
estejam no vetor. Os valores que não tem repetição e a primeira ocorrência (a que permanece) dos que tem
repetição devem ser mantidos em suas posições originais. No final, deve ser retornado para a main o vetor
com todos os números entre 1 e 10, sem repetição. Receba o vetor na função com um ponteiro para a
primeira posição e faça manipulação sem usar índices.

*/


// vet      1 5 2 3 4 8 7 7 9 4
// Vetten   1 2 3 4 5 6 7 8 9 10

void repete(int *trix)   {

    int Vetten[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int *initen, *ten, *position, *ten2;
    initen = ten = Vetten;

    int sair = 0, digit = 0, i, j, verdade = 1, count, count2;
    count = count2 = 0;

    while(!sair)    {
        for(i=0;i<10;i++)   { // verificar a repetição do dígito
            if(*(trix+i) == *ten) {
                digit++;
                position = (trix+i);
            }
        }

        if(digit>1) { // se repetir  
            ten2 = ten;
            ten = initen;
            while(verdade)    {
                for(j=0;j<10;j++)   {
                    if (*ten == *(trix+j))  { // procura o número mais próximo para substituição
                        break;
                    }
                    else    {
                        count2++;
                    }
                }
                if(count2==10)   { // somente se não estiver em vet
                    *position = *ten; // troca
                    verdade = 0;
                }
                count2 = 0;
                ten++;
            }
            ten = ten2; // volta para onde estava
        }
        else    {
            count++;
        }

        ten++;

        if(count == 10) { // verificou todo? saia!
            sair = 1;
        }
    }

}

int main() {
    int vet[10];

    for(int i=0;i<10;i++)   {
        printf("Digite o %d elemento: ", i+1);
        scanf("%d", &vet[i]);
        
        if(vet[i]<1 || vet[i]>10)   {
            printf("Valor não permitido!\nSomente valores entre [1] e [10]\n");
            i--;
        }
    }
    
    printf("Antes da Troca\n\n");
    for(int i=0;i<10;i++)   {
        printf("=: %d\n", vet[i]);
    }
    repete(vet);
    printf("Depois da Troca\n\n");
    for(int i=0;i<10;i++)   {
        printf("=: %d\n", vet[i]);
    }
    return 0;
}