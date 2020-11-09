#ifndef _POSTO_H_
#define _POSTO_H_
#include "lista.h"

typedef void *Posto;

double getXPS(Info elemento);

double getYPS(Info elemento);

void imprimePosto(double x, double y, int raio, char fill[], char saida[]);

void postoLista(Lista lista, double x, double y);

void imprimeListaPS(Lista l, char saida[]);

#endif