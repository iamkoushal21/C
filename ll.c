#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef struct dllnode {
	int data;
	struct dllnode *previous;
	struct dllnode *next;
}dllnode;

node * insertAtBegin(node *, int);
void insertAtEnd(node *, int);
void printlist(node *);
int  listlength(node *);
node * deleteAtBegin(node *);
node * deleteAtEnd(node *);
node * deleteAtPosition(node *, int);
void printmaxmin(node *head);
void sumofevenincll(node *head);
dllnode * reverseDLL(dllnode *dll);

void printlist(node *head)
{
	if (head == NULL) {
		printf("No element");
		
		return;
	}
	printf("%d -> ", head->data);
	while (head->next != NULL) {
		head = head->next;
		printf("%d -> ", head->data);
	}
}

int listlength(node *head) {
	int k = 0;
	if (head == NULL) {
		return k;
	}	
	k++;
	while (head->next != NULL) {
		k++;
		head = head->next;
	}

	return k;
}

void insertAtPos(node *head, int pos, int data)
{
	int length;
	length = listlength(head);
	if (pos <= 0 || pos > length + 1) {
		printf("Wrong Position");

		return;
	} else {
		 if (pos == length + 1) {
			insertAtEnd(head, data);
		} else {
			int k = 0;
			node *temp = (node *) malloc(sizeof(node));
			if (temp == NULL) {
				printf("\nMemory Overflow");
				
				return;
			}
			temp->data = data;
			temp->next = NULL;
			k++;
			while (k < pos - 1) {
				head = head->next;
				k++;
			}
			temp->next = head->next;
			head->next = temp;
			temp = NULL;
		}
	}
}

