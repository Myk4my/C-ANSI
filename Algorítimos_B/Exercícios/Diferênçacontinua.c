#include <stdio.h>

#define TAM 10

int verifica(int *vet)  {
    int flag = *(vet+1)-*vet;
    int count = 0;
    
    while(count<TAM-1)    {
        if(*(vet+1)-*vet==flag) {
            printf("FLAG = %d\n", *vet);
            vet++;
        }
        else return 0;
        count++;
    }

    return 1;
}

int main() {
    int vetor[TAM];
    printf("Digite a sequência a ser verificada\n");

    for (int i=0;i<TAM;i++) {
        printf("%d º#: ",i+1);
        scanf("%d", &vetor[i]);
    }
    
    if(verifica(vetor)) printf("A diferênça é contínua");
    else printf("A diferênça não é contínua");
    return 0;
}