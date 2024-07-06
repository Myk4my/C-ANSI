#include <stdio.h>
#include <stdlib.h>


char *multiplicastr(char *);


int main()      {
    char str1[20], *str2;

    printf("Digite a palavra a ser alterada: ");
    scanf("%s", str1);

    str2 = multiplicastr(str1);
    printf("Palavra original: %s\n", str1);
    printf("Palavra modificada: %s\n", str2);
    return 0;
} 

char *multiplicastr(char *str)  {
    char *ptr, *ini;
    int num, i, j;
    num = i = j = 0;
    ptr = str;

    for (; *ptr; ptr++, i++, num += i);
    ptr = (char *) malloc(1 * num);
    ini = ptr;
    
    for (i = 0; *str; str++, i++) {
        for(j=0; j<=i; j++) {
             *ptr = *str;
            ptr++;
        }
    }
    *ptr = '\0';

    return ini;
}