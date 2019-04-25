#ifndef STUDENTBOOK_H_INCLUDED
#define STUDENTBOOK_H_INCLUDED
extern void bookBorrow(Book *Bhead,Student *Shead,int ID);
extern void motifyBorrow(char *a,char *b);
extern void bookReturn(Book *Bhead,Student *Shead,int ID);
extern void motifyReturn(char *a,char *b);
extern int checknumber(char *a);
extern int checkRepeat(char *a,char *b);
#endif // STUDENTBOOK_H_INCLUDED
