#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct regist{
    int stuID;
    char nameR[20];
    char passWord[20];
    char reBorrow[100];
    char reReturn[100];
    struct regist *next;
}Student;
typedef struct book{
    int serialNum;
    char nameB[20];
    char writer[20];
    int totalNum,leftNum;
    struct book *next;
}Book;
#endif // STRUCT_H_INCLUDED
