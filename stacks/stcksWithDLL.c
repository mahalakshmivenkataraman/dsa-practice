#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next, * prev;
};
void peek(struct node * top)
{
	if (top==NULL)
		printf("\nNo Data in the stack\n");
	else
		printf("\nData at the stack top is %d\n",top->data);
}
void push(struct node ** top, int dt)
{
	if(*top==NULL)
	{
		*top=(struct node *)malloc(sizeof(struct node));
		(*top)->prev=NULL;
	}
	else
	{
		(*top)->next=(struct node *)malloc(sizeof(struct node));
		(*top)->next->prev=*top;
		*top=(*top)->next;	
	}
	(*top)->data=dt;
	(*top)->next=NULL;
}
int pop(struct node **top)
{
	if ((*top)==NULL)
	{
		return -1;
	}
	int x=(*top)->data;
	struct node *temp;
	temp=*top;
	if((*top)->prev==NULL)
	{
		*top=(*top)->prev;
		free(temp);
		return x;
	}
	
	*top=(*top)->prev;
	(*top)->next=NULL;
	free(temp);
	return x;
}



int main()
{
	int n,d;
	printf("how many times do you want to push?");
	scanf("%d",&n);
	struct node * top=NULL;
	for(int i=0;i<n;i++)
	{
		printf("enter data:");
		scanf("%d",&d);
		push(&top,d);	
	}
	peek(top);
	char ch;
	while(1)
	{
		printf("\nDo you want to pop?");
		scanf(" %c",&ch);
		if(ch=='n' || ch=='N')
			break;
		int p=pop(&top);
		if (p==-1)
			printf("Stack empty cant pop");
		else
			printf("\nthe popped data is %d",p);
	}
	
	
}












