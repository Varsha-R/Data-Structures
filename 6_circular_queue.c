/* 6. Design, Develop and Implement a menu driven Program in C for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations */


#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
void insert(char ele, int *r, char q[], int *count);
void delete(int *f, char q[], int *count);
void display(int f, char q[], int count);
void main()
{
	int choice, front=0, rear=-1, count=0;
	char q[SIZE], ele;
	for(;;)
	{
		printf("Enter\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(count==(SIZE-1))
					printf("Queue is full!!!\n");
				else
				{
					printf("Enter character to be inserted:\n");
					scanf("%s", &ele); // It is necessary to put %s instead of %c 'cause of the compiler
					insert(ele, &rear, q, &count);
				}
				break;
			case 2: if(count==0)
					printf("Queue is empty!!!\n");
				else
					delete(&front, q, &count);
				break;
			case 3: if(count==0)
					printf("Queue is empty!!!\n");
				else
					display(front, q, count);
				break;
			case 4: exit(0);
		}
	}
}
void insert(char ele, int *r, char q[], int *count)
{
	*r=(*r+1)%SIZE;
	q[*r]=ele;
	(*count)++;
}
void delete(int *f, char q[], int *count)
{
	printf("Deleted character:\n%c\n", q[*f]);
	(*count)--;
	*f=(*f+1)%SIZE;
}
void display(int f, char q[], int count)
{
	int i;
	printf("Elements in the queue:\n");
	for(i=1; i<=count; i++)
	{
		printf("%c\t", q[f]);
		f=(f+1)%SIZE;
	}
	printf("\n");
}
	
					
	
