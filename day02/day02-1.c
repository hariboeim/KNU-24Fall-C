#include <stdio.h>

int main() {
	int m;
	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &m);

	if (m == 1) {
		double a, b, c = 0;
		printf("숫자 1을 입력하세요 : ");
		scanf_s("%lf", &a);
		printf("숫자 2를 입력하세요 : ");
		scanf_s("%lf", &b);
		c = a + b;
		printf("\n%lf + %lf = %lf" ,a, b, c);
	}
	else if (m == 2) {
		double a, b, c = 0;
		printf("숫자 1을 입력하세요 : ");
		scanf_s("%lf", &a);
		printf("숫자 2를 입력하세요 : ");
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
		printf("숫자 1을 입력하세요 : ");
		scanf_s("%lf", &a);
		printf("숫자 2를 입력하세요 : ");
		scanf_s("%lf", &b);
		c = a * b;
		printf("\n%lf * %lf = %lf", a, b, c);
	}
	else if (m == 4) {
		double a, b, c = 0;
		printf("숫자 1을 입력하세요 : ");
		scanf_s("%lf", &a);
		printf("숫자 2를 입력하세요 : ");
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
		printf("지정된 숫자가 아닙니다.\n");
		printf("프로그램을 다시 실행하시오.");
		return 0;
	}
	return 0;
}