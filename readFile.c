#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "readFile.h"
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
    char tital[100];
    fgets( tital , sizeof(tital) , fp );
  //  printf("%s",tital);
    while(!feof(fp))
        {
            char str[sizeof(Book)];
            fgets( str , sizeof(Book) , fp );
            n++;
            node=(Book*)malloc(sizeof(Book));
            node->next=NULL;
            sscanf(str,"%d %s %s %d %d",&node->serialNum,node->nameB,node->writer,&node->totalNum,&node->leftNum);
            end->next=node;
            end = node;
        }
   // printf("%d",n);
    end->next=NULL;
   // dispBook(head);
    return n;
}
int writeStudent(FILE *fp,Student *head){
    Student *node,*end;
    end=head;
    char c;
    int n=0,i=0;
    char tital[100];
    fgets( tital , sizeof(Student) , fp );
    printf("%s",tital);

//    char seg[] = "/";
    while(!feof(fp))
        {
            char str[sizeof(Student)];
            fgets( str , sizeof(Student) , fp ) ;
            n++;
            node=(Student*)malloc(sizeof(Student));
            node->next=NULL;
            sscanf(str,"%d %s %s %s %s",&node->stuID,node->nameR,node->passWord,node->reBorrow,node->reReturn);
            end->next=node;
            end = node;
        }
   // printf("%d",n);
    end->next=NULL;
    dispStudent(head);
    return n;
}

void dispBook(Book *head)//(struct student *head)
{
    struct book* pointer;
    printf("  Serial Name Writer Total Left\n");
    pointer=head->next; //跳过无数据的头结点->next
    while(pointer!=NULL)
        {
        printf("  %d  %s  %s  %d  %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        pointer=pointer->next;//指向下一个节点
        }
    return;
}
void dispStudent(Student *head){
    struct regist* pointer;
    printf("  studentID userName Password  recordBorrow  recordReturn\n");
    pointer=head->next; //跳过无数据的头结点->next
    while(pointer!=NULL)
        {
        printf("  %d  %s  %s  %s  %s\n",pointer->stuID,pointer->nameR,pointer->passWord,pointer->reBorrow,pointer->reReturn);//,pointer->writer);
        pointer=pointer->next;//指向下一个节点
        }
    return;
}/*
Serial Name Writer Total Left
1 dog dogs 24 24
2 buk buks 30 30
3 wet wets 20 20
4 cats cats 20 20
5 temp temper 12 12*/
void writeFileB(Book *head)
{
    FILE *fp;
    fp=fopen("book.txt","w+");
    struct book* pointer;
    pointer=head->next; //跳过无数据的头结点
    fprintf(fp,"Serial Name Writer Total Left\n");
    do
        {
        fprintf(fp,"%d %s %s %d %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        pointer=pointer->next;//指向下一个节点
        }while(pointer!=NULL);
    fclose(fp);
    return;
}
/*studentID userName Password  recordBorrow  recordReturn
001 tony shui  /no  /no
002 kim wuie  /no  /no
003 Alice kuiy  /buk/wet  no/no
004 SHY shuij  /oop  /no*/
void writeFileS(Student *head)
{
    FILE *fp;
    fp=fopen("student.txt","w+");
    struct regist* pointer;
    pointer=head->next; //跳过无数据的头结点
    fprintf(fp,"studentID userName Password  recordBorrow  recordReturn\n");
    do
        {
        fprintf(fp,"%d %s %s %s %s\n",pointer->stuID,pointer->nameR,pointer->passWord,pointer->reBorrow,pointer->reReturn);
     //   fprintf(fp,"%d %s %s %d %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        pointer=pointer->next;//指向下一个节点
        }while(pointer!=NULL);
    fclose(fp);
    return;
}
 /*   Student *node,*end;
    end=head;
    char c;
    int n=0,i=0;
    char tital[100];
    fgets( tital , sizeof(Student) , fp );
    printf("%s",tital);
    while(!feof(fp))
        {
            char str[sizeof(Student)];
            fgets( str , sizeof(Student) , fp ) ;
            n++;
            node=(Student*)malloc(sizeof(Student));
            node->next=NULL;
            sscanf(str,"%d %s %s %s %s",&node->stuID,node->nameR,node->passWord,node->reBorrow,node->reReturn);
            end->next=node;
            end = node;
        }
    printf("%d",n);
    end->next=NULL;
    dispStudent(head);
    return n;*/
