#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
struct node
{
int data;
char gift[50];
struct node *next;
};

void print(struct node * head)
{
struct node *temp;
printf("\n");
int i=1;
for(temp=head;temp!=NULL;temp=temp->next)
{
//printf(" %d %s",temp->data,temp->gift);
printf(" %d ",temp->data);
if(i==13)
	break;
i++;
}
printf("\n\n");
}
void spin(struct node *head,int n)
{
	srand(time(NULL));
	int r = (rand() % (n)) + 1;
	printf("the random no is %d \n",r);
    
struct node *temp;
printf("\n");
int i=1;
for(temp=head;temp!=NULL;temp=temp->next)
{
if(i==r)
	{printf("gift for number %d is %s",temp->data,temp->gift);
	break;
	}
i++;
}
printf("\n\n");
}
struct node *create(struct node * head, int n)
{
char prize[6][20]={"teddy bear","football","bat","car toy","pencil","water bottle"};
struct node *temp;
for(int i=0;i<n;i++)
{
if(head==NULL)
{head=(struct node *)malloc(sizeof(struct node));
head->data=(i+1);
strcpy(head->gift,prize[i%6]);
head->next=head;
}
else
{
for(temp=head;temp->next!=head;temp=temp->next);
temp->next=(struct node *)malloc(sizeof(struct node));
temp=temp->next;
temp->data=(i+1);
strcpy(temp->gift,prize[i%5]);
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
spin(head,n);
}


