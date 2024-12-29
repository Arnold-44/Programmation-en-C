article: main.o article.o
	gcc -o main main.o article.o
article.o: article.c article.h
	gcc -c article.c
main.o: main.c article.h
	gcc -c main.c	
clean:
	rm -f *.o

