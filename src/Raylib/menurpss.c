#include "menurpss.h"
#include "raylib.h"

 void menu_inicial(int* op){
	char *opcoes[] = {"Iniciar Jogo", "Placar de Tempos", "Sair"};
	static int escolha = 1;
	int i;
	
	if(IsKeyPressed(KEY_ENTER)){
		*op = escolha;
	}
	else{
		if(IsKeyPressed(KEY_DOWN)){
			(escolha)++;
			if(escolha > 3){
				escolha = 1;
			}
		}
		
		if(IsKeyPressed(KEY_UP)){
			(escolha)--;
			if(escolha < 1){
				escolha = 3;
			}
		}
	}
	
	BeginDrawing();
		ClearBackground(BLACK);
		
		DrawText("MENU INICIAL", ((GetScreenWidth() / 2) - (MeasureText("MENU INICIAL", 40) / 2)), 50, 40, WHITE);
		
		for(i = 0; i < 3; i++){
			if((i + 1) != escolha){
				DrawText(opcoes[i], 250, 50 * (i + 2), 30 , WHITE);
			}
			else{
				DrawText(opcoes[i], 250, 50 * (i + 2), 30, RED);
			}
		}
	EndDrawing();
}

//Mudar de lista para carrocel
void menu_fases(int* op, int fase_atual){
	int i;
	static int escolha = 1;
	
	if(IsKeyPressed(KEY_ENTER)){
		if(escolha > fase_atual){
			
		}
		else{
			*op = escolha;
		}
	}
	else{
		if(IsKeyPressed(KEY_DOWN)){
			(escolha)++;
			if(escolha > 6){
				escolha = 1;
			}
		}
		
		if(IsKeyPressed(KEY_UP)){
			(escolha)--;
			if(escolha < 1){
				escolha = 3;
			}
		}
	}
	
	BeginDrawing();
		ClearBackground(BLACK);
		
		DrawText("ESCOLHA A FASE", ((GetScreenWidth() / 2) - (MeasureText("ESCOLHA A FASE", 40) / 2)), 50, 40, WHITE);
		
		for(i = 0; i < 6; i++){
			if((i + 1) <= fase_atual){
				if((i + 1) != escolha){
					DrawText(TextFormat("Fase %d - Disponivel", i + 1), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("Fase %d - Disponivel", i + 1), 30) / 2)), 50 * (i + 2), 30 , WHITE);
				}
				else{
					DrawText(TextFormat("Fase %d - Disponivel", i + 1), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("Fase %d - Disponivel", i + 1), 30) / 2)), 50 * (i + 2), 30, BLUE);
				}
			}
			else{
				if((i + 1) != escolha){
					DrawText(TextFormat("Fase %d - Bloqueada", i + 1), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("Fase %d - Bloqueada", i + 1), 30) / 2)), 50 * (i + 2), 30 , WHITE);
				}
				else{
					DrawText(TextFormat("Fase %d - Bloqueada", i + 1), ((GetScreenWidth() / 2) - (MeasureText(TextFormat("Fase %d - Bloqueada", i + 1), 30) / 2)), 50 * (i + 2), 30, BLUE);
				}
			}
		}
		
		EndDrawing();
}