#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;	
}node;

node * createlist(int n) 
{
	int data;
	int i;
	node *temp = NULL;
	node *head = NULL;
	node *temp2 = NULL;
	for (i = 0; i < n; i++) {
		printf("Enter %d data", i+1);
		scanf("%d", &data);
		temp = (node *) malloc(sizeof(node));
		if (temp == NULL) {
			printf("\nMemory overflow");
			
			return temp;
		}
		temp->next = NULL;
		temp->data = data;
		if (head == NULL) {
			head = temp;
			temp2 = temp;
		} else {
			temp2->next = temp;
			temp2 = temp;
		}
	}

	return head;
}

node * check(node *head) 
{
	int i;
	int j;
	node *temp = NULL;
	node *temp2 = NULL;
	node * temp3 = NULL;
	printf("Enter i = ");
	scanf("%d", &i);
	printf("Enter j = ");
	scanf("%d", &j);
	if (head == NULL) {
		printf("\nNo Element in List");

		return head;
	}
	temp = head;
	while (temp->data != i && (temp->next != NULL)) {
		if (temp->next != NULL) {
			temp = temp->next;
		} else {
			return head;
		}
	}
	temp2 = temp->next;
	while (temp2 != NULL && temp2->data != j) {
		temp3 = temp2;
		free(temp3);
		temp2 = temp2->next;
	}
	temp->next = temp2;

	return head;
}

void printlist(node *head) 
{
	if (head == NULL) {
		printf("NO memory in list");

		return;
	}
	while (head != NULL) {
		printf("%d ->", head->data);
		head = head->next;
	}
	printf("NULL");
}

int main()
{	int n;
	node *head = NULL;
	n = 0;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	head = createlist(n);
	head = check(head);
	printlist(head);
}
