#include <stdio.h>



struct testcases{

	int inputSequence;

	int medData;
	}tests[5] = { 
		{ 1234567, 4 }, { 123456789,5}, { 1234, 3}, { 56, 6 }, { 7, 7 }
	};


struct node {
	int num;
	struct node *next;
	};


struct node* findMedian(struct node* head);
void test(int num_test);
struct node * createNode(int num);
struct node * createList(int num);

int main(){

	int num_test = 5;

	test(num_test);

	getchar();

	}


struct node* findMedian(struct node* head){

	struct node* fptr;
	struct node* nptr;

	if (head == NULL)
		return NULL;

	fptr = nptr = head;

	while (fptr != NULL && fptr->next != NULL){
		nptr = nptr->next;
		fptr = fptr->next->next;

		}

	return nptr;

	}

/*Test function*/
void test(int num_test){

	struct node* head;

	struct node* median;
	for (int i = 0; i < num_test; i++){

		head = createList(tests[i].inputSequence);

		median = findMedian(head);

		if (median->num == tests[i].medData)
			printf("\nPass");
		else
			printf("\nFail");
		}


	}

/* Utility functions - creating List and nodes*/
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
	}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
		}
	return head;
	}