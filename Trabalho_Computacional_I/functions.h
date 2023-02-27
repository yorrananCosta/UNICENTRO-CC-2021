#include <math.h>
#include <stdio.h>

double function(double x)
{
    double y;
    y = x*log10(x-1);
    return y;
}

double derivative(double x)
{
    double y;
    y = log(x-1) + x/(x-1);
    return y;
}