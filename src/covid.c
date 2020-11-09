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

typedef struct envStruct{
    double x, y;
}EnvoltoriaStruct;


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

void criaEnvoltoria(double x, double y, Lista lista){
    EnvoltoriaStruct *envolt = (EnvoltoriaStruct* ) malloc (sizeof(EnvoltoriaStruct));

    envolt->x = x;
    envolt->y = y;

    insere(lista, envolt);

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


void  criaPontoCovid(Lista lista, double x, double y, int n){
    CovidStruct *covid = (CovidStruct*) malloc (sizeof(CovidStruct));
    
    covid->x = x;
    covid->y = y;
    covid->n = n;

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

void imprimeEnvoltoria(Lista lista, char fill[], char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    No node = getFirst(lista);

    fprintf(arq,"\n\t<polygon points=\"");
    for (int i = 0; i < length(lista); i++){
        fprintf(arq,"%lf,%lf ", getXCovid(getInfo(node)), getYCovid(getInfo(node)));
        node = getNext(node);
    }
    fprintf(arq, "\" fill=\"#%s\" stroke=\"red\" stroke-width=\"5px\" opacity=\"0.5\"/>",fill);
    
    fclose(arq);
}

void cv(Lista listaCovid, Lista listaQuadra, Lista listaQRY, int n, char cep[], char face,int num){
    double x, y;
    
    No node = getFirst(listaQuadra);

    while (node != NULL){
        Info elemento = getInfo(node);

        if(strcmp(getCep(elemento),cep)==0){
            
            if (face == 'N'){
                x = getXQ(elemento)+num;
                y = getYQ(elemento) + (getHQ(elemento)-20);
                criaQuadradoeN(listaQRY, getXQ(elemento)+num, getYQ(elemento) + (getHQ(elemento)-20), n);        
            }
            if (face == 'O'){
                x = getXQ(elemento)+ (getWQ(elemento) - 20);
                y = getYQ(elemento) + num;
                criaQuadradoeN(listaQRY, getXQ(elemento) + (getWQ(elemento) - 20), getYQ(elemento)+num, n);
            }
            if (face == 'L'){
                x = getXQ(elemento);
                y = getYQ(elemento) + num;
                criaQuadradoeN(listaQRY, getXQ(elemento), getYQ(elemento)+num, n);
            }
            if (face == 'S'){
                x = getXQ(elemento) + num;
                y = getYQ(elemento);
                criaQuadradoeN(listaQRY, getXQ(elemento)+num, getYQ(elemento), n);
            }
            break;
        }

        node = getNext(node);
    } 
    criaPontoCovid(listaCovid, x, y, n);   
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
            break;
        }
        node = getNext(node);
    }
    fprintf(txt,"\n");
    fclose(txt);
}

void ci(Cidade listas, double x, double y, double raio, char *categoria, char arqtxt[]){
    No nodePS = getFirst(getListaPS(listas)), nodeQ = getFirst(getListaQuadra(listas)), aux;
    Info elemento = getInfo(nodeQ);
    int size = length(getListaPS(listas)), NPostos = 0, NCasos = 0;
    double casos, area;
    char incidencia[20];

    FILE *txt;
    txt = fopen(arqtxt, "a");       

    criaCirculoVerde(getListaQRY(listas), raio, x, y);

    envoltoria(x, y, raio, getListaCovid(listas), getListaPS(listas), getListaEnvoltoria(listas), getListaPontosCovid(listas));
   
    casos = (cidadeD(listas) / 1000000);
    casos = casos * areaConvexa(getListaEnvoltoria(listas));

    if ( getListaEnvoltoria(listas) != NULL){    
        if (casos < 0.1){
            strcpy(categoria,"00FFFF"); strcpy(incidencia,"Livre de Covid");
        }if(casos < 5){
            strcpy(categoria,"008080"); strcpy(incidencia,"Baixa incidência");
        }if(casos < 10){
            strcpy(categoria,"FFFF00"); strcpy(incidencia,"Média incidência");
        }if(casos < 20){
            strcpy(categoria,"FF0000"); strcpy(incidencia,"Alta incidência");
        }if(casos >= 20){
            strcpy(categoria,"800080"); strcpy(incidencia,"Catastrófico");
            nodePS = getFirst(getListaPS(listas));
            while(nodePS!=NULL){
                if (PontoInterno(getXPS(getInfo(nodePS)), getYPS(getInfo(nodePS)), x, y, raio) == true){
                    NPostos++;
                }
                nodePS = getNext(nodePS);
            }
            if (NPostos == 0){
                printf("true\n");
                postoLista(getListaPS(listas), centroideX(getListaEnvoltoria(listas)), centroideY(getListaEnvoltoria(listas)));
            }
        }

        aux = getFirst(getListaPontosCovid(listas));
        while(aux!=NULL){
            fprintf(txt,"CEP x: %lf y: %lf\n", getXCovid(getInfo(aux)), getYCovid(getInfo(aux)));
            aux = getNext(aux);
        }
        aux = getFirst(getListaPontosCovid(listas));
        while(aux!=NULL){
            NCasos += getNCovid(getInfo(aux));
            aux = getNext(aux);
        }
        fprintf(txt,"Total de Casos: %d\nÁrea: %lf\nIncidencia: %s\n\n", NCasos, areaConvexa(getListaEnvoltoria(listas)), incidencia);
    }

    fclose(txt);
}

