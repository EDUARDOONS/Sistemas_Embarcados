//arquivo ola_argumentos
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf(" %s", argv[i]);
    } 
    
    	printf("\nQuantidade de argumentos %d", (i-1));
		return 0;   
}

