#include <stdio.h>

#define TAM 5

void remover(int *vet, int n)   {
    int aux1, aux2;
    vet += n;
    aux1 = *vet;

    for(;n<TAM-1;n++)   {
        aux2 = *(vet+1);
        *vet = aux2;
        vet++;
    }
    *vet = aux1;
}


int main() {
    int n;
    int vet[TAM];

    printf("Digite n: ");
    scanf("%d", &n);

    printf("\nDigite os valores do vetor\n\n");
    
    for(int i=0;i<TAM;i++)  {
        printf("%d#: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("\nVetor ANTES da modificação do %d elemento\n\n", n);
    for(int i=0;i<TAM;i++)  {
        printf("# - %d -#\n", vet[i]);

    }

    remover(vet, n);

    printf("\nVetor DEPOIS da modificação do %d elemento\n\n", n);
    for(int i=0;i<TAM;i++)  {
        printf("# - %d -#\n", vet[i]);

    }

    return 0;
}