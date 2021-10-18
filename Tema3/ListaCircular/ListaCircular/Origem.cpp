#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//insert link at the first location
void insert(int data) {
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->data = data;
	link->next = NULL;

	// If head is empty, create new list
	if (head == NULL) {
		head = link;
		head->next = link;
		return;
	}

	current = head;

	// move to the end of the list
	while (current->next != head)
		current = current->next;

	// Insert link at the end of the list
	current->next = link;

	// Link the last node back to head
	link->next = head;

}

//display the list
void printList() {
	struct node *ptr = head;

	printf("\n[head] =>");

	//start from the beginning
	while (ptr->next != head) {
		printf(" %d =>", ptr->data);
		ptr = ptr->next;
	}

	printf(" %d =>", ptr->data);
	printf(" [head]\n");
}

int main() {
	insert(10);
	insert(20);
	insert(30);
	insert(1);
	insert(40);
	insert(56);

	printList();

	system("pause");
	return 0;
}