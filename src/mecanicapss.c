#include <stdio.h>

#include "mecanicapss.h"

//Função para imprimir o estado dos pneus na tela
//FIX: Melhorar o layout
void imprimir_pneu (int* vet){
	char f[] = "Trocar", v[] = "Novo";
	int i;
	
	for (i = 0; i < 4; i++){
		if(vet[i] == 0){
			printf("\nPneu %d - %s", i + 1, f);
		}
		else{
			printf("\nPneu %d - %s", i + 1, v);
		}
	}
}

//Função que verifica o estado dos pneus e retorna 1 se todos os pneus foram trocados e 0 se ainda falta algumm pneu
int estado_pneu (int* vet){
	int check = 1, i;
	
	for (i = 0; i < 4; i++){
		if (vet[i] == 0){
			check = 0;
		}
	}
	
	return check;
}

//Menu para escolher quaal pneu trocar, n impede de escolher um pneu ja trocado
void escolhe_pneu (int* op){
	do{
		printf("\nEscolha o Pneu a ser trocado (1 a 4): ");
		scanf(" %d", op);
	}while (*op < 1 || *op > 4);
}

//Função para trocar o estado dos pneus, necessita apertar os botões certos, caso erre resulta penalidade de tempo
int trocando_pneu (int op, double* penalidade){
	char button;
	
	do{
		printf("\nAperte \"x\" para desparafusar o pneu %d. ", op);
		scanf(" %c", &button);
		
		if (button != 'x' && button != 'X'){
			printf("\nFalha ao desparafusar o pneu %d! Perdemos 2.5 s.", op);
			
			*penalidade = *penalidade + 2.5;
		}
		else{
			do{
				printf("\nAperte \"y\" para colocar o pneu novo %d. ", op);
				scanf(" %c", &button);
				
				if(button != 'y' && button != 'Y'){
					printf("\nFalha ao colocar o pneu %d! Perdemos 2.5 s.", op);
					
					*penalidade = *penalidade + 2.5;
				}
				else{
					do{
						printf("\nAperte \"z\" para parafusar o novo pneu %d. ", op);
						scanf(" %c", &button);
					
						if(button != 'z' && button != 'Z'){
							printf("\nFalha ao parafusar o pneu %d! Perdemos 2.5 s.", op);
							
							*penalidade = *penalidade + 2.5;
						}
						else{
							return 1;
						}
					}while(button != 'z' && button != 'Z');
				}
			}while(button != 'y' && button != 'Y');
		}
	}while(button != 'x' && button != 'X');
}

void trocando_asa (double* penalidade, int* asa){
	char button;
	int i = 0;
	
	printf("\nAperte \"w\" três vezes para soltar os parafusos centrais da asa: ");
	
	while(i < 3){
		printf("\n%d > ", i + 1);
		scanf(" %c", &button);
		
		if(button != 'w' && button != 'W'){
			printf("\nFalha ao soltar o primeiro parafuso, tente novamente! Perdemos 2.5 s");
			
			*penalidade = *penalidade + 2.5;
		}
		else{
			i++;
		}
	}
	
	do{
		printf("\nAperte \"e\" para retirar a asa: ");
		scanf(" %c", &button);
		
		if(button != 'e' && button != 'E'){
		printf("\nFalaha ao retirar a asa! Perdemos 1.5 s");
		
		*penalidade = *penalidade + 1.5;
		}
	}while(button != 'e' && button != 'E');
	
	do{
		printf("\nAperte \"r\" para colocar a nova asa: ");
		scanf(" %c", &button);
		
		if(button != 'r' && button != 'R'){
		printf("Falha ao colocar a nova asa! Perdemos 4 .0 s");
		
		*penalidade = *penalidade + 4;
		}
	}while(button != 'r' && button != 'R');
	
	printf("\nAsa trocada com sucessp!");
}

