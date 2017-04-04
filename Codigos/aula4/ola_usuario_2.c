//arquivo ola_usuario_2
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int i=0;
    char string[10];
	FILE *p;

	//criar o nome do arquivo
	sprintf(string, "%s.txt", argv[1]); //junta os nomes do arquivo
	
	
	if (!(p = fopen(string,"w"))) /* Caso ocorra algum erro na abertura do arquivo..*/
	{ /* o programa aborta automaticamente */
	printf("Erro! Impossivel abrir o arquivo!\n");
	exit(1);
	}
		
	fprintf(p, "Nome: %s\n", argv[1]); // escreve no arquivo
	fprintf(p, "Idade: %s anos.\n", argv[2]);  // escreve no arquivo
	    
return 0;   
} 
