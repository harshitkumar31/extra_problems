#include<stdio.h>

struct testcases{

	int n1;
	int n2;
	int r;
	int res;
	}tests[10] = { 
		{4,6,7,20 },
		{6,2,5,10 },
		{5,8,1,5 },
		{11,5,11,40 },
		{7,5,7,21 },
		{ 5,7,7,21 },
		{ 3,3,3,9},
		{ 3,6,5, 15}
	};

long int gcd(long int a,long int b);
int getTableEl(int a, int b, int n);
void test(int num_test);

int main(){

	int num_test = 8;
	test(num_test);

	getchar();

	}

void test(int num_test){

	int i;

	int res;

	for (i = 0; i < num_test; i++){

		res = getTableEl(tests[i].n1, tests[i].n2, tests[i].r);

		if (res == tests[i].res)

			printf("\nPass");
		else
			printf("\nFail");

		}
	}

long int gcd(long int a,long int b){
	

	while (a != b){
		if (a > b)
			return gcd(a - b, b);
		else
			return gcd(a, b - a);
		}

	return a;
	}

int getTableEl(int a, int b, int n){
	
	int k, flag;
	k = 0;

	if (a%b == 0)
		return b*n;
	else if (b%a == 0)
		return a*n;
	else{
		long int lcm = a*b / gcd(a, b);
		long int num = lcm / a + lcm / b - 1;
		int x, y;
		x = y = lcm * (n / num);
		n = n % num;

		if (x == 0){
			x = a;
			y = b;
			}else{
			n++;
			}

		for (k = 0; k < n; k++){
			if (x < y){
				x = x + a;
				flag = 1;
				}
			else if (x > y){
				y = y + b;
				flag = 0;

				}
			else{
				y = y + b;
				x = x + a;

				}
			
			}
			
		if (flag)
			return x - a;
		else
			return y - b;

		}


	}