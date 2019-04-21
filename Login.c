#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
int checkID(Student *Shead)
{
    Login();
   // int count=0,a=0;
    char ID[5],password [5];
    gets(ID);gets(password);
  //  puts(ID);puts(password);
    Student *pointer;
    pointer=Shead;
    while(pointer->next != NULL)
    {
        pointer=pointer->next;
        dispStudent(pointer);
        if(strcmpi(pointer->numberR,ID)==0&&strcmpi(pointer->nameR,password)==0)
        {
            printf("    SUCCESS!   \n");
            return 1;

        }
    }
    printf("    FAIL!   ");
    return 0;
}
int checkStaff()
{
    LoginStaff();
    char ID[10],password [10];
    gets(ID);
    gets(password);
    char staff[10]="00000";
    char pass[10]="11111";
    if(strcmpi(ID,staff)==0&&strcmpi(password,pass)==0)
        {
            printf("    SUCCESS!   \n");
            return 1;
        }
    printf("    FAIL!   \n");
    return 0;
}

void regist(Student *Shead)
{
    newRegist();
    Student *pointer;
    pointer=Shead;
    dispStudent(Shead);
    while(pointer->next!=NULL)
        {
            pointer=pointer->next;
        }
    Student *temp;
    temp = (Student*)malloc(sizeof(Student));
    scanf("%s %s",temp->numberR,temp->nameR);getchar();
    pointer->next=temp;
    pointer=temp;
    dispStudent(Shead);
    printf("      SUCCESS !     ");
    return;
}
