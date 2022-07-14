#include<iostream>
#include<cstring>
using namespace std;

#include"Bookstore.h"

Bookstore::Bookstore()
{
    for(int i = 0; i < 4; i++)
    	books[i] = NULL;
    bookCount = 0;
}

void Bookstore::addBook()
{
	cout << "Enter Book Title, Price, Quantity";
	int price, quantity, i;
	bool index = -1;
	char title[10];
	cin >> title >> price >> quantity;
	for(i = 0; i < 4; i++) {
		if(NULL == books[i]) {
			if(-1 != index)
				index = i;
		}
		else if(0 == strcmp(title, books[i]->getBookTitle())) {
            books[i]->setBookStock(books[i]->getBookStock() + quantity);
            cout << "Book with the title already Exist. Updated stocks"<<endl;
            return;
		}
	}
	if(-1 == index) {
		cout << "No space in Book Store" <<endl;
	}
	else {
		books[index] = new Book(title, price, quantity);
		cout << "New Book added Successfully" <<endl;
		bookCount++;
	}

}

void Bookstore::displayBooks()
{
	if(0 == bookCount)
		cout<<"Bookstore is empty" <<endl;
	else {
		for(int i = 0; i < 4; i++) {
			if(NULL != books[i])
				books[i]->displayBookDetails();
		}
		cout <<"------------------------------"<<endl;
	}
}

void Bookstore::searchBook()
{
	char title[10];
	int quantity,i;

    cout<<"Enter title and Quantity : "<<endl;
    cin>>title>>quantity;

    for(i = 0; i < 4; i++) {
    	if(NULL != books[i]) {
			if(0 == strcmp(title, books[i]->getBookTitle())) {
				if(quantity <= books[i]->getBookStock()) {
					cout<<"Book available with sufficient stock"<<endl;
					cout<<"Billing Cost : "<< quantity*(books[i]->getBookCost())<<endl;
					books[i]->setBookStock((books[i]->getBookStock()) - quantity);
				}
				else {
					cout<<"Book available but the stock is insufficient"<<endl;
				}
				break;
			}
    	}
    }
    
	if(4 == i)
       	cout<<"Book for the specified title does not exist"<<endl;
}

Bookstore::~Bookstore()
{
    for(int i = 0; i < 4; i++)
    	if(NULL != books[i])
    		delete books[i];
}