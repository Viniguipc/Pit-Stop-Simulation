#include "raylib.h"
#include "menurpss.h"
#include "mecanicarpss.h"
#include "fasesrpss.h"
#include "saverpss.h"

int main(){
	save dados;
	int op = 0, fase = 0, tela_atual = 0;
	
	abrir_save(&dados);
	dados.fase = 2; //teste, retirar
	
	InitWindow(1200, 900, "Pit Stop Simulation");
	SetTargetFPS(60);
	
	while(!WindowShouldClose() && op != 3){
		switch(tela_atual){
			case 0:
				menu_inicial(&op);
				tela_atual = op;
				break;
			case 1:
				menu_fases(&fase, dados.fase);
				break;
			case 2:
				verificar_tempos(&dados);
				break;
			case 4:
				break;
		}
	}
	
	CloseWindow();
}