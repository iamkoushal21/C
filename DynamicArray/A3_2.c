#include <stdio.h>
#include <stdlib.h>

int capacity;
int size;

void pop(int *ptr)
{
	int i;
	size--;
	if (size <= capacity / 4) {
		capacity = capacity/2;
	}
	printf("Capacity: %3d, Size:%3d, Elements:", capacity, size);
	i = 0;
	while (i < size) {
		printf("%3d", *(ptr + i));
		i++;	
	}
	printf("\n");
}

int main() 
{
	int i;
	int *ptr = NULL;
	int pop_back;
	printf("Enter capacity, size, elements, pop back calls\n");
	scanf("%d%d", &capacity, &size);
	ptr = (int *) calloc(capacity, sizeof(int));
	for (i  = 0; i < size; i++) {
		scanf("%d", (ptr + i));
	}
	scanf("%d", &pop_back);
	while (pop_back >= 1) {
		pop(ptr);
		pop_back--;
	}
}

