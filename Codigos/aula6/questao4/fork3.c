#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
	{
		v_global++;
		printf("\n");
		printf("ID do processo que executou esta funcao = %d\n", id_atual);
		printf("v_global = %d\n", v_global);
		
	}
	
int main ()
{
		pid_t pid_filho1 = fork();
	   	if (pid_filho1 == 0)
		{	   	
			Incrementa_Variavel_Global((int) getpid());
		}
		else
		{	
			sleep(1);
			printf("* Este texto foi escrito no terminal pelo processo PAI1 (ID=%d) *\n", (int) getpid());
		}
		
		pid_t pid_filho2 = fork();
	   	if (pid_filho2 == 0)
		{	   	
			Incrementa_Variavel_Global((int) getpid());
		}
		else
		{	
			sleep(1);
			printf("* Este texto foi escrito no terminal pelo processo PAI2 (ID=%d) *\n", (int) getpid());
		}
		
		
		pid_t pid_filho3 = fork();
	   	if (pid_filho3 == 0)
		{	   	
			Incrementa_Variavel_Global((int) getpid());
		}
		else
		{	
			sleep(1);
			printf("* Este texto foi escrito no terminal pelo processo PAI3 (ID=%d) *\n", (int) getpid());
		}
		
	return 0;
}
