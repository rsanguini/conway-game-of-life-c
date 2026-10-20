
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO 10

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

int main(void) {
    setlocale(LC_ALL, "");
    srand((unsigned int) time(NULL));

    int opcao;
    int tabuleiro[TAMANHO][TAMANHO];
    int proxima[TAMANHO][TAMANHO];

    exibirMenuInicial();

    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (opcao == 1) {
        inicializarTabuleiro(tabuleiro);
        imprimirTabuleiro(tabuleiro, 0);

        simularGeracao(tabuleiro, proxima);
        imprimirTabuleiro(proxima, 1);
    } else if (opcao == 0) {
        printf("Obrigado por jogar!\n");
    } else {
        printf("Opcao invalida.\n");
    }

    return 0;
}
