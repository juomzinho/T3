#ifndef _CIDADE_H_
#define _CIDADE_H_
#include "lista.h"

typedef void* Cidade;

/*Inicia e retorna as listas do programa iniciadas
Lista hidrantes, lista quadras, lista formas, lista semaforos, 
lista qry e lista radio*/
Cidade iniciaCidade();

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de quadras*/
Lista getListaQuadra(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de formas*/
Lista getListaFormas(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de semaforos*/
Lista getListaSemaforo(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de radios*/
Lista getListaRadio(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de hindrantes*/
Lista getListaHidrante(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de qrys*/
Lista getListaQRY(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de postos de saúde*/
Lista getListaPS(Cidade listas);

Lista getListaEnvoltoria(Cidade listas);

Lista getListaCovid(Cidade lista);

Lista getListaPontosCovid(Cidade listas);

double cidadeX(Cidade listas);

double cidadeY(Cidade listas);

double cidadeW(Cidade listas);

double cidadeH(Cidade listas);

double cidadeD(Cidade listas);

void DDCidade(double x, double y, double w, double h, double d, Cidade cidade);

/*Esta funcao rebece a lista que contem todas as listas
e desaloca*/
void removeListas(Cidade cidade);

#endif