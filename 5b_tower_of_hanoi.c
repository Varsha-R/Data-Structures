/* 5.  Design, Develop and Implement a Program in C for the following Stack Applications:
 b. Solving Tower of Hanoi problem with n disks */
 
#include<stdio.h>
#include<stdlib.h>
void TOH( int n, char source, char destination, char spare);
void main()
{
	int n;
	printf("Enter number of rings:\n");
	scanf("%d", &n);
	TOH(n, 'A', 'C', 'B');
}
void TOH( int n, char source, char destination, char spare)
{
	if(n==1)
		printf("Move from %c to %c\n",source, destination);
	else
	{
		TOH(n-1, source, spare, destination);
		TOH(1, source, destination, spare);
		TOH(n-1, spare, destination, source);
	}
} 
