#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "book.h"
#include "addData.h"
void readFile(){
    FILE *fp1,*fp2;
    fp1=fopen("book.txt","r+");//open the file
  //  fp2=fopen("student.txt","r+");
    if(fp1==NULL){
		printf("cannot open file\n");
	}
  /*  if(fp2==NULL){
		printf("cannot open file\n");
	}*/
	Book *Bhead;
//	Student *Shead;
	Bhead = (Book*)malloc(sizeof(Book));
	                             //head=NULL;
//	Shead = (Student*)malloc(sizeof(Student));
    int count=writeBook(fp1,Bhead);
  //  addbook(count,fp1);
  //  writeStudent(fp2,Shead);
   deleBook(Bhead);
   writeFile(Bhead);
  //  regist(fp2);
    dispBook(Bhead);
  //  dispStudent(Shead);
    fclose(fp1);
   // fclose(fp2);
    return;
}
int writeBook(FILE *fp,Book *head){
    //printf("111");
    Book *node,*end;//*head,
  //  head = (Book*)malloc(sizeof(Book));
    //head = node;
    end=head;
    //end->next = NULL;
    int n=0;
    struct book temp;
    //lseek(fp,0,SEEK_SET);
    //int num=0;
    while(fscanf(fp,"%s%s%s",temp.numberB,temp.nameB,temp.writer)!=EOF){//!feof(fp)
        //    printf("%s",fp);
        //   printf("111");
         // struct book temp;
          n++;
          node = (Book*)malloc(sizeof(Book));
        //  fscanf(fp,"%s%s%s",temp.numberB,temp.nameB,temp.writer);
           // fread(node,sizeof(struct book),1,fp);     //将fp所指向的文件中的内容赋给p

         //  printf("%s%s%s\n",temp.numberB,temp.nameB,temp.writer);
        //  printf("%s%s%s\n",node->numberB,node->nameB,node->writer);
          strcpy(node->numberB,temp.numberB);
           strcpy(node->nameB,temp.nameB);
           strcpy(node->writer,temp.writer);

           printf("%d\n",n);

           end->next=node;
           end = node;

    }
    end->next=NULL;

   // dispBook(head);
    return n; //head;// head;
}
/*void deleBook(Book *head){
    char num;
    printf("which books do you want to delete:");
    scanf("%s",&num);
    struct book *pointer,*jump;
    pointer=head->next; //跳过无数据的头结点
    while(1)
        {
        if(pointer->numberB==num||pointer->nameB==num||pointer->writer==num){
            jump=pointer->next;
            pointer=*jump;
            break;
        }
      // printf("%s %s %s\n",pointer->numberB,pointer->nameB,pointer->writer);
        pointer=pointer->next;//指向下一个节点
        }
    dispBook(pointer);
    return;// pointer;
}*/
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

void writeStudent(FILE *fp,Student *head){
       Student *node,*end;//*head,
  //  head = (Book*)malloc(sizeof(Book));
    //head = node;
    struct regist temp;
    end=head;
    //end->next = NULL;
    int n=0;
    //lseek(fp,0,SEEK_SET);
    //int num=0;
    while(fscanf(fp,"%s%s",temp.numberR,temp.nameR)!=EOF){//!feof(fp)
        //    printf("%s",fp);
        //   printf("111");

          n++;
          node = (Student*)malloc(sizeof(Student));
          //fscanf(fp,"%s%s",temp.numberR,temp.nameR);//,temp.writer);
           // fread(node,sizeof(struct book),1,fp);     //将fp所指向的文件中的内容赋给p
        //  printf("%d",n);
          strcpy(node->numberR,temp.numberR);
           strcpy(node->nameR,temp.nameR);
        //   strcpy(node->writer,temp.writer);
         // printf("%s %s\n",node->numberR,node->nameR);//,node->writer


           end->next=node;
           end = node;

    }
    end->next=NULL;

   // dispBook(head);
    return; //head;// head;
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




