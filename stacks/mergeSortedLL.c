#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
void print(struct node * head)
{
	printf("\n");
	struct node * temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}
	printf("\n");
}
struct node * create(struct node * head, int n)
{
	int x;
	struct node * temp;
	for(int i=0;i<n;i++)
	{
		printf("enter data");
		scanf("%d",&x);
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(struct node));
			head->next=NULL;
			head->data=x;
			temp=head;
		}
		else
		{
			temp->next=(struct node *)malloc(sizeof(struct node));
			temp=temp->next;
			temp->data=x;
			temp->next=NULL;
		}
	}
	return head;
}
struct node * merge(struct node *h1,struct node *h2)
{
	struct node *t1=h1,*t2=h2,*h3=NULL,*t3;
	h3=(struct node *)malloc(sizeof(struct node));
	h3->next=NULL;
	if(h1->data<=h2->data)
	{
		h3->data=h1->data;
		t1=t1->next;
	}
	else
	{
		h3->data=h2->data;
		t2=t2->next;
	}
	t3=h3;
	while(t1!=NULL && t2!=NULL)
	{
		t3->next=(struct node *)malloc(sizeof(struct node));
		t3=t3->next;
		if((t1->data)<=(t2->data))
		{
			t3->data=t1->data;
			t1=t1->next;
		}
		else
		{
			t3->data=t2->data;
			t2=t2->next;
		}
	}
	if(t2!=NULL)
	{
		t1=t2;
	}
	else
		t1=NULL;
	while(t1!=NULL)
	{
		t3->next=(struct node *)malloc(sizeof(struct node));
		t3=t3->next;
		t3->data=t1->data;
		t1=t1->next;
	}
	t3->next=NULL;
	return h3;
	
	
}






int main()
{
	int n;
	struct node *h1=NULL,*h2=NULL,*h3=NULL;
	printf("enter no of nodes to create for 1:");
	scanf("%d",&n);
	h1=create(h1,n);
	printf("enter no of nodes to create for 2:");
	scanf("%d",&n);
	h2=create(h2,n);
	printf("Data of LL1:");
	print(h1);
	printf("Data of LL2:");
	print(h2);
	printf("Data of merged LL:");
	h3=merge(h1,h2);
	print(h3);
}



















