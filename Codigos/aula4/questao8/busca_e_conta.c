//arquivo busca e conta.c
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{    
	char c, string[100], *conteudo;
	FILE *p;
    int i, num = 0 ;
    for(i = 0; i < argc; i++)
    {	      	
	}

	p = fopen(argv[1],"r");
	if(p == NULL)
	{
	printf("ERRO ao tentar abrir %s\n");
	exit (1);
	}
	
	while((c = getc(p) ) != EOF)
	{ /* Enquanto não chegar ao final do arquivo */
	num=num+1;
	}
	
	printf("%s ocorreu %d no arquivo %s", argv[1], num, argv[2]); /* imprime o caracter lido */
	fclose(p);
return 0;   

}
