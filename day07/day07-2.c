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

	printf("���� ī���� �˰���\n");
	printf("���簢�� ���� ���̸� �Է��ϼ���\n");
	printf("���� ���� : ");
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
				printf("%d%%����.. ������ : %lf ", c, R);
				for (int k = 0; k < 20; k++) {

					if (c / 5 > k) {
						printf("��");
					}
					else {
						printf("��");
					}
				}
				printf("\n");
			}
		}
		printf("������ : %lf", R);
	}
	else {
		printf("�߸��� �Է°� �Դϴ�.\n");
		printf("���α׷��� �ٽ� �����Ͻÿ�\n");
	}
	return 0;
}