#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char name[30];
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//insert link at the first location
void insert(char data[]) {
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));

	strcpy_s(link->name, data);
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
		printf(" %s =>", ptr->name);
		ptr = ptr->next;
	}

	printf(" %s =>", ptr->name);
	printf(" [head]\n");
}



int main() {
	insert("vinicius");
	insert("teste");
	insert("sdfsdfsd");
	insert("aaaaaaa");

	printList();

	system("pause");
	return 0;
}