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

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de pontos da envoltoria*/
Lista getListaEnvoltoria(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de pontos de covid*/
Lista getListaCovid(Cidade lista);

/*Esta funcao rebece a lista que contem todas as listas
e retorna a lista de pontos de covid dentro do raio*/
Lista getListaPontosCovid(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna o valor de x do comando dd*/
double cidadeX(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna o valor de y do comando dd*/
double cidadeY(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna o valor de w do comando dd*/
double cidadeW(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna o valor de h do comando dd*/
double cidadeH(Cidade listas);

/*Esta funcao rebece a lista que contem todas as listas
e retorna o valor de d do comando dd*/
double cidadeD(Cidade listas);

/*Esta funcao isere os dados lidos no comando dd na struct cidade*/
void DDCidade(double x, double y, double w, double h, double d, Cidade cidade);

/*Esta funcao rebece a lista que contem todas as listas
e desaloca*/
void removeListas(Cidade cidade);

#endif