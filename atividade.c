#include <stdlib.h>
#include <stdio.h>

struct texto{
    char frase[100];
    struct texto *prox;

};
typedef struct texto txt;
void inicia (txt *PILHA);
int main( int argc, char **argv ){
    txt *PILHA = (txt *) malloc(sizeof(txt));
    if(!PILHA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    //printf("\n%s,%s\n", argv[1],argv[2]);
    //exit(0);

}

void inicia(txt *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}
