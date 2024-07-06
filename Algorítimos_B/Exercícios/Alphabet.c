#include <stdio.h>

void alphabet(char *ini)    {
    char letra = 'A';

    for(;letra<='Z';letra++)  {
        *ini = letra;
        ini++;
    }
    *ini = '\0';
}

int main() {
    char estrigue[26];
    alphabet(estrigue);
    printf("%s", estrigue);
    return 0;
}