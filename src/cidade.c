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
    Lista listaConvex;
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
    list->listaConvex = create();
    list->listaCovid = create();

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

Lista getListaConvexa(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaConvex;
}

Lista getListaCovid(Cidade listas){
    CidadeStruct* l = (CidadeStruct*) listas;
    return l->listaCovid;
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
    desalocaLista(list->listaConvex);
    desalocaLista(list->listaCovid);

    free(list->listaF);
    free(list->listaS);
    free(list->listaRB);
    free(list->listaH);
    free(list->listaQ);
    free(list->listaqry);
    free(list->listaPS);
    free(list->listaConvex);
    free(list->listaCovid);
    free(list);
}