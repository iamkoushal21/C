#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, names ;
    char str[20][50], temp[50];
    scanf("%d", &names);
    for(i=0; i<names; ++i)
        scanf("%s",str[i]);
    
    for(i=0; i< names-1; ++i)
        for(j=i+1; j<names ; ++j)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    printf("\nIn lexicographical order: \n");
    for(i=0; i<names; ++i)
    {
        puts(str[i]);
    }
	
    printf("Unique\n");
	int len1=0, len2=0;
    for(i=0;i<names-1;++i) {
		len1 = strlen(str[i]);
		len2 = strlen(str[i+1]);
		if (len1 != len2) {
			printf("%s\n", str[i]);
		} else {
			int k = 0;
		while((str[i][k] == str[i+1][k]) && (str[i][k] != '\0')) {
				k++;
			} 
			if (k == len1) {
				continue;
			} else {
				 printf("%s\n", str[i]);
			}
		}

	}
	printf("%s", str[names-1]);
    return 0;
}
