#include<stdio.h>

#define MAX 100000

int fib(int );

int array_fib[MAX];

int main()
{
	int n,i;
	
	printf("Enter the number to compute fibonacci\n");

	scanf("%d",&n);

	printf("Fibonacci number is= %d\n",fib(n));

	return 0;
}

int fib(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;

	if(array_fib[n]!=-1)
		return array_fib[n];

	array_fib[n] = fib(n-1)+fib(n-2);

	return(fib[n]);
}
