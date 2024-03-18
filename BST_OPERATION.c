#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*lchild;
     struct node*rchild;
};
typedef struct node*NODE;
NODE create()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("\nEnter the value:\n");
    scanf("%d",&temp-> data);
    temp->lchild = NULL;
    temp->rchild =NULL;
    return temp;
} 
void insert(NODE root,NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void  postorder(NODE root);
void insert(NODE root, NODE newnode)
{
    if(newnode -> data < root -> data)
    {
        if(root-> lchild == NULL)
           root-> lchild = newnode;
        else
           insert(root->lchild, newnode);
    }
    if(newnode -> data > root -> data)
    {
        if(root-> rchild == NULL)
           root-> rchild = newnode;
        else
           insert(root->rchild, newnode);
    }
}

void search(NODE root)
{
    int key;
    NODE cur;
    if(root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nEnter the element to be searched\n");
    scanf("%d",&key);
    cur = root;
    while(cur!= NULL)
    {
       if(cur -> data == key)
       {
         printf("\nElement found successfully\n");
         return;
       }
       if(cur-> data > key)
       {
          cur = cur -> lchild;
       }
       else
       {
          cur = cur -> rchild;
       }
    }
    printf("\nElement not found\n");
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root -> lchild);
        printf("\t%d",root-> data);
        inorder(root-> rchild);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("\t%d",root-> data);
        preorder(root -> lchild);
        preorder(root-> rchild);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root -> lchild);
        postorder(root-> rchild);
         printf("\t%d",root-> data);
    }
}
void main()
{
     int i,n,ch;
     NODE newnode,root=NULL;
     while(1)
     {
        printf("\n~~~~~~~~~~~~~MENU~~~~~~~~~~~~\n");
        printf("1-> Create BST\n");
        printf("2-> Search\n");
        printf("3-> BsT traversal\n");
        printf("4-> exit\n");
        printf("\nENter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1: printf("\nENter no of elements \n");
                     scanf("%d",&n);
                     for(i=1;i<=n;i++)
                     {
                         newnode = create();
                         if(root == NULL)
                         {
                            root = newnode;
                         }
                         else
                         {
                            insert(root,newnode);
                         }
                     }
                     break;
              case 2: search(root);
              break;
              case 3 : if(root ==NULL)
                    {
                      printf("\nTree is not created\n");
                    }
                    else
                    {
                      printf("\nThe Inorder traversal:\n");
                      inorder(root);
                      printf("\nThe postorder traversal:\n");
                      postorder(root);
                      printf("\nThe preorder traversal:\n");
                      preorder(root);
                     }
                     break;
              case 4: exit(1);
        }
        
      }
}