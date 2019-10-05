#include <stdio.h>
#include <stdlib.h>

int capacity;
int size;

void delete(int index, int *ptr)
{
	int i;
	if (index != size - 1) {
		i  = index;
		while (i <= size - 2) {
			*(ptr + i) = *(ptr + i + 1);
			i++;
		}
	}	
	size--;
	if (size <= capacity / 4) {
		capacity = capacity / 2;
	}
	printf("Capacity: %3d, Size:%3d, Elements:", capacity, size);
	i = 0;
	while (i <= size - 1) {
		printf("%3d", *(ptr + i));
		i++;
	}
	printf("\n");
}

void value(int value, int *ptr) 
{
	int i = 0;
	int pos = 0;
	while (i <= size - 1) {
		if (value == *(ptr + i)) {
			pos = i;
			break;
		}
		i++;
	}
	delete(pos, ptr);
}

void allitembyvalue(int value, int *ptr) 
{
	int i = 0;
	int pos = 0;
	while (i <= size - 1) {
		if (value == *(ptr + i)) {
			pos = i;
			delete(pos, ptr);
		} else {
			i++;
		}
	}
}

int main() 
{
	int i;
	int index;
	int *ptr = NULL;
	printf("Enter capacity, size, elements\n");
	scanf("%d%d", &capacity, &size);
	ptr = (int *) calloc(capacity, sizeof(int));
	for (i  = 0; i < size; i++) {
		scanf("%d", (ptr + i));
	}
	printf("Enter index to delete: ");
	scanf("%d", &index);
	delete(index, ptr);

	printf("Delete the first item by value: ");
	scanf("%d", &index);
	value(index, ptr);
	

	printf("Delete all items by value: ");
	scanf("%d", &index);
	allitembyvalue(index, ptr);
}

