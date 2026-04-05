#include "raylib.h"
#include "menurpss.h"
#include "mecanicarpss.h"
#include "fasesrpss.h"
#include "saverpss.h"

int main(){
	int op = 0;
	
	InitWindow(800, 600, "Pit Stop Simulation");
	
	while(!WindowShouldClose() && op != 3){
		op = menu_inicial();
	}
	
	CloseWindow();
}