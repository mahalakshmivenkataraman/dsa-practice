#include<stdio.h>
#include<stdlib.h>
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
if(i==12)
	break;
i++;
}
printf("\n");
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
printf("enter the number of nodes to create:");
scanf("%d",&n);
struct node *head=NULL;
head=create(head,n);
print(head);
}


