#include <stdio.h>

int p(int num);

int main() {
	int num;
	printf("계산할 팩토리얼 값 입력 : ");
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