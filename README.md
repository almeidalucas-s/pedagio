# Sistema de Controle de Pedágio

Programa em linguagem C que registra a quantidade de carros que passam por um pedágio em cada **dia da semana** e em cada **período do dia** (manhã, tarde e noite), calcula os totais e a média e **destaca o dia de pico** no terminal.

Projeto desenvolvido como Experiência Prática de Aprendizagem (EPI) da graduação em Ciência da Computação, com foco em **vetores, matrizes e estruturas de repetição**.

---

## Funcionalidades

- Leitura de 21 valores (7 dias × 3 períodos) com laços `for` aninhados
- Validação da entrada: rejeita números negativos e texto digitado no lugar de números
- Cálculo do total de carros de cada dia, do total da semana e da média diária
- Identificação do dia de pico (em caso de empate, vale o primeiro dia)
- Relatório em formato de tabela, com colunas alinhadas e linhas divisórias
- **Bônus:** o dia de pico aparece em **negrito e vermelho** (códigos ANSI)

---

## Estruturas de dados utilizadas

| Nome          | Tipo                     | Papel                                               |
| ------------- | ------------------------ | --------------------------------------------------- |
| `carros`      | `int carros[7][3]`       | Matriz principal: linhas = dias, colunas = períodos |
| `totalDia`    | `int totalDia[7]`        | Vetor com a soma de carros de cada dia              |
| `diasSemana`  | `char diasSemana[7][14]` | Nomes dos dias, usados nas mensagens e no relatório |
| `periodos`    | `char periodos[3][8]`    | Nomes dos períodos (Manha, Tarde, Noite)            |
| `totalSemana` | `int`                    | Soma de todos os carros da semana                   |
| `mediaDiaria` | `float`                  | Média de carros por dia (`totalSemana / 7`)         |
| `diaPico`     | `int`                    | Índice (0 a 6) do dia com mais carros               |

---

## Como compilar e executar

**Requisito:** compilador GCC instalado (no Windows, por exemplo, via MSYS2).

1. Abra um terminal na pasta onde está o arquivo `pedagio.c`
2. Compile:

```
gcc pedagio.c -o pedagio
```

3. Execute:

```
# Windows (PowerShell)
.\pedagio

# Linux / macOS
./pedagio
```

> As cores funcionam no terminal do VS Code e em terminais modernos. Em terminais antigos, o destaque pode aparecer como símbolos; o texto `<- DIA DE PICO` garante que a informação continue visível.

---

## Exemplo de execução

**Entradas (Manhã, Tarde e Noite de cada dia):**

| Dia     | Manhã | Tarde | Noite |
| ------- | ----- | ----- | ----- |
| Segunda | 320   | 450   | 380   |
| Terça   | 300   | 430   | 360   |
| Quarta  | 310   | 440   | 370   |
| Quinta  | 340   | 480   | 410   |
| Sexta   | 520   | 690   | 610   |
| Sábado  | 600   | 820   | 540   |
| Domingo | 410   | 560   | 300   |

**Saída:**

```
=== RELATORIO SEMANAL ===
----------------------------------------------
Dia              Manha   Tarde   Noite   Total
----------------------------------------------
Segunda-feira      320     450     380    1150
Terca-feira        300     430     360    1090
Quarta-feira       310     440     370    1120
Quinta-feira       340     480     410    1230
Sexta-feira        520     690     610    1820
Sabado             600     820     540    1960  <- DIA DE PICO
Domingo            410     560     300    1270
----------------------------------------------
Total da semana: 9640 carros
Media diaria: 1377.14 carros
Dia de pico: Sabado (1960 carros)
```

---

## Testes realizados

| Teste              | Entrada                           | Resultado esperado                                                              |
| ------------------ | --------------------------------- | ------------------------------------------------------------------------------- |
| Semana normal      | Valores da tabela acima           | Sábado como dia de pico (1960 carros), média de 1377.14                         |
| Entradas inválidas | `abc` e `-5` na primeira pergunta | Mensagem de valor inválido e nova pergunta até receber um número válido         |
| Caso extremo       | Todos os valores iguais a `0`     | Totais zerados, média `0.00` e Segunda-feira como dia de pico (regra de empate) |

---

## Organização do código

O programa está dividido em três blocos comentados dentro da função `main`:

1. **Leitura:** `for` externo percorre os dias e `for` interno percorre os períodos, com `do-while` para validar cada valor
2. **Processamento:** soma cada linha da matriz no vetor `totalDia`, acumula o total da semana, define o dia de pico e calcula a média com conversão `(float)`
3. **Exibição:** imprime cabeçalho, linhas da tabela e resumo final, usando larguras fixas no `printf` (`%-14s` e `%8d`) e o destaque do dia de pico

---

## Possíveis melhorias

- Separar leitura, cálculo e exibição em funções
- Ler os dados de um arquivo em vez de digitar manualmente
- Permitir cadastrar mais de uma semana
- Mostrar também o período de maior movimento

---

## Autor

**Lucas Almeida Souza**
GitHub: [almeidalucas-s](https://github.com/almeidalucas-s)
