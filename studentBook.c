#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "login.h"
#include "book.h"
#include "readFile.h"
void bookBorrow(Book *Bhead,Student *Shead,int ID)
{
    char name[20],writer[20];
    printf("   ENTER book's name: ");
    scanf("%s",&name);getchar();
    printf("   ENTER book's writer: ");
    gets(writer);puts(writer);
    Student *pointerS;
    pointerS=Shead;
    while(pointerS->next!=NULL)
    {
        pointerS=pointerS->next;
        if(pointerS->stuID==ID)
            break;
    }

    Book *pointerB;
    pointerB=Bhead;
    while(pointerB->next!=NULL)
    {
        pointerB=pointerB->next;
        if(strcmpi(pointerB->nameB,name)==0&&strcmpi(pointerB->writer,writer)==0)
        {
            int choice1=0;
            printf("%d  %s  %s  %d  %d\n",pointerB->serialNum,pointerB->nameB,pointerB->writer,pointerB->totalNum,pointerB->leftNum);
            printf("  There are %d books to borrow.\n",pointerB->leftNum);
            if(pointerB->leftNum>0)
            {
                printf("  SURE BORROW?(1.yes|2.no)\n");
                scanf("%d",&choice1);
                if(choice1==1)
                {
                    char no[]="no";
                    pointerB->leftNum=pointerB->leftNum-1;
                    //char *new[100];
                    motifyBorrow(pointerS->reBorrow,name);
                    motifyBorrow(pointerS->reReturn,no);
                    printf("%s",pointerS->reBorrow);
                    dispBook(Bhead);
                    dispStudent(Shead);
                    printf("    SUCCESS  !");
                }
            }


        }
    }
    return;
}
void bookReturn(Book *Bhead,Student *Shead,int ID)
{
    char name[20],writer[20];
    printf("   ENTER book's name: ");
    scanf("%s",&name);getchar();
    printf("   ENTER book's writer: ");
    gets(writer);puts(writer);
    Student *pointerS;
    pointerS=Shead;
    while(pointerS->next!=NULL)
    {
        pointerS=pointerS->next;
        if(pointerS->stuID==ID)
            break;
    }

    Book *pointerB;
    pointerB=Bhead;
    while(pointerB->next!=NULL)
    {
        pointerB=pointerB->next;
        if(strcmpi(pointerB->nameB,name)==0&&strcmpi(pointerB->writer,writer)==0)
        {
            int choice1=0;
            printf("%d  %s  %s  %d  %d\n",pointerB->serialNum,pointerB->nameB,pointerB->writer,pointerB->totalNum,pointerB->leftNum);
                printf("  SURE RETURN?(1.yes|2.no)\n");
                scanf("%d",&choice1);
                if(choice1==1)
                {
                    char no[]="no";
                    pointerB->leftNum=pointerB->leftNum+1;
                    motifyReturn(pointerS->reBorrow,name);
                    motifyReturn(pointerS->reReturn,no);
                    dispStudent(Shead);
                    printf("    SUCCESS  !");
                }
        }
    }
    return;
}
void motifyReturn(char *a,char *b)
{
    int n=strlen(a),m=strlen(b);
    printf("%d %d\n",n,m);
    int flag=0,i=0;
    for(i;i<n;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
            if(a[i+j]==b[j])
                count++;
        }
        if(count==m)
        {
            flag=m;
            break;
        }
    }
    if(flag==m)
    {   char c[n-m];
        for(int k=0;k<n-m;k++)
        {
            if(k>=i-1)
                c[k]=a[k+m+1];
            else
                c[k]=a[k];
        }
        printf("%s\n",c);
        strcpy(a,c);
    }
    return;
}
void motifyBorrow(char *a,char *b)
{
    char del='/';
    int m=strlen(a)+strlen(b),q=strlen(a),p=strlen(b);
    printf("%s %s",a,b);
    printf("%d %d",q,p);
    char c[m+2];
    for(int i=0;i<m+2;i++)
    {
        if(i<q)
            c[i]=a[i];
        if(i==q)
            c[i]=del;
        if(i>q)
            c[i]=b[i-q-1];
        printf("%c\n",c[i]);
    }
    printf("%s\n",c);
    int count=0;
    for(int i=0;i<m+1;i++)
    {
        if(c[i]==del)
            count++;
    }
    if(count<5)
    {
        printf("%d",count);
        strcpy(a,c);
    }
    else
        printf(" 5 books enough, can't borrow book anymore! ");
    return;
}



