#include <stdio.h>
#include <stdlib.h>
#include "posto.h"
#include "lista.h"

typedef struct ps{
    double x, y;
} PSStruct;


void imprimePosto(double x, double y, int raio, char fill[], char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");

    if (arq==NULL){
        printf("Erro ao abrir SVG em Quadra!");
        exit(1);
    }

    fprintf(arq,"\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" fill=\"%s\" stroke=\"black\" strokeWidth=\"2.0px\" />", x,y,raio,fill);
    fprintf(arq, "\n\t<text x=\"%lf\" y=\"%lf\" fill=\"white\" >+</text>", x-(raio/2) , y+raio/2);
    fclose(arq);    
}


void postoLista(Lista lista, double x, double y){
    PSStruct* posto = (PSStruct*) malloc(sizeof(PSStruct));

    posto->x = x;
    posto->y = y;

    insere(lista, posto);
}

double getXPS(Info elemento){
    PSStruct* posto = (PSStruct*) elemento;
    return posto->x;
}

double getYPS(Info elemento){
    PSStruct* posto = (PSStruct*) elemento;
    return posto->y;
}

void imprimeListaPS(Lista l, char saida[]){
    No node = getFirst(l);
    Info elemento;
    PSStruct def;


    while (node != NULL){
        elemento = getInfo(node);

        def.x = getXPS(elemento);
        def.y = getYPS(elemento);
        imprimePosto(def.x, def.y, 6, "red", saida);

        node = getNext(node);
    }
    

}

