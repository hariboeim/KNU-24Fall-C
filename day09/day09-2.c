#include <stdio.h>

struct Product {
	int ID;
	char name[20];
	int price;
};

void printProduct(struct Product p) {
	
	printf("��ǰ ID : %d\n", p.ID);
	printf("��ǰ�� : %s\n", p.name);
	printf("���� : %d\n", p.price);
}

int main() {
	struct Product p[5];
	int i, count = 0;

	for (i = 0; i < 5; i++) {
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &p[i].ID);
		if (p[i].ID == 0) {
			break;
		}
		printf("��ǰ�� : ");
		scanf_s("%s", p[i].name, 20);
		printf("���� : ");
		scanf_s("%d", &p[i].price);
		printf("\n");

		count++;
	}
	for (i = 0; i < count; i++) {
		printf("<<�Էµ� ��ǰ ���>>\n");
		printf("\n");
		printProduct(p[i]);
	}
	return 0;
}