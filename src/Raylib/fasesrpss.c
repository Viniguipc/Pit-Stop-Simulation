#include "fasesrpss.h"
#include "raylib.h"
#include "saverpss.h"


void fase1(save* dados){
	BeginDrawing();
		ClearBackground(BLACK);
		DrawText("FASE 1", ((GetScreenWidth() / 2) - (MeasureText("FASE 1", 40) / 2)), 50, 40, RED);
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
