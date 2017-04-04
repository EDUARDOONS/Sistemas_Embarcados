//arquivo bib_arqs.h
#include <stdio.h>

int tam_arq_texto(char *nome_arquivo)
{
	int t=0;
	FILE *p;
	
	p = fopen(nome_arquivo,"r");
	fseek (p, 0, SEEK_END);
	t = ftell (p);
	fclose(p);

	printf("\tTamanho do arquivo= %i\n", t);
	
return 0;
}
