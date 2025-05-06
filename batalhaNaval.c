#include <stdio.h>

#define LINHAS 10 // Número de linhas do tabuleiro
#define COLUNAS 10 // Número de colunas do tabuleiro
#define TAM_NAVIOS 3 // Tamanho dos navios

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0; // 0 representa a água
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIOS; i++) {
        if (orientacao == 0) { // Se for horizontal
            tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
        } else { // Se for vertical
            tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("Tabuleiro Batalha Naval:\n");
    // Laço para exibir o tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Exibe a água (0)
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Exibe o navio (3)
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Exibe a área afetada pela habilidade (5)
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int matrizCone[5][5] = {
        {0, 0, 1, 0, 0}, // Define a forma do cone
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Laços para aplicar a matriz do cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCone[i][j] == 1) { // Se for 1, marca como área afetada pela habilidade
                int linha = linhaOrigem + i - 2; // Ajusta a posição no tabuleiro
                int coluna = colunaOrigem + j - 2;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    tabuleiro[linha][coluna] = 5; // Marca como afetada
                }
            }
        }
    }
}

// Função para aplicar a habilidade Cruz no tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int matrizCruz[5][5] = {
        {0, 0, 1, 0, 0}, // Define a forma da cruz
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Laços para aplicar a matriz da cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCruz[i][j] == 1) { // Se for 1, marca como área afetada pela habilidade
                int linha = linhaOrigem + i - 2; // Ajusta a posição no tabuleiro
                int coluna = colunaOrigem + j - 2;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    tabuleiro[linha][coluna] = 5; // Marca como afetada
                }
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro no tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int matrizOctaedro[5][5] = {
        {0, 0, 1, 0, 0}, // Define a forma do octaedro
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Laços para aplicar a matriz do octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizOctaedro[i][j] == 1) { // Se for 1, marca como área afetada pela habilidade
                int linha = linhaOrigem + i - 2; // Ajusta a posição no tabuleiro
                int coluna = colunaOrigem + j - 2;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    tabuleiro[linha][coluna] = 5; // Marca como afetada
                }
            }
        }
    }
}

int main() {

    int tabuleiro[LINHAS][COLUNAS]; // Tabuleiro do jogo

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posicionando os navios no tabuleiro
    // Navio 1 horizontal (início na posição 2,4)
    posicionarNavio(tabuleiro, 2, 4, 0); 
    // Navio 2 vertical (início na posição 5,1)
    posicionarNavio(tabuleiro, 5, 1, 1);
    // Navio 3 diagonal (início na posição 0,0)
    posicionarNavio(tabuleiro, 0, 0, 0);
    // Navio 4 diagonal (início na posição 0,9)
    posicionarNavio(tabuleiro, 0, 9, 1);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 2, 4); // Aplica habilidade cone na posição (2,4)
    aplicarHabilidadeCruz(tabuleiro, 5, 5); // Aplica habilidade cruz na posição (5,5)
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7); // Aplica habilidade octaedro na posição (7,7)

    // Exibe o tabuleiro com as habilidades aplicadas
    exibirTabuleiro(tabuleiro);

    return 0;
}
