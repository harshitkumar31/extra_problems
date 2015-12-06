#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(){

	FILE* inp;

	char filename[81];
	printf("\nEnter file name : ");
	scanf(" %[^\n]", filename);
	int num;
	printf("\nEnter no of lines to be printed : ");
	scanf("%d", &num);
	inp = fopen(filename, "r");

	char line[81];
	char ch;

	int count = 0;

	while ((ch = fgetc(inp))!=EOF){

		if (ch == '\n')
			count++;

		}

	int i = 0;
	count = count - num;
	rewind(inp);
	while (i < count){
		ch =fgetc(inp);
		if (ch == '\n')
			i++;

		}


		while ((ch = fgetc(inp)) != EOF)
			fprintf(stdout, "%c", ch);

		
		


	getchar();
	getchar();

	}