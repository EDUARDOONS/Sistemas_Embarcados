//arquivo bib_arqs.h
#include <stdio.h>

void le_arq_texto(char *nome_arquivo, char *conteudo);
{

	FILE *p;
	
	p = fopen(nome_arquivo,"r");
	
	while((*conteudo = getc(p) ) != EOF)
	{ /* Enquanto não chegar ao final do arquivo */
	printf("%c", *conteudo); /* imprime o caracter lido */
	fclose(p);
	}
	
return 0;
}
