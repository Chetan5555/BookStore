#ifndef TECHNICAL_BOOK_H
#define TECHNICAL_BOOK_H
#include"Book.h"
class TechnicalBook : public Book {
private:
	int discount;
public:
	TechnicalBook(char* title, int cost, int stock);
	virtual void displayBookDetails();
	int getDiscount();
	~TechnicalBook();
};
#endif