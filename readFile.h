#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED
extern int readFile(Book *Bhead,Student *Shead);
extern int writeBook(FILE *fp,Book *head);
extern int writeStudent(FILE *fp,Student *head);
extern void dispBook(Book *head);
extern void dispStudent(Student *head);
extern void writeFileB(Book *head);
extern void writeFileS(Student *head);
#endif // READFILE_H_INCLUDED
