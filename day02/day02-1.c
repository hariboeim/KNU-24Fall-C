#include <stdio.h>

int main() {
	int m;
	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &m);

	if (m == 1) {
		double a, b, c = 0;
		printf("���� 1�� �Է��ϼ��� : ");
		scanf_s("%lf", &a);
		printf("���� 2�� �Է��ϼ��� : ");
		scanf_s("%lf", &b);
		c = a + b;
		printf("\n%lf + %lf = %lf" ,a, b, c);
	}
	else if (m == 2) {
		double a, b, c = 0;
		printf("���� 1�� �Է��ϼ��� : ");
		scanf_s("%lf", &a);
		printf("���� 2�� �Է��ϼ��� : ");
		scanf_s("%lf", &b);
		if (a > b) {
			c = a - b;
			printf("\n%lf - %lf = %lf", a, b, c);
		}
		else {
			c = b - a;
			printf("\n%lf - %lf = %lf", b, a, c);
		}
	}
	else if (m == 3) {
		double a, b, c = 0;
		printf("���� 1�� �Է��ϼ��� : ");
		scanf_s("%lf", &a);
		printf("���� 2�� �Է��ϼ��� : ");
		scanf_s("%lf", &b);
		c = a * b;
		printf("\n%lf * %lf = %lf", a, b, c);
	}
	else if (m == 4) {
		double a, b, c = 0;
		printf("���� 1�� �Է��ϼ��� : ");
		scanf_s("%lf", &a);
		printf("���� 2�� �Է��ϼ��� : ");
		scanf_s("%lf", &b);
		if (a > b) {
			c = a / b;
			printf("\n%lf / %lf = %lf", a, b, c);
		}
		else {
			c = b / a;
			printf("\n%lf / %lf = %lf", b, a, c);
		}
	}
	else {
		printf("������ ���ڰ� �ƴմϴ�.\n");
		printf("���α׷��� �ٽ� �����Ͻÿ�.");
		return 0;
	}
	return 0;
}