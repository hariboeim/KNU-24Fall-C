#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, x1 = 0, x2 = 0;
	float r;
	printf("근의 공식을 이용하여 이차방정식의 근을 구하라\n");
	printf("ax^2 + bx + c\n");
	printf("a = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("c = ");
	scanf_s("%f", &c);

	r = (pow(b,2) - 4 * a * c);

	if (r == 0) {
		x1 = (-b + sqrt(r)) / (2 * a);
		printf("중근 : %.2f", x1);
	}
	else if (r < 0) {
		printf("허근입니다.");
	}
	else {
		x1 = (-b + sqrt(r)) / (2 * a);
		x2 = (-b - sqrt(r)) / (2 * a);
		printf("첫 번째 근 : %.2f\n", x1);
		printf("두 번째 근 : %.2f\n", x2);
	}
	return 0;
}

