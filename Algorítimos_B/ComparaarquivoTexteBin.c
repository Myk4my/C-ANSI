#include <stdio.h>

int main()      {
    FILE *file, *file2;
    int num, num2;

    if((file = fopen("text", "r"))!=NULL) printf("funfou\n");
    else printf("não funfou\n");

    if((file2 = fopen("bin.txt", "rb"))!=NULL) printf("funfou\n");
    else printf("não funfou\n");

     while(!feof(file) && !feof(file2))      {
        fscanf(file, "%d", &num);
        fread(&num2, sizeof(int), 1, file2);

        if(num == num2) {
            printf("T= %d\tB= %d\n", num, num2);
        } 
        else    {
            printf("os arquivos são diferentes\n\n");
            printf("T= %d\tB= %d\n", num, num2);
            break;
        }
    }

        /*

    if(feof(file2) && feof(file2)) {
        printf("Os arquivos são iguais\n");
    }

    else if(feof(file2) || feof(file2)){
        printf("Os arquivos são diferentes\n");
                      
    }
    else printf("What??\n");
        */
    fclose(file);
    fclose(file2);

    return 0;
} 