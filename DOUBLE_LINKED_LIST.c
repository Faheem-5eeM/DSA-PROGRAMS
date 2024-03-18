#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
    long int sal, phno;
    char ssn[20], name[20], dept[20],designation[20];
    struct node*llink;
    struct node*rlink;
}*first =NULL, *last=NULL,*temp=NULL,*temp1;

void create()
{
    long int sal, phno;
    char ssn[20], name[20], dept[20],designation[20]; 
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Name, SSN, Department, Designaton, Salary and phno\n");
    scanf("%s %s %s %s %d %d",name,ssn,dept,designation,&sal,&phno);
    strcpy(temp->ssn,ssn);
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->designation,designation);
    temp->sal = sal;
    temp->phno = phno;
    temp->llink = NULL;
    temp->rlink=NULL;
    count++;
}

void insert_first()
{
    if(first == NULL)
    {
       create();
       first = temp;
       last = first;

    }
    else
    {
       create();
       temp-> rlink = first;
       first -> llink = temp;
       first = temp;
    }
}

void insert_last()
{
    if(first == NULL)
    {
       create();
       first = temp;
       last = first;
    }
    else
    {
        create();
        last -> rlink = temp;
        temp -> llink = last;
        last = temp;
    }     
}

void display()
{
    int nodeno = 1;
    temp1 = first;
    if(temp1 == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while(temp1!=NULL)
    {
        printf("\nEnode : %d | name : %s | ssn : %s | Department : %s | Designation : %s | salary : %ld | phno : %ld\n",nodeno,temp1 ->name,temp1 ->ssn,temp1 ->dept,temp1 ->designation,temp1 ->sal,temp1 ->phno );
        nodeno++;
        temp1 = temp1-> rlink;
    }
    printf("\nTotal no of employees %d \n", count);
}

void delete_last()
{
    struct node*temp;
    temp = last;

    if(last == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else if(last -> llink == NULL)
    {
       printf("\nEmployee with %s is deleted\n", last -> ssn);
       first = last= NULL;
       free(last);
    }
    else
    {
        last = last -> llink;
        last -> rlink = NULL;
        printf("\nEmployee with %s is deleted\n", temp -> ssn);
        free(temp);
    }
    count--;
    return;
}

void delete_first()
{
    struct node*temp;
    temp = first;
    if(first == NULL)
    {
       printf("\nList is empty\n");
        return;
    }
    else
    {
           printf("\nEmployee with %s is deleted\n", temp -> ssn);
           first = first -> rlink;
           if(first!=NULL)
           {
               first -> llink =NULL;
           }
           else
           {
              last = NULL;
           }
           free(temp);
    }
    count--;
    return;
}

void deqdemo()
{
      int ch;
      while(1)
      {
          printf("\nDouble ended queue operations\n");
          printf("\n1-> Insert Queue front\n2-> delete Queue front \n3-> Insert Queue rear\n4-> Delete Queue rear\n5-> display\n 6-> exit");
          printf("\nEnter your choice\n");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1: insert_first();
              break;
              case 2: delete_first();
              break;
              case 3: insert_last();
              break;
              case 4: delete_last();
              break;
              case 5: display();
              break;
              default:return;
          }
      }
}

void main()
{
      int ch,n;
      while(1)
      {
          printf("\n1-> CREATE A DLL FOR N EMPLOYEES\n");
          printf("2-> INSERT_FRONT\n");
          printf("3-> INSERT BACK\n");
          printf("4-> DELETE_FRONt\n");
          printf("5-> DELETE_BACK\n");
          printf("6-> DISPLAY\n");
          printf("7-> EXIT\n");
          printf("8-> Double ended Queue demo using dll\n");
          printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nEnter your choice\n");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1: printf("\nEnter no of employees :\n");
                      scanf("%d",&n);
                      for(int i=0;i<n;i++)
                      {
                           insert_first();
                      }
                      break;
             case 2: insert_first();
                     break;
             case 3: insert_last();
                      break;
             case 4: delete_first();
                     break;
             case 5: delete_last();
                     break;
             case 6: display();
                     break;
             case 7: exit(1);
             case 8: deqdemo();
                     break;
             default:printf("\nEnter a valid input\n");                   
          }
      }
}