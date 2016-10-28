#include<stdio.h>
typedef struct node
{
    int info;
    struct node *link;
}nd;
nd *start=NULL;
int main()
{
    int a,b,c,d,e,f,g,h,i,k;
    nd *t;
    while(1)
    {
        printf("\n1.CREATION\n2.DISPLAY\n3.INSERTION\n4.DELETION\n5.SEARCHING\n6.SORTING\n7.EXIT\nPlease enter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            creation();
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nenter the number to insert: ");
            scanf("%d",&b);
            printf("\t1.insert after a data\n\t2.insert at first position\n\t3.insert in a specified position\n\t4.insert at last\n\t5.insert before a data :  ");;
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                printf("\nenter the specified number before the input data:");
                scanf("%d",&d);
                insert_after(b,d);
                display();
                break;

            case 2:
                insert_first(b);
                display();
                break;
            case 3:
                printf("\nenter the specified position: ");
                scanf("%d",&e);
                insert_specified(b,e);
                display();
                break;
            case 4:
                insert_last(b);
                display();
                break;
            case 5:
                printf("enter the value before you want to insert: ");
                scanf("%d",&g);
                insert_before(b,g);
                display();
                break;
            default:
                printf("\nwrong input\nplease enter a valid keyword");

            }
            break;
            case 5:
                printf("enter the number to search: ");
                scanf("%d",&f);
                search(f);
                break;
            case 4:
                printf("\t1.by position\n\t2.by value: ");
                scanf("%d",&h);
                switch(h)
                {
                case 1:
                    printf("\nenter the position you want to delete: ");
                    scanf("%d",&i);
                    delete_position(i);
                    display();
                    break;
                case 2:
                    printf("\nenter the value you want to delete: ");
                    scanf("%d",&i);
                    delete_value(i);
                    display();
                    break;
                default:
                    printf("\n\twrong input please enter a valid input  ");
                }
                break;
            case 6:
                printf("\t1.using insertion sort\n\t2.using selection sort\n\t3.using bubble sort  :");
                scanf("%d",&k);
                switch(k)
                {
                case 1:
                    insertion_sort();
                    display();
                    break;
                case 2:
                    selection_sort();
                    display();
                    break;
                case 3:
                    bubble_sort();
                    display();
                    break;
                default:
                    printf("\nwrong input please enter a valid input\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("\nwrong input\nplease enter a valid input:\n");
    }

  }
  return 0;
}
void creation()
{
    char ch;
   nd *ptr=(nd *)malloc(sizeof(nd));
   printf("enter the data: ");
   scanf("%d",&ptr->info);
   start=ptr;
   printf("Do you want to continue (y/n):  ");
   fflush(stdin);
   scanf("%c",&ch);
   while(ch=='y'||ch=='Y')
   {
       ptr->link=(nd*)malloc(sizeof(nd));
       ptr=ptr->link;
       printf("\nenter the data: ");
       scanf("%d",&ptr->info);
       printf("\nDo you want to continue (y/n):  ");
       fflush(stdin);
       scanf("%c",&ch);

   }
   ptr->link=NULL;
}
void display()
{
    nd *ptr=start;
    printf("start");
    while(ptr)
    {
        printf("->%d",ptr->info);
        ptr=ptr->link;
    }
}
void search(int y)
{
    nd *ptr=start;
    while(ptr)
    {
        if(ptr->info==y)
            break;
        ptr=ptr->link;
    }
    if(ptr)
        printf("\nsearch is successful");
    else
        printf("\nsearch is unsuccessful");

}
void insert_after(int x,int y)                    //insert x after y
{
    nd *t=(nd *)malloc(sizeof(nd));
    nd *ptr=start;
    while(ptr)
    {
        if(ptr->info==y)
            break;
        ptr=ptr->link;
    }

    if(ptr)
    {
        t->info=x;
        t->link=ptr->link;
        ptr->link=t;
    }
    else
        printf("\n insertion not possible as because the given item %d not found",x);
}
void insert_first(int x)
{
    nd *t=(nd *)malloc(sizeof(nd));
    if(start)
    {   t->info=x;
        t->link=start;
        start=t;
    }
    else
    {
        t->info=x;
        start=t;
        start->link=NULL;
    }

}
void insert_specified(int x,int pos)
{
  nd *t=(nd *)malloc(sizeof(nd));
  int c=0,i;
  nd *ptr=start;
  while(ptr)
  {
      ptr=ptr->link;
      c++;
  }
  if(pos==1)
    insert_first(x);
  else if(pos>1&&pos<=c)
  {
      ptr=start;
      for(i=1;i<pos-1;i++)
        ptr=ptr->link;
      t->info=x;
      t->link=ptr->link;
      ptr->link=t;

  }
  else if(pos==c+1)
    insert_last(x);
  else
    printf("not \n");


}
void insert_last(int x)
{
   nd *t=(nd *)malloc(sizeof(nd));
   nd *ptr=start;
   while(ptr)
    {
        if(ptr->link==NULL)
        break;
        ptr=ptr->link;

    }
   if(ptr)
   {
       t->info=x;
       ptr->link=t;
       t->link=NULL;
   }
   else
    {
        t->info=x;
        start=t;
        start->link=NULL;
    }
}
void insert_before(int x,int y)                 //insert x before y  //57741802
{
   nd *t=(nd *)malloc(sizeof(nd));
   nd *ptr=start;
   if(ptr)
   {
     if(ptr->info==y)
     {
         t->info=x;
         t->link=start;
         start=t;
     }
     else
     {
         while(ptr->link)
         {
             ptr=ptr->link;
             if(ptr->link->info==y)
                break;
         }
         if(ptr->link)
         {
             t->info=x;
             t->link=ptr->link;
             ptr->link=t;
         }
         else
            printf("\ninsertion not possible as because %d is present in the link list\n",y);
     }
   }
   else
    printf("\ninsertion not possible as because link list is empty\n");
}
void delete_position(int pos)
{
    nd *ptr=start,*t;
    int c=0,i;
    while(ptr)
    {
        ptr=ptr->link;
        c++;
    }
    ptr=start;
    if(ptr)
    {
        if(pos==1)
        {
            start=ptr->link;
            free(ptr);
        }
        else if(pos>1&&pos<=c)
        {
            ptr=start;
            for(i=1;i<pos-1;i++)
                ptr=ptr->link;
            t=ptr->link;
            ptr->link=t->link;
            free(t);

        }
        else
            printf("\ninsertion not possible as because the position out of bound\n");

    }
    else
        printf("\ndeletion not possible as because the link list is empty");
}
void delete_value(int x)
{
  nd *ptr=start,*t;
  if(ptr)
  {
      if(ptr->info==x)
      {
          start=ptr->link;
          free(ptr);
      }
      else
      {
          while(ptr->link)
          {
              ptr=ptr->link;
              if(ptr->link->info==x)
                break;
          }
          if(ptr->link)

          {
             t=ptr->link;
             ptr->link=t->link;
             free(t);
          }
          else
            printf("\ndeletion not possible as because the item is not found");

      }
  }
  else
    printf("\ndeletion not possible as because the link list is empty ");
}
void insertion_sort()
{
    nd *ptr=start;
    int c=0,t;
    while(ptr)
    {
        ptr=ptr->link;
        c++;
    }
    if(start)
    {

    }
}
void selection_sort()
{
  nd *i,*j;
  int k;
  if(start)
  {
      printf("\nafter sorting the link list is\n");
    for(i=start;i->link!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->info>j->info)
            {
                k=i->info;
                i->info=j->info;
                j->info=k;
            }
        }
    }
  }
  else
    printf("\nsorting not possible as because link list is empty  ");

}
void bubble_sort()
{
  nd *j;
  nd *ptr=start;
  int t,c=0,d=1,g=1;
  while(ptr)
  {
      ptr=ptr->link;
      c++;
  }
  if(start)
  {
      ptr=start;
      while(d!=c)
      {
          g=1;
          for(j=start;g<c;j=j->link)
          {

              if(j->info>j->link->info)
              {
                  t=j->info;
                  j->info=j->link->info;
                  j->link->info=t;

              }
              g++;


          }
          d++;
      }
  }
  else
    printf("\nsorting is not possible as because link list is empty");
}
