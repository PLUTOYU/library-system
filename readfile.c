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
                fread(p,sizeof(struct book),1,fp);     //��fp��ָ����ļ��е����ݸ���p
                if(n==1){
	                head=p;
	              //  p2=p;
	             }
	             else{       //��������
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
Book *p=head->next;//����һ�����ָ��pָ��ͷ������һ�����
while(p){ //���p��Ϊ����ѭ��
printf("%d",head);
p=p->next;//�ƶ�ָ��p��������
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
            for( int n=0;n<strlen(oneBook);n++){  //--->�ڱ���һ�齫ÿ��ֵ����ͬһ�׼���Ӧ��ֵ
                if(oneBook[n]==','&&king%3==1){

                }
            }          */

       // fgets(oneBook,sizeof(oneBook),fp);
