#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *acrescentastr(char *, int, int );


int main()      {
    char str1[20], *str2;
    int a, b;

    printf("Digite a palavra a ser alterada: ");
    scanf("%s", str1);
    printf("Digite 1º indice: ");
    scanf("%d", &a);
    printf("Digite 2º indice: ");
    scanf("%d", &b);

    str2 = acrescentastr(str1, a, b);
    printf("Palavra original: %s\n", str1);
    printf("Palavra modificada: %s\n", str2);
    return 0;
} 

char *acrescentastr(char *str, int pri, int ult)  {
    char *ptr, *ini;
    int tam, aux;
    aux = 0;
    ini = str;
    tam = strlen(str);

    if((pri<0 || ult<0) || (pri>tam || ult>tam))    {
        ini = (char *) malloc(1 * (tam+1));
        ini = str;
    }
    else    {
        tam = (ult - pri) + 2;
        ptr = (char *) malloc(1 * (tam));
        ini = ptr;

        for(;*str;str++, aux++)    {
            if(aux>=pri && aux<=ult)    {
                *ptr = *str;
                ptr++;
            }   
        }
    }
    *ptr = '\0';


    return ini;
}