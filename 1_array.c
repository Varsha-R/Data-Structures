/* 1. Design, Develop and Implement a menu driven Program in C for the following array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations. */



#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
void create(int a[], int n);
void display(int a[], int n);
void insert(int ele, int pos, int a[], int *n);
void delete(int pos, int a[], int *n);
void main()
{
	int a[SIZE], i, choice, n, ele, pos;
	printf("Enter number of elements in the array:\n");
	scanf("%d", &n);
	create(a, n);
	for(;;)
	{
		printf("Enter\n1. Display\n2. Insert\n3. Delete\n4. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: display(a, n);
				break;
			case 2: printf("Enter the element to be inserted:\n");
				scanf("%d", &ele);
				printf("Enter position for insertion:\n");
				scanf("%d", &pos);
				insert(ele, pos, a, &n);
				break;
			case 3: printf("Enter position for deletion:\n");
				scanf("%d", &pos);
				delete(pos, a, &n);
				break;
			case 4: exit(0);
		}
	}
}
void create(int a[], int n)
{
	int i;
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
}
void display(int a[], int n)
{
	int i;
	printf("Array elements:\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void insert(int ele, int pos, int a[], int *n)
{
	int i;
	if(pos>*n+1)
	{
		printf("Invalid position.\n");
		return;
	}
	for(i= *n-1; i>=pos-1; i--)
		a[i+1]= a[i];
	a[pos-1]= ele;
	*n+=1;
	printf("Array after insertion:\n");
	for(i=0;i<*n;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void delete(int pos, int a[], int *n)
{
	int i;
	if(pos>*n)
	{
		printf("Invalid position.\n");
		return;
	}
	for(i=pos-1; i< *n-1; i++)
		a[i]= a[i+1];
	*n-=1;
	printf("Array after deletion:\n");
	for(i=0;i<*n;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
				 
