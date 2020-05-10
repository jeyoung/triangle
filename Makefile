CC = gcc

.PHONY:
all: triangle

run: triangle
	./$<

triangle.o: triangle.c
	$(CC) -o $@ -c $<

triangle: triangle.o
	$(CC) -o $@ $<

clean: triangle.*
	find . -name triangle.o -exec rm {} + -or -name triangle -exec rm {} +
