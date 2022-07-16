all: lin-bookstore-x64

lin-bookstore-x64: main.o bookstore.a
	g++ main.o bookstore.a -o lin-bookstore-x64

bookstore.a: book.o bookstore.o technicalbook.o managementbook.o
	ar rcs bookstore.a book.o bookstore.o technicalbook.o managementbook.o 

main.o: main.cpp
	g++ -c main.cpp -o main.o

book.o: Book.cpp Book.h
	g++ -c Book.cpp -o book.o

bookstore.o: Bookstore.cpp Bookstore.h
	g++ -c Bookstore.cpp -std=c++11 -o bookstore.o

technicalbook.o: TechnicalBook.cpp TechnicalBook.h
	g++ -c TechnicalBook.cpp -o technicalbook.o

managementbook.o: ManagementBook.cpp ManagementBook.h
	g++ -c ManagementBook.cpp -o managementbook.o

clean:
	rm -rf *o lin-bookstore-x64