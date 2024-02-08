#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int front = 0, rear = -1, q[MAX] ;
int main()
{
     void insert();
     void display();
     void delete();
     int choice;
        printf("Circular Operation Menu:\n");
        printf("1-> Insert\n2-> Delete \n3->display\n4->Exit.\n");
        while(1)
        {
                printf("Enter your choice :");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1: insert();
                            break;
                    case 2: delete();
                            break;
                    case 3: display();
                            break;
                    case 4: exit(1);
                    default: printf("\nEnter valid expression");
                }
        }
}
void insert()
{
    int x;
    if((front==0)&&(rear==MAX-1)||(front>0)&&(rear==front -1))
    {
         printf("Queue Overflow!!\n");
    }
    else
    {
        printf("\nEnter th item to be inserted :");
        scanf("%d",&x);
    }
    if(rear == MAX-1 && front>0)
    {
        rear = 0;
        q[rear] = x;
    }
    else
    {
        if((front == 0 && rear == -1)||(rear != front -1))
        {
            q[++rear] = x;
        }
    }
}
void delete()
{
     int a;
     if(front == 0 && rear == -1)
     {
         printf("\nQueue Underflow..");
         exit(1);
     }
     if(front == rear)
     {
         a = q[front];
         front = 0;
         rear = -1;
     } 
     else if(front == MAX-1)
     {
         a= q[front];
         front = 0;
     }
     else
     {
         a = q[front++];
     }
     printf("\n%d has been deleted.\n",a);
}
void display()
{
     if(front == 0 && rear == -1)
     {
         printf("\nQueue Underflow..");
         exit(1);
     }
     if(front>rear)
     {
        for(int i=0;i<=rear;i++)
        {
        printf("\t%d",q[i]);
        }
        for(int j=front;j<MAX-1;j++)
        {
            printf("\t%d",q[j]);
        }
        printf("\nFront is at %d ",q[front]);
        printf("\nRear is at %d ",q[rear]);
     }
     else
     {
        for(int i=front;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
     }
     printf("\nFront is at %d ",q[front]);
     printf("\nRear is at %d ",q[rear]);
     
}