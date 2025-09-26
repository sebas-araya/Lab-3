#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int findLargestLine(int matrix[][SIZE], int n) {
	int sum = 0;
	int i, j;

	for (j = 0; j<n; j++) /*usa la primera fila de referencia*/
		sum+=matrix[0][j];

	for (i=1; i<n; i++) {
		int sumafila=0;
		for (j=0; j <n; j++)
			sumafila += matrix [i][j];
		if (sumafila != sum) return 0;
	}

	for (j=0; j < n; j++) {
		int sumaCol=0;
		for (i=0; i < n; i++)
			sumaCol+= matrix[i][j];
		if (sumaCol != sum) return 0;
	}

	int sumaDiag1=0, sumaDiag2=0;
	for(i=0; i<n; i++) {
		sumaDiag1 += matrix[i][i];
		sumaDiag2 += matrix[i][n -i -1];
	}
	if(sumaDiag1 != sum || sumaDiag2 != sum) return 0;

	return 1;
}

void imprimirMatriz(int matrix[][SIZE], int n) {
	int i,j;
	for (i=0; i < n; i++) {
		for (j=0; j < n; j++)
			printf("%3d ", matrix[i][j]);
		printf("\n");
	}
}

int main() {
	int i,j;
	int base = 3;
	int matrix[SIZE][SIZE] = {
		{2,7,6},
		{9,5,1},
		{4,3,8}

	};

	printf("La matriz utilizada corresponde a: \n");
	imprimirMatriz(matrix, base);

	if (findLargestLine(matrix, base))
		printf("La matriz es cuadrada mágico \n");
	else
		printf("La matriz no es cuadrado mágico \n");

	srand((unsigned int) time(NULL));
	int aleatoria[SIZE][SIZE];
	for (i=0; i <SIZE;  i++)
		for (j=0; j<SIZE;  j++)
			aleatoria[i][j] = rand() %  25 + 1;
	printf("\nMatriz aleatoria creada: \n");
		imprimirMatriz(aleatoria, SIZE);

	if (findLargestLine(aleatoria, SIZE))
		printf("La matriz aleatoria es cuadrada magica .\n");
	else
		printf("La matriz aleatoria no es cuadrado magico \n");
	return 0;
}
