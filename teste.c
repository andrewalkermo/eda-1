#include <stdio.h>
#include <stdlib.h>

struct lista{
    char nome[60];
    char numero[60];
    struct lista* proximo;
};
typedef struct lista Agenda;

Agenda* adiciona (Agenda *p) {			// A fuñção é do tipo Agenda* porque ela retorna um pnteiro.
    
    // Agenda* regi;
    
    printf("%s", "Nome:");
    scanf("%s", p->nome);
    printf("%s", "Telefone:");
    scanf("%s", p->numero);
    
    return p->proximo = malloc(sizeof(Agenda)); 	// Retorna um ponteiro para o proximo nó da lista. Essa é das várias soluções.
}

void imprime(Agenda* reg, Agenda* ini) {
    // Agenda *p;
	
	reg->proximo = NULL; 			// Faz com que o ponteiro do último elemento da lista aponte para NULL.
    
    reg = ini; 					// p agora aponta para o prmeiro nó da lista.
    
    printf("\nNome | telefone\n\n");    
    while (reg != NULL) {  
        printf("%s", reg->nome);
        printf(" %s\n", reg->numero);

        reg = reg->proximo; 		// p agora aponta para o proximo nó da lista.
    }
}

int main() {
    
    int sair = 0;
    
    // Agenda registro;
    
    Agenda* inicio; 			// O ponteiro ini aponta para o primeiro nó da lista;
    Agenda* prox;

    inicio = malloc(sizeof(Agenda));

    if(inicio == NULL) { 						// verifica se existe memória para alocar.
    	printf("MEMORIA INDISPONÍVEL\n");
    	exit(1);
    }

    prox = inicio;				// Quando só tem 1 elemento na lista, prox =  ini;

    while (!sair) {
        int escolha;
        printf("Escolha as seguinte opções:\n 1 - Adicionar um novo contato \n 2 - Imprimir todos os contatos \n 3 - Sair da Agenda.\nResposta: ");
        scanf("%d", &escolha);
        switch(escolha) {       
            case 1:
                prox = adiciona(prox);
                break;
            case 2:
                imprime(prox, inicio);
                break;
            case 3:
                sair = 1;
                break;
        } 
   }
}