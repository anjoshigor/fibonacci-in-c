#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibo.h"
#define RED "\033[31m" /* Red */
#define RESET "\033[0m"
#define GREEN "\033[32m" /* Green */



int main()
{
    int escolha = 3;
    int n = 10;
    char *opcao = "[3] Fibonacci c/ Big Integers";
    char *(*function)(int) = bigFibo;

    printf("\n\n");

    printf(GREEN"----------------------------------------\n");
    printf("-----------TRABALHO PRATICO 1-----------\n");
    printf("----------------------------------------\n"RESET);

    printf("\n\n");

    printf("-----------------MENU:------------------\n");
    printf("| Escolha a opcao desejada:            |\n");
    printf("| "RED"[1]"RESET" Fibonacci recursivo              |\n");
    printf("| "RED"[2]"RESET" Fibonacci c/ Dynamic Programming |\n");
    printf("| "RED"[3]"RESET" Fibonacci c/ Big Integers        |\n");
    printf("----------------------------------------\n");

    printf(GREEN"Sua escolha: ");
    scanf("%d", &escolha);

    printf(RESET"\n");

    switch (escolha)
    {
    case 1:
        function = recursiveFibo;
        opcao = "[1] Fibonacci recursivo";
        break;
    case 2:
        function = dpFibo;
        opcao = "[2] Fibonacci c/ Dynamic Programming";
        break;
    case 3:
        function = bigFibo;
        opcao = "[3] Fibonacci c/ Big Integers";
        break;

    default:
        printf(RED"Opção invalida, finalizando programa...\n"RESET);
        exit(0);
    }

    printf("Voce quer calcular Fibonacci de que numero?\n");

    printf(GREEN"Sua escolha: ");
    scanf("%d", &n);
    printf(RESET"\n");

    printf("Calculando o Fibonacci de "RED"%d"RESET" usando "GREEN"%s"RESET"...\n", n, opcao);

    printf("\n");

    char *result = function(n);

    printf("----------------------------------------\n");
    printf("| RESULTADO: "GREEN"%s"RESET" \n", result);
    printf("----------------------------------------\n");

    printf("\n\n");

    return 0;
}