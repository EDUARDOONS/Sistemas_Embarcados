#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void funcao_para_control_c()
{
	printf("\nEncerrando o programa agora\n");
	exit(1);
}

void tratamento_alarme(int sig)
{
	system("ps -l");
	alarm(1);
}

int main()
{	
	signal(SIGINT, funcao_para_control_c);
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}

