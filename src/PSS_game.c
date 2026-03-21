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

main(){
	int i, op, pneu[4] = {0, 0, 0, 0}, check;
	
	printf("Pit Stop Simulation - The Game");

}
