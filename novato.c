#include <stdio.h>


int main(){

    int tabuleiro[10][10] = {0};
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
    int sobreposicao = 0;

    int navioLinha = 1;
    int navioColuna = 2;
    int navio2Linha = 4;
    int navio2Coluna = 5;

    if(navioLinha + tamanhoNavio > tamanhoTabuleiro ||
        navioColuna > tamanhoTabuleiro ||
        navio2Linha + tamanhoNavio > tamanhoTabuleiro ||
        navio2Coluna > tamanhoTabuleiro){
            printf("ERRO, os navios são grandes demais");
            return 1;
        }

    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[navioLinha +i][navioColuna] = 3;
    }    

    for(int i = 0; i < tamanhoNavio; i++){
        int linha = navio2Linha; //linha vai sempre ser a mesma (porque o navio 2 é horizontal).
        int coluna = navio2Coluna +i; //coluna vai aumentando (+ i) pra ir olhando da esquerda pra direita.


        //"Se eu encontrar um 3 naquela posição, significa que já tem um navio ali!"
        if(tabuleiro[linha][coluna] == 3){
            sobreposicao = 1; //Aí a gente coloca sobreposicao = 1 pra marcar o erro.
            break;
        }
    }
    if(sobreposicao == 1){
        printf("Erro ja existe um navio no lugar!");
        return 1;
    } else {
        for (int i = 0; i < tamanhoNavio; i++){
            tabuleiro[navio2Linha][navio2Coluna +i] = 3;
        }
    }

    for(int i = 0; i < tamanhoTabuleiro; i++){
        for (int j = 0; j < tamanhoTabuleiro; j++){
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }








    return 0;
}