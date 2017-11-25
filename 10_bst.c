/* 10. Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers: 
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
e. Exit  */

#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *rlink, *llink;
}TNODE;
TNODE * getnode();
TNODE * insert(int ele, TNODE * root);
void inorder(TNODE * root);
void preorder(TNODE * root);
void postorder(TNODE * root);
int search(TNODE * root, int key);
void main()
{
	TNODE *root= NULL;
	int choice, ele, key, flag;
	for(;;)
	{
		printf("Enter\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter element to be inserted:\n");
				scanf("%d", &ele);
				root= insert(ele, root);
				break;
			case 2: if(root==NULL)
					printf("Tree is empty\n");
				else
				{
					printf("The contents are:\n");
					inorder(root);
				}
				break;
			case 3: if(root==NULL)
					printf("Tree is empty\n");
				else
				{
					printf("The contents are:\n");
					preorder(root);
				}
				break;
			case 4: if(root==NULL)
					printf("Tree is empty\n");
				else
				{
					printf("The contents are:\n");
					postorder(root);
				}
				break; 
			case 5: printf("Enter the node to be searched:\n");
				scanf("%d", &key);
				flag= search(root, key);
				if(flag==-1)
					printf("Unsuccessful search!!!\n");
				else
					printf("Successful search!!!\n");
				break;
			case 6: exit(0);
		}
	}
}
TNODE * getnode()
{
	TNODE *temp= (TNODE*)malloc(sizeof(TNODE));
	if(temp==NULL)
	{
		printf("Out of memory!!!\n");
		return NULL;
	}
	return temp;
}
TNODE * insert( int ele, TNODE * root)
{
	TNODE *newN= getnode();
	//TNODE *previous, *present;
	newN->data= ele;
	newN->rlink= newN->llink= NULL;
	if(root==NULL)
		return newN;
	if(ele<root->data)
		root->llink= insert(ele, root->llink);
	if(ele>root->data)
		root->rlink= insert(ele, root->rlink);
	return root;
}
void inorder(TNODE * root)
{
	if(root!=NULL)
	{
		inorder(root->llink);
		printf("%d\n", root->data);
		inorder(root->rlink);
	}
}
void preorder(TNODE * root)
{
	if(root!=NULL)
	{
		printf("%d\n", root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
void postorder(TNODE * root)
{
	if(root!=NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d\n", root->data);
	}
}
int search( TNODE * root, int key)
{
	if(root!=NULL)
	{
		if(root->data==key)
			return key;
		if(key < root->data)
			return search(root->llink, key);
		return search(root->rlink, key);
	}
	return -1;
}
			
