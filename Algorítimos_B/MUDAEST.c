#include <stdio.h>
#include <stdlib.h>

char *muda_str(char *str1, char *str2)	{
	int t = 0;
	int t2 = 0;
	char *str3, *ini; 
	int Nchou = 1;

	for(str3 = str1; *str3; str3++)	{
		if(*str3 == *str2)	{
			Nchou = 0;
		}
	}

	t = str3 - str1;

	for(str3 = str2; *str3; str3++);
	t2 = str3 - str2;
	ini = str3 = (char *) malloc (sizeof(char) * t+t2+Nchou);

	if(Nchou)	{
		for(; *str1; str1++)
			*(str3++) = *str1;
		for(; *str2; str2++)
			*(str3++) = *str2;
	}
	else	{
		for(; *str1 != *str2; str1++)
			*(str3++) = *str1;
		for(; *str2; str2++)
			*(str3++) = *str2;
	}
	*str3 = '\0';
	return ini;

}


int main()	{
	char estr1[15], estr2[15], *S;

	printf("Digite a primeira palavra: ");
	scanf("%s", estr1);
	printf("Digite a primeira palavra: ");
	scanf("%s", estr2);

	S = muda_str(estr1, estr2);
	printf("A nova palavra é: %s\n", S);
	free(S);
}