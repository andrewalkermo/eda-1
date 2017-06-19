#include <stdio.h>
#include <stdlib.h>

struct lista{
    char nome[60];
    char numero[60];
    struct lista* proximo;
};
typedef struct lista Agenda;

void adiciona (Agenda *p) {
    Agenda* regi;
    // Lista* novo = (Lista*)malloc(sizeof(Lista));
    //regi = (Agenda*)mallocc(sizeof(Agenda));
    printf("%s", "Nome:");
    scanf("%s", regi->nome);
    printf("%s", "Telefone:");
    scanf("%s", regi->numero);
    regi->proximo = p->proximo;
    p->proximo = regi;
}

void imprime(Agenda* reg) {
    Agenda *p;
    p = reg;
    printf("\nNome | telefone\n\n");    
    while (p != NULL) { 
        p = p->proximo; 
        printf("%s", p->nome);
        printf(" | %s\n", p->numero);
    }
}

int main() {
    int sair = 0;
    int i = 0;
    Agenda registro;
    while (!sair) {
        int escolha;
        printf("Escolha as seguinte opções:\n 1 - Adicionar um novo contato \n 2 - Imprimir todos os contatos \n 3 - Sair da Agenda.\nResposta: ");
        scanf("%d", &escolha);
        switch(escolha) {       
            case 1:
                adiciona(&registro);
                i++;
                break;
            case 2:
                imprime(&registro);
                break;
            case 3:
                sair = 1;
                break;
        } 
   }
}