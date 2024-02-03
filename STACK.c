#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top=-1;
int pop();
int s[MAX];
void push(int item);
void display();
void palindrome();
void main()
{
    int item, choice;
    while(1)
    {
        printf("~~~~~~~STACK MENU~~~~~~~~\n\n");
        printf("1 -> Push an element and Overflow demo.\n");
        printf("2 -> Pop and element and Underflow demo.\n");
        printf("3 -> Display contents of stack. \n");
        printf("4 -> Palindrome Demo.\n");
        printf("5 -> Exit.\n");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1: printf("\nEnter the element to be push into the stack: ");
                     scanf("%d",&item);
                     push(item);
                     break;

             case 2: item = pop();
                     if(item!=-1)
                     {
                       printf("\nPopped item is %d ",item);
                     }
                     break;
                
              case 3: display();
                      break;

              case 4: palindrome();
                      break;

              case 5: exit(1);

              default:printf("\nEnter a Valid Input.\n");
                      break;
        }
    }
}
void push(int item)
{
   if(top == MAX-1)
   {
     printf("\n~~~~~~~~~Stack Overflow~~~~~~~~~\n");
     return;
   }
   top = top + 1;
   s[top] = item;
}
int pop()
{
    if(top==-1)
    {
       printf("\n~~~~~~~~~~Stack Underflow~~~~~~~~~\n");
       return -1;
    }
    int item = s[top];
    top = top-1;
    return item;

}

void display()
{
    if(top == -1)
    {
       printf("\n~~~~~~~~~~Stack Underflow!~~~~~~~~~\n");
       return;
    }
    printf("\nStack Contents Are: \n");
    for(int i=top;i>=0;i--)
    {
      printf("|%d|\n",s[i]);
    }

}

void palindrome()
{
    int flag = 1;
    printf("\nStack Contents Are: \n");
    for(int i=top;i>=0;i--)
    {
      printf("|%d|\n",s[i]);
    }
    printf("\nStack Reverse Contents:\n");
    for(int i=0;i<=top;i++)
    {
        printf("|%d|\n",s[i]);
    }

    for(int i=0;i<=top/2;i++)
    {
        if(s[i]!= s[top - i])
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
           printf("\nStack contents are Palindrome.\n");
    }
    else
    {
          printf("\nStack Contents are Not Palindrome.\n");
    }

}