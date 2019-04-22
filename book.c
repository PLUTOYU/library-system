#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "readFile.h"
void addBook(Book *Bhead)
{
    int flag=0,num=0;
    Book *pointer;
    pointer=Bhead;
    while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            flag++;
        }
    printf("%d",flag);
    dispBook(Bhead);
    printf("what number books do you want to store:\n");
	scanf("%d",&num);getchar();
    printf("Input book's name|writer|total number|left number:  \n");
    for(int i=0; i<num; i++)
    {
        int a=0;                              //加入结构体数组，判断输入的书是否会重叠
        Book *temp;
        temp = (Book*)malloc(sizeof(Book));
        scanf("%s %s %d %d",temp->nameB,temp->writer,&temp->totalNum,&temp->leftNum);getchar();
        Book *check;
        check=Bhead;
        while(check->next!=NULL)
        {
            check=check->next;
            if(strcmpi(check->nameB,temp->nameB)==0&&strcmpi(check->writer,temp->writer)==0)
               {
                   printf("   FAIL !   \n");
                   printf("  the book |%s|%s| has already been stored in the library! \n",temp->nameB,temp->writer);
                   //a=1;
               }
        }
        printf("    SAVE or NOT SAVE(1.yes|2.no): ");
        scanf("%d",&a);getchar();
        if(a==1)
        {
            flag++;
            printf("    SUCCESS !   \n");
            temp->serialNum=flag;
            temp->next=pointer->next;
            pointer->next=temp;
            pointer=pointer->next;
        }
    }
    dispBook(Bhead);
    return;
}
void deleBook(Book *head)
{
    char num[20];
    char writer[20];
    int choice=0;
    printf("Find books do you want to delete(input 1.name|2.writer):");
    scanf("%d",&choice);getchar();
    struct book *pointer,*jump,*jump2;
    int flag=0;
    pointer=head;
    if(choice==1)
    {
        printf("Enter the book's name:");
        gets(num);
        puts(num);
        while(strcmpi(pointer->next->nameB,num)!=0&& pointer != NULL)
        {
            pointer=pointer->next;
            flag++;
            printf("%d\n",flag);//让程序真正输入书名
        }
    }
    if(choice==2)
    {
        printf("Enter the book's writer:");
        gets(num);
        puts(num);
        while(strcmpi(pointer->next->writer,num)!=0&& pointer != NULL)
        {
            pointer=pointer->next;
            flag++;
            printf("%d\n",flag);//让程序真正输入作者
        }
    }
    printf("  %d  %s  %s  %d  %d\n",pointer->next->serialNum,pointer->next->nameB,pointer->next->writer,pointer->next->totalNum,pointer->next->leftNum);
    printf("do you really want to delete this book?(1.yes 2.no): ");
    int count=0;
    scanf("%d",&count);getchar();
    if(count==1)
    {
        if (pointer == NULL)
		    return 0;
        else
        {
            jump = pointer->next;
		    if (jump == NULL)
               return 0;
	     	pointer->next = jump->next;
            while(pointer->next!=NULL)
            {
                flag++;
                pointer=pointer->next;
                pointer->serialNum=flag;
             }
            printf("    SUCCESS!  \n");
            dispBook(head);
            free(jump);
            return 1;
        }
    }
    printf("    FAIL!   \n");
    return 0;
}
void bookQuery(Book *head)
{
    queryMenu();
    int choice=0,flag=0;
    scanf("%d",&choice);getchar();
    Book *pointer;
    pointer=head;
    char name[20];
    if(choice==1)
    {
        printf("  Enter Name : ");
        gets(name);puts(name);
        printf(" Serial Name Writer Total Left\n");
        while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            if(strcmpi(pointer->nameB,name)==0)
            {
                printf("%d  %s  %s  %d  %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
                flag=1;
            }

        }
    }
    if(choice==2)
    {
        printf("  Enter Writer : ");
        gets(name);puts(name);
        printf(" Serial Name Writer Total Left\n");
        while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            if(strcmpi(pointer->writer,name)==0)
            {
                printf("  %d  %s  %s  %d  %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
                flag=1;
            }
        }
    }
    if(flag==0)
        printf(" Can't find book about %s  \n!", name);
    return;
}
