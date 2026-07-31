#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct node
{
int data;
int sl;
struct node * next, *prev;
};
void print(struct node * head, struct node * tail)
{
struct node * temp;
printf("\n print from head\n");
for(temp=head; temp!=NULL;temp=temp->next)
{
printf(" %d ",temp->data);
if((temp->data)%10==0)
{printf("\n");
}
}
printf("\n print from tail\n");
for(temp=tail; temp!=NULL;temp=temp->prev)
{
if((temp->data)%10==0)
{printf("\n");
}
printf(" %d ",temp->data);

}
printf("\n");
}
void assign(struct node * head)
{
struct node * temp;
for(temp=head;temp!=NULL;temp=temp->next)
{
switch(temp->data)
{
case 5:
	{
	temp->sl=53;
	break;
	}
case 14:
	{
	temp->sl=35;
	break;
	}
case 38:
	{
	temp->sl=-18;
	break;
	}
case 45:
	{
	temp->sl=-38;
	break;
	}
case 42:
	{
	temp->sl=18;
	break;
	}
case 53:
	{
	temp->sl=19;
	break;
	}
case 64:
	{
	temp->sl=19;
	break;
	}
case 75:
	{
	temp->sl=19;
	break;
	}
case 97:
	{
	temp->sl=-36;
	break;
	}
case 91:
	{
	temp->sl=-18;
	break;
	}
case 65:
	{
	temp->sl=-11;
	break;
	}
case 51:
	{
	temp->sl=-41;
	break;
	}
}
}

}
struct node * ladder(struct node * temp,int s)
{
for(int i=0;i<s ;i++)
{
temp=temp->next;
}
return temp;
}
struct node * snake(struct node * temp,int s)
{
for(int i=0;i<s ;i++)
{
temp=temp->prev;
}
return temp;
}
struct node * move(struct node * temp, int x)
{
for(int i=0;i<x;i++)
{
if(temp->next==NULL)
	return temp;
temp=temp->next;
}
return temp;
}

int game(struct node * head)
{

struct node * p1=head;
printf("\n starting position is %d",p1->data);
int c=0;
while(1)
{
int x=(rand() %6)+1;
printf("\n\n dice number: %d ",x);
c++;
p1=move(p1,x);
printf("\n landed at :%d ",p1->data);
if((p1->sl)>0)
	{
	printf(" ladder ");
	p1=ladder(p1,p1->sl);
	}
    
else if ((p1->sl)<0)
	{
	printf(" snake ");
	p1=snake(p1,-(p1->sl));
	}
printf("\n current position is %d",p1->data);
    
if((p1->data)==100)
	{
	printf("\n WINNER");
	break;
	}

}
printf("\n no of turns= %d ",c);
return c;
}


void create(struct node ** head, struct node ** tail, int n)
{
struct node * temp;
for( int i=0;i<n;i++)
{
if((*head)==NULL)
{
*head=(struct node *)malloc(sizeof(struct node));
(*head)->data=(i+1);
(*head)->sl=0;
(*head)->next=NULL;
(*head)->prev=NULL;
temp=*head;
}
else
{
temp->next=(struct node *)malloc(sizeof(struct node));
temp->next->prev=temp;
temp=temp->next;
temp->data=(i+1);
temp->sl=0;
temp->next=NULL;
}
}
*tail=temp;

}

int main()
{
int n=100;
struct node *head=NULL,*tail=NULL;
create(&head,&tail,n);
print(head,tail);
assign(head);
srand(time(NULL));
printf("\n PLAYER 1 IS PLAYING \n\n");
int c1=game(head);
printf("\n\n PLAYER 2 IS PLAYING \n\n");
int c2=game(head);
if(c1<c2)
	printf("\n Player 1 is the winnner");
else if (c1>c2)
	printf("\n Player 2 is the winnner");
else
	printf("\n tie");
printf("\n\n");
}

