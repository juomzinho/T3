#ifndef _POSTO_H_
#define _POSTO_H_
#include "lista.h"

typedef void *Posto;

/* esta funcao retorna o ponto x de um posto
ela recebe o elemento onde o posto esta
armazenado como parametro */
double getXPS(Info elemento);

/* esta funcao retorna o ponto y de um posto
ela recebe o elemento onde o posto esta
armazenado como parametro */
double getYPS(Info elemento);

/* esta funcao imprime um postos no arquivo svg
ela recebe as informacoes a serem impressas como parametro */
void imprimePosto(double x, double y, int raio, char fill[], char saida[]);


/* esta funcao insere um posto na lista de postos
ela recebe as informacoes a serem adicionadas como parametro */
void postoLista(Lista lista, double x, double y);

/* esta funcao percorre a lista de postos e chama a funcao imprimePosto
ela recebe a a lista a ser percorrida e o diretorio de saida como parametro */
void imprimeListaPS(Lista l, char saida[]);

#endif