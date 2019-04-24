all: exe

operacoes.o: operacoes.c
	gcc -c operacoes.c

lista.o: lista.c
	gcc -c lista.c

main.o: main.c
	gcc -c main.c

exe: main.o lista.o operacoes.o
	gcc -o exe.x main.o lista.o operacoes.o

clean:
	rm -f *.x *.o
