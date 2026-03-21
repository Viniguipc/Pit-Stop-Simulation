// Bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
		scanf("%d", op);
	}while (*op < 1 || *op > 4);
}

//Função para trocar o estado dos pneus, necessita apertar os botões certos, caso erre resulta em abandono (DNF)
int trocando_pneu (int op, int* DNF){
	char button;
	
	printf("Aperte \"x\" para desparafusar o pneu %d. ", op);
	scanf(" %c", &button);
	
	if (button != 'x' && button != 'X'){
		printf("Falha ao desparafusar o pneu %d! Abandonamos a Corrida.", op);
		
		*DNF = 1;
		return 0;
	}
	else{
		printf("Aperte \"y\" para colocar o pneu novo %d. ", op);
		scanf(" %c", &button);
		
		if(button != 'y' && button != 'Y'){
			printf("Falha ao colocar o pneu %d! Abandonamos a Corrida.", op);
			
			*DNF = 1;
			return 0;
		}
		else{
			printf("Aperte \"z\" para parafusar o novo pneu %d ", op);
			scanf(" %c", &button);
			
			if(button != 'z' && button != 'Z'){
				printf("Falha ao parafusar o pneu %d! Abandonamos a Corrida.", op);
				
				*DNF = 1;
				return 0;
			}
			else{
				return 1;
			}
		}
	}
}

int main(){
	int i, op, dnf = 0, pneu[4] = {0, 0, 0, 0}, check;
	
	do{
		printf("Pit Stop Simulation - The Game\n");
		
		imprimir_pneu(pneu);
		
		escolhe_pneu(&op);
		pneu[op - 1] = trocando_pneu(op, &dnf);
		
		system("cls");
		check = estado_pneu(pneu);
	} while (check != 1 && dnf == 0);
	
	if (check == 1){
		printf("\nPit Stop concluido com sucesso!");
	}
	else{
		printf("\n\nDNF");
	}
}
