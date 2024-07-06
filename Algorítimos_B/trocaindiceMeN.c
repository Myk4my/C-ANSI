#include <stdio.h>

#define TAM 10

int vetores(int *vet1, int *vet2, int m, int n)  { 
    int aux;

    if(m<n) {
        vet1 += m;
        vet2 += m;

        for(;m<n;m++)   {
            aux = *vet1;
            *vet1 = *vet2;
            *vet2 = aux;
            vet1++;
            vet2++;
        }
    }

    else {
        vet1 += n;
        vet2 += n;

        for(;n<m;n++)   {
            aux = *vet1;
            *vet1 = *vet2;
            *vet2 = aux;
            vet1++;
            vet2++;
        }
    } 
}

int main() {
    int vetor1[TAM];
    int vetor2[TAM];
    int m, n;

    printf("Digite o valor de m: ");
    scanf("%d", &m);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite a sequência Do primeiro vetor\n");

    for (int i=0;i<TAM;i++) {
        printf("%d º#: ",i+1);
        scanf("%d", &vetor1[i]);
    }
    printf("Digite a sequência Do segundo vetor\n");

    for (int i=0;i<TAM;i++) {
        printf("%d º#: ",i+1);
        scanf("%d", &vetor2[i]);
    }

    printf("\nVetores Antes das modificações\n\n");
    for (int i=0;i<TAM;i++) {
        printf("V1 = %d\tV2 = %d\n", vetor1[i], vetor2[i]);
    }
    
    vetores(vetor1, vetor2, m, n);

    printf("\nVetores Depois das modificações\n\n");
    
    for (int i=0;i<TAM;i++) {
        printf("V1 = %d\tV2 = %d\n", vetor1[i], vetor2[i]);
    }

    return 0;
}