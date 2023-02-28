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
    y = (exp(-pow(x, 2)) - cos(x));
    return y;
}

double dx(double x)
{
    double y;
    y = exp(-pow(x, 2))*(-2*x) + sin(x);
    return y;
}

double phi(double x)
{
    double phi;
    phi = cos(x) - exp(-pow(x, 2));
    return phi;
}

results bisection(double precision, double a, double b, int max_interactions)
{
    results result;
    double fbegin, fmid, mid, root;
    int k = 0;
    if (fabs(b-a) < precision)
    {
        root = (a+b)/2;
        result.root = root;
        result.final_interaction = k;
        return result;
    }
    else
    {
        while (fabs(b-a) > precision && k < max_interactions)
        {
            k++;
            fbegin = f(a);
            mid = (a+b)/2;
            fmid = f(mid);
            if((fbegin*fmid) < 0){
                b = mid;
                root = b;
            }else{
                a = mid;
                root = a;
            }
        }
        
    }
    
    result.root = root;
    result.final_interaction = k;
    return result;
}

results FPI(double precision, double a, double b, int max_interactions)
{
    results result;
    int k = 0;
    double root, x0 = a, x1 = b, module;
    if(fabs(x0) < precision){
        result.root = x0;
        result.final_interaction = k;
    }else{
        do{
            k++;
            x1 = phi(x0);
            module = x1 - x0;
            x0 = x1;
        }while(fabs(f(x1)) > precision && fabs(module) > precision && k < max_interactions);
        result.root = x1;
        result.final_interaction = k;
        return result;
    }
}

results newton(double precision, double x0, int max_interactions)
{
    int k;
    double root, fx_derivative, fx, x1;
    results result;
    if(fabs(fx) > precision)
    {
        k = 1;
        fx_derivative = dx(x0);
        x1 = x0 - (fx/fx_derivative);
        fx = f(x1);
        while(fabs(fx) > precision && fabs((x1-x0)) > precision && k <= max_interactions)
        {
            k++;
            x0 = x1;
            fx_derivative = dx(x0);
            x1 = x0 - (fx/fx_derivative);
            fx = f(x1);
        }
        result.root = x1;
        result.final_interaction = k;
        return result;
    }
    else
    {
        result.root = x0;
        result.final_interaction = k;
        return result;
    }
}

results secante (double precision, double x0, double x1, int max_interactions)
{
    int k = 0;
    double x2, root, fx1, fx0, module;
    results result;
    if(fabs(f(x0)) < precision)
    {
        result.root = x0;
        result.final_interaction = k;
        return result;
    }
    else if (fabs(f(x1)) < precision || fabs((x1-x0)) < precision)
    {
        result.root = x1;
        result.final_interaction = k;
        return result;
    }
    else
    {
        do
        {
            k++;
            x2 = x1 - ((f(x1)*(x1-x0))/(f(x1)-f(x0)));
            module = x2 - x1;
            x0 = x1;
            x1 = x2;
        }while(fabs
(f(x2)) > precision && fabs
(module) > precision && k < max_interactions);
        result.root = x2;
        result.final_interaction = k;
        return result;
    }
    
}

results regula_falsi (double precision_one, double precision_two, double a, double b, int max_interactions)
{
    results result;
    double root, x, module;
    int k = 0;
    if(fabs((b-a)) < precision_one)
    {
        result.root = (a+b)/2;
        result.final_interaction = k;
        return result;
    }
    else if(fabs(f(a)) < precision_one)
    {
        result.root = a;
        result.final_interaction = k;
        return result;
    }else if(fabs(f(b)) < precision_one)
    {
        result.root = b;
        result.final_interaction = k;
        return result;
    }
    else
    {
        do
        {
            k++;
            module = f(a);
            x = ((a*f(b)) - (b*f(a)))/(f(b) - f(a));
            if(module*f(x)>0){
                a = x;
            }else{
                b = x;
            }
            if(fabs((b-a)) < precision_one){
                result.root = (a+b)/2;
                result.final_interaction = k;
                return result;
            }
        }while(fabs(f(x)) > precision_one && k < max_interactions);
        result.root = x;
        result.final_interaction = k;
        return result;
    }
        
}