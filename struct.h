#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
//#define N sizeof(struct book)

struct regist{
    char numberR[10];
    char nameR[20];
    char bookBorrow[20];
    char bookReturn[20];
    struct regist *next;
};
typedef struct regist Read;
struct book{
    char numberB[10];
    char nameB[20];
    char writer[20];
    struct book *next;
};
typedef struct book Book;
typedef Book *book;

#endif // STRUCT_H_INCLUDED
