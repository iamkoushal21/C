#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;

node* createNode(int setmember) {
	node* allocation = (node*) malloc(sizeof(node));
	if (allocation == NULL) {
		printf("Memory Overflow");
		exit(0);
	}
	allocation -> data = setmember;
	allocation -> next = NULL;
	
	return allocation;
}

void  multisetUnion(node* setone, node* settwo) {
	node* temp = setone;
	
	while (setone -> next != NULL) {
		setone = setone -> next;
	}	
	setone -> next = settwo;
	while(temp) {
		printf("%d  ", temp -> data);	
		temp = temp -> next;
	}
}

void singleSetUnion(node* setonehead, node* settwohead) {
	node* temp3 = setonehead, *temp4;
	node* temp = settwohead, *temp2 = settwohead -> next;
	while(setonehead) {
		int member = setonehead -> data;
		if (temp && settwohead && settwohead == temp && member == temp -> data)  {
			settwohead  = temp -> next;
			free(temp);
		} else {
			while (temp2) {
				if (member == temp2 -> data) {
					temp -> next = temp2 -> next;
					temp4 = temp2;
					free(temp4);
				}
				temp = temp -> next;
				temp2 = temp2 -> next;
			}
		}
		temp = settwohead;
		if (temp) {
			temp2 = temp -> next;
		}
		setonehead = setonehead -> next;
	}
	
	temp = temp3;
	while (temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = settwohead;

	printf("------------------");
	while(temp3) {
		printf("%d  ", temp3 -> data);
		temp3 = temp3 -> next;
	}
}

void main() {
	int ele1, ele2,i, number;
	node* setonehead, * settwoHead,* temp, *temp2;
	printf("Enter number of elements in set one  ");
	scanf("%d", &ele1);
	printf("\nEnter number of elements in set two  ");
	scanf("%d", &ele2);

	for (i=0;i<ele1;i++) {
		printf("\nEnter %d element of set one  ", i+1);
		scanf("%d", &number);
		temp = createNode(number);
		if (i == 0) {
			setonehead = temp;
			temp2 = temp;
		} else {
			temp2 -> next = temp;
			temp2 = temp;
		}
	}	

	for (i=0;i<ele2;i++) {
		printf("\nEnter %d element of set two  ", i+1);
		scanf("%d", &number);
		temp = createNode(number);
		if (i == 0) {
			settwoHead = temp;
			temp2 = temp;
		} else {
			temp2 -> next = temp;
			temp2 = temp;
		}
	}	
	
	temp = NULL; temp2 = NULL;	
	printf("--------------------");
	singleSetUnion(setonehead, settwoHead);
}
