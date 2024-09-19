#include <stdio.h>

int is_prime_num(int num);
int main() {
	int num;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);
	int result = is_prime_num(num);
	printf("%d\n", result);
	return 0;
}

int is_prime_num(int num) {

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;

}