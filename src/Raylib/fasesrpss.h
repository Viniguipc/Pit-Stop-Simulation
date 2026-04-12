#include "saverpss.h"

#ifndef FASESPSS_H
#define FASESPSS_H

void fase1(save* dados, int* tela);
void fase2(save* dados);
void fase3(save* dados);
void fase4(save* dados);
void fase5(save* dados);
void fase6(save* dados);
extern void (*fases[])(save*);

#endif
