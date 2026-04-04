#include <stdio.h>

#include "menupss.h"

//Função menu inicial para começar o jogo, fechar ou conferir tempos
void menu_inicial(int* op){
	do{
		printf("\n\n\tMENU\n");
		printf("\n----------");
		printf("\n1 - Iniciar Jogo\n2 - Verificar Tempos\n3 - Sair");
		printf("\n----------\n");
		scanf(" %d", op);
	}while(*op < 1 || *op > 3);
}

void menu_fases(int* op, int fase_atual){
	int i;
	do{
		printf("\n\n\tESCOLHA A FASE: \n");
		printf("\n----------");
		for(i = 0; i < 2; i++){
			if(fase_atual <= i){
				printf("\nFase %d - Selecionar", i + 1);
			}
			else{
				printf("\nFase %d - Bloqueada", i + 1);
			}
		}
		printf("\n----------\n");
		scanf(" %d", op);
	}while(*op < 1 || *op > fase_atual + 1);
}
