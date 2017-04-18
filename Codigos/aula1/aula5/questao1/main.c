#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp, i, num = 0 ;  
	char *c, string[100];
	
    //ler quantos argumentos
	for(i = 1; i < argc; i++)
    {	   
	   num=num+1;	
	}
	
	
	fp = open("ola_mundo.txt", O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}


	for(i = 1; i < argc; i++){
	
		write(fp, (argv[i]), sizeof(argv[i])); // Grava a string, caractere a caractere	
		write(fp, " ", 1); // Grava a string, caractere a caractere	
	}
		close(fp);
	return 0;
}
