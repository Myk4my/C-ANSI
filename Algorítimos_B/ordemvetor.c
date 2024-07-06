#include <stdio.h>

int arruma(int vetor[])	{
	int count = 0;
	int num = 0;

	for(int i=0;i<10;i++)	{
		int menor=vetor[i];
		
		for (int j=0;j<10;j++)	{

			if(menor<=vetor[j])	{
				count +=1;
			}

			//else if (vetor[j]!=menor)	{
			//	continue;
			//}
		}

		if (count==10-num)	{
			printf("%d\n", menor);
			num +=1;
		}
		count = 0;
	}

}


int main()	{
	int vetor[10];
	printf("Digite o número a ser verificado: ");

	for (int i=0;i<10;i++)	{
		scanf("%d", &vetor[i]);
	}

	arruma(vetor);

	return 0;
}