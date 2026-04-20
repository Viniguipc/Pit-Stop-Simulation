#include "raylib.h"
#include "menurpss.h"
#include "mecanicarpss.h"
#include "fasesrpss.h"
#include "saverpss.h"

int main(){
	save dados;
	int op = 0, fase = 0, tela_atual = 0;
	
	abrir_save(&dados);
	
	InitWindow(1200, 900, "Pit Stop Simulation");
	SetTargetFPS(60);
	
	while(!WindowShouldClose() && op != 3){
		switch(tela_atual){
			case 0:
				fase = 0;
				menu_inicial(&op);
				tela_atual = op;
				op = 0;
				break;
			case 1:
				menu_fases(&fase, dados.fase);
				if(fase != 0){
					tela_atual = 4;
				}
				break;
			case 2:
				verificar_tempos(&dados, &tela_atual);
				break;
			case 4:
				switch(fase){
					case 1:
						fase1(&dados, &tela_atual);
						break;
					case 2:
						fase2(&dados, &tela_atual);
						break;
					case 3:
					case 4:
					case 5:
					case 6:
						tela_atual = 1;
						fase = 0;
						break;
				}
				break;
		}
	}
	
	CloseWindow();
}