#include <cmath>
#include "functions.h"

typedef struct 
{
    double root = 0.0;
    int final_interaction = 0.0;
}results;

double f(double x)
{
    double y;
    y = x*log10(x-1);
    return y;
}

double dx(double x)
{
    double y;
    y = log(x-1) + x/(x-1);
    return y;
}

results bisection(double precision, double a, double b, int max_interactions)
{
    results result;
    double fbegin, fmid, mid, root;
    int k = 0;
    if (abs(b-a) < precision)
    {
        root = a;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    while (abs(b-a) > precision && k < max_interactions)
    {
        k++;
        fbegin = f(a);
        mid = (a+b)/2;
        fmid = f(mid);
            if ((fbegin*fmid) < 0)
            {
                b = mid;
                root = b;
            }
            else
            {
                a = mid;
                root = a;
            }
    }
    result.root = root;
    result.final_interaction = k;
    return result;
}

results FPI(double precision, double a, double b, int max_interactions)
{
    results result;
    int k = 1;
    double root, x0 = a, x1 = b;
    if (f (x0) < precision)
    {
        root = x1;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    x1 = dx (x0);
    while (abs(x1 - x0) > precision && k  < max_interactions)
    {
        x0 = x1;
        k++;
    }
    root = x1;
    result.root = root;
    result.final_interaction = k;
    return result;
}

results newton(double precision, double x0, int max_interactions)
{
    int k;
    double root, fx_derivative, fx, x1;
    results result;
    fx = f(x0);
    if (abs(fx) > precision)
    {
        k = 1;
        fx_derivative = dx(x0);
        x1 = x0 - (fx/fx_derivative);
        fx = f(x1);
        while (abs(fx) > precision && abs(x1-x0) > precision && k < max_interactions)
        {
            k++;
            x0 = x1;
            fx_derivative = dx(x0);
            x1 = x0 - (fx/fx_derivative);
            fx = f(x1);
        }
        root = x1;
    }
    else
    {
        root = 0;
    }
    result.root = root;
    result.final_interaction = k;
    return result;
}

results secante (double precision, double x0, double x1, int max_interactions)
{
    int k = 0;
    double x2, root, fx1, fx0;
    results result;
    if (abs(f(x0)) > precision)
    {
        root = x0;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    if (abs(f(x1)) > precision)
    {
        root = x1;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    k = 1;
    label: {
        x2 = x1 - (fx1*(x1-x0))/(fx1 - fx0); 
        if (abs(f(x2)) < precision || abs(x2-x1) < precision || k > max_interactions)
        {
            root = x2;
            result.root = root;
            result.final_interaction = k;
            return result;
        }
        x0 = x1;
        k++;
    }
    goto label;
    root = x2;
    
}

results regula_falsi (double precision_one, double precision_two, double a, double b, int max_interactions)
{
    results result;
    double root, M, x;
    int k = 1;
    if (abs(b-a) < precision_one)
    {
        root = a;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    if (abs(f(a)) < precision_two)
    {
        root = b;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    label1: {
        M = f(a);
    }
    x = (a*f(b)-b*f(a))/(f(b) - f(a));
    if (abs(f(x)) < precision_two || k > max_interactions)
    {
        root = x;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    if (M*f(x) > 0)
    {
        a = x;
        result.root = root;
        result.final_interaction = k;
        return result;
        goto label1;
    }
    b = x;
    label2: {
        if (abs(b-a) < precision_one)
        {
            root = a;
            result.root = root;
            result.final_interaction = k;
            return result;
        }
    }
    k++;
    goto label1;
        
}