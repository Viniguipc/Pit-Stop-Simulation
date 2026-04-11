#include "mecanicarpss.h"
#include "raylib.h"

void imprimir_pneu (int* vet){
	
}

int estado_pneu (int* vet){
	
}

void escolhe_pneu (int* op, int* estado){
	static int escolha = 0;
	int i;
	
	if(IsKeyPressed(KEY_ENTER)){
		*op = escolha;
		if(escolha != 0){
			*estado = 0;
		}
	}
	else{
		if(IsKeyPressed(KEY_DOWN)){
			(escolha)++;
			if(escolha > 4){
				escolha = 1;
			}
		}
		
		if(IsKeyPressed(KEY_UP)){
			(escolha)--;
			if(escolha < 1){
				escolha = 4;
			}
		}
	}
		
		DrawText("ESCOLHA O PNEU QUE DEVE SER TROCADO", ((GetScreenWidth() / 2) - (MeasureText("ESCOLHA O PNEU QUE DEVE SER TROCADO", 30) / 2)), 150, 30, WHITE);
		
		for(i = 0; i < 4; i++){
			if((i + 1) != escolha){
				DrawCircle((GetScreenWidth() / 2) - 100 + ((i % 2) * 200), 300 * (i / 2) + 300, 30 , WHITE);
			}
			else{
				DrawCircle((GetScreenWidth() / 2) - 100 + ((i % 2) * 200), 300 * (i / 2) + 300, 30 , RED);
			}
		}
}

int trocando_pneu (int op, double* penalidade){
	static int pit_step = 0;
	
	if(!IsKeyPressed(KEY_X) && pit_step == 0){
		*penalidade += 2.5;
	}
	else{
		pit_step = 1;
		
		if(!IsKeyPressed(KEY_Y) && pit_step == 1){
			*penalidade += 2.5;
		}
		else{
			pit_step = 2;
			
			if(!IsKeyPressed(KEY_Z)){
				*penalidade += 2.5;
			}
			else{
				pit_step = 3;
			}
		}
	}
}

void trocando_asa (double* penalidade, int* asa){
	
}
