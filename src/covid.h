#ifndef _COVID_H_
#define _COVID_H_
#include "lista.h"
#include "cidade.h"

int getNCovid(Info elemento);

double getXCovid(Info elemento);

double getYCovid(Info elemento);

void criaPontoCovid(Lista lista, Lista listaQ, int n, char cep[], char face, int num);

void criaTracejado(double x, double y, double x2, double y2, Lista lista);

void criaQuadradoeN(Lista lista, double x, double y, int n);

void criaQuadrado(Lista l, double x, double y);

void imprimeQuadrado(double x, double y, int n, char saida[]);

void imprimeQuadradoAzul(double x, double y, char saida[]);

void imprimeTracejado(double x, double y, double x2, double y2, char saida[]);

void imprimeCirculoVerde(double x, double y, double raio, char saida[]);

void imprimeEnvoltoria(Lista lista, char fill[], char saida[]);

void cv(Lista listaQuadra, Lista listaQRY, int n, char cep[], char face,int num);

void soc(Cidade cidade, int k, char cep[], char face, int num, char arqtxt[]);

void ci(Cidade listas, double x, double y, double raio);

void envoltoria(double x, double y, double raio, Lista listaCovid, Lista listaPS, Lista listaEnvoltoria,double densidade);

int compare(double x1, double y1, double x2, double y2);

int orient(double x1, double y1, double x2, double y2, double x3, double y3);

double areaConvexa(Lista lista);

double centroideX(Lista lista);

double centroideY(Lista lista);

#endif