#include<stdio.h>
#include<stdbool.h>


struct node {
	int num;
	struct node *next;
	};

struct testcases{

	int inpSeq[10];
	int addData;
	int outSeq[10];
	}tests[10] = {
		{ { 1,2,2,3,4},3 ,{1,2,2,3,3,4 } },
		{ { 9,11,12,15}, 10, {9,10,11,12,15 } },
		{ { 1,2,3,4},5 , {1,2,3,4,5 } },
		{ { 1}, 2 , {1,2 } },
		{ { 2, 4, 7, 10, 22, 90 }, 11, {2,4,7,10,11,22,90 } },
		{ { 2,2,2,2},2 , {2,2,2,2,2 } },
		{ { 3,4,5,6},2 ,{2,3,4,5,6 } }
	};

void test(int num_test);
struct node * createNode(int num);
struct node * createList(int* num);
void reverseLL(struct node* head);
bool compare(struct node *result, int* num);
struct node* addToCll(struct node* head, int num);

int main(){

	int num_test = 7;

	test(num_test);

	getchar();
	}

void test(int num_test){

	int i;

	struct node* head = NULL;

	for (i = 0; i < num_test; i++){

		head = createList(tests[i].inpSeq);

		head = addToCll(head, tests[i].addData);

		if (compare(head, tests[i].outSeq))
			printf("\nPass");
		else
			printf("\nFail");

		free(head);

		}

	}

struct node* addToCll(struct node* head, int num){

	struct node* curr = head;
	
	struct node* newNode = createNode(num);
	if (curr == NULL){
		newNode->next = newNode;
		return newNode;
		}

	if (num < curr->num){

		while (curr->next != head)
			curr = curr->next;

		curr->next = newNode;
		newNode->next = head;
		return newNode;

		}
	else{

		while (curr->next->num < num && curr->next != head)
			curr = curr->next;

		newNode->next = curr->next;
		curr->next = newNode;

		return head;
		}

	}

/* Utility Functions */
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
	}

/*creates circular linked list*/
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
	curr->next = head;

	return head;
	}


bool compare(struct node *result, int* num) {
	struct node *head = createList(num);
	int hd1, hd2;
	hd1 = result->num;
	hd2 = num[0];

	do {
		head = head->next;
		result = result->next;
		} while ( head->num == result->num && head->num!=hd1  && result->num!=hd2);
	return head->num== result->num;
	}