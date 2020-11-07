#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "imprimeQRY.h"
#include "covid.h"
#include "lista.h"
#include "resolveQry.h"
#include "posto.h"
#include "quadra.h"


typedef struct novas{
    char tipo, cep[20], sw[10], face;
    double x, y, x2, y2,w, h, area, raio;
    int n;
} structQry;

void imprimeQry(Lista l, char saida[]){
    No node = getFirst(l);
    Info elemento;
    structQry def;

    while (node != NULL)
    {
        elemento = getInfo(node);
        def.tipo = getTipoQRY(elemento);

        if (def.tipo == 'l'){
            imprimeLinha(getXQRY(elemento), getYQRY(elemento), getCepQRY(elemento), saida);
        }
        if (def.tipo == 'p'){
            imprimeLinhaD(getXQRY(elemento), getYQRY(elemento), getHQRY(elemento), saida);
        }
        if (def.tipo == 'c'){
            imprimeCirculoQry(getXQRY(elemento), getYQRY(elemento),getRaioQRY(elemento), saida);
        }
        if (def.tipo == 'n'){
            imprimeRetT(getXQRY(elemento), getYQRY(elemento), getWQRY(elemento), getHQRY(elemento), getSWQRY(elemento), saida);
        }
        if (def.tipo == 's'){
            imprimeRet(getXQRY(elemento), getYQRY(elemento), getWQRY(elemento), getHQRY(elemento), getSWQRY(elemento), saida);
        }
        if (def.tipo == 'a'){
            imprimeArea(getXQRY(elemento),getYQRY(elemento),getWQRY(elemento),getHQRY(elemento),getAreaQRY(elemento), saida);
        }

        if (def.tipo == 'x'){
            imprimeQuadrado( getXQRY(elemento), getYQRY(elemento), getNQRY(elemento), saida);
        }        

        if (def.tipo == 'q'){
            imprimeQuadradoAzul(getXQRY(elemento), getYQRY(elemento), saida);
        }        

        if (def.tipo == 't'){            
            imprimeTracejado(getXQRY(elemento), getYQRY(elemento), getX2QRY(elemento), getY2QRY(elemento), saida);
        }
        if (def.tipo == 'j'){
            imprimeCirculoVerde(getXQRY(elemento), getYQRY(elemento),getRaioQRY(elemento), saida);
        }
        node = getNext(node);
    }
}



void imprimeArea(double x, double y,double w, double h,double area, char saida[]){
    double textX, textY;

    textX = x + (w/2);
    textY = y + (h/2);

    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL){
        printf("Erro ao abrir SVG!");
        exit(1);
    }
    
    fprintf(arq, "\t<text x=\"%lf\" y=\"%lf\">%lf</text>", textX, textY, area);

    fclose(arq);
}

void imprimeLinha(double x, double y, char cep[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\" stroke=\"black\" stroke-width=\"2\"/>\n", x, y, x);
    x = x + 2;
    fprintf(arq, "\t<text x=\"%lf\" y=\"10\">%s</text>", x, cep);

    fclose(arq);
}

void imprimeLinhaD(double x, double y, double area, char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\" stroke=\"black\" stroke-width=\"2\"/>\n", x, y, x);
    x = x + 2;
    fprintf(arq, "\t<text x=\"%lf\" y=\"10\">%lf</text>\n", x, area);

    fclose(arq);
}

void imprimeCirculoQry(double x, double y, double raio, char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"1.0px\"/>\n", x, y, raio);

    fclose(arq);
}

void imprimeRetT(double x, double y, double w, double h, char sw[], char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"%s\" stroke-dasharray=\"5\"/>\n", x, y, w, h, sw);

    fclose(arq);
}

void imprimeRet(double x, double y, double w, double h, char sw[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"%s\" />\n", x, y, w, h, sw);

    fclose(arq);
}