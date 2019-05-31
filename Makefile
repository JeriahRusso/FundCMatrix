all:
	gcc -Wall -Werror -ansi -o matrix.o colourfulmatrix.c accounts.c ColourMatrix.c -lm
