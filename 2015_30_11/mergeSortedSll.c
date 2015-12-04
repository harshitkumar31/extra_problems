#include<stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
	};

struct testcases{

	int ll1;
	int ll2;
	int res;
	}tests[5] = {
		{ 1278, 569, 1256789 }, { 347, 256, 234567 }, { 1, 111, 1111 }, {1234,1234,11223344 }
	};


void test(int num_test);
struct node * createNode(int num);
struct node * createList(int num);
struct node* mergeLLs(struct node* head1, struct node* head2);
bool compare(struct node *result, int num);

int main(){

	int num_test = 5;

	test(num_test);

	getchar();

	}



struct node* mergeLLs(struct node* head1, struct node* head2){

	struct node* finLl = NULL;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	if (head1->num <= head2->num){

		finLl = head1;

		finLl->next = mergeLLs(head2, head1->next);
		}else{

		finLl = head2;

		finLl->next = mergeLLs(head1, head2->next);
		}

	return finLl;

	}
/*Test function*/
void test(int num_test){

	struct node* head1;
	struct node* head2;
	
	struct node* merge;
	for (int i = 0; i < num_test; i++){

		head1 = createList(tests[i].ll1);
		head2 = createList(tests[i].ll2);
		
		head1 = mergeLLs(head1, head2);

		if (compare(head1, tests[i].res))
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


bool compare(struct node *result, int num) {
	struct node *head = createList(num);
	while (head && result && head->num == result->num) {
		head = head->next;
		result = result->next;
		}
	return !head && !result;
	}