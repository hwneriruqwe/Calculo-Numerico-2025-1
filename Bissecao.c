#include <stdio.h>
#include <math.h>

// Definição da função f(x) para a qual queremos encontrar a raiz
double f(double x) {
    return x * x - 4; // Exemplo: f(x) = x^2 - 4 (raiz em x = ±2)
}

void bissecao(double a, double b, double toler, int iterMax, double *raiz, int *iter, int *condErro) {
    double fa = f(a);
    double fb = f(b);
    
    // Verifica se a função muda de sinal no intervalo dado
    if (fa * fb > 0) {
        printf("A função não muda de sinal nos extremos do intervalo dado.\n");
        *condErro = 1;
        return;
    }

    *iter = 0;
    double deltaX = fabs(b - a) / 2;
    double x, fx;
    
    while (1) {
        x = (a + b) / 2;
        fx = f(x);
        
        printf("Iteração %d: a = %lf, fa = %lf, b = %lf, fb = %lf, x = %lf, fx = %lf, deltaX = %lf\n",
               *iter, a, fa, b, fb, x, fx, deltaX);
        
        if ((deltaX <= toler && fabs(fx) <= toler) || *iter > iterMax) {
            break;
        }
        
        // Atualiza os extremos do intervalo
        if (fa * fx > 0) {
            a = x;
            fa = fx;
        } else {
            b = x;
        }
        
        deltaX /= 2;
        (*iter)++;
    }
    
    *raiz = x;
    *condErro = (deltaX <= toler && fabs(fx) <= toler) ? 0 : 1;
}

int main() {
    double a = 0, b = 3, toler = 0.001, raiz;
    int iterMax = 100, iter, condErro;
    
    bissecao(a, b, toler, iterMax, &raiz, &iter, &condErro);
    
    if (condErro == 0) {
        printf("Raiz encontrada: %lf após %d iterações\n", raiz, iter);
    } else {
        printf("O método não convergiu após %d iterações.\n", iter);
    }
    
    return 0;
}
