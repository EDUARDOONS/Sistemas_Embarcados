//arquivo bib_arqs_main.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{
    int i=0,p;
    char c, nome[100];
	
	printf("digite o nome completo do arquivo\n");
	gets(nome);
	
  	le_arq_texto(nome, &c);
  	
}
