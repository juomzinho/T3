#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "covid.h"
#include "quadra.h"
#include "readqry.h"
#include "lista.h"
#include "cidade.h"
#include "resolveQry.h"
#include "posto.h"

typedef struct novas{
    char tipo, cep[20], sw[10], face;
    double x, y, x2, y2,w, h, area, raio;
    int n;
} structQry;

typedef struct cvStruct{
    double x, y;
    int n;
} CovidStruct;

int getNCovid(Info elemento){
    CovidStruct *covid = (CovidStruct*) elemento;
    return covid->n;
}

double getXCovid(Info elemento){
    CovidStruct *covid = (CovidStruct*) elemento;
    return covid->x;
}

double getYCovid(Info elemento){
    CovidStruct *covid = (CovidStruct*) elemento;
    return covid->y;
}


void criaTracejado(double x, double y, double x2, double y2, Lista lista){
    structQry *linha = (structQry *)malloc(sizeof(structQry));

    linha->x = x;
    linha->y = y;
    linha->x2 = x2;
    linha->y2 = y2;
    linha->tipo = 't';

    insere(lista, linha);
}

void criaQuadradoeN(Lista l, double x, double y,  int n){
    structQry *quadrado = (structQry *) malloc (sizeof(structQry));

    quadrado->x = x;
    quadrado->y = y;
    quadrado->n = n;
    quadrado->tipo = 'x';

    insere(l, quadrado);
}

void criaCirculoVerde(Lista l, double raio, double x, double y){
    structQry *circulo = (structQry *)malloc(sizeof(structQry));

    circulo->x = x;
    circulo->raio = raio;
    circulo->y = y;
    circulo->tipo = 'j';

    insere(l, circulo);
}

void criaQuadrado(Lista l, double x, double y){
    structQry *quadrado = (structQry *) malloc (sizeof(structQry));

    quadrado->x = x;
    quadrado->y = y;
    quadrado->tipo = 'q';

    insere(l, quadrado);
}

void criaPontoCovid(Lista lista, Lista listaQ, int n, char cep[], char face, int num){
    CovidStruct *covid = (CovidStruct*) malloc (sizeof(CovidStruct));
    No nodeQ = getFirst(listaQ);
    Info elemento;

    while (nodeQ != NULL){
        elemento = getInfo(nodeQ);

        if (strcmp(getCep(getInfo(nodeQ)),cep)==0){
            if (face == 'N'){
                covid->x = getXQ(elemento) + num;
                covid->y = getYQ(elemento) + getHQ(elemento);
                covid->n = n;        
            }
            if (face == 'O'){
                covid->x = getXQ(elemento) + getWQ(elemento);
                covid->y = getYQ(elemento)+num;
                covid->n = n;
            }
            if (face == 'L'){
                covid->n = getXQ(elemento);
                covid->y = getYQ(elemento) + num;
                covid->n = n;
            }
            if (face == 'S'){
                covid->x = getXQ(elemento) + num;
                covid->y = getYQ(elemento);
                covid->n = n;
            }
        }
        nodeQ = getNext(nodeQ);
    }

    insere(lista, covid);

}

void imprimeQuadrado(double x, double y, int n, char saida[]){
    double textX, textY, w = 20, h = 20;

    textX = x + 5;

    textY = y + 13;

    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL){
        printf("Erro ao abrir SVG!");
        exit(1);
    }
    
    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"orange\"/>\n", x, y, w, h);
    fprintf(arq, "\t<text x=\"%lf\" y=\"%lf\" fill=\"white\" stroke=\"none\">%d</text>", textX, textY, n);

    fclose(arq);
}

void imprimeQuadradoAzul(double x, double y, char saida[]){

    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL){
        printf("Erro ao abrir SVG!");
        exit(1);
    }
    
    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"20\" height=\"20\" fill=\"blue\" stroke=\"white\" strokeWidth=\"1.0px\"/>\n", x, y);
    fclose(arq);
}

void imprimeTracejado(double x, double y, double x2, double y2, char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" fill=\"white\" stroke-dasharray=\"5\"/>\n", x, y, x2, y2);

    fclose(arq);
}

void imprimeCirculoVerde(double x, double y, double raio, char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"none\" stroke=\"green\" stroke-width=\"5.0px\"/>\n", x, y, raio);

    fclose(arq);
}

void cv(Lista listaQuadra, Lista listaQRY, int n, char cep[], char face,int num){

    No node = getFirst(listaQuadra);

    while (node != NULL){
        Info elemento = getInfo(node);

        if(strcmp(getCep(elemento),cep)==0){
            
            if (face == 'N'){
                criaQuadradoeN(listaQRY, getXQ(elemento)+num, getYQ(elemento) + (getHQ(elemento)-20), n);        
            }
            if (face == 'O'){
                criaQuadradoeN(listaQRY, getXQ(elemento) + (getWQ(elemento) - 20), getYQ(elemento)+num, n);
            }
            if (face == 'L'){
                criaQuadradoeN(listaQRY, getXQ(elemento), getYQ(elemento)+num, n);
            }
            if (face == 'S'){
                criaQuadradoeN(listaQRY, getXQ(elemento)+num, getYQ(elemento), n);
            }
        }

        node = getNext(node);
    }    

}

