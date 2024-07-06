#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int m, n;

    srand((unsigned) time(NULL));
    m = 100 + rand()%901;
    printf("O valor de M = %d\n", m);
    n = (-m/2) + rand()%m+1;
    printf("O intervalo esperado é de [%d] até [%d]\n\n", -m/2, m/2);
    printf("O valor de N = %d\n",n);

    return 0;
}
