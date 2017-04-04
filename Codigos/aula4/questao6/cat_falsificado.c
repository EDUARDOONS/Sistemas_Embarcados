//arquivo bib_arqs_main.c
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i=0;
    char c, string[100], *conteudo;
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
	
	while((*conteudo = getc(p) ) != EOF)
	{ /* Enquanto não chegar ao final do arquivo */
	printf("%c", *conteudo); /* imprime o caracter lido */
	fclose(p);
	}

return 0;   

}
