#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para a função sleep()
#include <locale.h>
#include <conio.h>

#define TAMANHO 10

// Fução para limpar a tela
void limparTela() {

        system("cls");

                }

// Fução para inicializar o tabuleiro com células vivas e mortas aleatórias
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = rand() % 2; // 0 ou 1 aleatório
        }
    }
}

void contarCelulas(int tabuleiro[TAMANHO][TAMANHO], int *vivas, int *mortas) {
    *vivas = 0;
    *mortas = 0;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 1)
                (*vivas)++;
            else
                (*mortas)++;
        }
    }
}

// Fução para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int geracao) {
    printf("\n=== GERACAO %d ===\n\n", geracao);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j] ? 'V' : '-'); // Usando V para vivo e - para morto
        }
        printf("\n");
    }
}

int historico[100][TAMANHO][TAMANHO];


// Fução para contar os vizinhos vivos de uma célula
int contarVizinhos(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    int vizinhos = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Ignora a própria célula

            int vizinhoLinha = linha + i;
            int vizinhoColuna = coluna + j;

            // Verifica se o vizinho está dentro dos limites do tabuleiro
            if (vizinhoLinha >= 0 && vizinhoLinha < TAMANHO &&
                vizinhoColuna >= 0 && vizinhoColuna < TAMANHO) {
                vizinhos += tabuleiro[vizinhoLinha][vizinhoColuna];
            }
        }
    }

    return vizinhos;
}

// Fução para simular uma geração
void simularGeracao(int tabuleiroAtual[TAMANHO][TAMANHO], int tabuleiroProximo[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int vizinhos = contarVizinhos(tabuleiroAtual, i, j);

            // Aplica as regras do Jogo da Vida
            if (tabuleiroAtual[i][j] == 1) {
                // Célula viva
                if (vizinhos == 2 || vizinhos == 3) {
                    tabuleiroProximo[i][j] = 1; // Sobrevive
                } else {
                    tabuleiroProximo[i][j] = 0; // Morre
                }
            } else {
                // Célula morta
                if (vizinhos == 3) {
                    tabuleiroProximo[i][j] = 1; // Nasce
                } else {
                    tabuleiroProximo[i][j] = 0; // Permanece morta
                }
            }
        }
    }
}

