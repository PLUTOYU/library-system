#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "struct.h"
#include "book.h"
void readFile(Book *head){
    FILE *fp;
    fp=fopen("book.txt","r");//open the file
    if(fp==NULL){
		printf("cannot open file\n");
	}
    writeBook(fp,head);
    fclose(fp);
    return;
}
void writeBook(FILE *fp,Book *head){
    int n=0;
    head=NULL;
    Book *p;
	//Book p2,p,pr=NULL;
   // if(head->next == NULL){
        while(!feof(fp)){
                n++;
                p=(book)malloc(sizeof(struct book));
                fread(p,sizeof(struct book),1,fp);     //将fp所指向的文件中的内容赋给p
                if(n==1){
	                head=p;
	              //  p2=p;
	             }
	             else{       //创建链表
                  //  pr=p2;
	    	        head->next=p;
	           	  //  p2=p;
	             }
          }
          dispBook(head);
 //   }
 //   else{
  //      writeBook( fp,head->next );
  //  }
   /* if(pr!=NULL)
        pr->next=NULL;
    else
        head=NULL;*/
    return *head;
}
void dispBook(Book *head)
{
Book *p=head->next;//定义一个结点指针p指向头结点的下一个结点
while(p){ //如果p不为空则循环
printf("%d",head);
p=p->next;//移动指针p遍历链表
}
}
    /*for (int n=0;!feof(fp);n++){
        char oneBook[1024];
        fgets(oneBook,sizeof(oneBook),fp);

    }*/
         /*   char *oneBook;
            oneBook=(char*)malloc(1024*sizeof(char));
            fgets(oneBook,sizeof(oneBook),fp);
            int kind=1;
            for( int n=0;n<strlen(oneBook);n++){  //--->在遍历一遍将每个值赋给同一阶级相应的值
                if(oneBook[n]==','&&king%3==1){

                }
            }          */

       // fgets(oneBook,sizeof(oneBook),fp);
