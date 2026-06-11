#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define TAM 5

void change_terminal_color(char color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (color)
    {
        case 'r':
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case 'g':
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        default:
            break;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand((unsigned)time(NULL));

    change_terminal_color('g');

    int quantidade_geracoes, geracao;
    int geracao_anterior[TAM][TAM], geracao_atual[TAM][TAM];

    printf("\n\n\t\t\tBEM VINDO AO JOGO DA VIDA!!!!\n\n");

    printf("\n\tDigite quantas gera��es voc� deseja observar: ");
    scanf("%d", &quantidade_geracoes);
    system("cls");

    for (geracao = 1; geracao <= quantidade_geracoes; geracao++)
    {
        printf("\n\n\t%d� gera��o: \n", geracao);
        int quantidade_vizinhos_vivos = 0;
        for (int i = 0; i < TAM; i++)
        {
            for (int j = 0; j < TAM; j++)
            {
                if (geracao == 1) {
                    geracao_atual[i][j] = rand() % 2;
                    geracao_anterior[i][j] = geracao_atual[i][j];
                } else {
                    quantidade_vizinhos_vivos = 0;

                    if ((geracao_anterior[i+1][j] == 1) && (i + 1 < TAM))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i-1][j] == 1) && (i-1 >= 0))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i][j+1] == 1) && (j+1 < TAM))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i][j-1] == 1) && (j-1 >= 0))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i-1][j-1] == 1) && (i-1 >= 0) && (j-1 >= 0))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i+1][j+1] == 1) && (j+1 < TAM) && (i+1 < TAM))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i-1][j+1] == 1) && (i-1 >= 0) && (j+1 < TAM))
                        quantidade_vizinhos_vivos++;
                    if ((geracao_anterior[i+1][j-1] == 1) && (i+1 < TAM) && (j-1 >= 0))
                        quantidade_vizinhos_vivos++;

                    geracao_atual[i][j] = geracao_anterior[i][j];

                    if (quantidade_vizinhos_vivos < 2 || quantidade_vizinhos_vivos > 3)
                    {
                        geracao_atual[i][j] = 0;
                    }

                    if (quantidade_vizinhos_vivos == 3)
                    {
                        geracao_atual[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < TAM; i++)
        {
            printf("\n\t");
            for (int j = 0; j < TAM; j++)
            {
                if (geracao_atual[i][j] == 1)
                {
                    change_terminal_color('g');
                    printf(" V ");
                }
                else
                {
                    change_terminal_color('r');
                    printf(" M ");
                }

                geracao_anterior[i][j] = geracao_atual[i][j];
            }
        }
        change_terminal_color('g');
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}
