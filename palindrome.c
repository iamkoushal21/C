#include <stdio.h>
#include <string.h>
void checkpalindrome(char *str) 
{
	int len;
	len = strlen(str);
	int i = 0;
	while (i < len/2) {
		if (str[i] == str[len-i-1]) {
			i++;
		} else {
			break;			
		}
	}

	if (i == (len/2)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() 
{
	int nos,i;
	char strings[20][30];
	scanf("%d", &nos);
	for (i = 0; i < nos; i++) {
		scanf("%s", strings[i]);
	}
	
	for (i = 0; i< nos; i++) {
		checkpalindrome(strings[i]);
	}
}
