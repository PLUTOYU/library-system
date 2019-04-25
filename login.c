#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
#include "readFile.h"
/*student could input student ID and password to login the library,
tips:password need to distinguish uppercase and lower case
*/
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
        if(pointer->stuID==ID&&strcmp(pointer->passWord,password)==0)
        {
            printf("    SUCCESS!   \n");
            printf("      WELCOME %s !  \n",pointer->nameR);
            return ID;
        }
    }
    printf("    FAIL!   \n");
    return 0;
}
// check library staff input the correct initialized ID and password
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
/*used for new student, input the unique studentID and password need to longer 5,
input your correct information
*/
int regist(Student *Shead)
{
    newRegist();
    Student *temp;
    temp = (Student*)malloc(sizeof(Student));
    scanf("%d",&temp->stuID);getchar();
    printf("   ");
    gets(temp->nameR);
    printf("   ");
    gets(temp->passWord);
    if(strlen(temp->passWord)<5)          //check if password is less then 5 words
     {
         printf("     PLEASE input correct LENGTH PASSWORD!   \n");
         return 0;
     }
    if(temp->stuID<150000||temp->stuID>200000)         //check if student  ID is correct
     {
         printf("     PLEASE input correct ID!     \n");
         return 0;
     }
    char no[]="/no";
    strcpy(temp->reBorrow,no);
    strcpy(temp->reReturn,no);
    Student *scanner;
    scanner=Shead;
    int b=0;
    while(scanner->next!=NULL)
        {
            scanner=scanner->next;
            if(scanner->stuID==temp->stuID)              //check if input ID is repeated
                {
                    printf("  FAIL! %d repeated!    \n",temp->stuID);
                    return 0;
                }
        }
    Student *add;
    add=Shead;
    add=add->next;
        while(add->next!=NULL)                         //add the new register at the end of student linked list
        {
        if(add->stuID<temp->stuID&&temp->stuID<add->next->stuID)
        {
            temp->next=add->next;
            add->next=temp;
            break;
        }
        add=add->next;
        }
    if(add->next==NULL)
    {
            add->next=temp;
            add=temp;
            add->next=NULL;
    }
    printf("      SUCCESS !     \n");
    printf("      WELCOME %s !  \n",temp->nameR);
    int Q=temp->stuID;
    destroyS(temp);
    temp=NULL;
    return Q;
}
