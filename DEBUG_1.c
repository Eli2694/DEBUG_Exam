//BUG <stdio.h<
#include <stdio.h>
#pragma warning(disable:4996)
int main_1()
{
	// BUG .need to write  ',' instead of ';'
	int a = 4, b = 7;
	float c;
	//BUG. scanf is unsafe => #pragma warning(disable:4996)
	//BUG. in scanf we need '&' to have access to the address memory and change its value
	scanf("%f", &c);
	// (5 = c) => (5 == c)
	if (5 == c)
		printf("%f", c); //BUG. printf instead of print
}
