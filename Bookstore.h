#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include"Book.h"

class Bookstore {
private:
	int bookCount;
	Book* books[4];
public:
	Bookstore();
	void addBook();
	void displayBooks();
	void searchBook();
	~Bookstore();
};
#endif