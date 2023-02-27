#include <iostream>

using namespace std;

int select_operation()
{
    int option;
    do
    {
        printf("\n");
        printf("Escolha um dos metodos a seguir: \n");
        printf("1 - Bisseccao\n");
        printf("2 - MIL\n");
        printf("3 - Newton - Raphson\n");
        printf("4 - Secante\n");
        printf("5 - Regula Falsi\n");
        printf("6 - Sair\n");
        scanf("%d", &option);
    } while (option < 1 || option > 6);
    return option;
}

void regula_falsi_input(double *left_interval, double *right_interval, double *precision_one, 
double *precision_two, int *max_interactions)
{
    printf("\n");
    printf("DIgite o primeiro valor do intervalo:\n");
    cin >> *left_interval;
    printf("DIgite o segundo valor do intervalo:\n");
    cin >> *right_interval;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a primeira precisao desejada:\n");
    cin >> *precision_one;
    printf("Digite a segunda precisao desejada:\n");
    cin >> *precision_two;
}

void secante_FPI_and_bisection_input(double *precision, double *left_interval, double *right_interval, int *max_interactions)
{
    printf("\n");
    printf("Digite o primeiro valor do intervalo:\n");
    cin >> *left_interval;
    printf("Digite o segundo valor do intervalo:\n");
    cin >> *right_interval;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a precisao desejada:\n");
    cin >> *precision;
}

void newton_input(double *precision, double *aprox, int *max_interactions)
{
    printf("\n");
    printf("Digite o primeiro valor do aproximado:\n");
    cin >> *aprox;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a precisao desejada:\n");
    cin >> *precision;
}
