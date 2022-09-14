// GitHub: vidallamanda
// Autora: Amanda da Cunha Vidal
// Matricula: 202221364

// Extensões abaixa vistas no ebook
#include <stdio.h>
#include <string.h>

/* http://linguagemc.com.br/a-biblioteca-math-h/
Utilizei a biblioteca e função do site, não a lógica
Funções: sqrt() e pow() */
#include <math.h>

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
    int calculadoraAtivada = 1;
    int operacaoDesejada;
    int operacaoCorreta;
    float operando1, operando2;

    while (calculadoraAtivada == 1)
    {

        operacaoCorreta = 0;
        operacaoDesejada = 0;

        /* Enquanto o usuário não selecionar uma operação válida, o código
        dentro desse while será executado */
        while (operacaoCorreta == 0)
        {

            printf("\n**************** Calculadora ****************\n");
            printf("---------------------------------------------\n");
            printf("Qual operação você deseja realizar?\n\n");
            printf("1 - Soma\n");
            printf("2 - Subtração\n");
            printf("3 - Divisão\n");
            printf("4 - Multiplicação\n");
            printf("5 - Raiz quadrada\n");
            printf("6 - Potência\n\n");
            printf("Digite o número de uma das operações acima:");

            // Salva a opção que usuário informou na variavel operação desejada.
            scanf("%d", &operacaoDesejada);

            // Verifica se a operação é válida = se ela estiver entre 1 e 6.
            if ((operacaoDesejada >= 1) && (operacaoDesejada <= 6))
            {
                printf("\nDigite um número para o primeiro operando:");
                scanf("%f", &operando1);

                /* Verifica se a operação é diferente de raiz quadrada, assim é
                necessário mais um operando */
                if (operacaoDesejada != 5)
                {
                    printf("\nDigite um número para o segundo operando:");
                    scanf("%f", &operando2);
                }

                // Garante a saída do laço while.
                operacaoCorreta = 1;
            }
            else
            {
                printf("\n\nOperação inválida: Não digitou uma das operações listadas.\n\n");
            }
        }

        // Verifica qual a operação para realizar a conta necessária.
        switch (operacaoDesejada)
        {
        case 1:
            printf("\nResultado da soma %.2f", operando1 + operando2);
            break;
        case 2:
            printf("\nResultado da subtração %.2f", operando1 - operando2);
            break;
        case 3:
            if (operando2 == 0)
            {
                printf("Operação inválida: Divisor não pode ser igual 0");
            }
            else
            {
                printf("\nResultado da divisão %.2f", operando1 / operando2);
            }
            break;
        case 4:
            printf("\nResultado da multiplicação %.2f", operando1 * operando2);
            break;
        case 5:
            printf("\nResultado da raiz quadrada %.2f", sqrt(operando1));
            break;
        case 6:
            printf("\nResultado da potência %.2f", pow(operando1, operando2));
            break;
        }

        /* Se deseja realizar outra operação, o laço while continua sendo
        verdade, portanto, continua sendo executado */
        printf("\n\nDeseja realizar outra operação?");
        printf("\nCaso a resposta seja sim, digite 1, se não, digite qualquer coisa\n");
        scanf("%d", &calculadoraAtivada);

    }

    printf("\n++++++++++++++ Programa encerrado ++++++++++++++");

    return 0;
    
}
