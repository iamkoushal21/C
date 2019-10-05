#include<stdio.h>
#include<string.h>

int visited[256],i;
int calculateunique() {
	int sum = 0,k;
	for(int k=0;k<256;k++) {
		if (visited[k] == 1){
		sum = sum + visited[k];
	} 

int visited[256],i;
int calculateunique() {
	}

	return sum;
}

void reset() {
	for (i=0; i< 256;i++) {
		visited[i] = 0;
	}
}

void main() {
	int answer = 1;
	int length, i,j, unique;
	char str[100];
	printf("enter the string  ");
	scanf("%s", str);
	printf("\n %s\n", str);
	length = strlen(str);
	
	reset();
	for (i = 0; i<length; i++) {
		for (j = i; j < length; j++) {
			visited[str[j]]++;
			if (visited[str[j]] > 1) {
				if (answer < calculateunique() -1) {
					answer = calculateunique();
				}	
				       	reset();
			       		break;	       
			}
			if (answer < calculateunique()) {
				answer = calculateunique();
			}

		}
	}

	printf("%d", answer);
}
