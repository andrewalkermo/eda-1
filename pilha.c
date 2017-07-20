#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TNOME 100

// estrutura auto referenciada
struct nodoPilha {
    char nome[TNOME];
    char dado; // define dado como char
    struct nodoPilha *proximoPtr; // ponteiro para struct nodoPilha
};

typedef struct nodoPilha NodoPilha; // tipo para o struct nodoPilha
typedef NodoPilha *NodoPilhaPtr; // tipo ponteiro para NodoPilha

// prototipos de funcao
void imprimePilha( NodoPilhaPtr atualPtr );
int ehVazia( NodoPilhaPtr headPtr );
char pop( NodoPilhaPtr *headPtr );
void push( NodoPilhaPtr *headPtr, char value, char nome[TNOME] );
void instrucoes( void );


int main( void ){
    NodoPilhaPtr headPtr = NULL; // inicializa ponteiro da cabeça da fila
    char escolha; // variavel para a escolha do usuario
    char item; // variavel char de entrada do usuario
    char nome[TNOME];// variavel para receber o nome de entrada

    instrucoes(); // exibe o menu de instrucoes
    // enquanto o usuario nao digitar 3
    do {
        printf( "%s", "? " );
        fflush(stdin);
        scanf( "%c", &escolha );

        switch( escolha ) {
            // push value
            case '1':
                printf( "%s", "Digite um caractere: " );
                fflush(stdin);
                scanf( "\n%c", &item ); // \n serve para consumir o enter :)

                printf( "%s", "Digite um nome: " );
                fflush(stdin);
                fgets(nome,TNOME,stdin);

                push( &headPtr, item, nome );
                imprimePilha( headPtr );
            break;

            // pop value
            case '2':
                // if queue is not empty
                if ( !ehVazia( headPtr ) ) {
                    item = pop( &headPtr );
                    printf( "%c foi desenfileirado.\n", item );
                } // end if
                imprimePilha( headPtr );
            break;

            default:
                puts( "\n\nEscolha invalida.\n" );
                instrucoes(); // exibe o menu de instrucoes
            break;
        } // end switch


    } while ( escolha != '3' );

    puts( "End of run." );
}

// exibe as instrucoes de programa para o usuario
void instrucoes( void ){
    printf ( "Qual sua escolha:\n"
    " 1 para adicionar um item na pilha\n"
    " 2 para remover um item da pilha\n"
    " 3 to end\n" );
}

// insere um nodo no topo da pilha
void push( NodoPilhaPtr *headPtr, char value, char nome[TNOME] ){

    // substituir caracter de nova linha por fim de string
    char * novalinha = strchr(nome, '\n');
    if (novalinha)
        *novalinha = '\0';
    //alternativa
    //nome[strcspn(nome, "\n")] = '\0';

    NodoPilhaPtr newPtr; // pointer to new node
    newPtr=malloc(sizeof(NodoPilha));

    if ( newPtr != NULL ) { // is space available
        newPtr->dado = value;
        newPtr->proximoPtr = *headPtr;
        strcpy( newPtr->nome,nome);

        *headPtr = newPtr;

    } // end if
    else {
        printf( "%c nao foi inserido. Memoria nao foi disponibilizada.\n", value );
    } // end else
}

// remove o nodo do topo da pilha
char pop( NodoPilhaPtr *headPtr ) {
    char popValue; // valor do nodo
    NodoPilhaPtr tempPtr; // ponteiro temporario para nodo

    tempPtr = *headPtr; // guarda o head atual
    popValue = ( *headPtr )->dado;
    *headPtr = ( *headPtr )->proximoPtr; // altera o head atual para o proximo nodo
    free( tempPtr );
    return popValue;
}

// retorna 1 se a pilha estiver vazia, do contrario retorna 0
int ehVazia( NodoPilhaPtr headPtr ){
    return headPtr == NULL;
}

// imprime a fila
void imprimePilha( NodoPilhaPtr atualPtr ){
    NodoPilhaPtr inicioPtr;
    inicioPtr=atualPtr;
    // se a fila estiver vazia
    if ( atualPtr == NULL ) {
        puts( "Pilha esta vazia.\n" );
    }
    else {
        puts( "A pilha eh:" );

        // enquanto nao chegar no fim da pilha
        while ( atualPtr != NULL ) {
            printf( "%c --> ", atualPtr->dado );
            atualPtr = atualPtr->proximoPtr;
        }
        puts( "NULL\n" );

        atualPtr=inicioPtr;
        //puts( "A fila eh:" );
        // enquanto nao chegar no fim da fila
        while ( atualPtr != NULL ) {
            printf( "%s --> ", atualPtr->nome );
            atualPtr = atualPtr->proximoPtr;
        }
        puts( "NULL\n" );

    }
} // end function imprimePilha
