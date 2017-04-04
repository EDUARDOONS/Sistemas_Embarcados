//arquivo bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(void)
{
    int i=0;
    char string[80], *nome_arquivo;
	FILE *p;
	
	printf("digite o nome completo do arquivo\n");
	scanf("%s", string);
		
	p = fopen(string,"r");
	if(p == NULL){
	printf("ERRO ao tentar abrir %s\n");
	exit (1);
	}
	printf("ok");
	tam_arq_texto(string);
	    
return 0;   

}
