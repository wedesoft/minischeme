factor: factor.o
	gcc -o $@ $<

.c.o:
	gcc -c -o $@ $<
