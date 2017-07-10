#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct bloco {
    char *linha;
    struct bloco *prox;
};
typedef struct bloco lista;
lista* insere(char sequencia[100]) {
    for(int i = 0; i < strlen(sequencia);) {
        string_substring();

    }
    char *a = strtok(string_substring( i, strlen(sequencia)), ",");
    printf("%s\n",a );
}
int main() {
    char c[100];
    lista *inicio;
    lista *proximo;
    inicio = malloc(sizeof(lista));
    if(inicio == NULL) {
    	printf("MEMORIA INDISPONÍVEL\n");
    	exit(1);
    }
    proximo = inicio;
    fgets (c, 100, stdin);
    insere(c);
}
