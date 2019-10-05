#include <stdio.h>
#include <math.h>

int main() 
{
	int k, size, i, j, l = 0,m = 0, check;
	printf("Enter the no. of times permutaion will be performed:  ");
	scanf("%d", &k);
	size = pow(2,k+1);	
	double set[size], set2[size];
	double len, start;
	printf("Enter the starting value and last value of line: \n");
	scanf("%lf%lf", &set[0], &set[1]);
	for(i = 1;i <= k; i++) {
		m = 0;
		len = set[1] - set[0];
		len = len/3;
		check = pow(2,i);
		for (j = 0; j < check ; j++) {
			start = set[j];
			for(l = 0; l < 4; l++) {
				set2[m++] = start;		
				start += len;
			}
			j++;
		}	
		for(l = 0; l < m; l++) {
			set[l] = set2[l];
		}
	}
	for (i = 0; i < size; i++) {
		(i % 2 == 0) ? printf("%lf", set[i]) : printf("----%lf  ", set[i]);
	}
}

