//arquivo bib_arqs.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(void)
{
    int i=0, fp;
    char string[80], *nome_arquivo;
	
	//nome_arquivo = &string;
	
	printf("digite o nome completo do arquivo\n");
	gets(string);
		
	fp = open(string, O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	
	printf("ok");
	tam_arq_texto(string);
	    
return 0;   

}
