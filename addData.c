#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "book.h"
#include "addData.h"
void addbook(int count,FILE *fp){
    /*FILE *fp;

    int n=0;
    while(!feof(fp)){
        n++;
    }*/
    int num=0;
   // printf("%d",count);
    fseek(fp,0,2);
    printf("what number books do you want to store:\n");
	scanf("%d",&num);
    printf("Input data:\n");
    for(int i=0; i<num; i++){
        struct book temp1;
      //  temp1.numberB=count;

        sprintf(temp1.numberB, "%d", count);
        scanf("%s %s", temp1.nameB, temp1.writer);
        fprintf(fp,"%s %s %s\n", temp1.numberB, temp1.nameB, temp1.writer);
        printf("%s%s%s\n",temp1.numberB,temp1.nameB,temp1.writer);
        count++;
    }
   // fclose(fp);
    return;
}
void regist(FILE *fp){
   // int num=0;
   // printf("%d",count);
    fseek(fp,0,2);
    struct regist temp1;
    printf("what's your student ID :\n");
	scanf("%s",temp1.numberR);
	printf("what's password do you want :\n");
	scanf("%s",temp1.nameR);

	fprintf(fp,"%s %s\n",temp1.numberR,temp1.nameR);
	printf("%s %s\n",temp1.numberR,temp1.nameR);
   /* printf("Input data:\n");
    for(int i=0; i<num; i++){
        struct book temp1;
      //  temp1.numberB=count;

        sprintf(temp1.numberB, "%d", count);
        scanf("%s %s", temp1.nameB, temp1.writer);
        fprintf(fp,"%s %s %s\n", temp1.numberB, temp1.nameB, temp1.writer);
        printf("%s%s%s\n",temp1.numberB,temp1.nameB,temp1.writer);
        count++;
    }*/
   // fclose(fp);
    return;
}
void deleBook(Book *head)
{
      void dispBook(Book *head);
    char num[20];
    char writer[20];
   // getchar();
    printf("which books do you want to delete(please input the book and the writer^_^):");
    gets(num);
    puts(num);
    struct book *pointer,*jump,*jump2;
    int n=0;
    pointer=head; //���������ݵ�ͷ���
    while(strcmpi(pointer->next->numberB,num)!=0&&strcmpi(pointer->next->nameB,num)!=0&&strcmpi(pointer->next->writer,num)!=0&& pointer != NULL){
        pointer=pointer->next;
   // n++;
   // printf("%d\n",n);
    }
      if (pointer == NULL)                  //����Ҵ��ˣ�������i�ڵ㣬˵��СΤ�� ��ѧ��������ʦ�̵ģ�
		return 0;
      else
	{
		jump = pointer->next;             //����ҵ������֣�������һ���߳����飬��������ǰ���С���ѵ����������ֺ��� ��С���ѵ��·�
		if (jump == NULL)
		{
          return 0;
		}

		pointer->next = jump->next;
		free(jump);
		dispBook(head);
		return 1;
	}
}
void writeFile(Book *head)
{
    FILE *fp;
    fp=fopen("book.txt","w+");
    struct book* pointer;
    pointer=head->next; //���������ݵ�ͷ���
    do
        {
     //  printf("%d\n",a);
       fprintf(fp,"%s %s %s\n",pointer->numberB,pointer->nameB,pointer->writer);
        pointer=pointer->next;//ָ����һ���ڵ�
        }while(pointer!=NULL);
    fclose(fp);
    return;
}
/*void deleStudent(){

}*/
