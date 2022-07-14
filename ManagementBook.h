#ifndef MANAGEMENT_BOOK_H
#define MANAGEMENT_BOOK_H
#include"Book.h"
class ManagementBook : public Book {
private:
	int discount;
public:
	ManagementBook(char* title, int cost, int stock);
	int getDiscount();
	~ManagementBook();
};
#endif