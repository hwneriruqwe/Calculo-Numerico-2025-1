#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double modulo(double x) {
    if (x >= 0) {
        return x;
    }
    else {
        return (-x);
    }
}

// Definição da função f(x) para a qual queremos encontrar a raiz
double f(double x) {
    return (10.8 * (acos( 1 - ((x) / (3.35))) * 3.35 * 3.35 - (3.35 - x) * sqrt(x * (2 * 3.35 - x)))) - 200; // Exemplo: f(x) = x^2 - 4 (raiz em x = ±2)
}

int bissecao(double a, double b, double toler, int iterMax) {
    double fa = f(a);
    double fb = f(b);
    double erro = toler+100;
    double c, fc;
    
    // Verifica se a função muda de sinal no intervalo dado
    if (fa * fb > 0) {
        printf("A função não muda de sinal nos extremos do intervalo dado.\n");
        return 0;
    }

    for(int i=0; i<iterMax; i++) {
        c = (a + b) / 2;
        fc = f(c);
        fa = f(a);
        fb = f(b);
        
        printf("Iteração %d: a = %lf, fa = %lf, b = %lf, fb = %lf, c = %lf, fc = %lf",
               i, a, fa, b, fb, c, fc);
        
        // Atualiza os extremos do intervalo
        
        if (fa * fc < 0) {
            if (i>=1) {
                erro = modulo((c-b)/c) * 100;
                printf("b");
            }
            b = c;
        } else if (fb * fc < 0) {
            if (i>=1) {
                erro = modulo((c-a)/c) * 100;
            }
            a = c;
        }
        printf(", erro = %lf\n", erro);

        if (erro <= toler || fc == 0) {
            return 1;
        }
    }
}

int main() {
    double a = 3, b = 4, toler = 0.001;
    int iterMax = 100;
    
    if (bissecao(a, b, toler, iterMax)) {
        printf("Raiz encontrada!");
    }
    else {
        printf("O método não convergiu.");
    }
    
    return 0;
}
