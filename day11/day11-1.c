#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, x1 = 0, x2 = 0;
	float r;
	printf("���� ������ �̿��Ͽ� ������������ ���� ���϶�\n");
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
		printf("�߱� : %.2f", x1);
	}
	else if (r < 0) {
		printf("����Դϴ�.");
	}
	else {
		x1 = (-b + sqrt(r)) / (2 * a);
		x2 = (-b - sqrt(r)) / (2 * a);
		printf("ù ��° �� : %.2f\n", x1);
		printf("�� ��° �� : %.2f\n", x2);
	}
	return 0;
}

