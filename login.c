#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
#include "readFile.h"
int checkID(Student *Shead)
{
    Login();
    int ID;
    char password [20];
    scanf("%d %s",&ID,&password);getchar();
    Student *pointer;
    pointer=Shead;
    while(pointer->next != NULL)
    {
        pointer=pointer->next;
        //dispStudent(pointer);
        if(pointer->stuID==ID&&strcmpi(pointer->passWord,password)==0)
        {
            printf("    SUCCESS!   \n");
            return ID;
        }
    }
    printf("    FAIL!   ");
    return 0;
}
int checkStaff()
{
    LoginStaff();
    int ID=11111,staff=22222;
    int tempID=0,tempStaff=0;
    scanf("%d %d",&tempID,&tempStaff);
    if(tempID==ID&&tempStaff==staff)
        {
            printf("    SUCCESS!   \n");
            return 1;
        }
    printf("    FAIL!   \n");
    return 0;
}
int regist(Student *Shead)
{
    newRegist();
    Student *pointer;
    pointer=Shead;
   // dispStudent(Shead);
    int a=0;
    //pointer=pointer->next;
    //char normal[10]=0;
    while(pointer->next!=NULL)
        {
            a++;
            printf("%d",a);
            pointer=pointer->next;
        }
    Student *temp;
    temp = (Student*)malloc(sizeof(Student));
    scanf("%d %s %s",&temp->stuID,temp->nameR,temp->passWord);getchar();
    sprintf(temp->reBorrow, "%d", 0);
    sprintf(temp->reReturn, "%d", 0);
    Student *scanner;
    scanner=Shead;
    int b=0;
    while(scanner->next!=NULL)
        {
            scanner=scanner->next;
            if(scanner->stuID==temp->stuID||strcmpi(scanner->nameR,temp->nameR)==0||strcmpi(scanner->passWord,temp->passWord)==0)
                {
                    printf("  FAIL!    ");
                    return 0;
                }
        }
    pointer->next=temp;
    pointer=temp;
   //dispStudent(Shead);
    printf("      SUCCESS !     ");
    return temp->stuID;
}

