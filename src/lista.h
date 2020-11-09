#ifndef _LISTA_H_
#define _LISTA_H_

typedef void* Lista;
typedef void* No;
typedef void* Info;

/* Esta funcao cria as listas utilizadas no projeto
ela nao recebe nenhum parametro, ela apenas retorna as listas
inicializadas */
Lista create();

/* Esta funcao insere elementos nas listas
ela recebe como parametro a lista e o elemento que sera adicionado na lista */
void insere(Lista l, Info info);

/* Esta funcao insere um elemento depois de outro elemento
   ela recebe como parametro a lista, o elemento que servirá
   de base para a inserção e o novo elemento */
void insertAfter(Lista l, Info posicao, Info info);

/* Esta funcao insere um elemento antes de outro elemento
   ela recebe como parametro a lista, o elemento que servirá
   de base para a inserção e o novo elemento */
void insertBefore(Lista l, Info posicao, Info info);

/* Esta funcao retorna a quantidade de elementos contidos em uma lista
para realizar esta tarefa ela recebe uma lista por parametro*/
int length(Lista l);

/* Esta funcao remove elementos nas listas
ela recebe como parametro a lista e o elemento que sera removido da lista */
void removeElemento(Lista l, Info info);

/* Esta funcao localiza e retorna o primeiro elemento contido na lista
ele recebe como parametro a lista
e retorna seu primeiro elemeno */  
No getFirst(Lista lista);

/* Esta funcao localiza e retorna o ultimo elemento contido na lista
ele recebe como parametro a lista
e retorna seu ultimo elemeno */  
No getLast(Lista lista);

/* Esta funcao localiza e retorna o promixo elemento contido na lista
ele recebe como parametro um elemento da lista
e retorna o elemeno sucessor ao recebido*/ 
No getNext(No elemento);

/* Esta funcao localiza e retorna o anterior elemento contido na lista
ele recebe como parametro um elemento da lista
e retorna o elemeno antecessor ao recebido*/ 
No getPrevious(No elemento);

/* Esta funcao retorna as informacoes um elemento da lista
ela recebe como parametro um elemento da lista
e retorna as informações deste elemento*/ 
No getInfo(No elemento);

/* Esta funcao desaloca uma lista da memoria
ela recebe a lista a ser desalocada por parametro */
void desalocaLista(Lista l);

/* Esta funcao ordena os pontos da lista baseada na distancia entre pontos
ela recebe uma lista, o tamanho da lista, e os pontos para calcular a distancia*/
void shellSort(Lista lista, int size, double x, double y);

/* coloca o ponto com menor y na primeira posicao da lista
ele recebe uma lista e o numero da posicao em que o elemento esta localizado*/
void swap(Lista lista, int min);

/* Esta funcao ordena os pontos da lista baseada no angulo polar
ela rebece uma lista, o valor do inicio e o tamanho maximo a ser percorrido*/
void quickSort(Lista lista, int inicio, int size);

#endif