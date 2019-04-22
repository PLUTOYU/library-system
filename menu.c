#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "login.h"
#include "book.h"
#include "readFile.h"
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
    printf("  |    1.Reader entrance           |    \n\n");
    printf("  |    2.Administrator entrance    |    \n\n");
    printf("  |    3.new register              |    \n\n");
    printf("  |    4.Leave out                 |    \n\n\n");
    printf("   Your choice: ");
    int choice=0,ID=0;
    scanf("%d",&choice);
    getchar();

    switch(choice)
		{
			case 1:
			    ID=checkID(Shead);
			    if(ID!=0)
                    subMenu1(Bhead,Shead,ID);
                else
                    menu(Bhead,Shead);
			    break;
            case 2:
                if(checkStaff()==1)
                    subMenu2(Bhead,Shead);
                else
                    menu(Bhead,Shead);
                break;
            case 3:
                ID=regist(Shead);
                if(ID!=0)
                    subMenu1(Bhead,Shead,ID);
                else
                    menu(Bhead,Shead);
                break;
            case 4:
               // writeFileB(Bhead);
                writeFileS(Shead);
            default:
               // writeFile(Bhead);
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
                bookBorrow(Bhead,Shead,ID);
                subMenu1(Bhead,Shead,ID);
			    break;
            case 2:
                bookReturn(Bhead,Shead,ID);
                break;
            case 3:
                bookQuery(Bhead);
                subMenu1(Bhead,Shead,ID);
                break;
            case 4:
                dispBook(Bhead);
                subMenu1(Bhead,Shead,ID);
                break;
            case 5:
                menu(Bhead,Shead);
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
                subMenu2(Bhead,Shead);
			    break;
            case 2:
                deleBook(Bhead);
                subMenu2(Bhead,Shead);
                break;
            case 3:
                dispStudent(Shead);
                subMenu2(Bhead,Shead);
                break;
            case 4:
                dispBook(Bhead);
                subMenu2(Bhead,Shead);
                break;
            case 5:
                menu(Bhead,Shead);
                break;
            default:
                menu(Bhead,Shead);
                break;
		}
    return;
}

void Login()
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Student ID(5 integers) and Password(5 word):   \n");
    printf("   --------------------------------     \n");
    printf("   ");
}
void LoginStaff()
{
    printf("   --------------------------------     \n");
    printf("           Login in                     \n");
    printf("   --------------------------------     \n");
    printf("   Staff ID(5 integers) and password(5 word):   \n");
    printf("   --------------------------------     \n");
    printf("   ");
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
    printf("   Enter book's message (1.name|2.writer):   \n");

}
