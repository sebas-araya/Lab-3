#include <stdio.h>

int factorial (int n) {
	int i = 1;
	while (n > 1) {
		i=i * n;
		n = n - 1;
	}
	return i;
}

int main() {
	int num;
	printf("Ingrese un número: ");
	scanf("%d", &num);

	printf("%d! = %d\n", num, factorial(num));
	return 0;
}
