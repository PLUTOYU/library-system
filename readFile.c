#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "readFile.h"
#include "menu.h"
/*create two pointers to read file's data
*/
int readFile(Book *Bhead,Student *Shead)
{
        FILE *fp1,*fp2;
        fp1=fopen("book.txt","r+");
        if(fp1==NULL)
            printf("cannot open book's file\n");
        int numB=writeBook(fp1,Bhead);
        fp2=fopen("student.txt","r+");
        if(fp2==NULL)
            printf("cannot open register's file\n");
        int numR=writeStudent(fp2,Shead);
        fclose(fp1);
        fclose(fp2);
        return 0;
}
/*create book's linked list to stored the book's information for system using
*/
int writeBook(FILE *fp,Book *head){
    Book *node,*end;
    end=head;
    int n=0;
    char tital[100];
    fgets( tital , sizeof(tital) , fp );
    while(!feof(fp))
        {
            char str[sizeof(Book)];
            fgets( str , sizeof(Book) , fp );
            n++;
            node=(Book*)malloc(sizeof(Book));
            node->next=NULL;
            sscanf(str,"%d|%[0-9A-Za-z.,:?!-' ]|%[0-9A-Za-z., ]|%d|%d",&node->serialNum,node->nameB,node->writer,&node->totalNum,&node->leftNum);
            end->next=node;
            end = node;
        }
    end->next=NULL;
   // dispBook(head);
    return n;
}
/*create student's linked list to store student's information for system using
*/
int writeStudent(FILE *fp,Student *head){
    Student *node,*end;
    end=head;
    char c;
    int n=0,i=0;
    char tital[100];
    fgets( tital , sizeof(Student) , fp );
    while(!feof(fp))
        {
            char str[sizeof(Student)];
            fgets( str , sizeof(Student) , fp ) ;
            n++;
            node=(Student*)malloc(sizeof(Student));
            node->next=NULL;
            sscanf(str,"%d|%[0-9A-Za-z.,:?!-'/ ]|%[0-9A-Za-z.,:?!/-' ]|%[0-9A-Za-z.,:?!/-' ]|%[0-9A-Za-z.,:?!/-' ]",&node->stuID,node->nameR,node->passWord,node->reBorrow,node->reReturn);
            end->next=node;
            end = node;
        }
    end->next=NULL;
   // dispStudent(head);
    return n;
}
/*display book's linked list information, for student and library staff view
*/
void dispBook(Book *head)
{
    struct book* pointer;
    printf("  Serial Name Writer Total Left\n");
    pointer=head->next;
    while(pointer!=NULL)
    {
        printf("  %d | %s | %s | %d | %d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        pointer=pointer->next;
    }
    return;
}
/*display student's linked list information, for library staff view
*/
void dispStudent(Student *head){
    struct regist* pointer;
    printf("  studentID userName Password  recordBorrow  recordReturn\n");
    pointer=head->next;
    while(pointer!=NULL)
    {
        printf("  %d | %s | %s | %s | %s \n",pointer->stuID,pointer->nameR,pointer->passWord,pointer->reBorrow,pointer->reReturn);//,pointer->writer);
        pointer=pointer->next;
    }
    return;
}
/*create book pointer to read book.txt again, rewrite the file's content
*/
void writeFileB(Book *head)
{
    FILE *fp;
    fp=fopen("book.txt","w+");
    struct book* pointer;
    pointer=head->next;//skip the head node
    fprintf(fp,"Serial Name Writer Total Left\n");
    while(pointer!=NULL)
    {
        if(pointer->next==NULL)
            fprintf(fp,"%d|%s|%s|%d|%d",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        if(pointer->next!=NULL)
            fprintf(fp,"%d|%s|%s|%d|%d\n",pointer->serialNum,pointer->nameB,pointer->writer,pointer->totalNum,pointer->leftNum);
        pointer=pointer->next;
    }
    fclose(fp);
    //destroy(head);
    return;
}
/*create student pointer to read book.txt again, rewrite the file's content
*/
void writeFileS(Student *head)
{
    FILE *fp;
    fp=fopen("student.txt","w+");
    struct regist* pointer;
    pointer=head->next; //skip the head node
    fprintf(fp,"studentID userName Password  recordBorrow  recordReturn\n");
    while(pointer!=NULL)
    {
        if(pointer->next!=NULL)
            fprintf(fp,"%d|%s|%s|%s|%s\n",pointer->stuID,pointer->nameR,pointer->passWord,pointer->reBorrow,pointer->reReturn);
        if(pointer->next==NULL)
            fprintf(fp,"%d|%s|%s|%s|%s",pointer->stuID,pointer->nameR,pointer->passWord,pointer->reBorrow,pointer->reReturn);
        pointer=pointer->next;
    }

    fclose(fp);
   // destroy(head);
    return;
}
//free the book's linked list
void destroyB(Book *head){
    if(head->next==NULL){
         return;
    }
    if(head->next!=NULL)
    {
        destroyB(head->next);
        free(head->next);
        head->next=NULL;
        return;
    }
}
//free the student's linked list
void destroyS(Student *head){
    if(head->next==NULL){
       return;
    }
    if(head->next!=NULL)
    {
        destroyS(head->next);
        free(head->next);
        head->next=NULL;
        return;
    }
}
