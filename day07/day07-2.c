#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	double x = 0;
	double y = 0;
	int r = 0;
	int p = pow(10, 7);

	int count = 0, circle = 0;
	double R = 0;

	printf("몬테 카를로 알고리즘\n");
	printf("정사각형 변의 길이를 입력하세요\n");
	printf("변의 길이 : ");
	scanf_s("%d", &r);

	srand(time(NULL));

	if (r > 0) {
		while (count < pow(10, 9)) {
			x = (double)rand() / (double)RAND_MAX * r;
			y = (double)rand() / (double)RAND_MAX * r;
			count++;
			int c = count / p;
			if (x * x + y * y < r * r) {
				circle++;
			}
			if (count % p == 0) {
				R = 4 * ((double)circle / (double)count);
				printf("%d%%진행.. 원주율 : %lf ", c, R);
				for (int k = 0; k < 20; k++) {

					if (c / 5 > k) {
						printf("■");
					}
					else {
						printf("□");
					}
				}
				printf("\n");
			}
		}
		printf("원주율 : %lf", R);
	}
	else {
		printf("잘못된 입력값 입니다.\n");
		printf("프로그램을 다시 시작하시오\n");
	}
	return 0;
}