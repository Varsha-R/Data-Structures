/* 4. Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands. */



#include<stdio.h>
#include<stdlib.h>
typedef enum{ lparen, rparen, plus, minus, mul, divi, mod, power, eos, opnd} precedence;
void postfix( char infix[]);
precedence get_token(char * symbol, int *n, char infix[]);
void print_token(precedence item);
void push(int value, int stack[], int *top);
int pop(int stack[], int *top);
void main()
{
	char infix[20];
	printf("Enter infix expression:\n");
	scanf("%s", infix);
	printf("The postfix expression is:\n");
	postfix(infix);
	printf("\n");
}
void postfix( char infix[])
{
	int stack[20], top=0, n=0;
	int isp[]= {0, 4, 1, 1, 2, 2, 2, 3, 0};
	int icp[]= {5, 4, 1, 1, 2, 2, 2, 3, 0};
	char symbol;
	precedence token;
	stack[top]= eos;
	for(token=get_token(&symbol, &n, infix); token!=eos; token=get_token(&symbol, &n, infix))
	{
		if(token==opnd)
			printf("%c", symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				print_token(pop(stack, &top));
			pop(stack, &top);
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				print_token(pop(stack, &top));
			push(token, stack, &top);
		}
	}
	while((token=pop(stack, &top))!=eos)
		print_token(token);
}
precedence get_token(char * symbol, int *n, char infix[])
{
	*symbol= infix[(*n)++];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return mul;
		case '/': return divi;
		case '%': return mod;
		case '^': return power;
		case '\0': return eos;
		default: return opnd;
	}
}
void print_token(precedence item)
{
	switch(item)
	{
		case plus: printf("+"); break;
		case minus: printf("-"); break;
		case mul: printf("*"); break;
		case divi: printf("/"); break;
		case mod: printf("%%"); break;  //It is necessary to put %% instead of % for compilation in gcc
		case power: printf("^"); break;
	}
	return;
}
void push(int value, int stack[], int *top)
{
	stack[++(*top)]= value;
}
int pop(int stack[], int *top)
{
	return stack[(*top)--];
}		 
