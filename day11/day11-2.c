#include <stdio.h>
#include <math.h>

double f(double x) {
    return -log10(1 / x) + sin(x);
}

double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x1 = a + i * h;
        double x2 = a + (i + 1) * h;
        sum += (x2-x1)*f(x2);
    }

    return sum;
}

int main() {
    double a = 10, b = 30;
    int n, max = 1;

    printf("�ִ� ���� ���� �Է��ϼ��� (2^n): ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        max *= 2;
    }

    printf("\n���� ��\t���� ���\n");

    
    for (int i = 1; i <= max; i *= 2) {
        double result = integrate(a, b, i);
        printf("����\t%d ���� ��� : %.6f\n", i, result);
    }

    return 0;
}

