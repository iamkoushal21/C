#include <stdio.h>

int main() 
{
	int nos, i, j, k, l;
	int matrix[20][20];
	printf("Enter size of square matrix: ");
	scanf("%d", &nos);
	printf("Enter data of matrix: \n");
	for (i = 0; i < nos; i++) {
		for (j = 0; j < nos; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Zig Zag manner nodes will be printed like this: \n");
	for (k = 0; k < nos; k++) {
		j = k;
		i = 0;
		while (i + j == k && (!(i > nos -1) && !(j < 0))) {
			if (k %2 == 0) {
				printf("%d ", matrix[j][i]);
			} else {
				printf("%d ", matrix[i][j]);
			}
			j--;
			i++;
		}
	}
	l = 1;
	for (k = nos; k < 2* nos -2; k++) {
		j = nos -1;
		i = l;
		while (i + j == k && (!(i > nos -1) && !(j < 0))) {
			if (k %2 == 0) {
				printf("%d ", matrix[j][i]);
			} else {
				printf("%d ", matrix[i][j]);
			}
			j--;
			i++;
		}
		l++;	
	}
	printf("%d ", matrix[nos-1][nos-1]);
	
	return 0;
}
