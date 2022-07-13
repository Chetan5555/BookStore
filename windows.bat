@ECHO off
g++ -c Book.cpp -o book.o
g++ -c main.cpp -o main.o
g++ -c Bookstore.cpp -o bookstore.o
g++ book.o main.o bookstore.o -o win-bookstore-x64