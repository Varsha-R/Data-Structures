/* 5. Design, Develop and Implement a Program in C for the following Stack Application
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^ */


#include<stdio.h>  //Incase you use stdlib.h you'll have to change div to divi since div is a built-in function
#include<math.h>   //Use [cc suffix_evaluation.c -o a.out -lm] for compiling programs containing math.h  {O/P command: ./a.out}
typedef enum{ plus, minus, multi, div, mod, power, eos, opnd}precedence;
int evaluate( char postfix[]);
precedence get_token( char *s, int *n, char post[]);
void push(int n, int *top, int stack[]);
int pop(int *top, int stack[]);
int operation(int o1, int o2, precedence token);
void main()
{
	char post[20];
	printf("Enter the postfix expression:\n");
	scanf("%s", post);
	printf("Result:\n%d\n",evaluate(post));
}
int evaluate( char postfix[])
{
	int n=0, op1, op2;
	int stack[10], top=-1;
	char symbol;
	precedence token= get_token( &symbol, &n, postfix);
	while(token!=eos)
	{
		if(token==opnd)
			push( symbol-'0', &top, stack);
		else
		{
			op2= pop(&top, stack);
			op1= pop(&top, stack);
			push(operation(op1, op2, token), &top, stack);
		}
		token= get_token( &symbol, &n, postfix);
	}
	return stack[0];
}
precedence get_token( char *s, int *n, char post[])
{
	*s= post[(*n)++];
	switch(*s)
	{
		case '+': return plus;
		case '-': return minus;
		case '*': return multi;
		case '/': return div;
		case '%': return mod;
		case '^': return power;
		case '\0': return eos;
		default: return opnd;
	}
}
void push(int n, int *top, int stack[])
{
	stack[++(*top)]=n;
}
int pop(int *top, int stack[])
{
	return stack[(*top)--];
}
int operation(int o1, int o2, precedence token)
{
	switch(token)
	{
		case plus: return o1+o2;
		case minus: return o1-o2;
		case multi: return o1*o2;
		case div: return o1/o2;
		case mod: return o1%o2;
		case power: return pow(o1,o2);
	}
	return 0;
}
