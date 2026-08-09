
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev,*next;
};
int peek(struct node * top)
{
if(top==NULL)
	return -1000;
else
	return (top->data);
}
void push(struct node ** top, int c)
{
if(*top==NULL)
{
(*top)=(struct node *)malloc(sizeof(struct node));
(*top)->prev=NULL;
}
else
{
(*top)->next=(struct node *)malloc(sizeof(struct node));
(*top)->next->prev=(*top);
(*top)=(*top)->next;
}
(*top)->data=c;
(*top)->next=NULL;
}

int pop(struct node ** top)
{
if((*top)==NULL)
{
return -1000;
}
else
{
int c=(*top)->data;
struct node * temp=(*top);
(*top)=(*top)->prev;
if((*top)!=NULL)
	(*top)->next=NULL;
free(temp);
return c;
}
}

int operate(int a, int b, char c)
{
switch(c)
{
case '+':
	return a+b;
case '-':
	return a-b;
case '*':
	return a*b;
case '/':
	return a/b;

}

}
int eval(struct node * top, char str[])
{
int i=0;
int ans=0;
while(str[i]!='\0')
{
char cc=str[i];
if(isdigit(cc))
{push(&top,cc-'0');
}
else
{
int a=pop(&top);
int b=pop(&top);
if (a==-1000 || b==-1000)
{
printf("stack empty in middle");
return -1;
}
else
{
int c=operate(b,a,cc);
push(&top,c);
}

}


i++;
}
int n1=pop(&top);
if(n1==-1000)
{printf("\nnothing in stack after eval");
return -1;
}
int n2=pop(&top);
if(n2!=-1000)
{printf("\nmore items in stack after eval");
return -1;
}
return n1;

}







int main()
{

char str[20];
struct node * top=NULL;
printf("enter a string:");
scanf("%s",str);
int cnt=eval(top,str);
printf("\nans = %d\n",cnt);
}


