#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<cstring>
using namespace std;

class Book {
private:
	char* bookTitle;
	int   bookCost;
	int   bookStock;

public:
	Book(char* title, int cost, int stock);
	virtual void displayBookDetails();
	char* getBookTitle();
	int   getBookCost();
	int   getBookStock();
	void  setBookStock(int stock);
	virtual ~Book();
};
#endif