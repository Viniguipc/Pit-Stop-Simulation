#include "fasesrpss.h"
#include "raylib.h"
#include "saverpss.h"
#include "mecanicarpss.h"


void fase1(save* dados, int* tela){
	static int estado_pneu[4] = {0, 0, 0, 0};
	static int pneu = 0, escolhendo_pneu = 1, fase_completa = 0, check = 0, salvando = 1;
	static double penalidade = 0, tempo = 0, tempo_total = 0;
	
	BeginDrawing();
		ClearBackground(BLACK);
		DrawText("FASE 1", ((GetScreenWidth() / 2) - (MeasureText("FASE 1", 40) / 2)), 50, 40, RED);
		
		if(fase_completa == 1){
			tempo_total = tempo + penalidade;
			
			if(dados->tempo[1] > tempo_total){
				dados->tempo[1] = tempo_total;
			}
			
			if(dados->fase < 3){
				dados->fase = 3;
			}
			
			if(salvando == 1){
				salvar_save(dados);
				salvando = 0;
			}
			
			DrawText("* Precione ENTER para voltar ao MENU", 10, 10, 10, LIGHTGRAY);
			DrawText("Pit-Stop Concluido!", ((GetScreenWidth() / 2) - (MeasureText("Pit-Stop Concluido!", 40) / 2)), 250, 40, GREEN);
			DrawText(TextFormat("[%.3f s]", tempo_total), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("[%.3f s]", tempo_total), 50) / 2)), 300, 50, WHITE);
			
			if(IsKeyPressed(KEY_ENTER)){
				estado_pneu[0] = 0;
				estado_pneu[1] = 0;
				estado_pneu[2] = 0;
				estado_pneu[3] = 0;
				pneu = 0;
				escolhendo_pneu = 1;
				fase_completa = 0;
				penalidade = 0;
				tempo = 0;
				tempo_total = 0;
				salvando = 1;
				
				*tela = 0;
			}
		}
		else{
			DrawText(TextFormat("[%.3f s]", tempo), 800, 50, 40, WHITE);
			DrawText(TextFormat("+ %.3f", penalidade), 1000, 50, 40, RED);
			
			tempo += GetFrameTime();
			
			if(escolhendo_pneu == 1){
				escolhe_pneu(&pneu, &escolhendo_pneu);
			}
			else{
				estado_pneu[pneu - 1] = trocando_pneu(pneu, &penalidade);
				if(estado_pneu[pneu - 1] != 0){
					escolhendo_pneu = 1;
				}
			}
			
			for(int i = 0; i < 4; i++){
				if(estado_pneu[i] == 1){
					check++;
				}
			}
			
			if(check == 4){
				fase_completa = 1;
				check = 0;
			}
			else{
				check = 0;
			}
		}
	EndDrawing();
}

void fase2(save* dados, int* tela){
	static int estado_pneu[4] = {0, 0, 0, 0};
	static int pneu = 0, escolhendo_pneu = 1, fase_completa = 0, check = 0, salvando = 1, estado_asa = 0;
	static double penalidade = 0, tempo = 0, tempo_total = 0;
	
	BeginDrawing();
		ClearBackground(BLACK);
		DrawText("FASE 2", ((GetScreenWidth() / 2) - (MeasureText("FASE 2", 40) / 2)), 50, 40, RED);
		
		if(fase_completa == 1){
			tempo_total = tempo + penalidade;
			
			if(dados->tempo[0] > tempo_total){
				dados->tempo[0] = tempo_total;
			}
			
			if(dados->fase < 2){
				dados->fase = 2;
			}
			
			if(salvando == 1){
				salvar_save(dados);
				salvando = 0;
			}
			
			DrawText("* Precione ENTER para voltar ao MENU", 10, 10, 10, LIGHTGRAY);
			DrawText("Pit-Stop Concluido!", ((GetScreenWidth() / 2) - (MeasureText("Pit-Stop Concluido!", 40) / 2)), 250, 40, GREEN);
			DrawText(TextFormat("[%.3f s]", tempo_total), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("[%.3f s]", tempo_total), 50) / 2)), 300, 50, WHITE);
			
			if(IsKeyPressed(KEY_ENTER)){
				estado_pneu[0] = 0;
				estado_pneu[1] = 0;
				estado_pneu[2] = 0;
				estado_pneu[3] = 0;
				pneu = 0;
				escolhendo_pneu = 1;
				fase_completa = 0;
				penalidade = 0;
				tempo = 0;
				tempo_total = 0;
				salvando = 1;
				estado_asa = 0;
				
				*tela = 0;
			}
		}
		else{
			DrawText(TextFormat("[%.3f s]", tempo), 800, 50, 40, WHITE);
			DrawText(TextFormat("+ %.3f", penalidade), 1000, 50, 40, RED);
			
			tempo += GetFrameTime();
			
			if(escolhendo_pneu == 1){
				escolhe_pneu(&pneu, &escolhendo_pneu);
			}
			else{
				estado_pneu[pneu - 1] = trocando_pneu(pneu, &penalidade);
				if(estado_pneu[pneu - 1] != 0){
					escolhendo_pneu = 1;
				}
			}
			
			for(int i = 0; i < 4; i++){
				if(estado_pneu[i] == 1){
					check++;
				}
			}
			
			if(check == 4){
				check = 0;
				
				if(estado_asa == 1){
					fase_completa = 1;
				}
				else{
					estado_asa = trocando_asa(&penalidade);
				}
			}
			else{
				check = 0;
			}
		}
	EndDrawing();
}

void fase3(save* dados){
	
}

void fase4(save* dados){
	
}

void fase5(save* dados){
	
}

void fase6(save* dados){
	
}
