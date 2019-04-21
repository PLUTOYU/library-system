#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct regist{
    char numberR[20];
    char nameR[20];
    char password[20];
    char bookBorrow[20];
    char bookReturn[20];
    struct regist *next;
}Student;
typedef struct book{
    char numberB[20];
    char nameB[20];
    char writer[20];
    struct book *next;
}Book;
#endif // STRUCT_H_INCLUDED
