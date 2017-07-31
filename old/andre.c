#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Lista {
    char *word;
    struct Lista *nextWord;
};
typedef struct Lista lista;

void inicia(lista *sequencia){
	sequencia->nextWord = NULL;
}

int vazia(lista *s){
	if(s->nextWord == NULL)
		return 1;
	else
		return 0;
}

void insere(lista *s, char *p){
    lista *novo=(lista *) malloc(sizeof(lista));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    novo->word = p;
	novo->nextWord = NULL;
	if(vazia(s)){
        s->nextWord=novo;
    }
	else{
		lista *tmp = s->nextWord;
		while(tmp->nextWord != NULL){
			tmp = tmp->nextWord;
        }
		tmp->nextWord = novo;
	}
}

void quebra(lista *s, char txt[1024]){
    // char *p = strtok(txt, ",");
    // printf("Esse: %s\n", p);
    for (char *p = strtok(txt,","); p != NULL; p = strtok(NULL, ",")) {
        insere(s, p);
    }
}

void exibe(lista *s){
	if(vazia(s)){
		printf("Lista vazia!\n\n");
		return ;
	}

	lista *tmp;
	tmp = s->nextWord;

    int i = 1;
    printf("\n");
	while( tmp != NULL){
		printf("Bloco%d: %s\n",i++, tmp->word);
		tmp = tmp->nextWord;
	}
	printf("\n\n");
}

int main() {
    lista *sequencia = (lista *) malloc(sizeof(lista));
    if(!sequencia){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    inicia(sequencia);
    printf("%s\n","Digite o texto");
    char texto[1024];
    scanf("%[^\n]s",texto);
    quebra(sequencia, texto);
    exibe(sequencia);
    return 0;
}
