#include <stdio.h>
#include <time.h>

#include "savepss.h"

void fase2(save* dados){
	
}

void fase1(save* dados){
	int i, op, dnf = 0, pneu[4] = {0, 0, 0, 0}, check;
	struct timespec tempo_inicio, tempo_fim;
	double pit_time;
	
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
}

void (*fases[])(save*) = {
	fase1,
	fase2
};

