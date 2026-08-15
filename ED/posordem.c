#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    int info;
    struct no *direita;
    struct no *esquerda;
    struct no *prox;
} tno;

tno *pop(tno **pilha){
    tno *retirado=*pilha;
    (*pilha) = (*pilha)->prox;

    return retirado;
}

void push(tno **pilha, tno *aux){
    aux->prox = (*pilha);
    (*pilha) = aux;

}

void posOrdem(tno *raiz){
    tno *pilha=NULL;
    tno *aux=raiz, *visitado=NULL;

    while(aux!=NULL || pilha != NULL){
        while(aux!=NULL){
            push(&pilha, aux);
            aux = aux->esquerda;
        }

        if(pilha->direita!=NULL && visitado!=pilha->direita)
            aux = pilha->direita;
        else{
            printf("%d ", pilha->info);
            visitado = pop(&pilha);
        }
    }
}