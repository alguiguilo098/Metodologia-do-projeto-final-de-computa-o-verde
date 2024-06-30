compile:
	gcc CPU.c matriz/matriz.c  -pthread -lm -o CPU
	gcc IO.c matriz/matriz.c -pthread -o IO
