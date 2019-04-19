#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
extern void addbook(int count,FILE *fp);
extern void regist(FILE *fp);
extern void deleBook(Book *head);
extern void writeFile(Book *head);
#endif // BOOK_H_INCLUDED
