//arquivo bib_arqs.h
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int tam_arq_texto(char *nome_arquivo)
{
	int t=0, fp;

	
	fp = open(nome_arquivo, O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	fseek (fp, 0, SEEK_END);
	t = ftell (fp);
	close(fp);

	printf("\tTamanho do arquivo= %i\n", t);

return 0;
}
