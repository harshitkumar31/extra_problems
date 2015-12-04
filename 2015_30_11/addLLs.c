#include<stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
	};

struct testcases{

	int inpSeq1[20];
	int inpSeq2[20];
	int outSeq[20];
	}tests[10] = {
		{ { -3,-5,-9}, { -3,-5,-9 }, {-6,-10,-18 } },
		{ { 0,0,0,0}, {-2,-3,-4,-5 }, {-2,-3,-4,-5 } },
		{ { -1,2,-3,5,6}, {-2,-3,3,-2,-4 }, {-3,-1,0,3,2 } },
		{ { 1,1,1,1,1}, {9,9,9,9,9 }, {10,10,10,10,10 } },
		{ { 1,2,3,4,5}, {0 }, {1,2,3,4,5} },
		{ { 0}, {1,2,3,4,6 }, {1,2,3,4,6 } },
		{ { 4, 5, 6 }, { 3, 4, 5, 6, 7, 8 }, { 7,9,11,6,7,8} },
		{ { 1, 2, 3, 4, 5 }, { 5, 4, 3, 2, 1 }, { 6,6,6,6,6} }
	};

void test(int num_test);
struct node * createNode(int num);
struct node * createList(int num);
bool compare(struct node *result, int* num);
struct node* addLL(struct node* head1, struct node* head2);


int main(){

	int num_test = 8;

	test(num_test);

	getchar();
	}


/*Test function*/
void test(int num_test){

	int i;

	struct node* head1;
	struct node* head2;

	for (i = 0; i < num_test; i++){

		head1 = createList(tests[i].inpSeq1);

		head2 = createList(tests[i].inpSeq2);

		head1 = addLL(head1, head2);

		if (compare(head1, tests[i].outSeq))
			printf("\nPass");
		else
			printf("\nFail");
		}
	}


/*Add function*/
struct node* addLL(struct node* head1, struct node* head2){
	
	struct node* res;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	res = head1;

	res->num = head1->num + head2->num;

	res->next = addLL(head1->next, head2->next);

	return res;
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