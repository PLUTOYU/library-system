#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "login.h"
#include "book.h"
#include "readFile.h"
/*implement student to borrow books, first check student if borrow 5 books, then find book use
serial number or writer and name, check again if student want to borrow this book, and finish the operation
*/

void bookBorrow(Book *Bhead,Student *Shead,int ID)
{
    Student *pointerS;
    pointerS=Shead;
    while(pointerS->next!=NULL)
    {
        pointerS=pointerS->next;
        if(pointerS->stuID==ID)
            break;
    }
    int ch=checknumber(pointerS->reBorrow);             //check student if borrow 5 books
    if(ch==0)
    {
        printf(" Fail! 5 books enough, can't borrow book anymore! \n");
        return;
    }
    printf("Find book you wanted borrow:(1.serial number,2.name and writer): ");
    int choice=0;
    scanf("%d",&choice);getchar();
    if(choice>2||choice<1)
    {
        printf("   input invalid data!   \n");
        return;
    }
    int flag=0;
    Book *pointerB;
    pointerB=Bhead;
    if(choice==1)                                       //use serial number to find book
    {
       int sern=0;
       printf("    ENTER book's serial number: ");
       scanf("%d",&sern);
       while(pointerB->next!=NULL)
        {
        pointerB=pointerB->next;
        if(pointerB->serialNum==sern)
        {
            flag=1;
            break;
        }
       }
   }
   if(choice==2)                                          //use writer and name to find book
   {
    char name[20],writer[20];
    printf("   ENTER book's name: ");
    gets(name);
    printf("   ENTER book's writer: ");
    gets(writer);//puts(writer);
    while(pointerB->next!=NULL)
    {
        pointerB=pointerB->next;
        if(strcasecmp(pointerB->nameB,name)==0&&strcasecmp(pointerB->writer,writer)==0)
        {
            flag=1;
            break;
        }
    }
   }

    if(flag==1)                                //find out to borrow books
    {
           int choice1=0;
            printf("\n  %d  %s  %s  %d  %d \n",pointerB->serialNum,pointerB->nameB,pointerB->writer,pointerB->totalNum,pointerB->leftNum);
            printf("  There are %d books to borrow. \n\n",pointerB->leftNum);
            if(pointerB->leftNum>0)
            {
                printf("  SURE BORROW?(1.yes|2.no):");
                scanf("%d",&choice1);
                if(choice1==1)
                {
                    char no[]="no";
                    pointerB->leftNum=pointerB->leftNum-1;
                    if(strcasecmp(pointerS->reBorrow,"/no")==0)
                    {
                         strcpy(pointerS->reBorrow,"");
                         strcpy(pointerS->reReturn,"");
                    }
                    flag=1;
                    motifyBorrow(pointerS->reBorrow,pointerB->nameB);
                    motifyBorrow(pointerS->reReturn,no);
                    printf("    SUCCESS!  \n");
                }
            }
    }
    if(flag==0)
         printf("   Fail! Can't find this book  \n");
    return;
}
/*implement student to borrow books, there are two ways:serial number or name and writer to find book.
if choose sure return , system will finish this operation
*/
void bookReturn(Book *Bhead,Student *Shead,int ID)
{
    Student *pointerS;
    pointerS=Shead;
    while(pointerS->next!=NULL)
    {
        pointerS=pointerS->next;
        if(pointerS->stuID==ID)
            break;
    }
    if(strcasecmp(pointerS->reBorrow,"/no")==0)                   //check the ID if borrow books
    {
        printf(" Fail! YOU have not borrow book! \n");
        return;
    }
    printf("   Find book you wanted borrow:(1.serial number,2.name and writer):");
    int choice=0,flag=0;
    scanf("%d",&choice);getchar();
    if(choice>2||choice<1)                                        //check if input the invalid data
    {
        printf("   input invalid data!   \n");
        return;
    }
    Book *pointerB;
    pointerB=Bhead;
    if(choice==1)                                      //use serial number way to find book
    {
        int sern=0;
        printf("   ENTER book's serial number: ");
        scanf("%d",&sern);getchar();
        while(pointerB->next!=NULL)
        {
             pointerB=pointerB->next;
             if(pointerB->serialNum==sern)
             {
                     flag=1;
                     break;
             }
        }
    }
    if(choice==2)                                         //use writer and name to find book
    {
        char name[200],writer[200];
        printf("   ENTER book's name: ");
        gets(name);
        printf("   ENTER book's writer: ");
        gets(writer);
        while(pointerB->next!=NULL)
        {
             pointerB=pointerB->next;
             if(strcasecmp(pointerB->nameB,name)==0&&strcasecmp(pointerB->writer,writer)==0)
             {
                     flag=1;
                     break;
             }
        }
    }
    int ch=checkRepeat(pointerS->reBorrow,pointerB->nameB);
    if(flag==1&&ch!=0)
    {
          int choice1=0;
            printf("   %d  %s  %s  %d  %d\n",pointerB->serialNum,pointerB->nameB,pointerB->writer,pointerB->totalNum,pointerB->leftNum);
                printf("  SURE RETURN?(1.yes|2.no): ");          //ensure again
                scanf("%d",&choice1);
                if(choice1==1)
                {
                    char no[]="no";
                    pointerB->leftNum=pointerB->leftNum+1;
                    motifyReturn(pointerS->reBorrow,pointerB->nameB);
                    motifyReturn(pointerS->reReturn,no);
                    printf("    SUCCESS ! \n");
                }
    }
    if(flag==0)                                            //input information is not in book's linked list
        printf("   Fail! Can't find this book  \n");
    if(ch==0)                                              //return book's name is deferent from the ID borrow book's name
        printf("   Fail! you have not borrow this book! \n");
    return;
}
/*modify the student's linked list's record
*/
void motifyReturn(char *a,char *b)
{
    int n=strlen(a),m=strlen(b);
    int flag=0,i=0;
    for(i;i<n;i++)
    {
        int count=0,j=0;                       //find the return book's name position in the record
        for(j;j<m;j++)
        {
            if(a[i+j]==b[j])
                count++;
        }
        if(count==m)
        {
            flag=m;
            break;
        }
    }
    if(flag==m)                               //if record has return name, modify it
    {   char c[n-m];
        int k=0;
        for(k;k<n-m;k++)
        {
            if(k>=i-1)
                c[k]=a[k+m+1];
            else
                c[k]=a[k];
        }
        strcpy(a,c);
    }
    return;
}
//modify the student's linked list's record
void motifyBorrow(char *a,char *b)
{
    char del='/';
    int m=strlen(a)+strlen(b),q=strlen(a),p=strlen(b);
    char c[m+2];
    int i=0;
    for(i;i<m+2;i++)                           //create new record and strcpy the old
    {
        if(i<q)
            c[i]=a[i];
        if(i==q)
            c[i]=del;
        if(i>q)
            c[i]=b[i-q-1];
    }
    strcpy(a,c);
    return;
}
//check ID borrowed how many books
int checknumber(char *a)
{
    char del='/';
    int count=0,m=strlen(a);
    int i=0;
    for(i;i<m+1;i++)
    {
        if(a[i]==del)
            count++;
    }
    if(count==5)
    {
        return 0;
    }
    return 1;
}
//check if input return book's name is in ID's borrow record
int checkRepeat(char *a,char *b)
{
    int n=strlen(a),m=strlen(b);
    int flag=0,i=0;
    for(i;i<n;i++)
    {
        int count=0,j=0;
        for(j;j<m;j++)
        {
            if(a[i+j]==b[j])
                count++;
        }
        if(count==m)
        {
            flag=m;
            break;
        }
    }
    if(flag==0)
    {
        return 0;
    }
    if(flag==m)
    {
        return m;
    }
}

