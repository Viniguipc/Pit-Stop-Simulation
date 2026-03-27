// Bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FASE 2

//Struct com os dados do save, a fase atual e os recordes de tempo de cada fase
typedef struct sv{
	int fase;
	float tempo[FASE];
}save;

void menu_inicial(int* op){
	do{
		printf("\n\n\tMENU\n");
		printf("\n----------");
		printf("\n1 - Iniciar Jogo\n2 - Verificar Tempos\n3 - Sair");
		printf("\n----------\n");
		scanf(" %d", op);
	}while(*op < 1 || *op > 3);
}

//Função para salvar novo save no arquivo .save
void salvar_save(save* dados){
	FILE *save;
	
	save = fopen("PSS.save", "wb");
	
	if(save == NULL){
		printf("\nERRO ao salvar o arquivo");
	}
	else{
		fwrite(dados, sizeof(struct sv), 1, save);
		fclose(save);
	}
}

//Função para abrir o arquivo .save e ler a struct para pegar os dados
void abrir_save(save* dados){
	FILE *save;
	int i;
	
	save = fopen("PSS.save", "rb");
	
	if(save == NULL){
		save = fopen("PSS.save", "wb");
		
		if(save == NULL){
			printf("\nERRO");
		}
		else{
			dados->fase = 0;
			for(i; i < FASE; i++){
				dados->tempo[i] = 0;
			}
			
			fwrite(dados, sizeof(struct sv), 1, save);
			fclose(save);
		}
	}
	else{
		fread(dados, sizeof(struct sv), 1, save);
		fclose(save);
	}
}

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

//Função para trocar o estado dos pneus, necessita apertar os botões certos, caso erre resulta em abandono (DNF)
int trocando_pneu (int op, int* DNF){
	char button;
	
	printf("\nAperte \"x\" para desparafusar o pneu %d. ", op);
	scanf(" %c", &button);
	
	if (button != 'x' && button != 'X'){
		printf("\nFalha ao desparafusar o pneu %d! Abandonamos a Corrida.", op);
		
		*DNF = 1;
		return 0;
	}
	else{
		printf("\nAperte \"y\" para colocar o pneu novo %d. ", op);
		scanf(" %c", &button);
		
		if(button != 'y' && button != 'Y'){
			printf("\nFalha ao colocar o pneu %d! Abandonamos a Corrida.", op);
			
			*DNF = 1;
			return 0;
		}
		else{
			printf("\nAperte \"z\" para parafusar o novo pneu %d ", op);
			scanf(" %c", &button);
			
			if(button != 'z' && button != 'Z'){
				printf("\nFalha ao parafusar o pneu %d! Abandonamos a Corrida.", op);
				
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
	int op;
	struct timespec tempo_inicio, tempo_fim;
	double pit_time;
	save dados;
	
	abrir_save(&dados);
	menu_inicial(&op);
	
	
	/*
	clock_gettime(CLOCK_MONOTONIC, &tempo_inicio);
	
	do{
		printf("Pit Stop Simulation - The Game\n");
		
		imprimir_pneu(pneu);
		
		escolhe_pneu(&op);
		pneu[op - 1] = trocando_pneu(op, &dnf);
		
		system("clear");
		check = estado_pneu(pneu);
	} while (check != 1 && dnf == 0);
	
	clock_gettime(CLOCK_MONOTONIC, &tempo_fim);
	pit_time = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_nsec - tempo_inicio.tv_nsec) / 1e9;
	
	if (check == 1){
		printf("\nPit Stop concluido com sucesso!\nTempo: %.3f s", pit_time);
	}
	else{
		printf("\n\nDNF");
	}
	*/
}
