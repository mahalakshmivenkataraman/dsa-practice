#include<stdio.h>
struct poly
{
	int num;
	int pow;
	struct poly * next;
};

void print(struct poly *head)
{
	printf("\n");
	struct poly *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf(" %d x%d ",temp->num,temp->pow);
	}
}


struct poly * add(struct poly * h1,struct poly * h2)
{
	struct poly *h3=NULL;
	struct poly *t1=h1,*t2=h2;
	h3=(struct poly *)malloc(sizeof(struct poly));
	if(t1->pow==t2->pow)
			{
				h3->num=t1->num+t2->num;
				h3->pow=t1->pow;
				h3->next=NULL;
				t1=t1->next;
				t2=t2->next;
			}
		else if(t1->pow>t2->pow)
		{
				h3->num=t1->num;
				h3->pow=t1->pow;
				h3->next=NULL;
				t1=t1->next;
		}
		else
		{
				h3->num=t2->num;
				h3->pow=t2->pow;
				h3->next=NULL;
				t2=t2->next;
		}
	struct poly * t3=h3;
	while(t1!=NULL && t2!=NULL)
	{
		t3->next=(struct poly *)malloc(sizeof(struct poly));
		t3=t3->next;	
		if(t1->pow==t2->pow)
			{
				t3->num=t1->num+t2->num;
				t3->pow=t1->pow;
				t3->next=NULL;
				t1=t1->next;
				t2=t2->next;
			}
		else if(t1->pow>t2->pow)
		{
				t3->num=t1->num;
				t3->pow=t1->pow;
				t3->next=NULL;
				t1=t1->next;
		}
		else
		{
				t3->num=t2->num;
				t3->pow=t2->pow;
				t3->next=NULL;
				t2=t2->next;
		}
		
	}
	struct poly *np;
	if(t1!=NULL)
	{
		np=t1;
	}
	else if(t2!=NULL)
	{
		np=t2;
	}
	else
	{
		np=NULL;
	}
		
		while(np!=NULL)
		{	t3->next=(struct poly *)malloc(sizeof(struct poly));
			t3=t3->next;	
			t3->num=np->num;
			t3->pow=np->pow;
			t3->next=NULL;
			np=np->next;
		}
	
	
	return h3;
	
}


struct poly * create(struct poly * head, int n)
{
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=(struct poly *)malloc(sizeof(struct poly));
			scanf("%d",&(head->num));
			scanf("%d",&(head->pow));
			head->next=NULL;
		}
		else
		{
			struct poly * temp;
			for(temp=head;temp->next!=NULL;temp=temp->next);
			temp->next=(struct poly *)malloc(sizeof(struct poly));
			temp=temp->next;
			scanf("%d",&(temp->num));
			scanf("%d",&(temp->pow));
			temp->next=NULL;
		}
	}
	return head;
	
}

int main()
{
	int n;
	printf("\nEnter no of nodes:");
	scanf("%d",&n);
	struct poly *h1=NULL,*h2=NULL;
	printf("\nenter data of poly1 followed by power:\n");
	h1=create(h1,n);
	printf("\nEnter no of nodes:");
	scanf("%d",&n);
	printf("\nenter data of poly2 followed by power:\n");
	h2=create(h2,n);
	struct poly *h3=NULL;
	h3=add(h1,h2);
	printf("\ndata of poly1:");
	print(h1);
	printf("\ndata of poly2:");
	print(h2);
	printf("\ndata of addn:");
	print(h3);
	
	
	
	
}
