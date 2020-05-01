.SUFFIXES: .c .o .l

CC = gcc
FLEX = flex

OBJECTS = factor.o lexer.o

factor: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

.c.o:
	$(CC) -c $< -o $@

.l.c:
	$(FLEX) -o $@ $<

clean:
	rm -f factor lexer.c *.o
