#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* sen = (char*)malloc(100 * sizeof(char));

	printf("����, Ư������ �����ϰ� ���ڿ��� �Է��ϼ��� : ");
	scanf_s("%99s", sen, 100);
	//99�� �� �� ������ �ִ� ���ڸ� 99���� �Է¹ްڴٴ� ���̰�,
	//100�� �Է¹��� ������ ũ��(���� �Ҵ�� sen�� ũ��)�� ����� �־���� �Ǳ� ����

	char* s = sen;
	char* f = sen + strlen(sen) -1; 
	//���� �Է��� �Ϳ��� �� ���������� ã�°���
	//�̶� -1�� ������ �������� NULL�� ���ֱ� ���� ����
	//sen�� ������ ������ strlen�� ���ڿ��� ������ ���°Ŷ� 
	//strlen(sen) -1�� �ϸ� �Ȱ��� ����

	while (s < f) {
		char a = *s;
		*s = *f;
		*f = a;

		s++;
		f--;
	}

	printf("�������� ���ڿ� : %s", sen);
	free(sen);
	return 0;

}
