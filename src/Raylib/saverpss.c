#include <stdio.h>

#include "raylib.h"
#include "saverpss.h"

//Função para salvar novo save no arquivo .save
void salvar_save(save* dados){
	FILE *save;
	
	save = fopen("PSS.save", "wb");
	
	if(save == NULL){
		printf("\nERRO ao salvar o arquivo");
	}
	else{
		fwrite(dados, sizeof(struct sv), 1, save);
		fclose(save);
	}
}

//Função para abrir o arquivo .save e ler a struct para pegar os dados, caso n haja .save ela cria um 
//FIX: Criar um sistema para quando o .save estiver com a array de tempos com uma quantidade fases menor que o atual ele n deixe as fases faltantes com lixo de memoria e coloque 0
void abrir_save(save* dados){
	FILE *save;
	int i;
	
	save = fopen("PSS.save", "rb");
	
	if(save == NULL){
		save = fopen("PSS.save", "wb");
		
		if(save == NULL){
			printf("\nERRO");
		}
		else{
			dados->fase = 0;
			for(i = 0; i < 6; i++){
				dados->tempo[i] = 0;
			}
			
			fwrite(dados, sizeof(struct sv), 1, save);
			fclose(save);
		}
	}
	else{
		fread(dados, sizeof(struct sv), 1, save);
		fclose(save);
	}
}

void verificar_tempos(save* dados, int* tela){
	int i;
	
	BeginDrawing();
		ClearBackground(BLACK);
		
		DrawText("* Precione ENTER para voltar ao MENU", 10, 10, 10, LIGHTGRAY);
		DrawText("Records de Tempo", ((GetScreenWidth() / 2) - (MeasureText("Records de Tempo", 40) / 2)), 50, 40, WHITE);
		DrawText("----------------", ((GetScreenWidth() / 2) - (MeasureText("----------------", 40) / 2)), 100, 40, WHITE);
		 
		for(i = 0; i < 6; i++){
			DrawText(TextFormat("Fase %d -> %.3f s", i + 1, dados->tempo[i]), ((GetScreenWidth() / 2) - (MeasureText("----------------", 40) / 2)), 50 * (i + 1) + 100, 40, WHITE);
		}
		
		if(IsKeyPressed(KEY_ENTER)){
			*tela = 0;
		}
	EndDrawing();
}
