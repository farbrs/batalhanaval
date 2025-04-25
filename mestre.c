#include <stdio.h>

#define TAM 10              // Tamanho do tabuleiro (10x10)
#define TAM_HABILIDADE 5    // Tamanho das habilidades (5x5)

// Função que aplica a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    // Loop pra percorrer a matriz da habilidade
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Calcula onde essa parte da habilidade vai cair no tabuleiro real
            int linhaTab = origemLinha - 2 + i;
            int colunaTab = origemColuna - 2 + j;

            // Se tiver dentro do tabuleiro (evita acessar fora da matriz)
            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                // Se for parte ativa da habilidade e não tiver navio (valor 3)
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != 3) {
                    tabuleiro[linhaTab][colunaTab] = 5; // Marca como área afetada (usei 5)
                }
            }
        }
    }
}

// Só imprime o tabuleiro no terminal
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // Mostra cada célula
        }
        printf("\n"); // Quebra de linha pra parecer tabuleiro
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Começa tudo com água (zero)

    // Coloquei uns navios de exemplo com valor 3
    tabuleiro[2][3] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][3] = 3;

    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[3][6] = 3;

    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][7] = 3;

    // Criação do CONE (área de efeito em formato de triângulo)
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // A mágica aqui é que o cone começa no meio e vai abrindo aos poucos pra baixo
            if (i >= 2 && j >= 2 - (i - 2) && j <= 2 + (i - 2)) {
                cone[i][j] = 1; // Parte do cone
            } else {
                cone[i][j] = 0; // Fora do cone
            }
        }
    }

    // Criação da CRUZ (linha + coluna)
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
            // Centro e os braços da cruz recebem 1
        }
    }

    // Criação do OCTAEDRO (basicamente um losango simétrico)
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Se a soma das distâncias em X e Y for até 2, tá dentro do losango
            if ((i - 2 >= 0 ? i - 2 : 2 - i) + (j - 2 >= 0 ? j - 2 : 2 - j) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplica cada habilidade em um ponto do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 3);       // Cruz em (6,3)
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);   // Octaedro em (6,6)

    // Mostra o tabuleiro final com tudo aplicado
    imprimirTabuleiro(tabuleiro);

    return 0;
}
