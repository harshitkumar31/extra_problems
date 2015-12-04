#include<stdio.h>
#include<stdbool.h>

struct node {
	int num;
	struct node *next;
	};

struct testcases{

	int inpSeq[20];
	int sorted[20];

	}tests[10] = { 
		{
			{ 5, 4, 6, 7, 8 }, { 4, 5, 6, 7, 8 }
			},
			{ { 1, 2, 3, 15, 10, 4 },{ 1, 2, 3, 4, 10, 15 } 
				},
			{{ 1,2,3,4,5,8,7}, {1,2,3,4,5,7,8 }
				},
				{ { 8, 7 }, {7,8 }
				},
				{
					{ 1, 2, 3, 4, 5 }, {1,2,3,4,5 }
					},
				{
					{ 9 }, { 9 }
					},
				{
					{ 1, 1, 2, 4, 2 }, {1,1,2,2,4 }
					},
				{
					{ 1, 1, 1, 1, 1, 3, 1 }, {1,1,1,1,1,1,3 }
					}
	};

void test(int num_test);
struct node * createNode(int num);
struct node * createList(int num);
bool compare(struct node *result, int* num);
void misplaceSort(struct node* head);
void swapLL(struct node* node1, struct node* node2);


int main(){

	int num_test = 8;

	test(num_test);

	getchar();
	}



/*Test function*/
void test(int num_test){

	struct node* head;

	struct node* median;
	for (int i = 0; i < num_test; i++){

		head = createList(tests[i].inpSeq);

		misplaceSort(head);

		if (compare(head, tests[i].sorted))
			printf("\nPass");
		else
			printf("\nFail");
		}


	}


/*Misplaced Sort*/
void misplaceSort(struct node* head){
	
	struct node* node1 = NULL;
	struct node* node2 = NULL;

	struct node* curr = head;

	int flag1 = 0, flag2 = 0;

	while (curr->next != NULL){

		if (curr->num > curr->next->num && flag1 != 1){
			node1 = curr;
			flag1 = 1;
			}
		else if (curr->num > curr->next->num && flag1 == 1 && flag2 != 1){
			node2 = curr->next;
			flag2 = 1;
			break;
			}

		curr = curr->next;
		}

	if (flag2 == 0 && flag1==1){
		flag2 = 1;
		node2 = node1->next;
		}

	if (flag1 && flag2)
		swapLL(node1, node2);

	}

/*Swap Function*/
void swapLL(struct node* node1, struct node* node2){

	int temp=node1 ->num;

	node1->num = node2->num;

	node2->num = temp;

	}

/* Utility functions - creating List and nodes*/
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
	}

struct node * createList(int* num) {
	struct node *head=NULL;
	struct node* curr=NULL;
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