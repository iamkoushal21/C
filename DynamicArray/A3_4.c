#include <stdio.h>

int main()
{
	int data;
	FILE *file = NULL;
	file = fopen("A3_4.txt", "r");
	if (file == NULL) {
		printf("File not found\n");
	} else {
		printf("Yes");
	}
	while (!feof(file)) {
		fscanf(file,"%d,", &data);
		printf("%d -> ", data);
	}
	fprintf(file, "2`");
	fclose(file);
}
