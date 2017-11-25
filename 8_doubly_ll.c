/* 8.  Design, Develop and Implement a menu driven Program in C for the following operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit */

#include<stdio.h>
#include<stdlib.h>
typedef struct emp
{
	char SSN[10], name[20], department[10], designation[20];
	float salary;
	long int ph;
	struct emp *llink, *rlink;
}NODE;
typedef struct head_node
{
	int count;
	NODE *link;
}HEAD;
void ins_front(HEAD * head);
void ins_rear(HEAD * head);
void del_front(HEAD * head);
void del_rear(HEAD * head);
void display(HEAD * head);
void main()
{
	HEAD * head=(HEAD*)malloc(sizeof(HEAD));
	int choice;
	head->count= 0;
	head->link= NULL;
	for(;;)
	{
		printf("Enter\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display the list\n6. Choose options 1 and 3 or 4  OR 2 and 3 or 4 for demonstration of Deque\n7. exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: ins_front(head);
				break;
			case 2: ins_rear(head);
				break;
			case 3: del_front(head);
				break;
			case 4: del_rear(head);
				break;
			case 5: display(head);
				break;
			case 7: exit(0);
		}
	}
}
void ins_front(HEAD * head)
{
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	printf("Enter SSN, Employee name, Department, Designation, Salary, Phone:\n");
	scanf("%s%s%s%s%f%ld", (newN->SSN), (newN->name), (newN->department), (newN->designation), &(newN->salary), &(newN->ph));
	newN->rlink=head->link;
	//newN->llink=head;
	head->link= newN;
	(head->count)++;
	return;
}
void ins_rear(HEAD * head)
{
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	NODE *temp;
	printf("Enter SSN, Employee name, Department, Designation, Salary, Phone:\n");
	scanf("%s%s%s%s%f%ld", (newN->SSN), (newN->name), (newN->department), (newN->designation), &(newN->salary), &(newN->ph));
	newN->rlink=NULL; 
	if(head->link==NULL)
	{
		head->link=newN;
		//newN->llink=head;
		return;
	}
	temp=head->link;
	while(temp->rlink!=NULL)
	{
		temp=temp->rlink;
	}
	temp->rlink=newN;
	//newN->llink=temp;
	(head->count)++;
}
void del_front(HEAD * head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	temp=head->link;
	printf("Deleted record:\n%s\t%s\t%s\t%s\t%f\t%ld\n",(temp->SSN), (temp->name), (temp->department), (temp->designation),(temp->salary), (temp->ph));
	head->link=temp->rlink;
	free(temp);
	(head->count)--;
}
void del_rear(HEAD * head)
{
	NODE *present, *previous;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	present=head->link;
	while(present->rlink!=NULL)
	{
		previous=present;
		present=present->rlink;
	}
	printf("Deleted record:\n%s\t%s\t%s\t%s\t%f\t%ld\n",(present->SSN), (present->name), (present->department),       (present->designation), (present->salary), (present->ph));
	previous->rlink=NULL;
	free(present);
	(head->count)--;
}
void display( HEAD * head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("List Empty!!!\n");
		return;
	}
	temp=head->link;
	printf("Number of nodes: %d\n", (head->count));
	printf("Records:\nSSN\tNAME\tDEPARTMENT\tDESIGNATION\tSALARY\tPHONE\n");
	while(temp!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(temp->SSN), (temp->name), (temp->department), (temp->designation),(temp->salary), (temp->ph));
		temp=temp->rlink;
	}
}	
		
	
	
