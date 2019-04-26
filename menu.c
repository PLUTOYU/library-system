#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "login.h"
#include "book.h"
#include "readFile.h"
void start()      //start library system
{
    int choice=0,flag=1;
    printf("  Library system start(1.yes 2.no):  ");
    scanf("%d",&choice);getchar();
    if(choice>2||choice<1)
    {
        printf("   input invalid data!   ");
        return;
    }
    if(choice==1)
    {
        Book *Bhead;                                       //create the head node and malloc it
        Bhead = (Book*)malloc(sizeof(Book));
        Student *Shead;
        Shead = (Student*)malloc(sizeof(Student));
        readFile(Bhead,Shead);                           //read book.txt and student.txt file
        menu(Bhead,Shead);                               //output library's menu
    }
    return;
}
void menu(Book *Bhead,Student *Shead)
{
    printf("   --------------------------------     \n");
    printf("           Library System               \n");
    printf("   --------------------------------     \n");
    printf("  |    1.Reader entrance           |    \n\n");
    printf("  |    2.Administrator entrance    |    \n\n");
    printf("  |    3.new register              |    \n\n");
    printf("  |    4.Save and Leave out        |    \n\n");
    printf("  |    5.Don't Save and Leave out  |    \n\n\n");
    printf("   Your choice: ");
    int choice=0,ID=0;
    scanf("%d",&choice);
    getchar();

    switch(choice)
		{
			case 1:                                 // login first then reader entrance
			    ID=checkID(Shead);
			    if(ID!=0)
                    subMenu1(Bhead,Shead,ID);
                else
                    menu(Bhead,Shead);
			    break;
            case 2:                                  //login staff then administrator entrance
                if(checkStaff()==1)
                    subMenu2(Bhead,Shead);
                else
                    menu(Bhead,Shead);
                break;
            case 3:
                ID=regist(Shead);                    //login new student
                if(ID!=0)
                    subMenu1(Bhead,Shead,ID);
                else
                    menu(Bhead,Shead);
                break;
            case 4:
                writeFileB(Bhead);                    //free the linked list
                writeFileS(Shead);
                destroyB(Bhead);
                destroyS(Shead);
                free(Bhead);
                free(Shead);
                break;
            default:                                  //free the linked list
                destroyB(Bhead);
                destroyS(Shead);
                free(Bhead);
                free(Shead);
                break;
		}
    return;
}
void subMenu1(Book *Bhead,Student *Shead,int ID)
{
    printf("   --------------------------------     \n");
    printf("         Welcome %d Library !           \n",ID);
    printf("   --------------------------------     \n");
    printf("  |    1.Borrow books              |    \n\n");
    printf("  |    2.Return books              |    \n\n");
    printf("  |    3.Query books               |    \n\n");
    printf("  |    4.View library's books      |    \n\n");
    printf("  |    5.Leave out                 |    \n\n");
    printf("   Your choice: ");
    int choice;
    scanf("%d",&choice);
    getchar();
    switch(choice)
		{
			case 1:
                bookBorrow(Bhead,Shead,ID);                 //borrow books
                subMenu1(Bhead,Shead,ID);
			    break;
            case 2:
                bookReturn(Bhead,Shead,ID);                  //return books
                subMenu1(Bhead,Shead,ID);
                break;
            case 3:
                bookQuery(Bhead);                            //query books
                subMenu1(Bhead,Shead,ID);
                break;
            case 4:
                dispBook(Bhead);                              //view all the books
                subMenu1(Bhead,Shead,ID);
                break;
            case 5:
                menu(Bhead,Shead);                            //return the last menu
                break;
            default:
                menu(Bhead,Shead);
                break;
		}
    return;
}
void subMenu2(Book *Bhead,Student *Shead)
{
    printf("   --------------------------------     \n");
    printf("           Administrator                \n");
    printf("   --------------------------------     \n");
    printf("  |    1.Insert books              |    \n\n");
    printf("  |    2.delete books              |    \n\n");
    printf("  |    3.View library's registers  |    \n\n");
    printf("  |    4.View library's books      |    \n\n");
    printf("  |    5.Leave out                 |    \n\n");
    printf("   Your choice: ");
    int choice,flag=2;
    scanf("%d",&choice);
    getchar();
    switch(choice)
		{
			case 1:
                addBook(Bhead);                                  //add books
                subMenu2(Bhead,Shead);
			    break;
            case 2:
                deleBook(Bhead);                                 //delete books
                subMenu2(Bhead,Shead);
                break;
            case 3:
                dispStudent(Shead);                              //view all register information
                subMenu2(Bhead,Shead);
                break;
            case 4:
                dispBook(Bhead);                                 //view all register information
                subMenu2(Bhead,Shead);
                break;
            case 5:
                menu(Bhead,Shead);                                //return to the last menu
                break;
            default:
                menu(Bhead,Shead);
                break;
		}
    return;
}

void Login()                  //student login menu
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Student ID(5 integers) and Password(5 word):   \n");
    printf("   --------------------------------     \n");
    printf("   ");
}
void LoginStaff()                    //library staff menu
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Staff ID(5 integers) and password(5 word):   \n");
    printf("   --------------------------------     \n");
    printf("   ");
}
void newRegist()                     //new register menu
{
    printf("   --------------------------------     \n");
    printf("          new register                  \n");
    printf("   --------------------------------     \n");
    printf("   new student ID(5 INTERGEERS):        \n");
    printf("   --------------------------------     \n");
    printf("   new user name:                       \n");
    printf("   --------------------------------     \n");
    printf("   new password(more than 5 WORDS):     \n");
    printf("   --------------------------------     \n");
    printf("   ");
}
void queryMenu()
{
    printf("   --------------------------------     \n");
    printf("          Query Books                   \n");
    printf("   --------------------------------     \n");
    printf("   Enter book's message (1.name|2.writer):   \n");
    printf("   --------------------------------     \n");
    printf("   ");
}
