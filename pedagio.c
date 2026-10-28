/*
 * Sistema de Controle de Pedagio
 * Objetivo: registrar a quantidade de carros por dia da semana e por periodo,
 *           calcular totais e media e destacar o dia de pico (bonus).
 *
 * Estruturas de dados:
 *   carros[DIAS][PERIODOS] -> matriz com a contagem de carros (linha = dia, coluna = periodo)
 *   totalDia[DIAS]         -> vetor com o total de carros de cada dia
 *   diasSemana / periodos  -> matrizes de char com os nomes (rotulos) para exibicao
 */

#include <stdio.h>

#define DIAS     7   /* quantidade de linhas da matriz (dias da semana) */
#define PERIODOS 3   /* quantidade de colunas da matriz (manha, tarde, noite) */

/* Codigos ANSI para o destaque do dia de pico (bonus) */
#define DESTAQUE "\033[1;31m"   /* negrito + vermelho */
#define NORMAL   "\033[0m"      /* volta ao padrao do terminal */

/* Linha divisoria com 46 tracos = largura da tabela (14 + 3x8 + 8) */
#define LINHA "----------------------------------------------\n"

int main(void) {
    /* Rotulos usados nas mensagens e no relatorio */
    char diasSemana[DIAS][14] = {
        "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira",
        "Sexta-feira", "Sabado", "Domingo"
    };
    char periodos[PERIODOS][8] = {"Manha", "Tarde", "Noite"};

    int carros[DIAS][PERIODOS];   /* matriz principal com os dados lidos */
    int totalDia[DIAS];           /* vetor com a soma de cada dia */
    int totalSemana = 0;          /* soma de todos os carros da semana */
    float mediaDiaria;            /* media de carros por dia (com decimais) */
    int diaPico = 0;              /* indice do dia com mais carros */
    int i, j;                     /* i = indice do dia, j = indice do periodo */
    int leitura, descarte;        /* auxiliares para validar a entrada */

    printf("=== CONTROLE DE PEDAGIO ===\n");
    printf("Informe a quantidade de carros de cada periodo.\n\n");

    /* ---------- 1. LEITURA ----------
     * Laco externo percorre os dias (linhas); laco interno percorre os
     * periodos (colunas). Assim, 21 leituras sao feitas com poucas linhas. */
    for (i = 0; i < DIAS; i++) {
        for (j = 0; j < PERIODOS; j++) {
            do {
                printf("%s - %s: ", diasSemana[i], periodos[j]);
                leitura = scanf("%d", &carros[i][j]);

                if (leitura == EOF) {   /* entrada encerrada: sai com seguranca */
                    return 1;
                }
                if (leitura != 1) {
                    /* usuario digitou texto: limpa o buffer e forca nova tentativa */
                    while ((descarte = getchar()) != '\n' && descarte != EOF);
                    carros[i][j] = -1;
                }
                if (carros[i][j] < 0) {
                    printf("Valor invalido! Digite um numero inteiro maior ou igual a 0.\n");
                }
            } while (carros[i][j] < 0);   /* repete ate receber um valor valido */
        }
    }

    /* ---------- 2. PROCESSAMENTO ----------
     * Para cada dia: soma os periodos da linha da matriz, guarda no vetor
     * totalDia e verifica se este e o dia de maior movimento. */
    for (i = 0; i < DIAS; i++) {
        totalDia[i] = 0;                       /* zera antes de acumular */
        for (j = 0; j < PERIODOS; j++) {
            totalDia[i] += carros[i][j];       /* soma a linha i da matriz */
        }
        totalSemana += totalDia[i];

        /* Regra de negocio: dia de pico = maior total; em empate, vale o primeiro */
        if (totalDia[i] > totalDia[diaPico]) {
            diaPico = i;
        }
    }

    /* (float) evita divisao inteira, que descartaria as casas decimais */
    mediaDiaria = (float) totalSemana / DIAS;

    /* ---------- 3. EXIBICAO ---------- */
    printf("\n=== RELATORIO SEMANAL ===\n");

    /* Cabecalho: nomes dos periodos vindos da matriz de rotulos */
    printf("%-14s", "Dia");
    for (j = 0; j < PERIODOS; j++) {
        printf("%8s", periodos[j]);
    }
    printf("%8s\n", "Total");

    /* Uma linha por dia; o dia de pico recebe destaque (bonus) */
    for (i = 0; i < DIAS; i++) {
        if (i == diaPico) {
            printf(DESTAQUE);                  /* liga o destaque */
        }

        printf("%-14s", diasSemana[i]);
        for (j = 0; j < PERIODOS; j++) {
            printf("%8d", carros[i][j]);
        }
        printf("%8d", totalDia[i]);

        if (i == diaPico) {
            printf("  <- DIA DE PICO" NORMAL);  /* desliga o destaque */
        }
        printf("\n");
    }

    printf("\nTotal da semana: %d carros\n", totalSemana);
    printf("Media diaria: %.2f carros\n", mediaDiaria);
    printf("Dia de pico: %s (%d carros)\n", diasSemana[diaPico], totalDia[diaPico]);

    return 0;
}
