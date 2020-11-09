#ifndef _COVID_H_
#define _COVID_H_
#include "lista.h"
#include "cidade.h"

/*Esta funcao retorna o numero de casos de covid em
ponto passado como parametro*/
int getNCovid(Info elemento);

/*Esta funcao retorna o x de um ponto decasos de covid 
 passado como parametro*/
double getXCovid(Info elemento);

/*Esta funcao retorna o y de um ponto decasos de covid 
 passado como parametro*/
double getYCovid(Info elemento);

/* esta funcao aloca memoria e armazena os dados de um ponto de covid
ela recebe dos dados do ponto e a lista por parametro 
no fim ela insere a linha na lista*/
void criaPontoCovid(Lista lista, double x, double y, int n);

/* esta funcao aloca memoria e armazena os dados de uma linha tracejada
ela recebe dos dados da linha e a lista por parametro 
no fim ela insere a linha na lista*/
void criaTracejado(double x, double y, double x2, double y2, Lista lista);

/* esta funcao aloca memoria e armazena os dados de um quadrado e um numero
ela recebe dos dados do quadrado e a lista por parametro 
no fim ela insere a linha na lista*/
void criaQuadradoeN(Lista lista, double x, double y, int n);

/* esta funcao aloca memoria e armazena os dados de um quadrado
ela recebe dos dados do quadrado e a lista por parametro 
no fim ela insere a linha na lista*/
void criaQuadrado(Lista l, double x, double y);

/* esta funcao imprime um Quadrado e o Numero de casos de covid nesse ponto
ela recebe como parametro a posicao do quadrado e o numero de casos
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeQuadrado(double x, double y, int n, char saida[]);

/* esta funcao imprime um Quadrado azul
ela recebe como parametro a posicao do quadrado
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeQuadradoAzul(double x, double y, char saida[]);


/* esta funcao imprime uma linha tracejada
ela recebe como parametro a posicao do inicio e fim da linha
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeTracejado(double x, double y, double x2, double y2, char saida[]);

/* esta funcao imprime um Circulo de borda verde
ela recebe como parametro a posicao e raio do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeCirculoVerde(double x, double y, double raio, char saida[]);

/* esta funcao imprime a envoltoria convexa
ela recebe como parametro os dados da envoltoria
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeEnvoltoria(Lista lista, char fill[], char saida[]);

/* esta funcao resolve o comando cv
ela recebe como parametro a listaCovid, a lista de quadras,
a lista com os elementos a serem impresso no qry, e os dados do ponto*/
void cv(Lista listaCovid, Lista listaQuadra, Lista listaQRY, int n, char cep[], char face,int num);

/* esta funcao resolve o comando soc
ela recebe como parametro a cidade, a quantidade de postos a serem buscados
e os dados do ponto
e o nome arquivo do txt junto ao seu diretório*/
void soc(Cidade cidade, int k, char cep[], char face, int num, char arqtxt[]);

/* esta funcao resolve o comando ci
ela recebe como parametro a cidade, os pontos e o raio do circulo 
e um ponteiro para a string de preenchimento da envoltoria no svg
e o nome arquivo do txt junto ao seu diretório*/
void ci(Cidade listas, double x, double y, double raio, char *categoria, char arqtxt[]);

/* esta funcao cria a envoltoria convexa entre os casos de covid na area do circulo
ela recebe a posição do circulo, seu raio, a lista de casos, lista de pontos da envoltoria e a lista de posto*/
void envoltoria(double x, double y, double raio, Lista listaCovid, Lista listaEnvoltoria, Lista listaPCovid);

/* esta funcao compara se o ponto b é maior que o ponto c
para o quicksort dos pontos do poligono convexo
ela recebe tres pontos, sendo o primeiro um ponto de referencia e os dois outros para comparação*/
int compare(Info a, Info b, Info c);

/* esta funcao recebe tres pontos (x,y)
e retorna um indicador para informar se
os tres pontos estão no sentido horario, anti-horario ou são colineares*/
int orient(Info a, Info b, Info c);

/* esta funcao calcula a area do poligono convexo
ela recebe como parametro a lista de pontos da envoltoria convexa*/
double areaConvexa(Lista lista);

/* esta funcao calcula o ponto x do centroide do poligono convexo
ela recebe como parametro a lista de pontos da envoltoria convexa*/
double centroideX(Lista lista);

/* esta funcao calcula o ponto y do centroide do poligono convexo
ela recebe como parametro a lista de pontos da envoltoria convexa*/
double centroideY(Lista lista);

#endif