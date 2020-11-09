#ifndef _COVID_H_
#define _COVID_H_
#include "lista.h"
#include "cidade.h"

int getNCovid(Info elemento);

double getXCovid(Info elemento);

double getYCovid(Info elemento);

void criaPontoCovid(Lista lista, double x, double y, int n);

void criaTracejado(double x, double y, double x2, double y2, Lista lista);

void criaQuadradoeN(Lista lista, double x, double y, int n);

void criaQuadrado(Lista l, double x, double y);

void imprimeQuadrado(double x, double y, int n, char saida[]);

void imprimeQuadradoAzul(double x, double y, char saida[]);

void imprimeTracejado(double x, double y, double x2, double y2, char saida[]);

void imprimeCirculoVerde(double x, double y, double raio, char saida[]);

void imprimeEnvoltoria(Lista lista, char fill[], char saida[]);

void cv(Lista listaCovid, Lista listaQuadra, Lista listaQRY, int n, char cep[], char face,int num);

void soc(Cidade cidade, int k, char cep[], char face, int num, char arqtxt[]);

void ci(Cidade listas, double x, double y, double raio, char *categoria, char arqtxt[]);

void envoltoria(double x, double y, double raio, Lista listaCovid, Lista listaEnvoltoria, Lista listaPCovid);

int compare(Info a, Info b, Info c);

int orient(Info a, Info b, Info c);

double areaConvexa(Lista lista);

double centroideX(Lista lista);

double centroideY(Lista lista);

#endif