#include <stdio.h>
#include <stdlib.h>

int main()
{
	int capacity;
	int size;
	int *ptr = NULL;
	int nos;
	int k;
	int i;
	capacity = 1;
	size = 0;
	scanf("%d", &nos);
	int arr[nos];
	for (i = 0; i < nos; i++) {
		printf("Enter %d item: ", i + 1);
		scanf("%d", &arr[i]);
	}
	ptr = (int *) calloc(size, sizeof(int));
	for (i = 0; i < nos; i++) {
		if (capacity == size) {
			capacity = 2 * capacity;
			ptr = (int *) realloc(ptr, capacity * sizeof(int));	
		}
		*(ptr + i) = arr[i];
		size++;
		printf("capacity: %2d, size: %2d, elements: ", capacity, size);
		k = 0;
		while (k <= i) {
			printf("%3d", *(ptr + k));
			k++;
		}
		printf("\n");
	
	}
}
