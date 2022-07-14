#include"TechnicalBook.h"

TechnicalBook::TechnicalBook(char* title, int cost, int stock):Book(title, cost, stock),discount(5)
{
}

void TechnicalBook::displayBookDetails()
{
	Book::displayBookDetails();
	cout <<"Discount : "<<discount<<endl;
}

int TechnicalBook::getDiscount()
{
	return discount;
}

TechnicalBook::~TechnicalBook()
{
}
