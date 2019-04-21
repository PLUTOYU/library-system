#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
int readFile(Book *Bhead,Student *Shead)
{
        FILE *fp1,*fp2;
        fp1=fopen("book.txt","r+");
        if(fp1==NULL)
        {
            printf("cannot open book's file\n");
        }
        int numB=writeBook(fp1,Bhead);
        fp2=fopen("student.txt","r+");
        if(fp2==NULL)
        {
            printf("cannot open register's file\n");
        }
        int numR=writeStudent(fp2,Shead);
        fclose(fp1);
        fclose(fp2);
        return 0;
}


int writeBook(FILE *fp,Book *head){
    Book *node,*end;
    end=head;
    int n=0;
    struct book temp;
    while(fscanf(fp,"%s%s%s",temp.numberB,temp.nameB,temp.writer)!=EOF)
        {
           n++;
           node = (Book*)malloc(sizeof(Book));
           strcpy(node->numberB,temp.numberB);
           strcpy(node->nameB,temp.nameB);
           strcpy(node->writer,temp.writer);
           end->next=node;
           end = node;
        }
    end->next=NULL;
    return n;
}
int writeStudent(FILE *fp,Student *head){
    Student *node,*end;
    struct regist temp;
    end=head;
    int n=0;
    while(fscanf(fp,"%s%s",temp.numberR,temp.nameR)!=EOF)
        {
           n++;
           node = (Student*)malloc(sizeof(Student));
           strcpy(node->numberR,temp.numberR);
           strcpy(node->nameR,temp.nameR);
           end->next=node;
           end = node;
         }
    end->next=NULL;
    return n;
}
void dispBook(Book *head)//(struct student *head)
{
    struct book* pointer;
    pointer=head->next; //跳过无数据的头结点
    while(pointer!=NULL)
        {
       printf("%s %s %s\n",pointer->numberB,pointer->nameB,pointer->writer);
        pointer=pointer->next;//指向下一个节点
        }
    return;
}
void dispStudent(Student *head){
    struct regist* pointer;
    pointer=head->next; //跳过无数据的头结点
    while(pointer!=NULL)
        {
       printf("%s %s\n",pointer->numberR,pointer->nameR);//,pointer->writer);
        pointer=pointer->next;//指向下一个节点
        }
    return;
}
