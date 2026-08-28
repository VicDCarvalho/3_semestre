#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA *maior(TNoA *no) {
    if(no->dir != NULL)
        return maior(no->dir);
    else
        return no;

}

TNoA *exclui(TNoA *raiz, int chave) {
    TNoA *aux=raiz, *pre=NULL, *filho=NULL;
    int dir=0, max;

    //percorrer a árvore de busca
    while(aux!=NULL && aux->chave != chave){
        if(aux-> chave > chave){
            pre = aux;
            aux = aux->esq;
            dir = 0;
        }else{
            pre = aux;
            aux = aux->dir;
            dir = 1;
        }
        
    }

    if(aux == NULL)
        return raiz;

    //caso folha
    if(aux->dir == NULL && aux->esq == NULL){
        if(aux == raiz){
            free(aux);
            return NULL;
        }else{
            if(dir){
                pre->dir = NULL;
            }else
                pre->esq = NULL;
            free(aux);
            return raiz;
        }
    }else{

    //caso 2 filhos
        if(aux->dir != NULL && aux->esq != NULL){
            max = (maior(aux->esq))->chave;
            aux->chave = max;
            aux->esq = exclui(aux->esq, max);
        }else{ //caso 1 filho
            if(aux == raiz) {
                if(aux->esq != NULL)
                    filho = aux->esq;
                else
                    filho = aux->dir;

                free(aux);
                return filho;

            }else{
                if(dir){
                    if(aux->dir == NULL)
                        pre->dir = aux->esq;
                    else
                        pre->dir = aux->dir;
                }else
                    if(aux->dir == NULL)
                        pre->esq = aux->esq;
                    else
                        pre->esq = aux->dir;
                free(aux);
                return raiz;
            }
        }
    
   return raiz;
    }
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a arvore
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    //le valor a ser excluido
    scanf("%d", &valor);
    //Chama função
    raiz = exclui(raiz, valor);
    imprime(raiz, 0);
};