void soc(Cidade cidade, int k, char cep[], char face, int num, char arqtxt[]){
    No node = getFirst(getListaQuadra(cidade)), nodePS = getFirst(getListaPS(cidade));
    Info elemento;
    int nPostos = 0;

    while (nodePS!=NULL){
        nPostos++;
        nodePS = getNext(nodePS);
    }

    FILE *txt;
    txt = fopen(arqtxt, "a");
    if(txt ==NULL){
        printf("erro ao abrir svg!\n");
        exit(0);
    }

    while (node != NULL){
        elemento = getInfo(node);
        if (strcmp(getCep(elemento),cep)==0){

            if (face == 'N'){
                criaQuadrado(getListaQRY(cidade), getXQ(elemento)+num-10, getYQ(elemento) + (getHQ(elemento)-20));    
                shellSort(getListaPS(cidade), length(getListaPS(cidade)),getXQ(elemento)+num, getYQ(elemento) + getHQ(elemento));
            }
            if (face == 'O'){
                criaQuadrado(getListaQRY(cidade), getXQ(elemento) + (getWQ(elemento) - 20), getYQ(elemento)+num - 10);
                shellSort(getListaPS(cidade), length(getListaPS(cidade)), getXQ(elemento) + getWQ(elemento), getYQ(elemento)+num);
            }
            if (face == 'L'){
                criaQuadrado(getListaQRY(cidade), getXQ(elemento), getYQ(elemento)+num-10);
                shellSort(getListaPS(cidade), length(getListaPS(cidade)), getXQ(elemento), getYQ(elemento)+num);
            }
            if (face == 'S'){
                criaQuadrado(getListaQRY(cidade), getXQ(elemento)+num-10, getYQ(elemento));
                shellSort(getListaPS(cidade), length(getListaPS(cidade)), getXQ(elemento)+num, getYQ(elemento));
            }
            nodePS = getFirst(getListaPS(cidade));

            if (nPostos!=0){
                for(int i = 0; i < k; i++){
                    if (i == nPostos){
                        break;
                    }
                    if (face == 'N'){
                        criaTracejado(getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)), getXQ(elemento)+num , getYQ(elemento) + getHQ(elemento), getListaQRY(cidade));
                    }
                    if (face == 'O'){
                        criaTracejado(getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)), getXQ(elemento) + getWQ(elemento), getYQ(elemento)+num, getListaQRY(cidade));
                    }
                    if (face == 'L'){
                        criaTracejado(getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)), getXQ(elemento), getYQ(elemento)+num, getListaQRY(cidade));
                    }
                    if (face == 'S'){
                        criaTracejado(getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)), getXQ(elemento)+num, getYQ(elemento), getListaQRY(cidade));
                    }
                    fprintf(txt,"\tx: %lf   y: %lf\n", getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)));
                    nodePS = getNext(nodePS);
                }
            }  
        }
        node = getNext(node);
    }
    fprintf(txt,"\n");
    fclose(txt);
}

void ci(Cidade listas, double x, double y, double raio){
    No nodePS = getFirst(getListaPS(listas)), nodeQ = getFirst(getListaQuadra(listas));
    Info elemento = getInfo(nodeQ);
    int size = length(getListaPS(listas));       

    // quickSort(getListaPS(listas), getXQ(elemento), getYQ(elemento), 0, size);

    criaCirculoVerde(getListaQRY(listas), raio, x, y);

    envoltoria(x, y, raio, getListaCovid(listas));

    // while (nodePS!=NULL){
    //     printf("%lf\n",dist(getXQ(elemento), getYQ(elemento), getXPS(getInfo(nodePS)),getYPS(getInfo(nodePS))));
    //     nodePS = getNext(nodePS);
    // }
    // printf("\n");

}

void envoltoria(double x, double y, double raio, Lista listaCovid){
    int NCasosNoCirc = 0;
    No nodeCovid = getFirst(listaCovid);
    Info elemento;

    shellSort(listaCovid, length(listaCovid), x, y);
    
    while (nodeCovid != NULL){   
        elemento = getInfo(nodeCovid);

        if (PontoInterno(getXCovid(elemento), getYCovid(elemento), x, y, raio) == true){
            NCasosNoCirc++;
        }        

        nodeCovid = getNext(nodeCovid);
    }
        
    
    // printf("%d\n", NCasosNoCirc);

}