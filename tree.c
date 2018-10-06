#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};  
typedef struct Node node;
struct btnode
{
  struct btnode * left;
  int data;
  struct btnode * right;
};
typedef struct btnode btnode;

node* pre=NULL,*in=NULL;
void insert_at_end(node* start,int data);

node* create_ll(int total_no)
{
  node* start;
  for(int i=1;i<=total_no;i++)
  {
    int temp;
    printf("Enter element to be inserted\n");
    scanf("%d",&temp);
    if(i==1)
      {
        start=(node*)malloc(sizeof(node));
        start->data=temp;
        start->next=NULL;
      }
    else
      insert_at_end(start,temp);
  }
  return start;
}

void insert_at_end(node* start,int data)
{
  node* temp=(node*)malloc(sizeof(node));
  temp->data=data;
  temp->next=NULL;
  node* p=start;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=temp;
}
void print_linked_list(node* start)
{
  while(start!=NULL)
  {
    printf(" -> %d ->",start->data);
    start=start->next;
  }
}
btnode* create(btnode* tree,node* in,node* pre)
{
  if(pre==NULL || in==NULL)
    return tree;
  else
    {
      tree=(btnode*)malloc(sizeof(btnode));
      tree->data=pre->data;
      tree->left=NULL;
      tree->right=NULL;
      node *p=in,*q=NULL;
      while(p!=NULL && p->data!=pre->data)
      {
        q=p;
        p=p->next;
      }
      pre=pre->next;
      if(q==NULL)
      in=NULL;
      else
      q->next=NULL;
      if(p==NULL)
      return tree;
      tree->left=create(tree->left,in,pre);
      tree->right=create(tree->right,p->next,pre);
    }
    return tree;
}
void display(btnode* ptr,int level)
{
  if(ptr!=NULL)
  {
    display(ptr->right,level+1);
    printf("\n");
    for(int i=0;i<level;i++)
    printf("  ");
    printf("%d",ptr->data);
    display(ptr->left,level+1);
  }
}
void inorder(btnode* ptr)
{
  if(ptr)
  {
    inorder(ptr->left);
    printf(" %d ",ptr->data);
    inorder(ptr->right);
  }
}
int main()
{
  int n;
  printf("Enter total num of elements in tree.\n");
  scanf("%d",&n);
  printf("enter preorder.\n");
  pre=create_ll(n);
  printf("enter inorder.\n");
  in=create_ll(n);
  btnode* tree;
  tree=create(tree,in,pre);
  printf("Creation of tree completed!\n");
  display(tree,0);
  printf("\n");
  inorder(tree);
  printf("\n");
}

