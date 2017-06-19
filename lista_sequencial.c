/* Define o valor máximo da estrutura */
#include <stdio.h>
#define MAX 20

typedef struct {
        int elementos[MAX]; //Vetor com a lista
        int cont; //Quantidade de elementos da lista
} listaSeq; //tipo lista sequencial

void criar(listaSeq * l){
	l->cont = 0;
}

int vazia(listaSeq l){
	return (l.cont==0);
}

int cheia(listaSeq l){
	return (l.cont==MAX);
}


int inserir(listaSeq * lista, int novo){
	int i, pos;
	if(cheia(*lista)){
		return 0;
	}
	for (i = 0; i < lista->cont; i++){
		if (lista->elementos[i]>novo){
			break;
		}
	}
	pos = i;
	for (i=lista->cont;i>pos;i--){
	   lista->elementos[i] = lista->elementos[i-1];
	}
	lista->elementos[pos] = novo;
	lista->cont++;
	return 1;
}

/* Retorna um valor definido caso a posição seja inválida ou o dado na posição removida caso contrário */
int remover(listaSeq * lista,  int pos){
	int i;
 	int dado;
  	if ((pos >= lista->cont)||(pos<0))     
      	return -1; //valor definido para 
			//representar posicao 
			//invalida
	
	dado = lista->elementos[pos];
	for(i = pos+1; i<lista->cont; i++){
		lista->elementos[i-1] = lista->elementos[i];      
	}
     
	lista->cont--;
	return dado;
}

void printl(listaSeq lista){
     int i;
	//Percorre toda lista imprimindo cada elemento
     for(i=0; i<lista.cont; i++){
              printf("[%d] = %d\n",i,lista.elementos[i]);         
     }
}
