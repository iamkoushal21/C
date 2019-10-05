//Problem :- divide a 2D array in 4 matrix suxh that sum of each matrix is equal - Yes or No.



#include <stdio.h>

int main()
{
	int arr[4][4];
	int i,j,k,l;
	int n= 4;
	int lsum, rsum, lbottom, rbottom;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			lsum = 0;
			for (k = 0; k <= i; k++) {
				for (l = 0; l <= j; l++) {
					lsum += arr[k][l];
				}
			}

			rsum = 0;
			for (k = 0; k <= i; k++) {
				for (l = j+1; l < n; l++) {
					rsum += arr[k][l];
				}
			}

			lbottom = 0;
			for (k = i+1; k < n; k++) {
				for (l = 0; l <= j; l++) {
					lbottom += arr[k][l];
				}
			}

			rbottom = 0;
			for (k = i+1; k < n; k++) {
				for (l = j+1; l < n; l++) {
					rbottom += arr[k][l];
				}
			}
			if (lsum == rsum && rsum == lbottom && lbottom == rbottom) {
				printf("YES- %d", lsum);

				return 0;
			} else {
				if (j == 2 && i == 2)
				printf("NO\n");
		}
		}
	}
}
