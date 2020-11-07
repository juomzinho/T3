#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "resolveQry.h"
#include "cidade.h"
#include "svg.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "formas.h"
#include "radio.h"
#include "posto.h"
#include "covid.h"
#include "imprimeQRY.h"

struct Default{
    double x, y, w, h, r;
    char cstrk[20], cep[20], id[20], verifica[20], face;
    int j, k, n, num;
};

void leituraQRY(char saida[] , char arquivotxt[],char qry[], Cidade cidade){
    char comando[5];
    struct Default def;
    bool verifica;

    /* Abertura arquivo qry */

    FILE *arq;
    arq = fopen(qry,"r");
    if(arq==NULL){
        printf("Erro ao abrir qry!!");
        exit(1);
    }


    while (!feof(arq)){
        verifica = false;

        fscanf(arq,"%s",comando);

        /* QRY CEP E EQUIPAMENTOS URBANOS */

        if(strcmp("car",comando)==0){
            fscanf(arq,"%lf %lf %lf %lf",&def.x, &def.y, &def.w, &def.h);
            car(cidade, def.x, def.y, def.w, def.h, arquivotxt);
        }

        if(strcmp("crd?",comando)==0){
            fscanf(arq,"%s",def.id);    
            crd(cidade, def.id, arquivotxt);
        }

        if(strcmp("cbq",comando)==0){
            fscanf(arq,"%lf %lf %lf %s", &def.x, &def.y, &def.r, def.cstrk);
            cbq(cidade, def.x, def.y, def.r, def.cstrk, arquivotxt);
        }

        if(strcmp("del",comando)==0){
            fscanf(arq,"%s",def.id);
            del(cidade, def.id, arquivotxt);
        }

        if(strcmp("dq",comando)==0){
            fscanf(arq,"%s",def.verifica);
            if(strcmp("#",def.verifica)==0){
                fscanf(arq,"%s %lf",def.id, &def.r);
                verifica = true;
                dq(cidade, def.id, def.r, verifica, arquivotxt);
            }
            else{
                fscanf(arq,"%lf",&def.r);
                verifica = false;
                dq(cidade, def.verifica, def.r, verifica, arquivotxt);
            }
        }

        if(strcmp("cv",comando)==0){
            fscanf(arq,"%d %s %c %d", &def.n, def.cep, &def.face, &def.num);
            cv(getListaQuadra(cidade), getListaQRY(cidade), def.n, def.cep, def.face, def.num);
            criaPontoCovid(getListaCovid(cidade), getListaQuadra(cidade), def.n, def.cep, def.face, def.num);
        }

        if(strcmp("soc",comando)==0){
            fscanf(arq,"%d %s %c %d", &def.n, def.cep, &def.face, &def.num);
            soc(cidade, def.n, def.cep, def.face, def.num, arquivotxt);
        }

        if(strcmp("ci",comando)==0){
            fscanf(arq,"%lf %lf %lf", &def.x, &def.y, &def.r);
            ci(cidade,def.x, def.y, def.r);
        }

        /* QRY FORMAS */

        if(strcmp("o?",comando)==0){
            fscanf(arq,"%d %d", &def.j, &def.k);
            oFormas(def.j, def.k, getListaFormas(cidade), arquivotxt);
        }

        if(strcmp("i?",comando)==0){
            fscanf(arq,"%d %lf %lf", &def.j, &def.x, &def.y);
            iFormas(def.j, def.x, def.y, getListaFormas(cidade), arquivotxt);
        }

        if(strcmp("pnt",comando)==0){
            fscanf(arq,"%d %s %s", &def.j, def.cstrk, def.cep);
            pnt(def.j, def.cstrk, def.cep, getListaFormas(cidade), arquivotxt);
        }

        if(strcmp("pnt*",comando)==0){
            fscanf(arq,"%d %d %s %s", &def.j, &def.k, def.cstrk, def.cep);
            pntplus(def.j, def.k, def.cstrk, def.cep, getListaFormas(cidade), arquivotxt);
        }

        if(strcmp("delf",comando)==0){
            fscanf(arq,"%d", &def.j);
            delf(def.j, getListaFormas(cidade), arquivotxt);
        }

        strcpy(comando,"nada");
    }

    abrirSvg(saida);

    imprimeListaQ(getListaQuadra(cidade), saida);
    imprimeListaS(getListaSemaforo(cidade), saida);
    imprimeListaF(getListaFormas(cidade), saida);
    imprimeListaRB(getListaRadio(cidade), saida);
    imprimeListaH(getListaHidrante(cidade), saida);
    imprimeListaPS(getListaPS(cidade), saida);
    imprimeQry(getListaQRY(cidade), saida);

    fecharSvg(saida);

    fclose(arq);
}