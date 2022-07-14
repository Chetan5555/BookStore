@ECHO off
g++ -c Book.cpp -o book.o
g++ -c main.cpp -o main.o
g++ -c Bookstore.cpp -o bookstore.o
g++ -c TechnicalBook.cpp -o technicalbook.o
g++ -c ManagementBook.cpp -o managementbook.o
g++ book.o main.o bookstore.o technicalbook.o managementbook.o -o win-bookstore-x64