#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

#define LINHAS 10 // Define o número de linhas da matriz
#define COLUNAS 10 //Define o número de colunas da matriz
#define TAM_NAVIOS 3 // Define o tamanho dos navios

int main ()
{

    int tabuleiro[LINHAS][COLUNAS]; // Representação do meu tabuleiro usando matriz (array bidimensional)

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0; // Iniciei a matriz valendo 0 (0 = água)
        }
    }
    
    // Criando quatros navios usando vetores de tamanho 3

    int navio1[TAM_NAVIOS] = {3, 3, 3}; // Posição horizontal
    int navio2[TAM_NAVIOS] = {3, 3, 3}; // Posição vertical
    int navio3[TAM_NAVIOS] = {3, 3, 3}; // Posição diagonal
    int navio4[TAM_NAVIOS] = {3, 3, 3}; // Posição diagonal

    // ----- POSICIONAMENTO DOS NAVIOS -----

    // Posicionar o navio1 horizontalmente começando da posição (2, 4)

    for (int i = 0; i < TAM_NAVIOS; i++)
    {
        tabuleiro[2][4 + i] = navio1[i];
    }

    // Posicionar o navio2 verticalmente começando da posição (5, 1)

    for (int i = 0; i < TAM_NAVIOS; i++)
    {
        tabuleiro[5 + i][1] = navio2[i];
    }

    // Posicionar o navio3 diagonal começando da posição (0, 0)

    for (int i = 0; i < TAM_NAVIOS; i++)
    {
        tabuleiro[0 + i][0 + i] = navio3[i];
    }
    
    // Posicionar o navio4 diagonal começando da posição (0,9)
    for (int i = 0; i < TAM_NAVIOS; i++)
    {
        tabuleiro[0 + i][9 - i] = navio4[i];
    }

    // Exibir o tabuleiro

    printf("Tabuleiro Batalha Naval:\n");

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}