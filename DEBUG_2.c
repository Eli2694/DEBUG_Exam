


#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main_2()
{
	// BUG. x,y uninitialized local variable
	int x = 6, y = 5;
	int nums[6];
	int* arrPtr;
	// Section A - Print the variables
	puts("***** Section A *****");
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);
	// Section B - Print the static array "nums".
	puts("***** Section B *****");
	int i = 0;
	while (i < 6) {
		//BUG. array is empty
		int n;
		scanf("%d", &n); //BUG. scanf unsafe varibale => #pragma warning(disable:4996)
		nums[i] = n;
		printf(" nums[%d] = %d\n", i, nums[i]);
		//BUG. endless loop becuase i does not grow to be bigger then 6
		i++;
	}
	// Section C - Print allocated array.
	puts("***** Section C *****");
	// BUG. int* malloc casting
	// BUG. malloc(sizeof(int) * 6) instead of malloc(sizeof(int) * 10)
	arrPtr = (int*)malloc(sizeof(int) * 6);
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			//BUG. dynamic array is empty
			int x;
			scanf("%d", &x); //BUG. scanf unsafe varibale => #pragma warning(disable:4996)
			arrPtr[i] = x;
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	return 0;
}