node * insertAtBegin(node *head, int data) 
{
	node *temp = NULL;
	temp = (node *) malloc(sizeof(node));
	if (temp == NULL) {
		printf("Memory Overflow");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	if (head != NULL) {
		temp->next = head;
	}	

	return temp;
}

void insertAtEnd(node *head, int data)
{
	node *temp = NULL;
	temp = (node *) malloc(sizeof(node));
	if (temp == NULL) {
		printf("Memory Overflow");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = temp;
	temp = NULL;
}

node * deleteAtPos(node *head, int pos) 
{
	int length, k;
	node *temp = NULL, *temp2 = NULL;
	length = listlength(head);
	if (pos <= 0 || pos > length) {
		printf("Invalid Position");
		exit(1);
	}
	if (pos == 1) {
		temp = deleteAtBegin(head);
	} else if (pos == length) {
		temp = deleteAtEnd(head);
	} else {
		k = 1;
		temp2 = head;
		while (k < pos) {
			temp = temp2;
			temp2 = temp2->next;
			k++;
		}
		temp->next = temp2->next;
		free(temp2);
		temp = head;
		temp2 = NULL;
	}
	
	return temp;
}

node * deleteAtBegin(node *head) 
{
	node * temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
	
	return head;
}

node * deleteAtEnd(node *head) 
{
	node *temp = NULL, *temp2 = head;
	while (temp2->next != NULL) {
		temp = temp2;
		temp2 = temp2->next;
	}
	temp->next = NULL;
	free(temp2);
	temp = NULL;
	temp2 = NULL;

	return head;

}

void printmaxmin(node *head)
{
	int max, min;
	if (head == NULL) {
		printf("List Empty, So no max - min");
		return;
	}
	max = head->data;
	min = head->data;	
	while (head->next != NULL) {
		head = head->next;
		if (max < head->data) {
			max = head->data;
		}
		if (min > head->data) {
			min = head->data;
		}
	}

	printf("\nMax is - %d\nMin is - %d\nMax-Min is - %d", max, min, max-min);
}

void sumofevenincll(node *cll)
{
	int sum = 0;
	node *temp = NULL;
	temp = cll;
	if (cll == NULL) {
		printf("\nSum of even in CLL - %d", 0);

		return;
	}
	if (temp->data % 2 == 0) {
		sum  = temp->data;
	}
	while (temp->next != cll) {
		temp = temp->next;
		if (temp->data % 2 == 0) {
			sum += temp->data;
		}
	}
	printf("\nSum of even in CLL - %d", sum);
}	

dllnode * deletesmallestindll(dllnode *dll) 
{
	dllnode *temp = NULL, *temp2 = NULL, *p;
	int min;
	if (dll == NULL) { 
		printf("\nNo element to delete");

		return dll;
	}
	min = dll->data;
	temp = dll;

	if (temp->next == NULL) {
		free(temp);
		dll = NULL;

		return dll;
	}
	
	while (temp->next != NULL) {
		temp = temp->next;
		if (min > temp->data) {
			min = temp->data;
		}
	}
	
	temp = dll;
	while (temp->data == min) {
		temp2 = temp;
		if(temp->next == NULL) {
			free(temp2);
			dll = NULL;
			break;
		} else {
			temp = temp->next;
			temp->previous = NULL;
			dll = temp;
			free(temp2);
		}
	}
	
	while (temp->next != NULL) {
		p = temp;
		temp = temp->next;
		if (min == temp->data) {
			temp2 = temp;
			p->next = temp->next;
			if (temp->next != NULL) {
				temp->next->previous = p;
			}	
			free(temp2);
                }
		
	}

	return dll;
}

dllnode * reverseDLL(dllnode *dll)
{
	dllnode *temp, *t;
	if (dll == NULL) {
		printf("No element in DLL to reverse");
	} else {
		temp = dll;
		while(temp) {	
			dll = temp;
			t = temp->next;
			temp->next = temp->previous;
			temp->previous = t;
			if (t != NULL) {
				temp = t;
				dll = t;
			} else {
				break;
			}
		}
	}

	return dll;
}

void kmultiplevalue(node *head, int k) 
{
	int t = 0;
	if (head == NULL) {
		printf("No element in List to print k multiple value");

		return;
	}
	printf("\n%d -> ", head->data);
	while (head->next != NULL) {
		
		t++;
		head = head->next;
		if (t % k  == 0) {
			printf("%d -> ", head->data);
		}
	}

}

node * ksizereverse(node *head, int k)
{
	node *p = NULL, *q = NULL, *r = head, *end = NULL; 
	int t = 0, i = 0, length = 0, rem = 0;
	if (k == 0 || head == NULL) {
		printf("Invalid list or k");

		return head;
	}
	length = listlength(head);
	if (length % k == 0) {
		length = length / k;
	} else {
		rem = length % k;
		length = length / k + 1;
		
	}
	node* address[length];
	for (i = 0; i < length; i++) {
		t = 0;
		p = NULL;
		q = NULL;
		while((r) && (t < k)) {
			t++;
			if (p == NULL) {
				address[i] = r;
			}
			q = r->next;
			r->next = p;
			p = r;
			r = q;
			if ((i == 0) && (t == k)) {
				head = p;
			} else if (t == k || (rem > 0 && i == length - 1 && t == rem)) {
				address[i-1]->next = p;
			}
		}
	}
	
	return head;
}

void removealternatenodes(node *head)
{
	int k = 1;
	node *temp = NULL, *temp2 = head, *delete = NULL;
	if (head == NULL) {
		printf("No Element in List");
		
		return;
	}
	while (temp2->next != NULL) {
		k++;
		temp = temp2;
		temp2 = temp2->next;
		if (k % 2 == 0) {
			temp->next = temp2->next;
			delete = temp2;
			free(delete);
		}
	}
}

node * removegreaterright(node *head)
{
	node *temp = NULL, *temp2 = NULL, *p = NULL;
	if (head == NULL) 
	{
		printf("\nList is Empty");

		return head;
	}
	temp = head;
	temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
		if (temp->data < temp2->data && head == temp)  {
			free(temp);
			head = temp2;
			temp = temp2;
		} else if (temp2->data > temp->data) {
			if (p != NULL) {
				p->next = temp2;
			}
			free(temp);
			temp = temp2;
		} else {
			p = temp;
			temp = temp2;
		}
	}

	return head;
}

void middleelement(node *head)
{
	node *slow = head, *fast = head;
	if (head == NULL) {
		printf("\nNo Element");
		
		return;
	}	
	while((fast != NULL) && (fast->next != NULL) && (fast->next->next != NULL)) {
		fast = fast->next->next;
		slow = slow->next;
	}
	while((fast != NULL) && (fast->next != NULL)) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("\nMiddle Element is - %d -> NULL", slow->data);
}	

int main() 	
{
	int data, nos, i, pos, k;
	node *head = NULL, *temp = NULL, *temp2 = NULL, *cll = NULL;
	dllnode *dlltemp = NULL, *dlltemp2 = NULL, *dll = NULL;
	printf("Enter no. of elements: ");
	scanf("%d", &nos);
	for (i = 0; i < nos; i++) {
		temp = (node *) malloc(sizeof(node));
		if (temp == NULL) {
			printf("Memory Overflow");
			exit(1);
		}
		printf("Enter %d data: ", i+1);
		scanf("%d", &data);
		temp->data = data;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			temp2 = temp;
		} else {
			temp2->next = temp;
			temp2 = temp;
		}
	}	
	printlist(head);
	temp = NULL;
	temp2 = NULL;
	
	//InsertAtPos
	printf("\nEnter the data and position\n");
	scanf("%d%d", &data, &pos);
	if (pos == 1) {
		head = insertAtBegin(head, data);
	} else {
		insertAtPos(head, pos, data);
	}
	printlist(head);

	//DeleteAtPos
	printf("\nEnter position to be deleted - ");
	scanf("%d", &pos);
	head = deleteAtPos(head, pos);
	printlist(head);

	//min-max
	printmaxmin(head);

	//circular list
	printf("\nEnter nos of Circular linked list: ");
	scanf("%d", &nos);
	for(i = 0; i < nos; i++) {
		printf("Enter %d data: ", i+1);
		scanf("%d", &data);
		temp = (node *) malloc(sizeof(data));
		if (temp == NULL) {
			printf("Memory Overflow");

			exit(1);
		}
		temp->data = data;
		temp->next = NULL;
		if (cll == NULL) {
			cll = temp;
			cll->next = cll;
			temp2 = temp;
		} else {
			temp->next = cll;
			temp2->next = temp;
			temp2 = temp2->next;
		}
	}	
	sumofevenincll(cll);

	//DLL
	printf("\nEnter nos of Doubly Linked List: ");
	scanf("%d", &nos);
	for(i = 0; i <nos; i++) {
		printf("Enter %d data: ", i+1);
		scanf("%d", &data);
		dlltemp = (dllnode *) malloc(sizeof(dllnode));
		if (dlltemp == NULL) {
			printf("\nMemory Overflow");
			break;
		}
		dlltemp->data = data;
		dlltemp->previous = NULL;
		dlltemp->next = NULL;
		if (dll == NULL) {
			dll = dlltemp;
			dlltemp2 = dlltemp;
		} else {
			dlltemp2->next = dlltemp;
			dlltemp->previous = dlltemp2;
			dlltemp2 = dlltemp;
		}
	}
	if (dll == NULL) {
		printf("\nNo element in DLL");
	}
	dlltemp = dll;
	printf("%d -> ", dlltemp->data);
	while (dlltemp->next != NULL) {
		dlltemp = dlltemp->next;
		printf("%d -> ", dlltemp->data);
	}
	while(dlltemp->previous != NULL) {
		dlltemp = dlltemp->previous;
		printf("%d -> ", dlltemp->data);
	}

	//DELETESMALLEST IN DLL
	dll = deletesmallestindll(dll);
	if (dll == NULL) {
                printf("\nNo element in DLL");
		exit(1);
        }
        dlltemp = dll;
        printf("\n%d -> ", dlltemp->data);
        while (dlltemp->next != NULL) {
                dlltemp = dlltemp->next;
                printf("%d -> ", dlltemp->data);
        }
        while(dlltemp->previous != NULL) {
                dlltemp = dlltemp->previous;
                printf("%d -> ", dlltemp->data);
        }
	
	//REVERSEDLL
	dll = reverseDLL(dll);
	if (dll == NULL) {
                printf("\nNo element in DLL");
		exit(1);
        }
        dlltemp = dll;
        printf("\n%d -> ", dlltemp->data);
        while (dlltemp->next != NULL) {
                dlltemp = dlltemp->next;
                printf("%d -> ", dlltemp->data);
        }
        while(dlltemp->previous != NULL) {
                dlltemp = dlltemp->previous;
                printf("%d -> ", dlltemp->data);
        }
	
	//Print All the elements of multiples of K
	printf("\nEnter K multiple value: ");
	scanf("%d", &k);
	kmultiplevalue(head, k);
	
	//reverse the linked list in multiples of group
	printf("\nEnter K - reverse size: ");
	scanf("%d", &k);
	//head = ksizereverse(head, k);
	printlist(head);
	
	//REMOVE ALTERNATE NODES
	printf("\nAlternates: -\n");
	//removealternatenodes(head);	
	printlist(head);
	
	//Remove if right value is greater
	printf("\nRemove if Right value is greater\n");
	//head = removegreaterright(head);
	printlist(head);
	
	//Middle element 
	printf("\nMiddle Element");
	middleelement(head);

	return 0;
}

