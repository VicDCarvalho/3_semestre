#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    int info;
    struct no *direita;
    struct no *esquerda;
} tno;

void espelho(tno *raiz){
    tno *aux;
    if(aux!=NULL){
        aux = raiz->esquerda;
        raiz->esquerda = raiz->direita;
        raiz->direita = aux;
        espelho(raiz->esquerda);
        espelho(raiz->direita);
    }
}
