#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};

void print(struct node * head)
{
struct node *temp;
printf("\n");
int i=1;
for(temp=head;temp!=NULL;temp=temp->next)
{
printf(" %d ",temp->data);
if(i==13)
	break;
i++;
}
printf("\n\n");
}



struct node * delete(struct node * head, int n)
{
struct node *temp,*tnext;
if(n==1)
{
printf(" the winner is %d",head->data);
return head;
}

srand(time(NULL));
int r = (rand() % (n)) + 1;
printf("the random no is %d \n",r);

if(r==1)
{	printf(" %d is out",head->data);
	for(temp=head->next;temp->next!=head;temp=temp->next);
	temp->next=head->next;
	temp=head;
	head=head->next;
	free(temp);
	print(head);
}
else
{
	int i=2;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
	if(i==r)
	{
    	tnext=temp->next;
    	printf(" %d is out",tnext->data);
    	temp->next=tnext->next;
    	free(tnext);
    	print(head);
    	break;
	}
	i++;
	if(i>n)
    	break;
	}    
}
return delete(head,n-1);
}




struct node *create(struct node * head, int n)
{
struct node *temp;
for(int i=0;i<n;i++)
{
if(head==NULL)
{head=(struct node *)malloc(sizeof(struct node));
head->data=(i+1);
head->next=head;
}
else
{
for(temp=head;temp->next!=head;temp=temp->next);
temp->next=(struct node *)malloc(sizeof(struct node));
temp=temp->next;
temp->data=(i+1);
temp->next=head;
}

}
return head;
}



int main()
{
int n;
//n=10;
printf("\nenter no of players:");
scanf("%d",&n);
struct node *head=NULL;
head=create(head,n);
print(head);
//spin(head,n);
head=delete(head,n);
printf("\n\nlinked list in main is :");
print(head);

}


