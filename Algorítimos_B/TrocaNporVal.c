#include <stdio.h>

// 1 5 3 8 4 6 7 9 10 15
// n = 3 = 8
// val = 10

 void troca(int *vet, int n, int val)    {
    for(int i=0;i<10;i++)   {
        if(*(vet+i) == val) {
            *(vet+i) = *(vet+n);
            break;
        }
    }
    *(vet+n) = val;
 }

int main() {
    int vet[10];
    int n, val;

    for(int i=0;i<10;i++)   {
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("Digite o valor de Val: ");
    scanf("%d", &val);

    troca(vet, n, val);

    for(int i=0;i<10;i++)   {
        printf("Val[%d] = %d\n", i, vet[i]);

    }

    return 0;
}