#include <stdio.h>

void imprime_arquivo(char *nomeArq){
    FILE *arq; //declara ponteiro para arquivo
    //abre arquivo para leitura
    arq = fopen(nomeArq, "r");
    if (arq != NULL){// checa se não deu erro na abertura do arquivo
        char s[10];
        fscanf(arq, "%s", s);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }
        fclose(arq); //fecha arquivo
    }
    else printf("Erro ao abrir arquivo\n");
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arq1, *arq2, *merge;

    arq1 = fopen(nomeArq1, "r");
    arq2 = fopen(nomeArq2, "r");
    merge = fopen(nomeArqMerge, "w");

    if(arq1 != NULL && arq2 != NULL && merge != NULL){
        char s1[10], s2[10];
        int i1, i2;

        int tem1 = fscanf(arq1, "%s", s1);
        int tem2 = fscanf(arq2, "%s", s2);

        if(tem1 == 1)
            i1 = atoi(s1);
        
        if(tem2 == 1)
            i2 = atoi(s2);

        while(tem1 == 1 &&  tem2 == 1){
            if(i1 < i2){
                fprintf(merge, "%s", s1);
                tem1 = fscanf(arq1, "%s", s1);

                if(tem1 == 1)
                    i1 = atoi(s1);
            }else{
                if(i2 < i1){
                    fprintf(merge, "%s", s2);
                    tem2 = fscanf(arq2, "%s", s2);

                    if(tem2 == 1)
                        i2 = atoi(s2);
                }else{
                    fprintf(merge, "%s", s1);
                    tem1 = fscanf(arq1, "%s", s1);
                    tem2 = fscanf(arq2, "%s", s2);

                    if(tem1 == 1)
                        i1 = atoi(s1);
                    if(tem2 == 1)
                        i2 = atoi(s2);
                }
            }
        }

        if(tem1 == 1){
            while (tem1 == 1){
                fprintf(merge, "%s", s1);
                tem1 = fscanf(arq1, "%s", s1);
            }
        }
        if(tem2 == 1){
            while(tem2 == 1){
                fprintf(merge, "%s", s2);
                tem2 = fscanf(arq2, "%s", s2);
            }
        }
        fclose(arq1);
        fclose(arq2);
        fclose(merge);
    }
        
}

int main(int argc, char **argv) {
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
    imprime_arquivo("merge.txt");
}