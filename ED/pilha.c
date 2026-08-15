#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no{
    int info;
    struct no *prox;
};
typedef struct no tlista;

tlista *pop(tlista *L, int n){
    tlista *l=L;

    if(l!=NULL){
        if(l->info == n){
            L = l->prox;
            free(l);
        }else
            printf("Elemento não encontrado");

    }else
        printf("Lista Vazia");
    
    return(L);
}

tlista *push(tlista *L, int n){
    tlista *l=L, *novo;

    novo = (tlista*) malloc(sizeof(tlista));
    novo -> info = n;
    novo->prox = l;

    L = novo;

    return(L);

}

void imprime_lista(tlista *li) {
    tlista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

int main(void){
    tlista *L=NULL;
    int valor, quant, escolha, i;

    printf("Quantos elementos sua pilha terá inicialmente?");
    scanf("%d", &quant);

    for(i=0;i<quant;i++){
        scanf("%d", &valor);
        L = insere_fim(L, valor);
    }

    printf("Quer inserir(1) ou remover(2) um elemento?");
    scanf("%d", &escolha);

    if(escolha==1){
        scanf("%d", &valor);
        L = push(L, valor);
        imprime_lista(L);
    }
    if(escolha==2){
        scanf("%d", &valor);
        L = pop(L, valor);
        imprime_lista(L);
    }

    return 0;
}


