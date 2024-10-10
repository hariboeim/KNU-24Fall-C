#include <stdio.h>

int main() {
	int num;

	printf("피라미드 층 수를 입력하세요.\n");
	printf("층 수 : ");
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