//arquivo busca e conta.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[])
{    
	char c, palavra[100], string[100], *conteudo;
    int fp, i = 0, num = 0, num1 = 0, carac_1 = 0, carac_2 = 0, cont = 0, cont_i = 0;

	
	fp = open(argv[2], O_RDONLY);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	
	//copiar string
	strcpy(string, argv[1]);
	
	while(read(fp, &c, 1) != 0)
	{ /* Enquanto não chegar ao final do arquivo */
		palavra[i]=c;
		i=i+1;
	}


	while((cont_i) <= i)
	{ /* Enquanto não chegar ao final do arquivo */
		if (string[num1] == palavra[num])   //Conta o numero de caracteres iguais
		{
			carac_1=carac_1+1;	//numero de caracteres iguais
			num=num+1;   
			num1=num1+1;
		}
		else
		{
			carac_2=carac_2+1;
			num=num+1;
			num1=0;
		}
		
		if (strlen(string) == carac_1)  //verifica se tem o mesmo numero de caractes a palavra repetida
		{
			cont=cont+1; //conta o numero de ocorrencia
			carac_1=0; // zera para recontar
		}
		cont_i=cont_i+1;
	}
	printf("%s ocorreu %d no arquivo %s", argv[1], cont, argv[2]); /* imprime o caracter lido */
	close(fp);
return 0;   

}
