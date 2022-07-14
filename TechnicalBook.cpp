#include"TechnicalBook.h"

TechnicalBook::TechnicalBook(char* title, int cost, int stock):Book(title, cost, stock),discount(5)
{
}

int TechnicalBook::getDiscount()
{
	return discount;
}

TechnicalBook::~TechnicalBook()
{
}
