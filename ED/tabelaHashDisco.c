#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "encadeamento_exterior.h"

#define M 7

void imprime_arquivos(char *nome_arquivo_hash, char *nome_arquivo_dados) {
    //Imprime arquivo de hash
    printf("TABELA HASH:\n");
    imprime_arquivo_hash(nome_arquivo_hash);

    //Imprime arquivo de dados
    printf("\nDADOS:\n");
    imprime_arquivo_dados(nome_arquivo_dados);
}

/* Executa busca em Arquivos por Encadeamento Exterior (Hash)
 * Assumir que ponteiro para proximo noh eh igual a -1 quando nao houver proximo noh
 * Ponteiros são lógicos (é preciso multiplicar pelo tamanho do registro para calcular o valor do deslocamento
 * Use a função tamanho_compartimento() e tamanho_cliente() dependendo do arquivo que está sendo manipulado
 *
 * Parametros:
 * cod_cli: chave do cliente que esta sendo buscado
 * nome_arquivo_hash: nome do arquivo que contem a tabela hash
 * nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
 * m: tamanho da tabela hash (a função de hash é h(x) = x mod m
 *
 * Retorna o endereco (lógico) onde o cliente foi encontrado, ou -1 se nao for encontrado
 */
int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int m) {
    FILE *arquivo_hash = fopen(nome_arquivo_hash, "rb");
    FILE *arquivo_dados = fopen(nome_arquivo_dados, "rb");

    int pos = cod_cli % m;
    int tamanhoComp = tamanho_compartimento();
    fseek(arquivo_hash, pos*tamanhoComp, SEEK_SET);

    TCompartimento *pont = le_compartimento(arquivo_hash);
    int pos_dados = pont->prox;
    if(pos_dados == -1)
        return -1;

    int tamClie = tamanho_cliente();
    fseek(arquivo_dados,pos_dados*tamClie,SEEK_SET);

    TCliente *initList = le_cliente(arquivo_dados);
    while(pos_dados != -1){

        if(initList->cod == cod_cli && initList->ocupado ==1)
            return pos_dados;
        else{
            if(initList->prox != -1){
                pos_dados = initList->prox;
                fseek(arquivo_dados,pos_dados*tamClie,SEEK_SET);
                initList = le_cliente(arquivo_dados);
            }else
                break;
        }
    }
    fclose(arquivo_dados);
    fclose(arquivo_hash);

    return -1;
}

int main() {
    /* Essa função gera a saída que é usada nos casos de teste. Ela NÃO DEVE SER MODIFICADA */
    int cod;
    int pont;

    //Descomente essa linha de código caso deseje imprimir o conteúdo dos arquivos de entrada para analisar
    //o comportamento da sua implementação
    //imprime_arquivos("tabHash.dat", "clientes.dat");

    //le chave a ser buscada
    scanf("%d", &cod);
    printf("REGISTROS ACESSADOS:\n");
    pont = busca(cod, "tabHash.dat", "clientes.dat", M);

    //Imprime resultado da função
    printf("RESULTADO: %d\n", pont);
}