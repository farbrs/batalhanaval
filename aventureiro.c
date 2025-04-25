#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
    int sobreposicao = 0;

    // Coordenadas dos navios
    int navio1Linha = 1; // Vertical
    int navio1Coluna = 2;

    int navio2Linha = 2; // Horizontal
    int navio2Coluna = 3;

    int navio3Linha = 3; // Diagonal normal (\)
    int navio3Coluna = 4;

    int navio4Linha = 0; // Diagonal invertida (/)
    int navio4Coluna = 9;

    // Verificação de limites (para evitar sair do tabuleiro)
    if (
        navio1Linha + tamanhoNavio > tamanhoTabuleiro ||
        navio2Coluna + tamanhoNavio > tamanhoTabuleiro ||
        navio3Linha + tamanhoNavio > tamanhoTabuleiro ||
        navio3Coluna + tamanhoNavio > tamanhoTabuleiro ||
        navio4Linha + tamanhoNavio > tamanhoTabuleiro ||
        navio4Coluna - (tamanhoNavio - 1) < 0
    ) {
        printf("ERRO! Um dos navios está fora dos limites do tabuleiro.\n");
        return 1;
    }

    // ---------------- Navio 1 (Vertical)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[navio1Linha + i][navio1Coluna] = 3;
    }

    // ---------------- Navio 2 (Horizontal)
    sobreposicao = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        int linha = navio2Linha;
        int coluna = navio2Coluna + i;
        if (tabuleiro[linha][coluna] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 1) {
        printf("ERRO! Navio 2 está sobrepondo outro navio.\n");
        return 1;
    } else {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[navio2Linha][navio2Coluna + i] = 3;
        }
    }

    // ---------------- Navio 3 (Diagonal normal - \)
    sobreposicao = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        int linha = navio3Linha + i;
        int coluna = navio3Coluna + i;
        if (tabuleiro[linha][coluna] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 1) {
        printf("ERRO! Navio 3 está sobrepondo outro navio.\n");
        return 1;
    } else {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[navio3Linha + i][navio3Coluna + i] = 3;
        }
    }

    // ---------------- Navio 4 (Diagonal invertida - /)
    sobreposicao = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        int linha = navio4Linha + i;
        int coluna = navio4Coluna - i;
        if (tabuleiro[linha][coluna] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 1) {
        printf("ERRO! Navio 4 está sobrepondo outro navio.\n");
        return 1;
    } else {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[navio4Linha + i][navio4Coluna - i] = 3;
        }
    }

    // ---------------- mostra tabuleiro final
    printf("\nTabuleiro final:\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
