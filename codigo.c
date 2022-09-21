// GitHub: vidallamanda
// Projeto: Atividade-producao
// Arquivo: codigo.c
// Autora: Amanda da Cunha Vidal
// Matricula: 202221364

// Extensões abaixa vistas no ebook
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{

    // Declaração de string e atribuição dos dados da autora.
    char autor[] = "Amanda da Cunha Vidal";
    char matricula[] = "202221364";
    char universidade[] = "UniLaSalle";
    char curso[] = "Ciência de dados";

    // Mostra ao usuário os dados da autora inseridos anteriormente.
    printf("Olá! \nEsse código foi desenvolvido pelo(a) aluno(a): %s\n", autor);
    printf("Matrícula: %s\n", matricula);
    printf("Universidade: %s\n", universidade);
    printf("Curso: %s\n\n", curso);

    // Declaração de variáveis necessárias para a calculadora.
    int operacaoCorreta, i;
    float operando1, operando2, resultadoPotencia, raiz, decremento, resultadoRaiz;
    bool calculadoraAtiva = true;
    char operacaoDesejada;
    char leitor[] = "";

    /* Enquanto o usuário não selecionar uma operação válida, o código
    dentro desse while será executado */
    while (calculadoraAtiva == true)
    {
        operacaoCorreta = 1;

        raiz = 0;
        decremento = 1;
        resultadoRaiz = 0;

        i = 0;
        resultadoPotencia = 1;

        while (operacaoCorreta == 1)
        {

            printf("\n**************** Calculadora ****************\n");
            printf("---------------------------------------------\n");
            printf("Qual operação você deseja realizar?\n\n");
            printf("(+) Soma\n");
            printf("(-) Subtração\n");
            printf("(/) Divisão\n");
            printf("(*) Multiplicação\n");
            printf("(r) Raiz quadrada\n");
            printf("(^) Potência\n\n");
            printf("Digite o símbolo dessa operação, como está descrito abaixo (sem parênteses): ");

            // Salva a opção informada na variável operação desejada.
            scanf("%s", &operacaoDesejada);

            // Verifica se a operação é válida, se o caracter digitado corresponde a um dos símbolos.
            switch (operacaoDesejada)
            {
            case 'r':
                printf("\nDigite um número para o operando/radicando: ");
                scanf("%f", &operando1);
                // Garante a saída do while
                operacaoCorreta = 0;
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                printf("\nDigite um número para o primeiro operando (parcela/minuendo/dividendo/multiplicando/base): ");
                scanf("%f", &operando1);
                printf("\nDigite um número para o segundo operando (parcela/subtraendo/divisor/multiplicador/expoente): ");
                scanf("%f", &operando2);
                // Garante a saída do while
                operacaoCorreta = 0;
                break;
            default:
                // O laço repete até inserir uma opção válida
                operacaoCorreta = 1;
                printf("\n\nOperação inválida: Não digitou uma das operações listadas.\n\n");
            }
        }

        // Verifica qual a operação para realizar a conta necessária.
        switch (operacaoDesejada)
        {
        case '+':
            printf("\nResultado da soma: %.2f", operando1 + operando2);
            break;
        case '-':
            printf("\nResultado da subtração: %.2f", operando1 - operando2);
            break;
        case '/':
            if (operando2 == 0)
            {
                printf("Operação inválida: Divisor não pode ser igual 0");
            }
            else
            {
                printf("\nResultado da divisão: %.2f", operando1 / operando2);
            }
            break;
        case '*':
            printf("\nResultado da multiplicação: %.2f", operando1 * operando2);
            break;
        case 'r':
            // Codigo levemente adaptado.
            // Site: https://www.clubedohardware.com.br/forums/topic/1500666-c-raiz-quadrada-exata-linguagem-c/
            // Autor: Eduardo Ozelame
            // Poderia utilizar a função sqrt() da bibilioteca math.h
            raiz = operando1;
            // o número de vezes que o operando puder ser decrementado de um número impar (1,3,5,7...) será o resultado da raiz.
            while (raiz > 0)
            {
                raiz -= decremento;
                decremento += 2;
                resultadoRaiz += 1;
            }
            if (raiz < 0)
            {
                printf("A raiz quadrada não é exata!");
            }
            else
            {
                printf("A raiz quadrada exata é: %.2f", resultadoRaiz);
            }
            break;
        case '^':
            // Poderia utilizar a função pow() da bibilioteca math.h
            // Se o expoente for 0, a potência é 1
            if (operando2 == 0)
            {
                resultadoPotencia = 1;
            }
            else
            {
                // O operando1 será multiplicado n vezes por ele mesmo, o valor de n é o operando2, conhecido como expoente.
                for (i = 0; i < operando2; i++)
                {
                    resultadoPotencia *= operando1;
                }
            }
            printf("\nResultado da potência: %.2f", resultadoPotencia);
            break;
        }
        /*Se deseja realizar outra operação, o laço while continua sendo verdade, portanto, continua sendo executado */
        printf("\n\nDeseja realizar uma nova operação válida?");
        printf("\nDigite 'sim' sem as aspas e mínusculo caso queira, senão, digite qualquer coisa: \n");
        scanf("%s", &leitor);
        // se leitor for igual a sim, o strcmp retorna 0
        if (strcmp(leitor, "sim") == 0)
        {
            calculadoraAtiva = true;
        }
        else
        {
            calculadoraAtiva = false;
        }
    }
    printf("\n++++++++++++++ Programa encerrado ++++++++++++++");
    return 0;
}
