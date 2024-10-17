#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* sen = (char*)malloc(100 * sizeof(char));

	printf("공백, 특수문자 제외하고 문자열을 입력하세요 : ");
	scanf_s("%99s", sen, 100);
	//99를 써 준 이유는 최대 글자를 99까지 입력받겠다는 뜻이고,
	//100은 입력받을 버퍼의 크기(동적 할당된 sen의 크기)를 명시해 주어야지 되기 때문

	char* s = sen;
	char* f = sen + strlen(sen) -1; 
	//내가 입력한 것에서 맨 마지막꺼를 찾는것임
	//이때 -1인 이유는 마지막에 NULL을 빼주기 위한 것임
	//sen을 더해준 이유는 strlen이 문자열을 복사해 오는거라 
	//strlen(sen) -1을 하면 똑같이 나옴

	while (s < f) {
		char a = *s;
		*s = *f;
		*f = a;

		s++;
		f--;
	}

	printf("뒤집어진 문자열 : %s", sen);
	free(sen);
	return 0;

}
