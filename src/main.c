
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO 10

void exibirMenuInicial(void) {
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t       JOGO DA VIDA DE CONWAY\n");
    printf("\t\t========================================\n");

    printf("\n\t\tComo funciona o jogo?\n\n");
    printf("\t\tO Jogo da Vida de Conway e um automato\n");
    printf("\t\tcelular que simula a evolucao de celulas\n");
    printf("\t\tvivas e mortas em um tabuleiro.\n\n");

    printf("\t\tCada celula muda de estado conforme\n");
    printf("\t\tas regras e a quantidade de vizinhos.\n");

    printf("\n\t\t========================================\n");
    printf("\t\t             MENU PRINCIPAL\n");
    printf("\t\t========================================\n");

    printf("\n\t\t[1] Iniciar jogo");
    printf("\n\t\t[0] Sair");
    printf("\n\n\t\tEscolha uma opcao: ");
}

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = rand() % 2;
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "");

    int opcao;

    exibirMenuInicial();

    if (scanf("%d", &opcao) != 1) {
        printf("\nEntrada invalida.\n");
        return 1;
    }

    if (opcao == 1) {
        srand((unsigned int) time(NULL));

        int tabuleiro[TAMANHO][TAMANHO];

        inicializarTabuleiro(tabuleiro);

        printf("\nTabuleiro inicializado com sucesso!\n");
    } else if (opcao == 0) {
        printf("\nObrigado por conhecer o Jogo da Vida de Conway!\n");
    } else {
        printf("\nOpcao invalida.\n");
    }

    return 0;
}
