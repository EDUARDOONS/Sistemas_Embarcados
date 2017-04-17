#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t child_pid;
	
	printf("* Este texto foi escrito no terminal pelo processo PAI (ID=%d) *", (int) getpid());
	printf("\n");
	
	child_pid = fork(); //criando o processo filho
	
	if (child_pid == 0) //filho
	{
		printf("* Este texto foi escrito no terminal pelo processo do primeiro FILHO (ID=%d):", (int) getpid());
		printf("\n");
	}
	else
	{
		sleep(1);
		child_pid = fork(); //criando o processo filho
		if (child_pid == 0) //filho
		{
			printf("* Este texto foi escrito no terminal pelo processo do segundo FILHO (ID=%d):", (int) getpid());
			printf("\n");
		}
		else
		{
			sleep(1);
			child_pid = fork(); //criando o processo filho
			if (child_pid == 0) //filho
			{
				printf("* Este texto foi escrito no terminal pelo processo do terceiro FILHO (ID=%d):", (int) getpid());
				printf("\n");
			}
			else
			{
				sleep(1);
				printf("* Este texto foi escrito no terminal pelo processo PAI (ID=%d) *\n", (int) getpid());
				printf("\n");
			}
		}
	}
	return 0;
}

		



