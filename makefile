EXEDIR = .
EXE = $(EXEDIR)/sorts
SRC= sorts.c bubble.c quick.c insertion.c print.c
CC= cc
COPT= -O
CFLAGS=
OBJ= $(SRC:.c=.o)
.c.o:
				$(CC) $(COPT) -c -o $@ $<
$(EXE): $(OBJ)
				$(CC) $(OBJ) $(CFLAGS) -o $(EXE)
clean:
				rm -f $(OBJ) $(EXE)
sorts.o:  sorts.c
bubble.o: bubble.c bubble.h
quick.o:	quick.c quick.h
insertion.o: insertion.c insertion.h
print.o: print.c print.h
