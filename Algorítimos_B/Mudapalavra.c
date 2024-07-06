#include <stdio.h>

void mudapalavra(char *s)   {
    char *ss, *sss;
    sss = s;

    for(;*s!='\0';s++)   {
        ss = s;
        for(;*ss!='\0';ss++)   {
            if(*s==*(ss+1))  {
                *(ss+1) = 'x';
            }
        }
    }
    
    while(sss<s)   {
        if(*sss=='x')   {
            *s = *sss;
        }
        sss++;
    }

}

int main() {
    char palavra[20];
    printf("Digite a palavra: ");
    gets(palavra);
    printf("%s\n", palavra);

    mudapalavra(palavra);
    printf("%s\n", palavra);
    return 0;
}