/* 7. Design, Develop and Implement a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit */



#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char USN[10], name[20], branch[10];
	int sem;
	long int ph;
	struct node *link;
}NODE;
typedef struct head_node
{
	int count;
	NODE *link;
}HEAD;
void ins_front(HEAD *head);
void ins_rear(HEAD *head);
void del_front(HEAD *head);
void del_rear(HEAD *head);
void display(HEAD *head);
void main()
{
	HEAD *head=(HEAD*)malloc(sizeof(HEAD));
	int choice;
	head->count=0;
	head->link=NULL;
	for(;;)
	{
		printf("Enter\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: ins_front(head); break;
			case 2: ins_rear(head); break;
			case 3: del_front(head); break;
			case 4: del_rear(head); break;
			case 5: display(head); break;
			case 6: exit(0);
		}
	}
}
void ins_front(HEAD *head)
{
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	printf("Enter USN, NAME, BRANCH, SEM, PHONE of the student:\n");
	scanf("%s%s%s%d%ld", (newN->USN), (newN->name), (newN->branch), &(newN->sem), &(newN->ph));
	newN->link= head->link;
	(head->count)++;
	head->link= newN;
}
void ins_rear(HEAD *head)
{
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	NODE *temp;
	printf("Enter USN, NAME, BRANCH, SEM, PHONe of the student:\n");
	scanf("%s%s%s%d%ld", (newN->USN), (newN->name), (newN->branch), &(newN->sem), &(newN->ph));
	newN->link= NULL;
	if(head->link==NULL)
	{
		head->link=newN;
		(head->count)++;
		return;
	}
	temp= head->link;
	while(temp->link!=NULL)
		temp= temp->link;
	temp->link= newN;
	(head->count)++;
}
void del_front(HEAD *head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	temp= head->link;
	printf("Deleted record:\n");
	printf("%s\t%s\t%s\t%d\t%ld\n", (temp->USN), (temp->name), (temp->branch), (temp->sem), (temp->ph));
	head->link= temp->link;
	(head->count)--;
	free(temp);
}
void del_rear(HEAD *head)
{
	NODE *present, *previous;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	present= head->link;
	if(present->link==NULL)
	{
		printf("List contains one record.\n");
		head->link=NULL;
	}
	else
	{
		while(present->link!=NULL)
		{
			previous= present;
			present= present->link;
		}
		previous->link=NULL;
	}
	printf("Deleted record:\n");
	printf("%s\t%s\t%s\t%d\t%ld\n", (present->USN), (present->name), (present->branch), (present->sem), (present->ph));
	(head->count)--;
	free(present);
}
void display(HEAD *head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	else
	{
		printf("Number of nodes: %d\n", head->count);
		printf("Contents of the list\n");
		temp= head->link;
		while(temp!=NULL)
		{
			printf("%s\t%s\t%s\t%d\t%ld\n", (temp->USN), (temp->name), (temp->branch), (temp->sem),  (temp->ph));
			temp= temp->link;
		}
	}
}
		

