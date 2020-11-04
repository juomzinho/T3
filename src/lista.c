#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include "resolveQry.h"
#include "posto.h"

typedef struct node{
    Info info;
    struct node *anterior;
    struct node *proximo;
} NoStruct;

typedef struct lista{
    NoStruct *primeiro;
    NoStruct *ultimo;
} ListaStruct;


Lista create(){

    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;

};

void insere(Lista l, Info info){

    ListaStruct* lista = (ListaStruct*) l;

    NoStruct* no = (NoStruct*) malloc(sizeof(NoStruct));
    no->info = info;

    if(lista->primeiro == NULL){
        no->anterior = NULL;
        lista->primeiro = no;
    }
    else{
        lista->ultimo->proximo = no;
        no->anterior = lista->ultimo;
    }

    no->proximo = NULL;
    lista->ultimo = no;
    
}


void insertAfter(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            no->proximo = aux->proximo;
            no->anterior = aux;
            aux->proximo = no;
        }
        aux = getNext(aux);
    }
    
}


void insertBefore(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            no->proximo = aux;
            no->anterior = aux->anterior;
            aux->anterior = no;
            if (no->anterior == NULL){
                lista->primeiro = no;
            }else{
                no->anterior->proximo = no;
            }
                 
        }
        aux = aux->proximo;
    }
}

int length(Lista l){
    No node = getFirst(l);
    int i = 0; 

    while (node!=NULL){
        i++;
        node = getNext(node);
    }
    
    return i;
}


No getFirst(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->primeiro;
}

No getLast(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->ultimo;
}

No getNext(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->proximo;
}

No getPrevious(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->anterior;
}

Info getInfo(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->info;
}

void desalocaLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;

    aux = lista->primeiro;

    while (aux!=NULL){
        aux2 = aux->proximo;
        free(aux->info);
        free(aux);
        aux = aux2;
    }   
}

void removeElemento(Lista l, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->info == info){
            if (aux==lista->primeiro){
                lista->primeiro = aux->proximo;
                lista->primeiro->anterior = NULL;
            }
            if(aux==lista->ultimo){
                lista->ultimo = aux->anterior;
                lista->ultimo->proximo = NULL;
            }

            aux2 = aux->proximo;
            aux2->anterior = aux->anterior;

            if(aux->anterior!=NULL){
                aux->anterior->proximo = aux2;
            }
            
            free(aux->info);
            free(aux);
            break;
         }
        aux = aux->proximo;
    }  
}


void shellSort(Lista lista, int size, double x, double y){
	int h = size, i, j, k = 0;
    NoStruct *node, *aux, *aux2, *aux3, *aux4, aux5;
    ListaStruct* l = (ListaStruct*) lista;

    

	while (h > 0){

		for (i = h; i < size; i++){
			j = i - h;
            
            aux = getFirst(lista);
            for(k = 0; k < i; k++){
               aux = getNext(aux);
            }

            aux5.info = aux->info;

            node = getFirst(lista);
            for(k = 0; k < j; k++){
                node = getNext(node);
            }

            while (j>=0 && dist(x, y, getXPS(getInfo(aux)), getYPS(getInfo(aux))) < dist(x, y, getXPS(getInfo(node)), getYPS(getInfo(node)))){
                aux2 = getFirst(lista);
                for(k = 0; k < j + h; k++){
                    aux2 = getNext(aux2);
                }
                
                aux3 = getFirst(lista);
                for (k = 0; k < j; k++){
                    aux3 = getNext(aux3);
                }

                aux2->info = aux3->info;
                j -= h;
                

                node = getFirst(lista);
                for(k = 0; k < j; k++){
                    node = getNext(node);
                }
            }
            aux4 = getFirst(lista);
            for (k = 0; k < j + h; k++){
                aux4 = getNext(aux4);
            }
            aux4->info = aux5.info;
            
        }
        h /= 2;

	}
	
}

