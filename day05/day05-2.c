#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int num;
	char name[100];
	int score;
};

int main() {

	int N;
	struct Student person[2];

	person[0].num = 1111;
	strcpy_s(person[0].name, 100, "ö��");
	person[0].score = 100;

	printf("%d, %s, %d", person[0].num, person[0].name, person[0].score);


	return 0;
}