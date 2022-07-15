#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include"Book.h"
#include"ManagementBook.h"
#include"TechnicalBook.h"
#include<list>
class Bookstore {
private:
	// Book* books[4];
	list<Book*> books;
public:
	Bookstore();
	void addBook();
	void displayBooks();
	void searchBook();
	~Bookstore();
};
#endif