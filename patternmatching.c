#include <stdio.h>
#include <string.h>

int * prefixpattern(char pattern[50], int plen) 
{
	static int prefixgen[50];
	int j, i;
	prefixgen[0] = 0;
	j = 0;
	for (i = 1; i < plen; i++) {
		if (pattern[i] == pattern[j]) {
			prefixgen[i] = j + 1; 
		} else if (j > 0){
			j = prefixgen[j - 1];
		} else {
			prefixgen[i] = 0;
			i++;
		}	
	}

	return prefixgen;
}

int main() 
{
	char str[50];
	char pattern[50];
	int *prefixgen;
	int i, j, k;
	int patternlen, strlength;
	printf("Enter String: ");
	scanf("%s", str);
	printf("Enter Pattern: ");
	scanf("%s", pattern);
	patternlen = strlen(pattern);
	strlength = strlen(str);
	/*Naiva Approach 
	for (i = 0; i <= strlength - patternlen; i++) {
		k = 0;
		while (k < patternlen) {
			if (pattern[k] !=  str[i+k]) {
				break;;
			}
			k++;
		}
		if (k == patternlen) {
			printf("%d, ", i + 1);
		}
	}*/

	//KMP
	prefixgen = prefixpattern(pattern, patternlen);
	while (i < strlength) {
		if (str[i] == pattern[j]) {
			if (j == patternlen - 1) {
				printf("%d, ", i - j + 1);
				j = 0;
				i++;
			} else {
				i++;
				j++;
			}
		} else if (j > 0) {
			j = prefixgen[j - 1];
		} else {
			i++;
		}
	}
}
