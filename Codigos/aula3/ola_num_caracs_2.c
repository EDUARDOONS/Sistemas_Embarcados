//arquivo ola_argumentos
#include <stdio.h>
#include "num_caracs_2.h"

int main(int argc, char* argv[])
{
    int i, num = 0 ;
    for(i = 0; i < argc; i++)
    {	num = num + num_caracs_2(argv[i]);
            	
	}
		printf("\n Total de caracteres: %d", num);	
    
}
