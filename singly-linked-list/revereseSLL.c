#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
int data;
struct node *next;
};

void print(struct node * head)
{
struct node *temp;
for(temp=head;temp!=NULL;temp=temp->next)
{printf(" %d ",temp->data);
}
printf("\n");
}


void create(struct node ** head,int n)
{
struct node *temp;

for(int i=0;i<n;i++)
{
if((*head)==NULL)
{
(*head)=(struct node *)malloc(sizeof(struct node));
(*head)->data=(i+1)*5;
(*head)->next=NULL;
}
else{
for(temp=(*head);temp->next!=NULL;temp=temp->next);
temp->next=(struct node *)malloc(sizeof(struct node));
temp=temp->next;
temp->data=(i+1)*5;
temp->next=NULL;
}
}

}
struct node * reverse(struct node * head)
{
	struct node *temp,*tnext,*tprev=NULL;
	temp=head;
	if(temp==NULL)
		return head;
	while(temp->next!=NULL)
	{
		tnext=temp->next;
		temp->next=tprev;
		tprev=temp;
		temp=tnext;
	}
	temp->next=tprev;
	return temp;
}

int main()
{
struct node *head=NULL;
int n;
int ref,dt;
printf("enter no of nodes:");
scanf("%d",&n);
create(&head,n);
print(head);
head=reverse(head);
print(head);
}