// Fução para copiar um tabuleiro para outro
void copiarTabuleiro(int origem[TAMANHO][TAMANHO], int destino[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}
int main() {

    setlocale(LC_CTYPE, "portuguese");

    int tabuleiroAtual[TAMANHO][TAMANHO];
    int tabuleiroProximo[TAMANHO][TAMANHO];
    int geracoes;
    int c, j;

    do{
    system("cls");
    printf("\n\t\t\t\t--SEJA BEM VINDO AO JOGO DAS CELULAS!!!!--");
    printf("\n\n\n\t\t\t\t\t\t |");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\n\n\t -Como funciona o jogo??");
    printf("\n\n\t\t-->Este jogo foi criado baseado no classico Jogo da Vida de Conway. Esse mini jogo e um automato celular, um sistema dinamico discreto, que simula a evolucao de um sistema de celulas vivas e mortas em uma grade bidimensional. Cada celula pode estar viva ou morta e seu estado na proxima geracao e determinado pelas celulas vizinhas, seguindo um conjunto de regras simples. \n\n\n");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\n\n\t -Voce deseja jogar???");
    printf("\n\n\t\t -->Digite (1) para comecar ou algo diferente de 1 para sair: ");
    scanf("%d",&c);
    if(c!=1)
    {
        system("cls");
        printf("\n\n\t\n\n\n \t\t\t\t\t\tOBRIGADO!!!");
    printf("\n\n\t\n\n\n \t\t ---->Reinicie o programa caso você queira jogar mais tarde!!\n\n\n\n\n\n\n");
        exit(0);
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiroAtual);

    // Pede ao usuário o número de gerações
    system("cls");
    printf("\n\n\n\t\tDigite o numero de geracoes para serem simuladas: ");
    scanf("%d", &geracoes);

    // Imprime a geraçâo inicial
    limparTela();
    imprimirTabuleiro(tabuleiroAtual, 0);
    sleep(2); // Pausa por 2 segundo

    // Simula cada geração
    for (int g = 1; g <= geracoes; g++) {
        simularGeracao(tabuleiroAtual, tabuleiroProximo);
        copiarTabuleiro(tabuleiroProximo, tabuleiroAtual);
        copiarTabuleiro(tabuleiroAtual, historico[g]);

        limparTela();
        imprimirTabuleiro(tabuleiroAtual, g);
        sleep(2); // Pausa por 2 segundo entre gerações
        }
        printf("\n\n\nPressione qualquer tecla para seguir");
        _getch();
        system ("cls");
        printf("\t\t\t\t\t\t=== TODAS AS GERACOES ===\n\n\n");
    for (int g = 0; g <= geracoes; g++) {
    imprimirTabuleiro(historico[g], g);
        }
    int vivas, mortas;
    contarCelulas(tabuleiroAtual, &vivas, &mortas);

    printf("\n\nResumo Final da ultima Geracao:");
    printf("\nCelulas vivas: %d", vivas);
    printf("\nCelulas mortas: %d\n", mortas);

    printf("\n\n\nPressione qualquer tecla para seguir");
    getch();
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\tFim de jogo!!");
    printf("\n\n\n\n\nPressione qualquer tecla para seguir");
    getch();
    system("cls");
    printf("\n\n\n\t\t\tDeseja jogar novamente?\n\n");
    printf("\n\t\t\tDigite 1 para jogar novamente ou outro numero para encerrar: ",j);
    scanf("%d",&j);
    system("cls");

    }while(j==1);

    printf("\n\n\n\t\t\tObrigado por jogar!\n\n\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para a função sleep()
#include <locale.h>
#include <conio.h>

#define TAMANHO 10

// Fução para limpar a tela
void limparTela() {

        system("cls");

                }

// Fução para inicializar o tabuleiro com células vivas e mortas aleatórias
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = rand() % 2; // 0 ou 1 aleatório
        }
    }
}

void contarCelulas(int tabuleiro[TAMANHO][TAMANHO], int *vivas, int *mortas) {
    *vivas = 0;
    *mortas = 0;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 1)
                (*vivas)++;
            else
                (*mortas)++;
        }
    }
}

// Fução para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int geracao) {
    printf("\n=== GERACAO %d ===\n\n", geracao);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j] ? 'V' : '-'); // Usando V para vivo e - para morto
        }
        printf("\n");
    }
}

int historico[100][TAMANHO][TAMANHO];


// Fução para contar os vizinhos vivos de uma célula
int contarVizinhos(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    int vizinhos = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Ignora a própria célula

            int vizinhoLinha = linha + i;
            int vizinhoColuna = coluna + j;

            // Verifica se o vizinho está dentro dos limites do tabuleiro
            if (vizinhoLinha >= 0 && vizinhoLinha < TAMANHO &&
                vizinhoColuna >= 0 && vizinhoColuna < TAMANHO) {
                vizinhos += tabuleiro[vizinhoLinha][vizinhoColuna];
            }
        }
    }

    return vizinhos;
}

// Fução para simular uma geração
void simularGeracao(int tabuleiroAtual[TAMANHO][TAMANHO], int tabuleiroProximo[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int vizinhos = contarVizinhos(tabuleiroAtual, i, j);

            // Aplica as regras do Jogo da Vida
            if (tabuleiroAtual[i][j] == 1) {
                // Célula viva
                if (vizinhos == 2 || vizinhos == 3) {
                    tabuleiroProximo[i][j] = 1; // Sobrevive
                } else {
                    tabuleiroProximo[i][j] = 0; // Morre
                }
            } else {
                // Célula morta
                if (vizinhos == 3) {
                    tabuleiroProximo[i][j] = 1; // Nasce
                } else {
                    tabuleiroProximo[i][j] = 0; // Permanece morta
                }
            }
        }
    }
}

