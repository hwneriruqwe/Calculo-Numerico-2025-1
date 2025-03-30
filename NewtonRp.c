#include <stdio.h>
#include <math.h>

// Definição da função f(x)
double f(double x) {
    return x * x - 4; // Exemplo: f(x) = x^2 - 4 (raiz em x = ±2)
}

// Derivada da função f'(x)
double df(double x) {
    return 2 * x; // Derivada de f(x) = x^2 - 4 -> f'(x) = 2x
}

void newton(double x0, double toler, int iterMax, double *raiz, int *iter, int *condErro) {
    double fx = f(x0);
    double dfx = df(x0);
    double x = x0;
    *iter = 0;
    
    printf("Iteração %d: x = %lf, f(x) = %lf, f'(x) = %lf\n", *iter, x, fx, dfx);
    
    while (1) {
        if (dfx == 0) {
            printf("Derivada nula, método não pode continuar.\n");
            *condErro = 1;
            return;
        }
        
        double deltaX = -fx / dfx;
        x += deltaX;
        fx = f(x);
        dfx = df(x);
        (*iter)++;
        
        printf("Iteração %d: x = %lf, f(x) = %lf, f'(x) = %lf, DeltaX = %lf\n", *iter, x, fx, dfx, deltaX);
        
        if ((fabs(deltaX) <= toler && fabs(fx) <= toler) || *iter > iterMax) {
            break;
        }
    }
    
    *raiz = x;
    *condErro = (fabs(fx) <= toler) ? 0 : 1;
}

int main() {
    double x0 = 3, toler = 0.001, raiz;
    int iterMax = 100, iter, condErro;
    
    newton(x0, toler, iterMax, &raiz, &iter, &condErro);
    
    if (condErro == 0) {
        printf("Raiz encontrada: %lf após %d iterações\n", raiz, iter);
    } else {
        printf("O método não convergiu após %d iterações.\n");
    }
    
    return 0;
}
