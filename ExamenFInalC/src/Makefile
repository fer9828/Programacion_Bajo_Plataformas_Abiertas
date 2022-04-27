CC=gcc
CFLAGS=-I../include #Busca en el directorio 'include' los archivos de implementacion 

all:Polinomios

Polinomios: main.o 
	$(CC) main.o -o Polinomios $(CFLAGS)
	mv Polinomios ../build 

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
