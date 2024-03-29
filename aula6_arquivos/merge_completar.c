#include <stdio.h>
#include <stdlib.h>

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arq1, *arq2, *arq_merge;

    //abre os 2 arquivos numeros em modo leitura
    /*FAZER CODIGO AQUI*/
    arq1 = fopen("numeros1.txt", "r");
    arq2 = fopen("numeros2.txt", "r");
    //abrir o arquivo de merge em modo escrita
    /*FAZER CODIGO AQUI*/
    arq_merge = fopen("merge.txt", "w");
    //um numero de cada arquivo
    int n1, n2;
    //Testa se abriu tudo com sucesso
    if (arq1 != NULL && arq2 != NULL && arq_merge != NULL) {
        //le o primeiro numero de cada arquivo
        fscanf(arq1, "%d", &n1);
        fscanf(arq2, "%d", &n2);

        while (!feof(arq1) && !feof(arq2)) {
            if (n1 < n2) {
                //salva o n1 no arquivo merge
                //lê o proximo número do arq1
                fprintf(arq_merge, "%d\n", n1);
                fscanf(arq1, "%d", &n1);
            } else {
                if (n2 < n1) {
                    //salva o n2 no arquivo merge
                    fprintf(arq_merge, "%d\n", n2);
                    //lê o proximo número do arq2
                    fscanf(arq2, "%d", &n2);
                } else {
                    //sao iguais - grava um e avança ambos
                    fprintf(arq_merge, "%d\n", n1);
                    fscanf(arq1, "%d", &n1);
                    fscanf(arq2, "%d", &n2);
                }
            }
        }
        //trata caso de um arquivo terminar antes do outro
        //grava arq1 até terminar
        while (!feof(arq1)) {
            fprintf(arq_merge, "%d\n", n1);
            fscanf(arq1, "%d", &n1);
        }
        //grava arq 2 até terminar
        while (!feof(arq2)) {
            fprintf(arq_merge, "%d\n", n2);
            fscanf(arq2, "%d", &n2);
        }
        //Fechar todos os arquivos
        /*FAZER CODIGO AQUI*/
        fclose(arq1);
        fclose(arq2);
        fclose(arq_merge);
    } else printf("Erro ao abrir arquivos");
}

/*Gera um arquivo txt com números ordenados.*/
void grava_arquivo_strings(char *nomeArq, int inicio, int fim, int incremento) {
    FILE *arq; //declara ponteiro para arquivo

    //abre arquivo para gravação
    arq = fopen(nomeArq, "w");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char s[12];
        for (int i = inicio; i < fim; i += incremento) {
            sprintf(s, "%d", i); //transforma int em string
            fprintf(arq, "%s\n", s); //grava no arquivo
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo\n");
    }
}

int main(int argc, char **argv) {
    grava_arquivo_strings("numeros1.txt", 10, 30, 3);
    grava_arquivo_strings("numeros2.txt", 8, 20, 2);
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
}
