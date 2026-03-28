#include <stdio.h>

#include "savepss.h"

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
			for(i; i < 2; i++){
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
