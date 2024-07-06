#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int pacotinho(int envel, int t_album, int *envelope)	{
	int cromo;
    printf("\n\n\n#==================#\nSorteando pacotinho\n#==================#\n");
        
    for(int i=0;i<envel;i++)    {
           
        do  {
            cromo = rand() % t_album+1;
            for(int j=0; j<i;j++)   {
         	   	if(envelope[j] == cromo)	{
         	   		cromo = -1;
         	   		break;
         	   	}
        	}

        } while (cromo == -1);
      	
      	envelope[i] = cromo;
    }
  	
  	printf("\n---------\n\n");
  	for (int i=0;i<envel;i++) {
   		printf("%d\t|\n",envelope[i]);
    }
    printf("\n---------\n\n");
  
}


int main() {
    int t_album, envel, pacotes;
    int count = 0;
    pacotes = 0;
    
    printf("Qual o tamanho do album?\n#: ");
    scanf("%d", &t_album);
    int album[t_album];
    printf("Quantos Cromos tem em cada emvelope?\n#: ");
    scanf("%d", &envel);
    int envelope[envel];
    printf("O tamanho a ser preenchido é de: [%d]\n", t_album);
    srand((unsigned)time(NULL));
    
    for (int i=0;i<t_album;i++) {
        album[i] = -1;
    }

    do  {
        pacotinho(envel, t_album, envelope);
        pacotes++;

        for(int i=0; i<envel;i++)   {
           	for(int j=0;j<envel+count;j++)	{
           		if(album[j] == envelope[i])  {
           			break;
           		}
           		else if (album[j] == -1)	{
           			album[j] = envelope[i];
           			count++;
           			break;
           		}
           	}
        }
        for (int i=0;i<t_album;i++) {
        	printf("%d, \t",album[i]);
        	if(i != 0 && (i+1)%envel==0) printf("\n\n");
    	}
    } while (count != t_album);

    printf("\n\n\n");
    printf("O total de pacotes de %d Cromos cada necessários para preencher um album de %d Figurinhas foi\n#: [%d]\n", envel, t_album, pacotes);
    printf("\n");
    
    return 0;
}