#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int a, i=0;
	char * lista_de_argumentos[] = { "ls", "-ltr", "-af", NULL};
	
	//ler quantos argumentos
	for(i = 1; i < argc; i++)
    {	
		pid_t pid_filho = fork();
	   	if (pid_filho == 0)
			{	   	
				printf("* O ID do processo filho e %d.        *\n", (int) getpid ());
				printf("* Este é o processo FILHO, executando o comando'%s'. *\n", argv[i]);
				a = system(argv[i]);
				printf("\n");
				execvp(argv[i], lista_de_argumentos);
				printf("*******************************************\n");
				printf("* Este printf() so eh executado se houver *\n");
				printf("* um erro de execucao em execvp().        *\n");
				printf("*******************************************\n");
				printf("\n");
			}
		else
			{
				sleep(1);
				printf("\n");
				printf("* Este texto foi escrito no terminal pelo processo PAI (ID=%d) *\n", (int) getpid());
				printf("\n");
			}
	}
	return 0;
}

		