void envoltoria(double x, double y, double raio, Lista listaCovid, Lista listaPS, Lista listaEnvoltoria, Lista listaPCovid){
    No nodeCovid = getFirst(listaCovid), *aux, *aux2, *aux3;
    Info d1, d2;
    int NPontos = 0, min = 0;
    bool v = false;

    while(nodeCovid!=NULL){
        if (PontoInterno(getXCovid(getInfo(nodeCovid)), getYCovid(getInfo(nodeCovid)), x, y, raio) == true){
            NPontos++;
            criaPontoCovid(listaPCovid, getXCovid(getInfo(nodeCovid)), getYCovid(getInfo(nodeCovid)), getNCovid(getInfo(nodeCovid)));
        }        
        nodeCovid = getNext(nodeCovid);
    }

    if (NPontos < 3){
        return;
    }

    aux = getFirst(listaPCovid);
    d1 = getInfo(aux);


    for (int i = 0; i < NPontos; i++){
        aux2 = getFirst(listaPCovid);
        for (int k = 0; k < i; k++){
            aux2 = getNext(aux2);
        }
        d2 = getInfo(aux2);

        if ((getYCovid(d2) < getYCovid(d1)) || getYCovid(d2) == getYCovid(d1) && getXCovid(d2) < getXCovid(d1))        {
            aux = aux2;
            d1 = getInfo(aux);
            min = i;
        } 
    }

    swap(listaPCovid, min);
    quickSort(listaPCovid, 0, length(listaPCovid));
    
    for (int i = 0; i < 3; i++){
        aux = getFirst(listaPCovid);
        for (int k = 0; k < i; k++){
            aux = getNext(aux);
        }      

       criaEnvoltoria(getXCovid(getInfo(aux)), getYCovid(getInfo(aux)), listaEnvoltoria);
    }


    for (int i = 3; i < length(listaPCovid); i++){
        aux = getFirst(listaPCovid);
        for (int k = 0; k < i; k++){
            aux = getNext(aux);
        }  
        aux2 = getLast(listaEnvoltoria);
        aux3 = getPrevious(aux2);

        while (orient(getInfo(aux3),getInfo(aux2), getInfo(aux)) != 2){
            removeElemento(listaEnvoltoria, getInfo(getLast(listaEnvoltoria)));
            aux2 = getLast(listaEnvoltoria);
            aux3 = getPrevious(aux2);
        }

        criaEnvoltoria(getXCovid(getInfo(aux)), getYCovid(getInfo(aux)), listaEnvoltoria);
    }
}

int compare(Info a, Info b, Info c){
    CovidStruct* p0 = (CovidStruct*) a;
    CovidStruct* p2 = (CovidStruct*) b;
    CovidStruct* p3 = (CovidStruct*) c; 

    int o = orient(p0, p2 , p3), distancia = 0;
    if (o == 0){
       if (dist(getXCovid(p0) , getYCovid(p0), getXCovid(p3), getYCovid(p3)) >= dist(getXCovid(p0) , getYCovid(p0), getXCovid(p2), getYCovid(p2))){
           distancia = 1;
       }

       if (distancia == 1){
           return -1;
       }else{
           return 1;
       }       
    }if(o == 2){
        return-1;
    }else{
        return 1;
    }
}

int orient(Info a, Info b, Info c){
    CovidStruct* p0 = (CovidStruct*) a;
    CovidStruct* p2 = (CovidStruct*) b;
    CovidStruct* p3 = (CovidStruct*) c; 


    double val =  (getYCovid(p2) - getYCovid(p0)) * ( getXCovid(p3) - getXCovid(p2)) - (getXCovid(p2) - getXCovid(p0)) * (getYCovid(p3) - getYCovid(p2));

    if (val == 0){
        return 0;
    }if(val > 0){
        return 1;
    }
    return 2;
    
}

double areaConvexa(Lista lista){
    double area = 0;
    No *aux;

    for (int i = 0; i < length(lista) - 1; i++){
        aux = getFirst(lista);
        for (int k = 0; k < i; k++){
            aux = getNext(aux); 
        }
        area += (getXCovid(getInfo(aux)) * getYCovid(getInfo(getNext(aux))) - getXCovid(getInfo(getNext(aux))) * getYCovid(getInfo(aux)));
    }
    
    area /= 2;

    return area;

}

double centroideX(Lista lista){
    double cx = 0;
    No *aux;

    for(int i = 0; i < length(lista) - 1; i++){
        aux = getFirst(lista);
        for (int k = 0; k < i; k++){
            aux = getNext(aux); 
        }
        Info elemento = getInfo(aux);  
        
        cx += ((getXCovid(elemento) + getXCovid(getInfo(getNext(aux)))) * (getXCovid(elemento) * getYCovid(getInfo(getNext(aux))) - getXCovid(getInfo(getNext(aux))) * getYCovid(elemento)));        
    }

    cx /= (6*areaConvexa(lista));


    return cx;
}

double centroideY(Lista lista){
    double cy = 0;
    No *aux, *aux2;

    for(int i = 0; i < length(lista); i++){

        if(i == length(lista)-1){
            aux = getFirst(lista);
            for (int k = 0; k < i; k++){
                aux = getNext(aux);
            }
            aux2 = getFirst(lista);
            Info elemento = getInfo(aux), elemento2 = getInfo(aux2); 

            cy += ((getYCovid(elemento) + getYCovid(elemento2)) * (getXCovid(elemento) * getYCovid(elemento2) - getXCovid(elemento2) * getYCovid(elemento)));
        }else{
            aux = getFirst(lista);
            for (int k = 0; k < i; k++){
                aux = getNext(aux);
            }
            aux2 = getFirst(lista);
            Info elemento = getInfo(aux); 

            cy += ((getYCovid(elemento) + getYCovid(getInfo(getNext(aux)))) * (getXCovid(elemento) * getYCovid(getInfo(getNext(aux))) - getXCovid(getInfo(getNext(aux)))* getYCovid(elemento)));
        }        
    }

    cy /= (6*areaConvexa(lista));

    return cy;
}