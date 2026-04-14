#ifndef MECANICAPSS_H
#define MECANICAPSS_H

void imprimir_pneu (int* vet);
int estado_pneu (int* vet);
void escolhe_pneu (int* op, int* estado);
int trocando_pneu (int op, double* penalidade);
int trocando_asa (double* penalidade, int* asa);


#endif
 