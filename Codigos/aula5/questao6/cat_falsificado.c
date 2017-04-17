//arquivo cat falsificado
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    int i=0, fp;
    char string[100], c;
	
	//Abrir arquivo e cria-lo
	fp = open(argv[1], O_RDONLY);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	
	//leitura no arquivo
	while(read(fp, &c, 1) != 0)
 	{
		printf("%c", c);
 	}
 	
	 close(fp);
	    
return 0;   
}
