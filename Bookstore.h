#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include"Book.h"
#include"ManagementBook.h"
#include"TechnicalBook.h"
#include<map>

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return std::strcmp(a, b) < 0;
   }
};

class Bookstore {
private:
	map<char*, Book*, cmp_str> books;
public:
	Bookstore();
	void addBook();
	void displayBooks();
	void searchBook();
	~Bookstore();
};
#endif