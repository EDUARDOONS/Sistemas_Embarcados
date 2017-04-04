//arquivo bib_arqs_main.c
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{
    int i=0;
    char c, string[100], *nome_arquivo, *conteudo;
	FILE *p;
	
	
	conteudo = &c;
		
	printf("digite o nome completo do arquivo\n");
	scanf("%s", string);
	
	p = fopen(string,"r");
	if(p == NULL)
	{
	printf("ERRO ao tentar abrir %s\n");
	exit (1);
	}

	le_arq_texto(string, &c);


return 0;   

}
