#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void funcao_para_control_c()
{
	printf("\nEncerrando o programa agora\n");
	exit(1);
}

int main()
{
	signal(SIGINT, funcao_para_control_c);
	printf("Pressione CTRL-C para encerrar o programa.\n");
	while(1){
		system("ps");
		sleep(1);	
	}
	return 0;
}
