#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct regist{
    int stuID;
    char nameR[20];
    char passWord[20];
    char reBorrow[300];
    char reReturn[300];
    struct regist *next;
}Student;
typedef struct book{
    int serialNum;
    char nameB[100];
    char writer[50];
    int totalNum,leftNum;
    struct book *next;
}Book;
#endif // STRUCT_H_INCLUDED
