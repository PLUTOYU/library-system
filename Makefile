
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/LibraryNew

SRC= book.c login.c menu.c readFile.c studentBook.c main.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c struct.h
studentBook.o: studentBook.c struct.h login.h book.h readFile.h
readFile.o: readFile.c struct.h readFile.h menu.h 
menu.o: menu.c struct.h login.h book.h readFile.h
login.o:login.c struct.h menu.h readFile.h
book.o:book.c struct.h readFile.h

