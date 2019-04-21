#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "menu.h"
#include "Login.h"
#include "readFile.h"
#include "book.h"
void start()
{
    int choice=0,flag=1;
    printf("  Library system start(1.yes 2.no):  ");
    scanf("%d",&choice);getchar();
    if(choice==1)
        {
            Book *Bhead;
            Bhead = (Book*)malloc(sizeof(Book));
            Student *Shead;
            Shead = (Student*)malloc(sizeof(Student));
            readFile(Bhead,Shead);
            menu(Bhead,Shead);
        }

    return;
}
void menu(Book *Bhead,Student *Shead)
{
    printf("   --------------------------------     \n");
    printf("           Library System               \n");
    printf("   --------------------------------     \n");
    printf("  |    1.readers entrance          |    \n\n");
    printf("  |    2.Administrator entrance    |    \n\n");
    printf("  |    3.new register              |    \n\n");
    printf("  |    4.Leave out                 |    \n\n\n");
    printf("   Your choice: ");
    int choice;
    scanf("%d",&choice);
    getchar();

    switch(choice)
		{
			case 1:
			    if(checkID(Shead)==1)
                    subMenu1(Bhead,Shead);
			    break;
            case 2:
                if(checkStaff()==1)
                    subMenu2(Bhead,Shead);
                break;
            case 3:
                regist(Shead);
                break;
            default:
                break;
		}
    return;
}
void Login()
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Student ID(5 integers):   \n");
    printf("   --------------------------------     \n");
    printf("   password(5 word):      \n");
}
void LoginStaff()
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Staff ID(5 integers):   \n");
    printf("   --------------------------------     \n");
    printf("   password(5 word):      \n");
}
void newRegist()
{
    printf("   --------------------------------     \n");
    printf("          new register                  \n");
    printf("   --------------------------------     \n");
    printf("   new student ID(5 integers):   \n");
    printf("   --------------------------------     \n");
    printf("   new user name(5 integers):    \n");
    printf("   --------------------------------     \n");
    printf("   new password(5 word):         \n");
}
void queryMenu()
{
    printf("   --------------------------------     \n");
    printf("          Query Books                   \n");
    printf("   --------------------------------     \n");
    printf("   Enter book's name:   \n");

}
void subMenu1(Book *Bhead,Student *Shead)
{
    printf("   --------------------------------     \n");
    printf("           Welcome Library !            \n");
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

			    break;
            case 2:
                break;
            case 3:
                bookQuery(Bhead);
                break;
            case 4:
                dispBook(Bhead);
                break;
            case 5:
                break;
            default:
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
                addBook(Bhead);
			    break;
            case 2:
                deleBook(Bhead);
                break;
            case 3:
                dispStudent(Shead);
                break;
            case 4:
                dispBook(Bhead);
                break;
            case 5:
                break;
            default:
                break;
		}
    return;
}
