#include<stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
	};

struct testcases{

	int inpSeq[20];
	int outSeq[20];
	}tests[10]={
		{ { 90, 80, 70, 60 }, { 60, 70, 80, 90 } },
		{ { 1,2,3,4,5}, {1,2,3,4,5 } },		
		{ {1,2,3,50 }, {1,2,3,50 } },
		{ NULL,NULL},
		{ { 1,80,70,60}, {1,60,70,80 } },
		{ { 1,2,3,50,40,30}, {1,2,3,30,40,50 } }
	};


void test(int num_test);
struct node* sortAscDesc(struct node* head);
struct node * createNode(int num);
struct node * createList(int num);
bool compare(struct node *result, int* num);
struct node* reverseLL(struct node* head, struct node* prev);

int main(){

	int num_test = 6;

	test(num_test);

	getchar();
	}

struct node* sortAscDesc(struct node* head){

	struct node* curr=head;
	struct node* prev = NULL;

	if (head == NULL)
		return head;

	while (curr->next != NULL && curr->num < curr->next->num ){
		prev = curr;
		curr = curr->next;

		}

	if (prev!=NULL)
		prev->next = reverseLL(curr, NULL);
	else{
		head = reverseLL(curr, NULL);
		}

	return head;

	}


/*Test function*/
void test(int num_test){


	int i;

	struct node* head = NULL;

	for (i = 0; i < num_test; i++){

		head = createList(tests[i].inpSeq);

		head = sortAscDesc(head);

		if (compare(head, tests[i].outSeq))
			printf("\nPass");
		else
			printf("\nFail");

		}

	}


/*Reverse List*/
struct node* reverseLL(struct node* head, struct node* prev){

	if (head == NULL)
		return head;

	/*if it has one node*/
	if (head->next == NULL){
		head->next = prev;
		return head;

		}
	else{

		struct node* temp = head->next;

		head->next = prev;

		head = reverseLL(temp, head);

		return head;
		}


	}

/* Utility functions - creating List and nodes*/
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
	}

struct node * createList(int* num) {
	struct node *head = NULL;
	struct node* curr = NULL;
	int i = 0;

	while (num[i]>0) {
		struct node *newNode = createNode(num[i]);

		if (head == NULL)
			head = curr = newNode;
		else{
			curr->next = newNode;
			curr = curr->next;
			}
		i++;
		}
	return head;
	}


bool compare(struct node *result, int* num) {
	struct node *head = createList(num);
	while (head && result && head->num == result->num) {
		head = head->next;
		result = result->next;
		}
	return !head && !result;
	}