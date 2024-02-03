#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
  char*name;
  char*description;
  int date;
}Day;

Day*create()
{
    Day*calendar = (Day*)malloc(sizeof(Day)*7);
    if(calendar == NULL)
    {
      printf("Error: allocating memory for Calendar\n");
      exit(1);
    }
    return calendar;
}

void read(Day*calendar)
{
     for(int i=0;i<7;i++)
     {
        printf("\nEnter the Name of Day %d :",i+1);
        char*name = (char*)malloc(sizeof(char)*100);
        if(name==NULL)
        {
          printf("\nError allocating memory for Name of the day\n");
          exit(1);
        }
        scanf("%s",name);
        calendar[i].name = name;
        printf("\nEnter the Date of the Day %d:",i+1);
        int date;
        scanf("%d",&date);
        calendar[i].date = date;
        printf("\nEnter the the description details for day %d:",i+1);
        char*description = (char*)malloc(sizeof(char)*100);
        if(description==NULL)
        {
          printf("\nError: allocating memory for The description.\n");
          exit(1);
        }
        scanf("%s",description);
        calendar[i].description = description;

     }
}

void display(Day*calendar)
{ 
    printf("\n\n          Activity Details           \n");
    printf("-------------------------------------\n\n");
/*     printf("Week Name  Day  Description:\n"); */
    for(int i=0;i<7;i++)
    {
       printf("%s %d : %s\n",calendar[i].name,calendar[i].date,calendar[i].description);
    }  
}

int main()
{
    Day*calendar = create();
    read(calendar);
    display(calendar);

    for(int i=0;i<7;i++)
    {
      free(calendar[i].name);
      free(calendar[i].description);
    }
    free(calendar);
    return 0;
}
