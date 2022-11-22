CC = gcc
CCFLAGS = -O3
LDFLAGS = -lm

all: matmultc 

matmultc: main.o matrix_mul.o
	$(CC) -o $@ $^ $(LDFLAGS)
##$(CC) -o matmultc main.o matrix_mul.o $(LDFLAGS)     

matrix_mul.o: matrix_mul.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) matrix_mul.c

main.o: main.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) main.c

clean:
	rm *.o
