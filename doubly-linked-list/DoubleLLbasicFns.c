#include<stdio.h>
struct node
{
	int data;
	struct node *next,*prev;
};

void print(struct node *head, struct node *tail)
{
	struct node *temp;
	printf("\n\nPrinting from head:  ");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf(" %d ",temp->data);
	}
	printf("\n\nPrinting from tail:  ");
	for(temp=tail;temp!=NULL;temp=temp->prev)
	{
		printf(" %d ",temp->data);
	}
}

struct node * del(struct node*head,struct node **tail,int dt)
{
	struct node *temp,*tnext,*tprev;
	if(head->data==dt)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		return head;
	}
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==dt)
		{
			tnext=temp->next;
			tprev=temp->prev;
			tprev->next=tnext;
			if(tnext!=NULL)
				tnext->prev=tprev;
			else
			{*tail=tprev;
			}
			free(temp);
			return head;
		}
	}
}

void insertafter(struct node *head,struct node **tail,int ref,int dt)
{
	struct node *temp,*tnext;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==ref)
		{
			tnext=temp->next;
			
			struct node * nn=(struct node *)malloc(sizeof(struct node));
			nn->data=dt;
			temp->next=nn;
			nn->prev=temp;
			if(tnext!=NULL)
			{
			
			nn->next=tnext;
			tnext->prev=nn;
			break;
			}
			else
			{
			*tail=nn;
			nn->next=NULL;
			break;
			}
			
		}
	}
}
struct node * insertbefore(struct node *head,int ref,int dt)
{
	struct node *temp,*tnext;
	if(head->data==ref)
	{
		struct node * nn=(struct node *)malloc(sizeof(struct node));
		nn->data=dt;
		nn->next=head;
		nn->prev=NULL;
		head->prev=nn;
		head=nn;
	}
	else
	{
		
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		tnext=temp->next;
		if(tnext->data==ref)
		{		
			struct node * nn=(struct node *)malloc(sizeof(struct node));
			nn->data=dt;
			temp->next=nn;
			nn->prev=temp;
			nn->next=tnext;
			tnext->prev=nn;
			break;
		}
	}
	
	}
	return head;
}


struct node * create(struct node * head,struct node **tail, int n)
{
	struct node *temp;
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(struct node));
			head->data=(i+1)*10;
			head->prev=NULL;
			temp=head;
		}
		else
		{
			struct node * nn=(struct node *)malloc(sizeof(struct node));
			nn->data=(i+1)*10;
			temp->next=nn;
			nn->prev=temp;
			temp=temp->next;
			
		}
				
	}
	temp->next=NULL;
	*tail=temp;
	return head;
}

struct node * create2(struct node * head,struct node **tail, int n)
{
	struct node *temp;
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(struct node));
			head->data=(i+1)*10;
			head->prev=NULL;
			temp=head;
			head->next=NULL;
		}
		else
		{
			struct node * nn=(struct node *)malloc(sizeof(struct node));
			for(temp=head;temp->next!=NULL;temp=temp->next);
			nn->data=(i+1)*10;
			temp->next=nn;
			nn->prev=temp;
			temp=temp->next;
			temp->next=NULL;
			
		}
				
	}
	*tail=temp;
	return head;
}

int main()
{
	int n;
	printf("enter no of nodes:");
	scanf("%d",&n);
	struct node *head=NULL,*tail=NULL;
	//create once
	head=create(head,&tail,n);
	print(head,tail);
	//create again and again
	//head=create2(head,&tail,n);
	//print(head,tail);
	int ref,dt;
	printf("\nenter ref data and data to insert:");
	scanf("%d %d",&ref,&dt);
	insertafter(head,&tail,ref,dt);
	print(head,tail);
	
	printf("\nenter ref data and data to insert:");
	scanf("%d %d",&ref,&dt);
	insertafter(head,&tail,ref,dt);
	print(head,tail);
	
	printf("\nenter ref data and data to insert:");
	scanf("%d %d",&ref,&dt);
	head=insertbefore(head,ref,dt);
	print(head,tail);
	printf("\nenter ref data and data to insert:");
	scanf("%d %d",&ref,&dt);
	head=insertbefore(head,ref,dt);
	print(head,tail);
	printf("\nenter ref data to delete:");
	scanf("%d",&dt);
	head=del(head,&tail,dt);
	print(head,tail);
	printf("\nenter ref data to delete:");
	scanf("%d",&dt);
	head=del(head,&tail,dt);
	print(head,tail);
	printf("\nenter ref data to delete:");
	scanf("%d",&dt);
	head=del(head,&tail,dt);
	print(head,tail);
	
	
	
	
}
