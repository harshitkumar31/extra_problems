#include<stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
	};


struct testcases
	{

	int inpSeq1[20];
	int inpSeq2[20];
	int outSeq[20];

	}tests[10] = { 
		{ { 1, 2, 3 }, { NULL}, { 1, 2, 3 } },
		{ NULL, NULL,NULL},
		{ { 3,3,3}, {4,4,4 }, {7,7,7 } },
		{ { 1}, {1 }, {2 } },
		{ { 3,3,6}, {8,8,5,2 }, { 9,1,8,8} },
		{ { 8,9,9,9}, {1,1,2 }, { 9,1,1,1} },
		{ { 9,9,9}, {1,1,4 }, { 1,1,1,3} },
		{ { 3, 4, 5 }, { 7, 7, 2 }, { 1,1,1,7} },
		{ { 1, 2, 3, 4, 5 }, { 5, 4, 3, 2, 1 }, { 6, 6, 6, 6, 6 } } };

void test(int num_test);
struct node * createNode(int num);
struct node * createList(int num);
bool compare(struct node *result, int* num);
struct node* addLL(struct node* head1, struct node* head2);
int getLength(struct node* head);
struct node* addUtil(struct node* list1, struct node* list2, int* carry, int state);

int main(){

	int num_test = 9;

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

struct node* addLL(struct node* head1, struct node* head2){

	int diff = getLength(head1) - getLength(head2);

	int carry = 0;

	struct node* result = addUtil(head1, head2, &carry, diff);

	if (carry > 0){
		struct node* carNode = createNode(carry);

		carNode->next = result;

		result = carNode;
		}

	return result;
	}

struct node* addUtil(struct node* list1, struct node* list2, int* carry, int diff){

	if (list1 == NULL && list2 == NULL)
		return list1;

	struct node* result = createNode(0);

	if (diff > 0){
		result->next = addUtil(list1->next, list2, carry, diff - 1);

		result->num = *carry + list1->num;
		}
	else if (diff < 0){

		result->next = addUtil(list1, list2->next, carry, diff + 1);

		result->num = *carry + list2->num;
		}
	else{

		result->next = addUtil(list1->next, list2->next, carry, 0);

		result->num = *carry + (list1->num) + (list2->num);
		}

	*carry = result->num / 10;
	result->num %= 10;

	return result;
	}

int getLength(struct node* head){

	int i = 0;

	while (head != NULL){
		i++;
		head = head->next;
		}

	return i;

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