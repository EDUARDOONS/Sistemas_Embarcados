#include <stdio.h>

int main (int argc, char *argv[])
{
int i, t;
FILE *arq;

if (argc < 2){
fprintf(stderr, "ERRO: faltou parametro\n");
return(1);
}

for (i = 1; i< argc; i++){
if (! (arq = fopen(argv[i],"r"))){
fprintf(stderr, "ERRO ao tentar abrir %s\n", argv[i]);
continue;
}
fseek (arq, 0, SEEK_END);
t = ftell (arq);
fclose(arq);
printf("===> %s\n", argv[i]);
printf("\tTamanho = %i\n", t);
}
}