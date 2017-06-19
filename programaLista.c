
#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.c"

int main(){
	int op, pos; 
	int info; 
	listaSeq myList;
	criar(&myList);

	do{
		printf("Digite uma Opcao:\n");
		printf("1 - Inserir numero\n");
		printf("2 - Remover numero\n");
		printf("3 - Imprimir lista\n");
		printf("0 - Sair\n");
		scanf("%d",&op);

	switch(op){
		case 1:
			printf("Digite o dado a ser inserido\n");
			fflush(stdin);
			scanf("%d",&info);
			inserir(&myList,info);
			system("pause");
			break;
		case 2:
			printf("Digite a posicao do numero a ser removido!\n");
			fflush(stdin);
			scanf("%d",&pos);
			info = remover(&myList,pos);
			printf("Numero %d removido da lista\n",info);
			system("pause");
			break;
		case 3:
			printl(myList);
			system("pause");
			break;
		default:
			break;
	}




	}while(op!=0);

}



