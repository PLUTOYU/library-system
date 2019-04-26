#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "readFile.h"
#include "menu.h"
/*library staff use this function to add new books, input add books' number, then input the book's specific information
finally add the book in the end of book's linked list
*/
void addBook(Book *Bhead)
{
    int flag=0,num=0;
    Book *pointer;
    pointer=Bhead;
    while(pointer->next!=NULL)
        pointer=pointer->next;
    flag=pointer->serialNum;
    printf("what number books do you want to store:\n");           //input book's number
	scanf("%d",&num);getchar();
    int i=0;
    for(i; i<num; i++)                                             //loop:input the book's information
    {
        printf("Input book's information :  \n");
        int a=0,b=0;
        Book *temp;
        temp = (Book*)malloc(sizeof(Book));
        printf(" Name: ");
        gets(temp->nameB);
        printf(" Writer: ");
        gets(temp->writer);
        printf("total number and left number: ");
        scanf("%d %d",&temp->totalNum,&temp->leftNum);getchar();
        if(temp->totalNum<temp->leftNum)
        {
            printf("   total Num is less than temp->leftNum!  \n ");
            free(temp);                   //free the temp
            temp=NULL;
            continue;
        }
        Book *check;
        check=Bhead;
        while(check->next!=NULL)               //check if input information is already in library
        {
            check=check->next;
            if(strcasecmp(check->nameB,temp->nameB)==0&&strcasecmp(check->writer,temp->writer)==0)
               {
                   printf("   FAIL !   \n");
                   printf("  the book |%s|%s| has already been stored in the library! \n",temp->nameB,temp->writer);
                   b=1;
               }
        }
        if(b==0)        //add new book
        {
            printf("NEW BOOK: name:%s, writer:%s, total number:%d, left number:%d \n",temp->nameB,temp->writer,temp->totalNum,temp->leftNum);
            printf("    SAVE or NOT SAVE(1.yes|2.no): ");
            scanf("%d",&a);getchar();
            if(a>2||a<1)
            {
                printf("   input invalid data!   \n");
                free(temp);                   //free the temp
                temp=NULL;
                continue;
            }
            if(a==1)
            {
                flag++;
                printf("    SUCCESS !   \n");
                temp->serialNum=flag;
                temp->next=pointer->next;
                pointer->next=temp;
                pointer=pointer->next;
                printf("NEW BOOK: serial number, name, writer, total number, left number \n");
                printf("          %d, %s, %s, %d, %d \n",flag,temp->nameB,temp->writer,temp->totalNum,temp->leftNum);
            }
            if(a==2)
                printf("  the operation is cancel!   \n");
        }
        free(temp);                   //free the temp
        temp=NULL;
    }
    dispBook(Bhead);
    return;
}
/*library staff delete books, input delete number, then input the serial number to find book,
and delete it in a loop
*/
void deleBook(Book *head)
{
    int choice=0,num=0,count=0,m=0;
    Book *check;
    check=head;
    while(check->next!=NULL)
    {
        check=check->next;
        m++;
    }
    printf("what number books do you want to delete:\n");
	scanf("%d",&num);getchar();
	if(num>m)       //check input delete number if less then total of library book
    {
        printf("    there are not much book to delete!   \n");
        return;
    }
	for(count=0;count<num;count++)      //input information and delete in a loop
    {
        printf("Find books do you want to delete(input serial number):");
        scanf("%d",&choice);getchar();
        struct book *pointer,*jump;
        int flag=0;
        pointer=head;
        while(pointer->next->serialNum!=choice&& pointer != NULL)
        {
            pointer=pointer->next;
            flag++;
            if(pointer->next==NULL)
                break;
        }
        if(pointer->next!=NULL)     //check if the pointer stop in one books if not, output the input information is invalid
        {
            printf("  %d  %s  %s  %d  %d\n",pointer->next->serialNum,pointer->next->nameB,pointer->next->writer,pointer->next->totalNum,pointer->next->leftNum);
            printf("do you really want to delete this book?(1.yes 2.no): ");
            int count=0;
            scanf("%d",&count);getchar();
            if(count>2||count<1)
            {
                printf("   input invalid data!   \n");
                return;
            }
            if(count==1)
            {
                if (pointer == NULL)
                    return;
                else
                {
                    jump = pointer->next;
                    if (jump == NULL)
                        return;
                    pointer->next = jump->next;
                    printf("    SUCCESS!  \n");
                    free(jump);
                }
            }
        }
        else
        {
            printf("    FAIL! input INVALIDE   \n");
            printf("    There are no book had %d serial number!   \n",choice);
        }
    }
    dispBook(head);
    return;
}
/*student could use this function, there are two ways:writer and name to query books,input the choice,
then input the book's corresponding information, system will find book for you
*/
void bookQuery(Book *head)
{
    queryMenu();
    int choice=0,flag=0;
    scanf("%d",&choice);getchar();
    if(choice>2||choice<1)
    {
        printf("   input invalid data!   \n");
        return;
    }
    Book *pointer;
    pointer=head;
    char name[200];
    if(choice==1)            //use book's name to query
    {
        printf("  Enter Name : ");
        gets(name);//puts(name);
        printf(" Serial Name Writer Total Left\n");
        while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            if(strcasecmp(pointer->nameB,name)==0)
            {
                printf("%d  %s  %s  %d  %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
                flag=1;
            }
        }
    }
    if(choice==2)              //use book's writer to query
    {
        printf("  Enter Writer : ");
        gets(name);//puts(name);
        printf(" Serial Name Writer Total Left\n");
        while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            if(strcasecmp(pointer->writer,name)==0)
            {
                printf("  %d  %s  %s  %d  %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
                flag=1;
            }
        }
    }
    if(flag==0)                 //check if the input information is correct
        printf(" Can't find book about %s  \n!", name);
    return;
}
