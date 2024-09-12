#include <stdio.h>

int main() {
	int n = 0;
	for (; n <= 99; n++) {
		if (n % 7 == 0 || n % (3 * 4) == 0) {
			printf("%d ", n);
		}
	}
	return 0;

}