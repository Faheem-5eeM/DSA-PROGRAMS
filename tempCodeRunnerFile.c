

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