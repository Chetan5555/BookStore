#include"ManagementBook.h"

ManagementBook::ManagementBook(char* title, int cost, int stock):Book(title, cost, stock),discount(10)
{
}

int ManagementBook::getDiscount()
{
	return discount;
}

ManagementBook::~ManagementBook()
{
}
