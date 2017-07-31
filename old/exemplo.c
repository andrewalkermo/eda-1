#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TNOME 100

// estrutura auto referenciada
struct nodoFila {
    char nome[TNOME];
    char dado; // define dado como char
    struct nodoFila *proximoPtr; // ponteiro para struct nodoFila
};

typedef struct nodoFila NodoFila; // tipo para o struct nodoFila
typedef NodoFila *NodoFilaPtr; // tipo ponteiro para NodoFila

// prototipos de funcao
void imprimeFila( NodoFilaPtr atualPtr );
int ehVazia( NodoFilaPtr headPtr );
char dequeue( NodoFilaPtr *headPtr, NodoFilaPtr *tailPtr );
void enqueue( NodoFilaPtr *headPtr, NodoFilaPtr *tailPtr,char value, char nome[TNOME] );
void instrucoes( void );


int main( void ){
    NodoFilaPtr headPtr = NULL; // inicializa ponteiro da cabeça da fila
    NodoFilaPtr tailPtr = NULL; // initializa ponteiro da cauda da fila
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
            // enqueue value
            case '1':
                printf( "%s", "Digite um caractere: " );
                fflush(stdin);
                scanf( "\n%c", &item ); // \n serve para consumir o enter :)

                printf( "%s", "Digite um nome: " );
                fflush(stdin);
                fgets(nome,TNOME,stdin);

                enqueue( &headPtr, &tailPtr, item, nome );
                imprimeFila( headPtr );
            break;

            // dequeue value
            case '2':
                // if queue is not empty
                if ( !ehVazia( headPtr ) ) {
                    item = dequeue( &headPtr, &tailPtr );
                    printf( "%c foi desenfileirado.\n", item );
                } // end if
                imprimeFila( headPtr );
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
    " 1 para adicionar um item na fila\n"
    " 2 para remover um item da fila\n"
    " 3 to end\n" );
}

// insere um nodo na cauda da fila (fim da fila)
void enqueue( NodoFilaPtr *headPtr, NodoFilaPtr *tailPtr, char value, char nome[TNOME] ){

    // substituir caracter de nova linha por fim de string
    char * novalinha = strchr(nome, '\n');
    if (novalinha)
        *novalinha = '\0';
    //alternativa
    //nome[strcspn(nome, "\n")] = '\0';

    NodoFilaPtr newPtr; // pointer to new node
    newPtr=malloc(sizeof(NodoFila));

    if ( newPtr != NULL ) { // is space available
        newPtr->dado = value;
        newPtr->proximoPtr = NULL;

        strcpy( newPtr->nome,nome);

        // se fila vazia, insere nodo no inicio, no head
        if ( ehVazia( *headPtr ) ) {
            *headPtr = newPtr;
        } // end if
        else {
            ( *tailPtr )->proximoPtr = newPtr;
        } // end else

        *tailPtr = newPtr;
    } // end if
    else {
        printf( "%c nao foi inserido. Memoria nao foi disponibilizada.\n", value );
    } // end else
}

// remove node from queue head
char dequeue( NodoFilaPtr *headPtr, NodoFilaPtr *tailPtr ) {
    char value; // valor do nodo
    NodoFilaPtr tempPtr; // ponteiro temporario para nodo

    value = ( *headPtr )->dado;
    tempPtr = *headPtr; // guarda o endereco do head atual
    *headPtr = ( *headPtr )->proximoPtr; // altera o endereco do head atual para o proximo nodo

    // se a fila foi esvaziada
    if ( *headPtr == NULL ) {
        *tailPtr = NULL; //define a cauda para vazio tambem
    } // end if

    free( tempPtr );
    return value;
}

// retorna 1 se a fila estiver vazia, do contrario retorna 0
int ehVazia( NodoFilaPtr headPtr ){
    return headPtr == NULL;
}

// imprime a fila
void imprimeFila( NodoFilaPtr atualPtr ){
    NodoFilaPtr inicioPtr;
    inicioPtr=atualPtr;
    // se a fila estiver vazia
    if ( atualPtr == NULL ) {
        puts( "Fila esta vazia.\n" );
    }
    else {
        puts( "A fila eh:" );

        // enquanto nao chegar no fim da fila
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
} // end function imprimeFila
