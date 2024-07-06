#include <stdio.h>

// elimnadas

// eliminadamente
// eliminadamente
// elimnadt

void repete(char *str)   {
    char *str2, *ini, *str22;
    ini = str2 = str;
    int igual;
    igual = 0;

    while(*str)    {
        for(;*str;str++)   {
            for(;*str2;str2++)   {
                if(*str == *str2)   {
                    igual++;
                    if(igual>1) {
                        str22 = str2;
                        for(;*str2;str2++)   {
                            *str2 = *(str2+1);
                        }
                        str2 = str22;
                    }
                }
            }
            igual = 0;
            str2 = ini;
        }
    }
}


int main() {
    char palavra[20];

    printf("Digite a palavra: ");
    gets(palavra);
    printf("Palavra Antes = %s\n", palavra);

    repete(palavra);
    printf("Palavra Depois = %s\n", palavra);
    return 0;
}