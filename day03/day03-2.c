#include <stdio.h>

int p(int num);

int main() {
	int num;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);
	int result = p(num);
	printf("result = %d", result);
}

int p(int num) {
	int res;
	if (num == 0 || num == 1) {
		res = 1;
		return res;
	}
	res = num * p(num - 1);
	return res;
}