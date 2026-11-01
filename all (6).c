#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fa(double x);
double fb(double x);
double sin_n(double x1, int N);
double sin_eps(double x1, double eps);

int main() {
    double x, x1, eps;
    int ch, N;
    
    printf("Номер 1\n");
    printf("Введите x: ");
    
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    printf("\nМеню выбора:\n");
    printf("1. Расчет F1(x)\n");
    printf("2. Расчет F2(x)\n");
    printf("3. Расчет произведения, разности квадратов и удвоенной суммы\n");
    printf("Ваш выбор: ");
    scanf("%d", &ch);
    
    printf("\n Результат: \n");

    if (ch == 1) {
        printf("fa(x) = %lf\n", fa(x));
    } 
    else if (ch == 2) {
        printf("fb(x) = %lf\n", fb(x));
    } 
    else if (ch == 3) {
        printf("fa(x)=%lf , fb(x)=%lf\n", fa(x), fb(x));
        
        double res_a = fa(x);
        double res_b = fb(x);
        
        printf("Произведение = %lf, Разность квадратов = %lf, Удвоенная сумма = %lf\n", 
               res_a * res_b, 
               (res_a * res_a) - (res_b * res_b), 
               2 * (res_a + res_b));
    } 
    else {
        printf("Неверный пункт меню.\n");
    }
    
    printf("\nЗадание 2\n");
    printf("Введите x для sin(x): ");
    if (scanf("%lf", &x1) != 1) { 
        printf("Ошибка ввода x!\n");
        return 1;
    }
    
    printf("Введите число членов ряда N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка ввода N!\n");
        return 1;
    }

    printf("Введите точность вычислений eps: ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("Ошибка ввода eps!\n");
        return 1;
    }
    
    double res_math = sin(x1);
    double res_n = sin_n(x1, N);
    double res_eps = sin_eps(x1, eps);
    
    printf("\n=== Результаты Задания 2 ===\n");
    printf("1) Библиотечный sin(x):      %.15lf\n", res_math);
    printf("2) Ряд с N=%-3d членов:       %.15lf  (Отклонение: %e)\n", N, res_n, res_n - res_math);
    printf("3) Ряд с точностью eps=%-e: %.15lf  (Отклонение: %e)\n", eps, res_eps, res_eps - res_math);
    
    return 0;
} 

double fa(double x) {
    double y;
    if (x <= 3) {
        y = x * x - 3 * x + 9;
    } else {
        y = 1.0 / (x * x * x + 3);
    }
    return y;
}

double fb(double x) {
    double y;
    y = x * exp(sin(x * x));
    return y;
}

double sin_n(double x, int N) {
    double sum = x;     
    double term = x;    
    
    for (int k = 2; k <= N; k++) {
        term = term * (-x * x) / ((2 * k - 2) * (2 * k - 1));
        sum += term;
    }
    return sum;
}

double sin_eps(double x, double eps) {
    double sum = x;
    double term = x;
    int k = 2;
    
    while (fabs(term) >= eps) {
        term = term * (-x * x) / ((2 * k - 2) * (2 * k - 1));
        sum += term;
        k++;
    }
    return sum;
}
