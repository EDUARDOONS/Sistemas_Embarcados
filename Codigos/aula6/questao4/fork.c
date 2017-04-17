#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
	{
		v_global++;
		printf("\n");
		printf("ID do processo filho que executou esta funcao = %d\n", id_atual);
		printf("v_global = %d\n", v_global);
		
	}
	
int main ()
{
	pid_t pid_filho;
	int i = 0;
	//ler quantos argumentos
	for(i = 1; i <= 3; i++)
    {	
		pid_t pid_filho = fork();
	   	if (pid_filho == 0)
			{	   	
				Incrementa_Variavel_Global((int) getpid());
			}
		else
			{

			}
	}
	return 0;
}


	
		



