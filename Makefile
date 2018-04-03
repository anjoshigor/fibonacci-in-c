all: build run clean

build: main.c list.c bigInt.c fibo.c
	gcc *.c -o calc 

run:
	./calc

clean:
	rm calc