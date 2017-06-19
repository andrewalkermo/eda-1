#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[60];
    char numero[60];
}Agenda;

void adiciona(Agenda* reg, int i) {
    printf("%s", "Nome:");
    scanf("%s", reg[i].nome);
    printf("%s", "Telefone:");
    scanf("%s", reg[i].numero);
}

void imprime(Agenda* reg, int i) {
    printf("\nNome | telefone\n\n");    
    for (int j = 0; j < i; j++) {
        printf("%s", reg[j].nome);
        printf(" | %s\n", reg[j].numero);
    }
}

int main() {
    int sair = 0;
    int i = 0;
    Agenda *registro[10];
    while (!sair) {
        int escolha;
        printf("Escolha as seguinte opções:\n 1 - Adicionar um novo contato \n 2 - Imprimir todos os contatos \n 3 - Sair da Agenda.\nResposta: ");
        scanf("%d", &escolha);
        switch(escolha) {       
            case 1:
                adiciona(*registro, i);
                i++;
                break;
            case 2:
                imprime(*registro, i);
                break;
            case 3:
                sair = 1;
                break;
        } 
   }
}