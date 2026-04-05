#include "saverpss.h"

#ifndef FASESPSS_H
#define FASESPSS_H

void fase1(save* dados);
void fase2(save* dados);
extern void (*fases[])(save*);

#endif
