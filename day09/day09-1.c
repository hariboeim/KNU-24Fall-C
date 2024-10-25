#include <stdio.h>

struct vector {
	float x;
	float y;
	float z;
};

void plus(struct vector v1, struct vector v2) {
	float totalx = 0, totaly = 0, totalz = 0;
	totalx = v1.x + v2.x;
	totaly = v1.y + v2.y;
	totalz = v1.z + v2.z;
	printf("벡터의 합은 x:%.1f, y:%.1f, z:%.1f ", totalx, totaly, totalz);
}

void minus(struct vector v1, struct vector v2) {
	float totalx = 0, totaly = 0, totalz = 0;
	totalx = v1.x - v2.x;
	totaly = v1.y - v2.y;
	totalz = v1.z - v2.z;
	printf("벡터의 차는 x:%.1f, y:%.1f, z:%.1f ", totalx, totaly, totalz);
}

void in(struct vector v1, struct vector v2) {
	float totalx = 0, totaly = 0, totalz = 0;
	totalx = v1.x * v2.x;
	totaly = v1.y * v2.y;
	totalz = v1.z * v2.z;
	printf("벡터의 내적은 x:%.1f, y:%.1f, z:%.1f ", totalx, totaly, totalz);
}

void out(struct vector v1, struct vector v2) {
	float totalx = 0, totaly = 0, totalz = 0;
	totalx = (v1.y * v2.z) - (v1.z * v2.y);
	totaly = (v1.z * v2.x) - (v1.x * v2.z);
	totalz = (v1.x * v2.y) - (v1.y * v2.x);
	printf("벡터의 외적은 x:%.1f, y:%.1f, z:%.1f ", totalx, totaly, totalz);
}


int main() {
	struct vector v1;
	struct vector v2;
	int num = 0;
	printf("첫번째 벡터(x,y,z) : ");
	scanf_s("%f", &v1.x);
	scanf_s("%f", &v1.y);
	scanf_s("%f", &v1.z);


	printf("두번째 벡터(x,y,z) : ");
	scanf_s("%f", &v2.x);
	scanf_s("%f", &v2.y);
	scanf_s("%f", &v2.z);

	printf("\n입력된 첫번째 벡터 %.1f, %.1f, %.1f\n", v1.x, v1.y, v1.z);
	printf("입력된 두번째 벡터 %.1f, %.1f, %.1f\n", v2.x, v2.y, v2.z);
	printf("\n");
	printf("------------------------");
	printf("\n");
	printf("1.벡터의 합\n");
	printf("2.벡터의 차\n");
	printf("3.벡터의 외적\n");
	printf("4.벡터의 내적\n");
	printf("5.종료\n");
	printf("------------------------");
	printf("\n명령 입력 : ");
	scanf_s("%d", &num);

	if (num == 1) {
		plus(v1, v2);
	}
	else if (num == 2) {
		minus(v1, v2);
	}
	else if (num == 3) {
		out(v1, v2);
	}
	else if (num == 4) {
		in(v1, v2);
	}
	else if (num == 5) {
		printf("프로그램을 종료합니다.");
		return 0;
	}
	else {
		printf("잘못된 입력입니다.\n");
		printf("프로그램을 종료합니다.\n");
		return 0;
	}
}