#include<stdio.h>

void test(int num);

struct testcase{

	int a[20];
	int lena;
	int sum;
	int st;
	int end;
}tests[10] = {

	{ {1,2,2,-1,4,6,-2,-3,6,7,-2,-13},
	12,
	22,
	0,
	9
	},
	{
		{-1,0,0,1,-2,0,0,2},
		8,
		2,
		5,
		7
	},
	{
		{-1,0,0,1,-1,0,0,1},
		8,
		1,
		1,
		3
	},
	{
		{-1,-2,-3,-4},
		4,
		-1,
		0,
		0
	},
	{
		{-1,-2,-3,-4,4,3,2,1},
		8,
		10,
		4,
		7
	},
	{
		{4,3,2,1,-1,-2,-3,-4},
		8,
		10,
		0,
		3
	},
	{
		{0,0,0,0},
		4,
		0,
		0,
		0
	},
	{
		{-1,0,0,0,1},
		5,
		1,
		1,
		4
	},
	{
		{-1,1},
		2,
		1,
		1,
		1
	},
	{
		{10},
		1,
		10,
		0,
		0
	}
};

void test(int num){

	int i;
	int *start;
	int *end;
	int a, b;
	int sum;
	start = &a;
	end = &b;


	for (i = 0; i < num; i++){

		sum = getHighestSeq(tests[i].a, tests[i].lena, start, end);

		if (sum == tests[i].sum && *start == tests[i].st && *end == tests[i].end){
//			if (*start == tests[i].st)
			printf("\nPass");

		}
		else
			printf("\nFail");
	}
}

int getHighestSeq(int *array, int lena, int *start, int* end){

	//int sum=0;
	/*
	int maxSum;
	int i,j;
	
	int** sum;
	sum= (int**)(malloc(lena*sizeof(int*)));

	for (i = 0; i < lena; i++){

		sum[i] = (int*)malloc(lena* sizeof(int));
	}
	//int sum[10][10];

	for (i = 0; i < lena; i++){

		for (j = 0; j <= i; j++){
			if (j-1 != -1 || i-1 !=-1){
				sum[i][j] = sum[i ][j - 1] + a[j];
			}
			else{
				sum[i][j] = a[j];
			}
		}
	}

	//Checking max sum

	maxSum = sum[0][0];
	
	int start1 = 0,end1 =0;
	

	for (i = 0; i < lena; i++){

		for (j = 0; j < lena; j++){

			if ( sum[i][j] > maxSum){
				maxSum = sum[i][j];
				start1 = i;
				end1 = j;
			}
		}
	}
	*start = start1;
	*end = end1;
	return maxSum;

	*/

	int maxSumSoFar = -2147483;
	int curSum = 0;
	int a, b, s, i;
	a= b = s = i = 0;
	for (i = 0; i < lena; i++) {
		curSum += array[i];
		if (curSum > maxSumSoFar) {
			maxSumSoFar = curSum;
			a = s;
			b = i;
		}
		if (curSum < 0) {
			curSum = 0;
			s = i + 1;
		}
	}
	*start = a;
	*end = b;
	return maxSumSoFar;
	
}

int main(){

	test(10);
	getchar();
	return;
}