//arquivo ola_usuario_2
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Ola");
    for(i = 1; i < argc; i++)
    {
        printf(" %s", argv[i]);
    } 
return 0;   
} 
