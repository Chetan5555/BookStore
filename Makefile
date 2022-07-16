all: lin-bookstore-x64

lin-bookstore-x64: main.o lib.so
	g++ main.o lib.so -o lin-bookstore-x64

main.o: main.cpp
	g++ -c main.cpp -o main.o

lib.so: book.o bookstore.o technicalbook.o managementbook.o
	g++ -shared book.o bookstore.o technicalbook.o managementbook.o -o lib.so

book.o: Book.cpp Book.h
	g++ -fPIC -c Book.cpp -o book.o

bookstore.o: Bookstore.cpp Bookstore.h
	g++ -fPIC -std=c++11 -c Bookstore.cpp -o bookstore.o

technicalbook.o: TechnicalBook.cpp TechnicalBook.h
	g++ -fPIC -c TechnicalBook.cpp -o technicalbook.o

managementbook.o: ManagementBook.cpp ManagementBook.h
	g++ -fPIC -c ManagementBook.cpp -o managementbook.o

clean:
	rm -rf *o lin-bookstore-x64