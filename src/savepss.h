#ifndef SAVEPSS_H
#define SAVEPSS_H

//Struct com os dados do save, a fase atual e os recordes de tempo de cada fase
typedef struct sv{
	int fase;
	float tempo[2];
}save;

void salvar_save(save* dados);
void abrir_save(save* dados);

#endif
