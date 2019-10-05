#include<stdio.h>

int main()
{
	int nos;
	int row, column;
	int value;
	int i,j;
	printf("Enter the odd size of Magic square matrix: ");
	scanf("%d",&nos);
	int magic[nos][nos];
	for (i = 0; i < nos; i++)	{
		for (j = 0; j < nos; j++) {
			magic[i][j] = 0;
		}	
	}
	row = nos / 2;
	column = nos - 1;
	for (value = 1; value  <= nos*nos; ++value) {
		if (row == -1 && column == nos) {
			row = 0;
			column = nos - 2;
		} else {
			if (row == -1) {
				row = nos - 1;
			}
			if (column == nos) {
		       		column = 0;
			}
		}
		if (magic[row][column]) {
			column = column - 2;
			row = row + 1;
			magic[row][column] = value;
		} else {
			magic[row][column] = value;
		}
		column++;
		row--;
	}

	printf("Magic Square is: \n");
	for(i = 0; i < nos; i++) {
		for(j = 0; j < nos; j++) {
			printf("%3d ",magic[i][j]);
		}
		printf("\n");
	}
}
