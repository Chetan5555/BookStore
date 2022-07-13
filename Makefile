all: lin-bookstore-x64

lin-bookstore-x64: main.o book.o bookstore.o
	g++ main.o book.o bookstore.o -o lin-bookstore-x64

main.o: main.cpp
	g++ -c main.cpp -o main.o

book.o: Book.cpp Book.h
	g++ -c Book.cpp -o book.o

bookstore.o: Bookstore.cpp Bookstore.h
	g++ -c Bookstore.cpp -o bookstore.o

clean:
	rm -rf *o lin-bookstore-x64