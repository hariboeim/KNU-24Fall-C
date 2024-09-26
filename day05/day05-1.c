#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int N;
	int* num;
	int* score;
	char** name;
	printf("�л� ��: ");
	scanf_s("%d", &N);

	num = (int*)malloc(sizeof(int) * N);
	score = (int*)malloc(sizeof(int) * N);
	name = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(sizeof(char) * 100);
	}

	for (int a = 0; a < N; a++) {
		printf("�й� :");
		scanf_s("%d", &num[a]);

		printf("�̸� :");
		scanf_s("%s", name[a], 100);

		printf("���� :");
		scanf_s("%d", &score[a]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", num[i], name[i], score[i]);
	}

	int average, ave = 0;

	for (int i = 0; i < N; i++) {
		ave += score[i];
	}
	average = ave / N;
	printf("��� : %d\n", average);

	int min = score[0], max = score[0];
	for (int i = 1; i < N; i++) {
		if (score[i] < min) {
			min = score[i];
		}
		if (score[i] > max) {
			max = score[i];
		}
	}

	printf("�ּ� ����: %d\n", min);
	printf("�ִ� ����: %d\n", max);



	free(num);
	free(score);
	for(int i =0; i<N; i++) free(name[i]);
	free(name);



	return 0;
}