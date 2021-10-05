#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int Evoluat(){
    int i, a, b, result, val;
	char ch;
	
	for(i=0; i<SIZE; i++)
	{
		stack[i] = -1;
	}

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
			}
			
			push(result);
		}		
	
	}
	val = pop();
    return val;
}

int main()
{
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	int val = Evoluat();
	printf("\nThe postfix evaluation of '%s' is: %d\n",postfix,val);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
		printf("Stack is full!\n");
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
		printf("Stack is empty!\n");
}
