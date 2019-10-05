#include<stdio.h>

void transpose(int, int*);
void printmatrix(int, int*);
int main() 
{
	int i;
	int j;
	int num;
	scanf("%d", &num);
	int matrix[num][num];
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}	
	transpose(num, &matrix[0][0]);
	printmatrix(num, &matrix[0][0]);
	
	return 0;
}

void transpose(int n, int *mat) 
{
	int i;
	int j;
       	int temp;
	int (*a)[n] = (int (*) []) (mat);
	for (i = 0; i < n; i++) {
		for (j = i; j < n;j++) {
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
}	

void printmatrix(int n, int *mat) {
	int i;
	int j;
        int (*a)[n] = (int (*) []) mat;
        for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                        printf("%3d", a[i][j]);
                }      
		printf("\n");       
	}
}
