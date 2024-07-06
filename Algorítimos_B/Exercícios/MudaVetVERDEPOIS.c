#include <stdio.h>

#define TAM 10

// 5 8 2 1 6 12 7 9 15 3
// 1 2 3 5 6 7 8 9 12 15

void copiavet(int *vet, int *vet2)    {
   int i, menor = *vet, cont = 0;
   while (cont<TAM) {
        for(i=0;i<TAM;i++)   {
            if(*(vet+i)<menor && (*(vet+i) > *(vet2-1)))   {
                menor = *(vet+i);
            }
        }
        *vet2 = menor;
        vet2++;
        for (i=0; i<TAM; i++)  {
            if(*(vet+i)>*(vet2-1))  {
                menor = *(vet+i);
                break;
            }
        }
        cont++;
    }
    
}

int main() {
    int vet[TAM];
    int vet2[TAM];

    for (int i=0; i<TAM; i++)   {
        printf("Digite o valor do %d elemento: ", i+1);
        scanf("%d", &vet[i]);
    }
    
    copiavet(vet, vet2);

    printf("Vetor 1\n");
    for (int i=0; i<TAM; i++)   {
        printf("Elemento: %d\n", vet[i]);
    }
    printf("Vetor 2\n");
    for (int i=0; i<TAM; i++)   {
        printf("Elemento: %d\n", vet2[i]);
    } 

    return 0;
}