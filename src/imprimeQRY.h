#ifndef _IMPRIME_QRY_
#define _IMPRIME_QRY_
#include "lista.h"


/* esta funcao percorre a lista de qrys,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir o respectivo elemento passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeQry(Lista l, char saida[]);

/* esta funcao imprime uma linha e o cep no arquivo svg
ela recebe como parametro os dados do linha e o cep
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeLinha(double x, double y, char cep[], char saida[]);

/* esta funcao imprime uma linha e a area no arquivo svg
ela recebe como parametro os dados do linha e a area
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeLinhaD(double x, double y, double area, char saida[]);

/* esta funcao imprime um circulo no arquivo svg
ela recebe como parametro os dados do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeCirculoQry(double x, double y, double raio, char saida[]);

/* esta funcao imprime uma quadra com as bordas arredondadas no arquivo svg
ela recebe como parametro os dados do quadra
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeQuadraQRY(double x, double y, double w, double h, char sw[], char saida[]);

/* esta funcao imprime uma retangulo com as borda tracejada no arquivo svg
ela recebe como parametro os dados do retangulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRetT(double x, double y, double w, double h, char sw[], char saida[]);

/* esta funcao imprime a area do cep no arquivo svg
ela recebe como parametro os dados da area
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeArea(double x, double y,double w, double h,double area, char saida[]);

/* esta funcao imprime uma retangulo com as borda cheia no arquivo svg
ela recebe como parametro os dados do retangulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRet(double x, double y, double w, double h, char sw[], char saida[]);

#endif