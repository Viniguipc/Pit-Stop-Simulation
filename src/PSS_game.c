// Bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "menupss.h"
#include "mecanicapss.h"
#include "fasespss.h"
#include "menupss.h"

int main(){
	int op, op_main;
	struct timespec tempo_inicio, tempo_fim;
	double pit_time;
	save dados;
	
	abrir_save(&dados);
	
	do{
		menu_inicial(&op_main);
		
		switch(op_main){
			case 1:
				menu_fases(&op, dados.fase);
				fases[op - 1](&dados);
				
				salvar_save(&dados);
				break;
			case 2:
				verificar_tempos(&dados);
				break;
		}
	}while(op_main != 3);
}
