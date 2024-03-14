#include<stdio.h>
#include<stdlib.h>
void push(int item,int s[],int*top, int*SIZE)
{
    if(*top == *SIZE - 1)
    {
        (*SIZE) ++;
        s = (int*)realloc(s,sizeof(int)*(*SIZE));
    }
    (*top) ++;
    s[*top] = item;
    printf("\nPushed item is : %d\n",s[*top]);
}
int pop(int s[],int*top,int item)
{
    if(*top == -1)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    item = s[*top];
    (*top) --;
    return item;


}
void display(int s[],int top)
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
void main()
{
     int ch;
     int*s;
     int top = -1;
     int SIZE = 10;
     int item;
     s = (int*)malloc(sizeof(int)*SIZE);
     while(1)
     {
         printf("\n~~~~~~~~~~~~~~~MENU~~~~~~~~~~~\n");
         printf("\n1 -> PUSH\n");
         printf("2 -> POP\n");
         printf("3 -> DISPLAY\n");
         printf("4 -> EXIT\n");
         printf("--------------------------------\n\n");
         printf("Enter your choice:\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1: printf("\nEnter the element to be push into the stack: ");
                     scanf("%d",&item);
                     push(item,s,&top,&SIZE);
                     break;

             case 2: item = pop(s,&top,item);
                     if(item!=-1)
                     {
                       printf("\nPopped item is %d ",item);
                     }
                     break;
                
              case 3: display(s,top);
                      break;

              case 4: printf("\nThankyou for looking into my code :) .\n");
                     free(s);
                     exit(1);

              default:printf("\nEnter a Valid Input.\n");
                      break;                                   
         }
     }

}