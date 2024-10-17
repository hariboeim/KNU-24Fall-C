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

	printf("배열 출력:\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", array[j][i]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	void* now = array; //맨 처음 배열의 위치
	int num = *((int*)array); //맨 처음 배열값
	int x = 0;

	while(1) {
		num = *((int*)array + x); //처음에는 더해져도 0이라서 그대로임
		printf("현재 위치 : (%d, %d) , 배열의 값 : %d\n", x / 10, x % 10, num);
		x += num; //배열은 일자 출력이기 때문에 그대로 더해주면 됨 

		if (x> 100) {
			x -= num; //x의 값이 100을 넘을 때 멈추는거기 때문에 한번 더해진 값은 빼져야함
		
			printf("더 이상 이동할 수 없습니다.\n");
			printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x/10, x % 10, num);
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