#include"ManagementBook.h"

ManagementBook::ManagementBook(char* title, int cost, int stock):Book(title, cost, stock),discount(10)
{
}

void ManagementBook::displayBookDetails()
{
	Book::displayBookDetails();
	cout <<"Discount : "<<discount<<endl;
}

int ManagementBook::getDiscount()
{
	return discount;
}

ManagementBook::~ManagementBook()
{
}
