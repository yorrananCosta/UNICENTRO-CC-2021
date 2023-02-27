#include <iostream>
#include <fstream>
#include "inputs.cpp"
#include "methods.cpp"
#define EXIT 6

using namespace std;

ofstream file;

void archive_results(double root, int interactions);
int main()
{
    int option_selected;
    results result;
    
    do
    {
        result.root = 0.0;
        result.final_interaction = 0.0;
        double a, b, left_interval, right_interval, precision_one, precision_two;
        int max_interactions;
        option_selected = select_operation(); 
        switch (option_selected)
        {
        case 1:
            secante_FPI_and_bisection_input(&precision_one, &left_interval, &right_interval, &max_interactions);
            result = bisection(precision_one, left_interval, right_interval, max_interactions);
            break;
        case 2:
            secante_FPI_and_bisection_input(&precision_one, &left_interval, &right_interval, &max_interactions);
            result = FPI(precision_one, left_interval, right_interval, max_interactions); 
            break;
        case 3:
            newton_input(&precision_one, &left_interval, &max_interactions);
            result = newton(precision_one, left_interval, max_interactions);
            break;
        case 4:
            secante_FPI_and_bisection_input(&precision_one, &left_interval, &right_interval, &max_interactions);
            result = secante(precision_one, left_interval, right_interval, max_interactions);
            break;
        case 5:
            regula_falsi_input(&left_interval, &right_interval, &precision_one, &precision_two, &max_interactions);
            result = regula_falsi(precision_one, precision_two, left_interval, right_interval, max_interactions);
            break;

        default:
            break;
        }
        archive_results(result.root, result.final_interaction);
    } while (option_selected != EXIT);
    printf("Por favor verifique os resultados no arquivo de texto");
    return 0;
}

void archive_results(double root, int interactions)
{
    file.open("results.txt");
    file << "raiz: " << root << " quantidade de interacoes: " << interactions << endl;
    file.close();
}