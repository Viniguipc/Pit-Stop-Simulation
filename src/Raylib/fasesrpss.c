#include "fasesrpss.h"
#include "raylib.h"
#include "saverpss.h"


void fase1(save* dados){
	static int estado_pneu[4] = {0, 0, 0, 0};
	static int pneu = 0, escolhendo_pneu = 1;
	static double penalidade = 0;
	
	BeginDrawing();
		ClearBackground(BLACK);
		DrawText("FASE 1", ((GetScreenWidth() / 2) - (MeasureText("FASE 1", 40) / 2)), 50, 40, RED);
		
		if(escolhendo_pneu == 1){
			escolhe_pneu(&pneu, &escolhendo_pneu);
		}
		else{
			estado_pneu[pneu - 1] = trocando_pneu(pneu, &penalidade);
		}
		
	EndDrawing();
}

void fase2(save* dados){
	
}

void fase3(save* dados){
	
}

void fase4(save* dados){
	
}

void fase5(save* dados){
	
}

void fase6(save* dados){
	
}

extern void (*fases[])(save*) = {
	fase1,
	fase2,
	fase3,
	fase4,
	fase5,
	fase6
};
