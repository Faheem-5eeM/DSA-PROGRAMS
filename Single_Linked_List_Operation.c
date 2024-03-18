#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count =0;

struct node
{
    int sem, phno;
    char usn[20],name[20],branch[20];
    struct node*next;
}*first = NULL,*last = NULL,*temp =NULL,*temp1;
void create()
{
    int sem,phno;
    char usn[20],branch[20],name[20];
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter usn,name,branch,sem and phno of the student :\n");
    scanf("%s%s%s%d%d",usn,name,branch,&sem, &phno);
    strcpy(temp -> usn , usn);
    strcpy(temp -> name , name);
    strcpy(temp -> branch , branch);
    temp -> phno = phno;
    temp -> sem = sem;
    temp -> next = NULL;
    count ++;
    
}
void insert_atfirst()
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
        temp -> next = first;
        first = temp;
    }
}
void insert_atlast()
{
   if(last == NULL)
   {
       create();
       first = temp;
       last = first;
   }
   else
   {
       create();
       last -> next = temp;
       last = temp;
   }
}

void display()
{
    temp1= first;
    if(temp1 == NULL)
    {
        printf("\nSLL is emplty");
        return;
    }
    printf("\nDetails from Beginning:\n");
    while(temp1!= NULL)
    {
        printf("%s %s %s %d %d\n",temp1->usn,temp1->name,temp1->branch,temp1->sem,temp1->phno);
        temp1 = temp1->next;
    }
    printf("\nTotal no of students = %d",count);
}
int delete_end()
{
    struct node*temp ;
    temp = first;
    if(temp -> next ==NULL)
    {
        printf("%s %s %s %d %d\n",last->usn,last->name,last->branch,last->sem,last->phno);
        free(temp);
        first = NULL;
    }
    else
    {
         while(temp -> next!=last)
         {
             temp = temp -> next;
         }
         printf("%s %s %s %d %d\n",last->usn,last->name,last->branch,last->sem,last->phno);
         free(last);
         temp -> next = NULL;
         last = temp;
    }
    count--;
    return 0;
}
int delete_front()
{
    struct node*temp ;
    temp = first;
    if(temp -> next == NULL)
    {
        free(temp);
        first = NULL;
        return 0;
    }
    else
    {
        first = temp -> next;
        printf("%s %s %s %d %d\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

void main()
{
    int ch, n,i;
    printf("\n1. To Create a SLL for N Emp.\n");
    printf("\n2. to insert_atfirst\n");
    printf("\n3. To insert_atlast\n");
    printf("\n4. To delete_at_first\n");
    printf("\n5. To delete_at_last\n");
    printf("\n6. To display the information from begining\n");
    printf("\n7.Exit()\n");
    while(1)
    {
        printf("\n---------------------------------------------\nEnter your Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the no of students :\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                       insert_atfirst();
                    }
                    break;
            case 2: insert_atfirst();
                    break;
            case 3: insert_atlast();
                    break;
            case 4: delete_front();
                    break;
            case 5: delete_end();
                    break;
            case 6: display();
                    break;
            case 7: exit(1);
            default:printf("\nEnter a valid input\n");
        }
    }
}