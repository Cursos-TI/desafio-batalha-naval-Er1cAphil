#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3
#define VAZIO 0
#define ATINGIDO 1

int tabuleiro[TAMANHO][TAMANHO];

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

void exibirTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int x, int y, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0) tabuleiro[x + i][y] = NAVIO; // Vertical
        else if (direcao == 1) tabuleiro[x][y + i] = NAVIO; // Horizontal
        else if (direcao == 2) tabuleiro[x + i][y + i] = NAVIO; // Diagonal principal
        else tabuleiro[x + i][y - i] = NAVIO; // Diagonal inversa
    }
}

void colocarNavios() {
    posicionarNavio(1, 1, 3, 0);
    posicionarNavio(4, 2, 4, 1);
    posicionarNavio(6, 3, 3, 2);
    posicionarNavio(2, 7, 4, 3);
}

void aplicarHabilidadeCruz(int x, int y) {
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[i][y] = ATINGIDO;
        tabuleiro[x][i] = ATINGIDO;
    }
}

void aplicarHabilidadeCone(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (x + i < TAMANHO && y + j >= 0 && y + j < TAMANHO)
                tabuleiro[x + i][y + j] = ATINGIDO;
        }
    }
}

void aplicarHabilidadeOctaedro(int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2 && x + i >= 0 && x + i < TAMANHO && y + j >= 0 && y + j < TAMANHO)
                tabuleiro[x + i][y + j] = ATINGIDO;
        }
    }
}

int main() {
    srand(time(NULL));
    inicializarTabuleiro();
    colocarNavios();
    
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro();
    
    printf("\nAplicando Habilidade Cruz (5,5):\n");
    aplicarHabilidadeCruz(5, 5);
    exibirTabuleiro();
    
    printf("\nAplicando Habilidade Cone (2,2):\n");
    aplicarHabilidadeCone(2, 2);
    exibirTabuleiro();
    
    printf("\nAplicando Habilidade Octaedro (7,7):\n");
    aplicarHabilidadeOctaedro(7, 7);
    exibirTabuleiro();
    
    return 0;
}