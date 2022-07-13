#include<iostream>
#include<cstring>
using namespace std;
#include"Book.h"

Book::Book(char* title, int cost, int stock):bookTitle(new char[strlen(title)+1]),bookCost(cost), bookStock(stock)
{
	strcpy(bookTitle, title);
	bookTitle[strlen(title)] = '\0';
}

void Book::displayBookDetails()
{
	cout <<"------------------------------"<<endl;
	cout<<"Book Title: " << bookTitle<<endl;
	cout<<"Book Cost:  " << bookCost<<endl;
	cout<<"Book Stock: " << bookStock<<endl;
}

char* Book::getBookTitle()
{
	return bookTitle;
}

int Book::getBookCost()
{
	return bookCost;
}

int Book::getBookStock()
{
	return bookStock;
}

void Book::setBookStock(int stock)
{
	bookStock = stock;
}

Book::~Book()
{
	delete[] bookTitle;
}