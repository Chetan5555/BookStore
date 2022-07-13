@ECHO off
g++ -c Book.cpp -o book.o
g++ -c main.cpp -o main.o
g++ book.o main.o -o book