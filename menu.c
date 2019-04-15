#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "book.h"
void menu(){
    printf("----------------\n");
    printf(" Library System \n");
    printf("----------------\n");
  //  printf("1.Reader entrance\n");
    printf("1.Administrator entrance\n\n");
    printf("2.Leave out\n\n");
    printf("Your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        printf("2\n");
        readFile();
        //readFile(head);
    if(choice==2)
        printf("3");
    return;
}
