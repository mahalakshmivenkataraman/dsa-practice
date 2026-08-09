#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	int pr;
	char c;
	struct node * prev,*next;
};

int prior(char data)
{
	switch(data)
	{
		case '(':
			return 1;
		case '*':
		case '/':
			return 2;	
		case '+':
		case '-':
			return 3;
	}
}
void peek(struct node * top)
{
	if(top==NULL)
		printf("\n no item in stack\n");
	else
		printf("\ndata in stack top is %c\n",top->c);
}
void push(struct node ** top,char data)
{
	if((*top)==NULL)
	{
		(*top)=(struct node * )malloc(sizeof(struct node));
		(*top)->prev=NULL;
	}
	else
	{
		(*top)->next=(struct node * )malloc(sizeof(struct node));
		(*top)->next->prev=(*top);
		(*top)=(*top)->next;
	}
	(*top)->c=data;
	(*top)->pr=prior(data);
	(*top)->next=NULL;
}

char pop(struct node ** top)
{
	if((*top)==NULL)
		return '#';
	char ch=(*top)->c;
	(*top)=(*top)->prev;
	if((*top)!=NULL)
		(*top)->next=NULL;
	return ch;
	
}
void postfix(char exp[],struct node * top)
{
	int i=0;
	while(exp[i]!='\0')
	{
		char ch=exp[i];
		if(isdigit(ch))
		{
			printf("%c",ch);
		}
		else if(ch==')')
		{
			while(1)
			{
				char pp=pop(&top);
				if (pp=='(')
					break;
				else
					printf("%c",pp);
			}
		}
		else if(ch=='(')
			push(&top,ch);
		else if (top==NULL || prior(ch)<(top->pr))
			push(&top,ch);
		else
		{
			while(top!=NULL && top->c!='(')
			{if (prior(ch)>=(top->pr))
				{
				printf("%c",pop(&top));
				}
			else
				break;
			}
			push(&top,ch);
		}
		i++;
	}
	char pp=pop(&top);
	while(pp!='#')
	{
		printf("%c",pp);
		pp=pop(&top);
	}
}
int main()
{
	char exp[50];
	struct node * top=NULL;
	printf("enter your expression:");
	scanf("%s",&exp);
	postfix(exp,top);
	
}

















