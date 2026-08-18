#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
	int data;
	struct node * left, * right;
};
void inorder(struct node * root)
{
	if(root == NULL)
        return;
	if(root->left!=NULL)
		inorder(root->left);
	printf(" %d ",root->data);
	if(root->right!=NULL)
		inorder(root->right);
}

void preorder(struct node * root)
{
	if(root == NULL)
        return;
	printf(" %d ",root->data);
	
	if(root->left!=NULL)
		preorder(root->left);
	
	if(root->right!=NULL)
		preorder(root->right);
}

void postorder(struct node * root)
{
	if(root == NULL)
        return;
	if(root->left!=NULL)
		postorder(root->left);
	
	if(root->right!=NULL)
		postorder(root->right);
		
	printf(" %d ",root->data);
}

struct node * create(struct node * root,int el)
{
	if(root==NULL)
		{
			root=(struct node *)malloc(sizeof(struct node));
			root->data=el;
			root->left=NULL;
			root->right=NULL;
		}
	else if(el<root->data)
	{
		root->left=create(root->left,el);
	}
	else
		root->right=create(root->right,el);
	
	return root;
	
}

int height(struct node * root)
{
	if(root==NULL)
		return 0;
	int lh=0,rh=0;
	lh=height(root->left);
	rh=height(root->right);
	if(lh>rh)
		return (lh+1);
	else
		return (rh+1);
}





int main()
{
	srand(time(NULL));
	int n;
	printf(" how many random nos?");
	scanf("%d",&n);
	struct node * root=NULL;
	printf("Random numbers generated:  ");
	for(int i=0;i<n;i++)
	{
		int rn=rand()%100;
		root=create(root,rn);
		printf(" %d ",rn);
	}
	printf("\n INORDER TRAVERSAL :");
	inorder(root);
	printf("\n PREORDER TRAVERSAL :");
	preorder(root);
	printf("\n POSTORDER TRAVERSAL :");
	postorder(root);
	printf("\n");
	printf("\n height of the tree is %d ",height(root));
	printf("\n");
}










