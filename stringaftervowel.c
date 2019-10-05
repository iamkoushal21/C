#include<stdio.h>
#include<string.h>

void main() {
	int T;
	int a[26],len,j = 0,len1,len2,k;
	char str1[100], str2[100];
	char str3[100], str4[100];
	scanf("%d", &T);
	for(int i=0;i<T;i++) {
		scanf("%s", str1);
		scanf("%s", str2);
		len = strlen(str1);
		j = 0;
		k =0;
		while(j != len) {
			if ((str1[j] != 'a') && (str1[j] != 'e') && (str1[j] != 'i') && (str1[j] != 'o') && (str1[j] != 'u') && (str1[j] != '\0')) {				str3[k++] = str1[j++];		
			} else {
				j++;
				continue;
			}
	
		}
		printf("%d", k);
		str3[k] = '\0';
		j =0;
		len = strlen(str2);
		k = 0;
		while(j != len) {
			if ((str2[j] != 'a') && (str2[j] != 'e') && (str2[j] != 'i') && (str2[j] != 'o') && (str2[j] != 'u') && (str2[j] != '\0')) {
				str4[k++] = str2[j++];		
			} else {
				j++;
				continue;
			}
	
		}
		printf("%d", k);
		str4[k] = '\0';	
		 if(strcmp(str3, str4) ==0) {
		printf("Yes\n");	
	
	} 	else {
		printf("No\n");	
}
		
	}
}
