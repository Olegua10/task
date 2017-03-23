#include <stdio.h>
int mul(int*,int*);

int main()
{
	int a,b,c;
	printf("input a and b:\n");
	scanf("%d%d",&a,&b);
	
	printf("typed in the keyboard: a=%d b=%d\n",a,b);
	
	c=mul(&a,&b);
	printf(" %d*%d=%d\n",a,b,c);
	
	
		
}
int mul(int *x,int *y)
{
	int c;
	++*x;
	(*y)++;
	
	c=*x**y;
	
	return c;
		
}
