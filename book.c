#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
#include "Login.h"
#include "readFile.h"
#include "book.h"
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
    printf("Input book's name and writer:  \n");
    for(int i=0; i<num; i++)
        {
            Book *temp;
            temp = (Book*)malloc(sizeof(Book));
            scanf("%s %s",temp->nameB,temp->writer);
            sprintf(temp->numberB, "%d", flag);
            temp->next=pointer->next;
            pointer->next=temp;
            pointer=pointer->next;
            flag++;
            printf("%d\n",flag);
        }
    return;
}
void deleBook(Book *head)
{
    char num[20];
    char writer[20];
    printf("which books do you want to delete(please input the book and the writer^_^):");
    gets(num);
    puts(num);
    struct book *pointer,*jump,*jump2;
    int flag=0;
    pointer=head;
    while(strcmpi(pointer->next->numberB,num)!=0&&strcmpi(pointer->next->nameB,num)!=0&&strcmpi(pointer->next->writer,num)!=0&& pointer != NULL)
        {
            pointer=pointer->next;
            flag++;
            printf("%d\n",flag);
        }
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
            pointer=pointer->next;
            sprintf(pointer->numberB, "%d", flag);
            flag++;
        }
       dispBook(head);
       free(jump);
       return 1;
      }
}
void bookQuery(Book *head)
{
    queryMenu();
    char name[20];
    gets(name);puts(name);
    Book *pointer;
    pointer=head;
    while(pointer->next!=NULL)
        {
            pointer=pointer->next;
            if(strcmpi(pointer->nameB,name)==0)
                {
                    printf("Book number, Book name, Book writer \n");
                    printf("%s %s %s",pointer->numberB,pointer->nameB,pointer->writer);
                    return 1;
                }
        }
    printf(" Can't find %s book !", name);
    return 0;
}


