#include<stdio.h>
#define N 50

void transpose(int arr[N][N], int* m, int*n) {
	for (int k=0;k< *n; k++) {
		for (int l=0;l< *m; l++) {
			printf("%d ", arr[l][k]);
		}
		printf("\n");
	}
}

void main() {

	int i,j, m,n;
	int matrix[N][N];
	printf("Enter no of rows");
	scanf("%d", &m);
	printf("Enter the no 0f columns");
	scanf("%d", &n);
	printf("Enter the matrix\n");
	for (i =0;i< m;i++) {
		for (j =0; j<n;j++) {
			scanf("%d", &matrix[i][j]);		
		}
	}

	for (i =0;i< m;i++) {
		for (j =0; j<n;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	transpose(matrix, &m, &n);
}

