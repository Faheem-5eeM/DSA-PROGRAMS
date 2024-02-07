#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int op1,op2,result,top=-1;
char postfix[20],symbol,s[20];
void push(int item)
{
    top = top +1;
    s[top] = item;
}
int pop()
{
   int item = s[top];
   top = top-1;
   return item;
}
int main()
{
     printf("Enter the a valid postfix expression: ");
     scanf("%s",postfix);
     for(int i =0;postfix[i]!='\0';i++)
     {
        symbol = postfix[i];
         if(isdigit(symbol))
         {
             push(symbol - '0');
         }
         else
         {
            op2 = pop();
            op1 = pop();
            switch(symbol)
            {
                case '+':push(op1+op2);
                         break;
                case '-':push(op1-op2);
                         break;
                case '*':push(op1*op2);
                         break;
                case '/':push(op1/op2);
                         break;
                case '%':push(op1%op2);
                         break;
                case '$':
                case '^':push(pow(op1,op2));
                         break;
                default: push(0);
                         
            }
         }
     }
     result = pop();
     printf("result : %d",result);
}