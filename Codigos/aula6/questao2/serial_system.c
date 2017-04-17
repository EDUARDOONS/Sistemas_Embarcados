#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int a, i=0;
	
	//ler quantos argumentos
	for(i = 1; i < argc; i++)
    {
	   	a = system(argv[i]);
	   	printf("\n");
	}
	
	return 0;
}

		



