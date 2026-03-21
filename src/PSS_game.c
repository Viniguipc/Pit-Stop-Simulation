#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void imprimir_pneu (int* vet){
	int i;
	
	for (i = 0; i < 4; i++){
		printf("\nPneu %d - %d", i + 1, vet[i]);
	}
}

int estado_pneu (int* vet){
	int check = 1, i;
	
	for (i = 0; i < 4; i++){
		if (vet[i] == 0){
			check = 0;
		}
	}
	
	return check;
}

void escolhe_pneu (int* op){
	do{
		printf("\nEscolha o Pneu a ser trocado (1 a 4): ");
		scanf("%d", op);
	}while (*op < 1 || *op > 4);
}

int trocando_pneu (int op){
	char button;
	
	printf("Aperte \"x\" para desparafusar o pneu %d.", op);
	scanf("%c", &button);
	
	if (button != 'x' && button != 'X'){
		printf("Falha ao desparafusar o pneu %d! Abandonamos a Corrida DNF.", op);
	}
	else{
		printf("Aperte \"y\" para colocar o pneu novo %d.", op);
		scanf("%c", &button);
		
		if(button != 'y' && button != 'Y'){
			printf("Falha ao colocar o pneu %d! Abandonamos a Corrida DNF.", op);
		}
		else{
			printf("Aperte \"z\" para parafusar o novo pneu %d", op);
			scanf("%c", &button);
			
			if(button != 'z' && button != 'Z'){
				printf("Falha ao parafusar o pneu %d! Abandonamos a Corrida DNF.", op);
			}
			else{
				return 1;
			}
		}
	}
	
}

int main(){
	int i, op, pneu[4] = {0, 0, 0, 0}, check;
	
	printf("Pit Stop Simulation - The Game");
	
	do{
		imprimir_pneu(pneu);
		
		escolhe_pneu(&op);
		pneu[op - 1] = trocando_pneu(op);
		
		check = estado_pneu(pneu);
	} while (check != 1);
	
	printf("\nPit Stop concluido com sucesso!");

}
