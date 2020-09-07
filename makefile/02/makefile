#main:main.o impl.o
#	gcc main.o impl.o -o main
#	./main
#main.o:main.c main.h
#	gcc -c main.c
#impl.o:impl.c
#	gcc -c impl.c

#OBJ=main.o impl.o
#main:$(OBJ)
#	gcc $(OBJ) -o main
#	./main
#main.o:main.c main.h
#	gcc -c main.c
#impl.o:impl.c
#	gcc -c impl.c

main:main.o impl.o
	gcc main.o impl.o -o main
	./main
#main.o:main.c main.h
#	gcc -c main.c
#impl.o:impl.c
#	gcc -c impl.c

clean:
	rm *.o main
