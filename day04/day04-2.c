#include <stdio.h>

void swap(int* pnum1, int* pnum2) {
	int c = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = c;

}


int main() {
	int a = 10, b = 20;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
