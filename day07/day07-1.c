#include <stdio.h>

int main() {
	int num;

	printf("�Ƕ�̵� �� ���� �Է��ϼ���.\n");
	printf("�� �� : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			printf(" ");
		}
		for (int n = 0; n < 2 * i + 1; n++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}