#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include"Book.h"
#include"ManagementBook.h"
#include"TechnicalBook.h"

class Bookstore {
private:
	Book* books[4];
public:
	Bookstore();
	void addBook();
	void displayBooks();
	void searchBook();
	~Bookstore();
};
#endif