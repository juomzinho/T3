#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "cidade.h"

typedef struct cid{
    Lista listaQ;
    Lista listaS;
    Lista listaH;
    Lista listaRB;
    Lista listaF;
    Lista listaqry;
    Lista listaPS;
    Lista listaCovid;
    Lista listaPontosCovid;
    Lista listaEnvoltoria;
    double x, y, w, h, d;
} CidadeStruct;

Cidade iniciaCidade(){
    CidadeStruct *list;
    list = (CidadeStruct*) malloc(sizeof(CidadeStruct));

    list->listaF = create();
    list->listaS = create();
    list->listaRB = create();
    list->listaQ = create();
    list->listaH = create();
    list->listaqry = create();
    list->listaPS = create();
    list->listaEnvoltoria = create();
    list->listaCovid = create();
    list->listaPontosCovid = create();

    return list;
}

Cidade getListaHidrante(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaH;
}

Lista getListaQuadra(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaQ;
}

Lista getListaFormas(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaF;
}

Lista getListaSemaforo(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaS;
}

Lista getListaRadio(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaRB;
}

Lista getListaQRY(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaqry;
}

Lista getListaPS(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaPS;
}

Lista getListaEnvoltoria(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaEnvoltoria;
}

Lista getListaCovid(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaCovid;
}

Lista getListaPontosCovid(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaPontosCovid;
}

double cidadeX(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->x;
}

double cidadeY(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->y;
}

double cidadeW(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->w;
}

double cidadeH(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->h;
}

double cidadeD(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->d;
}

void DDCidade(double x, double y, double w, double h, double d, Cidade cidade){
    CidadeStruct* city = (CidadeStruct*) cidade;

    city->x = x;
    city->y = y;
    city->w = w;
    city->h = h;
    city->d = d;
}

void removeListas(Cidade cidade){
    CidadeStruct* list = (CidadeStruct*) cidade;

    desalocaLista(list->listaF);
    desalocaLista(list->listaH);
    desalocaLista(list->listaS);
    desalocaLista(list->listaRB);
    desalocaLista(list->listaQ);
    desalocaLista(list->listaqry);
    desalocaLista(list->listaPS);
    desalocaLista(list->listaEnvoltoria);
    desalocaLista(list->listaCovid);
    desalocaLista(list->listaPontosCovid);

    free(list->listaF);
    free(list->listaS);
    free(list->listaRB);
    free(list->listaH);
    free(list->listaQ);
    free(list->listaqry);
    free(list->listaPS);
    free(list->listaEnvoltoria);
    free(list->listaCovid);
    free(list->listaPontosCovid);
    free(list);
}