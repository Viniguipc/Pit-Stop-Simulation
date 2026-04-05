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
		
		DrawText("MENU INICIAL", 250, 50, 40, WHITE);
		
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

void menu_fases(int* op, int fase_atual){
	char *opcoes[] = {"Iniciar Jogo", "Placar de Tempos", "Sair"};
	int i, escolha;
	
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
		
		DrawText("MENU INICIAL", 250, 50, 40, WHITE);
		
		for(i = 0; i < 3; i++){
			if((i + 1) != escolha){
				DrawText(opcoes[i], 250, 50 * (i + 2), 30 , WHITE);
			}
			else{
				DrawText(opcoes[i], 250, 50 * (i + 2), 30, BLUE);
			}
		}
	EndDrawing();
}