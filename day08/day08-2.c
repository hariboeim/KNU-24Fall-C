#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {

	printf("�迭 ���:\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", array[j][i]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	void* now = array; //�� ó�� �迭�� ��ġ
	int num = *((int*)array); //�� ó�� �迭��
	int x = 0;

	while(1) {
		num = *((int*)array + x); //ó������ �������� 0�̶� �״����
		printf("���� ��ġ : (%d, %d) , �迭�� �� : %d\n", x / 10, x % 10, num);
		x += num; //�迭�� ���� ����̱� ������ �״�� �����ָ� �� 

		if (x> 100) {
			x -= num; //x�� ���� 100�� ���� �� ���ߴ°ű� ������ �ѹ� ������ ���� ��������
		
			printf("�� �̻� �̵��� �� �����ϴ�.\n");
			printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x/10, x % 10, num);
			break;
		}

	}
}

int main() {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}