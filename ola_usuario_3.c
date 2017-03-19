//arquivo ola_usuario_3
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Ola");
    for(i = 1; i < argc; i++)
    {
        printf(" %s", argv[i]);
    } 
    	printf("\nQuantidade de argumentos %d", (i-1));
return 0;   
} 
