#include<stdio.h>
#include<stdlib.h>
int *ht, count=0, m,n;
void insert(int key)
{
   int index = key % m;
   while(ht[index] != -1)
   {
      index = (index + 1) % m;
   }

   ht[index] = key;
   count ++; 
}
void display()
{
    if(count == 0)
    {
        printf("\nHashTable is empty");
        return;
    }
    printf("\nHash Table :\n");
    for(int i=0;i<m;i++)
    {
      printf("T|%d| - %d\n",i,ht[i]);
    }

}

int main()
{
      printf("\nEnter the value for N - Employee Recordes:");
      scanf("%d",&n);
      int key[n];

      printf("\nEnter the value for M - Hash Table memory :");
      scanf("%d",&m);

      ht = (int*) malloc(sizeof(int)*m);

      for(int i=0;i<m;i++)
      {
          ht[i] = -1;
      }

      printf("\nEnter the values for key(K), for employee recordes:\n");
      for(int i=0;i<n;i++)
      {
          scanf("%d",&key[i]);
      }

      for(int i=0;i<n;i++)
      {
         if(count == m)
         {
            printf("\nHash Table is full\n");
            break;
         }
         else
         {
            insert(key[i]);
         }
      }

      display();
}