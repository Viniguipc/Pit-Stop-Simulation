#include <stdio.h>
#include <time.h>

#include "mecanicapss.h"
#include "savepss.h"
#include "fasespss.h"

void fase1(save* dados){
	int i, op, pneu[4] = {0, 0, 0, 0}, check;
	struct timespec tempo_inicio, tempo_fim;
	double pit_time, penalidade;
	
	clock_gettime(CLOCK_MONOTONIC, &tempo_inicio);
	
	do{
		printf("Pit Stop Simulation - The Game\n");
		
		imprimir_pneu(pneu);
		
		escolhe_pneu(&op);
		pneu[op - 1] = trocando_pneu(op, &penalidade);
		
		system("clear");
		check = estado_pneu(pneu);
	} while (check != 1);
	
	clock_gettime(CLOCK_MONOTONIC, &tempo_fim);
	pit_time = ((tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_nsec - tempo_inicio.tv_nsec) / 1e9) + penalidade;
	
	if (check == 1){
		printf("\nPit Stop concluido com sucesso!\nTempo: %.3f s", pit_time);
		
		if(dados->tempo[0] == 0){
			dados->tempo[0] = pit_time;
		}
		else{
			if(dados->tempo[0] > pit_time){
				dados->tempo[0] = pit_time;
			}
		}
		if(dados->fase < 2){
			dados->fase = 2;
		}
	}
	else{
		printf("\n\nDNF");
	}
}

void fase2(save* dados){
	
}

void (*fases[])(save*) = {
	fase1,
	fase2
};

