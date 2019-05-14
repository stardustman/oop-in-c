oop-in-c : main.o shape.o circle.o rect.o
	cc -o oop-in-c main.o shape.o circle.o rect.o

main.o : main.c shape.h rect.h circle.h
	cc -c main.c
shape.o : shape.c shape.h
	cc -c shape.c
circle.o : circle.c circle.h
	cc -c circle.c
rect.o : rect.c circle.h
	cc -c rect.c
