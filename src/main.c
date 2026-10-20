
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO 10
#define MAX_GERACOES 100

void exibirMenuInicial(void) {
    printf("\n========================================\n");
    printf("       JOGO DA VIDA DE CONWAY\n");
    printf("========================================\n");
    printf("\n[1] Iniciar jogo\n");
    printf("[0] Sair\n");
    printf("\nEscolha uma opcao: ");
}

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = rand() % 2;
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO],
                       int geracao) {
    printf("\n=== GERACAO %d ===\n\n", geracao);

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j] ? 'V' : '-');
        }
        printf("\n");
    }
}

int contarVizinhos(int tabuleiro[TAMANHO][TAMANHO],
                   int linha, int coluna) {
    int vivos = 0;

    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
            if (i == linha && j == coluna) {
                continue;
            }

            if (i >= 0 && i < TAMANHO &&
                j >= 0 && j < TAMANHO) {
                vivos += tabuleiro[i][j];
            }
        }
    }

    return vivos;
}

void simularGeracao(int atual[TAMANHO][TAMANHO],
                    int proxima[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int vizinhos = contarVizinhos(atual, i, j);

            if (atual[i][j] == 1) {
                proxima[i][j] =
                    (vizinhos == 2 || vizinhos == 3) ? 1 : 0;
            } else {
                proxima[i][j] = (vizinhos == 3) ? 1 : 0;
            }
        }
    }
}

void copiarTabuleiro(int origem[TAMANHO][TAMANHO],
                     int destino[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

void contarCelulas(int tabuleiro[TAMANHO][TAMANHO],
                   int *vivas, int *mortas) {
    *vivas = 0;
    *mortas = 0;

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 1) {
                (*vivas)++;
            } else {
                (*mortas)++;
            }
        }
    }
}

void exibirEstatisticas(int tabuleiro[TAMANHO][TAMANHO],
                        int geracao) {
    int vivas, mortas;

    contarCelulas(tabuleiro, &vivas, &mortas);

    printf("\nEstatisticas da geracao %d:\n", geracao);
    printf("Celulas vivas: %d\n", vivas);
    printf("Celulas mortas: %d\n", mortas);
}

void executarJogo(void) {
    int geracoes;
    int tabuleiro[TAMANHO][TAMANHO];
    int proxima[TAMANHO][TAMANHO];
    int historico[MAX_GERACOES + 1][TAMANHO][TAMANHO];

    printf("\nQuantas geracoes deseja simular (1 a %d)? ",
           MAX_GERACOES);

    if (scanf("%d", &geracoes) != 1 ||
        geracoes < 1 || geracoes > MAX_GERACOES) {
        printf("Quantidade de geracoes invalida.\n");
        return;
    }

    inicializarTabuleiro(tabuleiro);
    copiarTabuleiro(tabuleiro, historico[0]);

    for (int g = 1; g <= geracoes; g++) {
        simularGeracao(tabuleiro, proxima);
        copiarTabuleiro(proxima, tabuleiro);
        copiarTabuleiro(tabuleiro, historico[g]);
    }

    printf("\n========== HISTORICO ==========\n");

    for (int g = 0; g <= geracoes; g++) {
        imprimirTabuleiro(historico[g], g);
        exibirEstatisticas(historico[g], g);
    }
}

int main(void) {
    setlocale(LC_ALL, "");
    srand((unsigned int) time(NULL));

    int opcao;

    do {
        exibirMenuInicial();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Encerrando o programa.\n");
            return 1;
        }

        if (opcao == 1) {
            executarJogo();
        } else if (opcao == 0) {
            printf("\nObrigado por jogar!\n");
        } else {
            printf("\nOpcao invalida. Escolha 1 ou 0.\n");
        }

    } while (opcao != 0);

    return 0;
}
