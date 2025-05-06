#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

int main ()
{

    int tabuleiro[10][10]; // Representação do meu tabuleiro usando matriz (array bidimensional)

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Iniciei a matriz valendo 0 (0 = água)
        }
    }
    
    // Criando dois navios usando vetores de tamanho 3

    int navio1[3] = {3, 3, 3}; // Posição horizontal
    int navio2[3] = {3, 3, 3}; // Posição vertical

    // Posicionar o navio1 horizontalmente começando da posição (2, 4)

    for (int i = 0; i < 3; i++) {
        tabuleiro[2][4 + i] = navio1[i];
    }

    // Posicionar o navio2 verticalmente começando da posição (5, 1)

    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][1] = navio2[i];
    }

    // Exibir o tabuleiro

    printf("Tabuleiro Batalha Naval:\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
