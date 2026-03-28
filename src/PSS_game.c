// Bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "menupss.h"
#include "mecanicapss.h"
#include "fasespss.h"
#include "menupss.h"

int main(){
	int op;
	struct timespec tempo_inicio, tempo_fim;
	double pit_time;
	save dados;
	
	abrir_save(&dados);
	menu_inicial(&op);
	
	switch(op){
		case 1:
			menu_fases(&op, dados.fase);
			fases[op - 1](&dados);
			break;
		case 2:
			
			break;
	}
}
