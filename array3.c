#include<stdio.h>
#define N 50

void main() {

	int i,j, rows;
	int matrix[N][N];
	printf("Enter no of rows");
	scanf("%d", &rows);
	printf("Enter the matrix\n");
	for (i =0;i< rows;i++) {
		for (j =0; j<rows;j++) {
			scanf("%d", &matrix[i][j]);		
		}
	}

	for (i =0;i<rows;i++) {
		for (j =0;j<rows;j++) {
			if (i == j) {
				sum = matrix[i+1][j] + matrix[i][]
			}
		}
	}

}
