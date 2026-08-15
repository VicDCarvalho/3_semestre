#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    int info;
    struct no *direita;
    struct no *esquerda;
} tno;

int altura(tno *raiz){
    int cont=0;
    tno *altura_direita, *altura_esquerda;

    if(raiz==NULL)
        return 0;
    else{
        altura_esquerda = altura(raiz->esquerda);
        altura_direita = altura(raiz->direita);

        if(altura_direita > altura_esquerda)
            return altura_direita + 1;
        else
            return altura_esquerda + 1;
    }
    
}

int cheia(tno *raiz,int nivel, int alt){

    if(raiz==NULL)
        return 1;
    
    if(raiz->esquerda == NULL && raiz->direita == NULL)
        if(alt == nivel)
            return 1;
        else
            return 0;
    
    if(raiz->esquerda == NULL || raiz->direita == NULL)
        return 0;
    
    return cheia(raiz->direita, nivel+1, alt) && cheia(raiz->esquerda, nivel+1, alt);
}