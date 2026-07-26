#include<stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node * prev;
};
struct node * push(struct node * top, int n)
{
struct node * nn;
nn=(struct node *) malloc(sizeof(struct node));
nn->data=n;
nn->prev=top;
top=nn;
return top;
}
int pop(struct node **top)
{
if(*top==NULL)
return -1;
else
{
int x=(*top)->data;
struct node * temp=*top;
*top=(*top)->prev;
free(temp);
return x;
}
}




int main()
{
struct node * top=NULL;
top=push(top,5);
printf("\npush done");
top=push(top,10);
printf("\npush done");
int x;
printf("\nPop done %d",pop(&top));
printf("\nPop done %d",pop(&top));
printf("\nPop done %d\n",pop(&top));
}

