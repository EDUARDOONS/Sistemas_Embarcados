//arquivo bib_arqs.h
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void le_arq_texto(char *nome_arquivo, char *conteudo){
	int p, i = 0, j = 0;
	char c, conteudo_salvo[100];
	conteudo= &c;
		
	p = open(nome_arquivo, O_RDWR | O_CREAT);
	if(p==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	
	//leitura no arquivo
	while(read(p, &c, 1) != 0)
 	{	i=i+1;
		printf("%c", c);
		conteudo_salvo[i]=c;

 	}
 	
	//escrever na tela
 		while(j <= i)
 	{	j=j+1;
		printf("%c", conteudo_salvo[j]);
	}
		 	
	 close(p);

//return 0; 

}