// Fução para copiar um tabuleiro para outro
void copiarTabuleiro(int origem[TAMANHO][TAMANHO], int destino[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}
int main() {

    setlocale(LC_CTYPE, "portuguese");

    int tabuleiroAtual[TAMANHO][TAMANHO];
    int tabuleiroProximo[TAMANHO][TAMANHO];
    int geracoes;
    int c, j;

    do{
    system("cls");
    printf("\n\t\t\t\t--SEJA BEM VINDO AO JOGO DAS CELULAS!!!!--");
    printf("\n\n\n\t\t\t\t\t\t |");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\n\n\t -Como funciona o jogo??");
    printf("\n\n\t\t-->Este jogo foi criado baseado no classico Jogo da Vida de Conway. Esse mini jogo e um automato celular, um sistema dinamico discreto, que simula a evolucao de um sistema de celulas vivas e mortas em uma grade bidimensional. Cada celula pode estar viva ou morta e seu estado na proxima geracao e determinado pelas celulas vizinhas, seguindo um conjunto de regras simples. \n\n\n");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\t\t\t\t\t\t |");
    printf("\n\n\n\t -Voce deseja jogar???");
    printf("\n\n\t\t -->Digite (1) para comecar ou algo diferente de 1 para sair: ");
    scanf("%d",&c);
    if(c!=1)
    {
        system("cls");
        printf("\n\n\t\n\n\n \t\t\t\t\t\tOBRIGADO!!!");
    printf("\n\n\t\n\n\n \t\t ---->Reinicie o programa caso você queira jogar mais tarde!!\n\n\n\n\n\n\n");
        exit(0);
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiroAtual);

    // Pede ao usuário o número de gerações
    system("cls");
    printf("\n\n\n\t\tDigite o numero de geracoes para serem simuladas: ");
    scanf("%d", &geracoes);

    // Imprime a geraçâo inicial
    limparTela();
    imprimirTabuleiro(tabuleiroAtual, 0);
    sleep(2); // Pausa por 2 segundo

    // Simula cada geração
    for (int g = 1; g <= geracoes; g++) {
        simularGeracao(tabuleiroAtual, tabuleiroProximo);
        copiarTabuleiro(tabuleiroProximo, tabuleiroAtual);
        copiarTabuleiro(tabuleiroAtual, historico[g]);

        limparTela();
        imprimirTabuleiro(tabuleiroAtual, g);
        sleep(2); // Pausa por 2 segundo entre gerações
        }
        printf("\n\n\nPressione qualquer tecla para seguir");
        _getch();
        system ("cls");
        printf("\t\t\t\t\t\t=== TODAS AS GERACOES ===\n\n\n");
    for (int g = 0; g <= geracoes; g++) {
    imprimirTabuleiro(historico[g], g);
        }
    int vivas, mortas;
    contarCelulas(tabuleiroAtual, &vivas, &mortas);

    printf("\n\nResumo Final da ultima Geracao:");
    printf("\nCelulas vivas: %d", vivas);
    printf("\nCelulas mortas: %d\n", mortas);

    printf("\n\n\nPressione qualquer tecla para seguir");
    getch();
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\tFim de jogo!!");
    printf("\n\n\n\n\nPressione qualquer tecla para seguir");
    getch();
    system("cls");
    printf("\n\n\n\t\t\tDeseja jogar novamente?\n\n");
    printf("\n\t\t\tDigite 1 para jogar novamente ou outro numero para encerrar: ",j);
    scanf("%d",&j);
    system("cls");

    }while(j==1);

    printf("\n\n\n\t\t\tObrigado por jogar!\n\n\n");

    return 0;
}
