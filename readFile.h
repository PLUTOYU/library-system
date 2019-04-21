#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED
extern void readFile(Book *Bhead,Student *Shead);
extern int writeBook(FILE *fp,Book *head);
extern int writeStudent(FILE *fp,Student *head);
extern void dispBook(Book *head);
extern void dispStudent(Student *head);
#endif // READFILE_H_INCLUDED
