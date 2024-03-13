#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,j,n;
     int pos;
     printf("\nEnter the no of array elements:\n");
     scanf("%d",&n);
     int a[n];
     printf("Enter the array elements - (%d - elements):\n",n);
     for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
     }
     int ch;
     while(1)
     {
          printf("\n~~~~~~~~~~~MENU~~~~~~~~~~~\n");
          printf("1 -> Insert an element in an array.\n");
          printf("2 -> Delete an element in an array.\n");
/*           printf("3 -> Search for an element in an array (binary search).\n");
          printf("4 -> Sort array.\n"); */
          printf("3 -> Display array contents.\n");
          printf("4 -> Exit()\n");

          printf("\nEnter your choice :\n");
          scanf("%d",&ch);
          switch(ch)
          {
             case 1 : printf("\nEnter an element to be inserted:\n");
                      int x;
                      scanf("%d",&x);
                      printf("\nEnter the position to be inserted:\n");
                      
                      scanf("%d",&pos);
                      n++;
                      for(i=n-1;i>=pos-1;i--)
                      {
                          a[i] = a[i-1];
                      }
                      a[pos-1] = x;
                      printf("\nAfter Addition - Array is :\n");
                      for(i=0;i<n;i++)
                      {
                          printf("%d\t",a[i]);
                      }
                      printf("\n");
                      break;

             case 2 : printf("\nEnter the position of the element to be deleted:\n");
                      scanf("%d",&pos);
                      for(i=pos-1; i<n-1;i++)
                      {
                          a[i] = a[i+1];
                      }
                      n = n-1;
                      printf("\nAfter Deletion -  Array is :\n");
                      for(i=0;i<n;i++)
                      {
                          printf("%d\t",a[i]);
                      }
                      printf("\n");
                      break;
                    
             case 3 : for(i=0;i<n;i++)
                      {
                          printf("%d\t",a[i]);
                      }
                      printf("\n");
                      break;

             case 4 : exit(1);
             default: printf("\nEnter a valid input:\n");
         }

     }

}