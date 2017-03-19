//arquivo ola_argumentos
#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf("\nArgumento: %s", argv[i]);
    	Num_caracs(argv[i]);
	}

    
}
