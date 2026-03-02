#include <stdio.h>

#define TAM 10

int main() {

    int tabuleiro[TAM][TAM] = {0};

    for(int i=0; i<3; i++) {
        tabuleiro[2][i+1] = 3;
        tabuleiro[i+5][8] = 3; 
        tabuleiro[i][i] = 3;
        tabuleiro[i+7][2-i] = 3;
    }

    int linhaCone = 2, colCone = 5;
    for (int i = 0; i < 3; i++) { 
        for (int j = colCone - i; j <= colCone + i; j++) {
            if (linhaCone + i < TAM && j >= 0 && j < TAM) {
                if (tabuleiro[linhaCone + i][j] == 0) tabuleiro[linhaCone + i][j] = 5;
            }
        }
    }

    int lC = 8, cC = 4;
    for (int i = 0; i < 5; i++) {
        if (tabuleiro[lC][cC-2+i] == 0) tabuleiro[lC][cC-2+i] = 5; 
        if (tabuleiro[lC-2+i][cC] == 0) tabuleiro[lC-2+i][cC] = 5; 
    }

    printf("TABULEIRO DE BATALHA NAVAL:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}