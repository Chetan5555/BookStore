#include<iostream>
#include<cstring>
using namespace std;
#include <typeinfo>

#include"Bookstore.h"

Bookstore::Bookstore()
{
}

void Bookstore::addBook()
{
	int input;
	cout<<"Enter \n1: to add Technical Book\n2: to add Management Book"<<endl;
    cin >>input;
    if((input > 2) || (input < 1) ) {
        cout <<"Invalid Input"<<endl;
        return;
    }

	cout << "Enter Book Title, Price, Quantity";
	int price, quantity;
	char title[10];
	cin >> title >> price >> quantity;

    if(1 == input) {
    	for(auto book : books) {
			if(0 == strcmp(title, book->getBookTitle())) {
				book->setBookStock(book->getBookStock() + quantity);
				cout << "Book with the title already Exist. Updated stocks"<<endl;
				return;
			}
		}
		books.insert(books.begin(), new TechnicalBook(title, price, quantity));
		cout << "New Technical Book added successfully" <<endl;
    }
    else if(2 == input) {
    	for(auto book : books) {
    		if(0 == strcmp(title, book->getBookTitle())) {
				book->setBookStock(book->getBookStock() + quantity);
				cout << "Book with the title already Exist. Updated stocks"<<endl;
				return;
			}
		}
		books.insert(books.begin(), new ManagementBook(title, price, quantity));
		cout << "New Management Book added successfully" <<endl;
    }
}

void Bookstore::displayBooks()
{
    int displayedBooks = 0;
    int input;

    cout<<"Enter\n1: to display all Books\n2: to display Technical Books\n3: to display Management Books\n";
    cin >> input;
    if(1 == input) {
		for(auto book : books) {
			if(NULL != book) {
				book->displayBookDetails();
				displayedBooks++;
			}
		}
    }
    else if(2 == input) {
		for(auto book : books) {
			if(NULL != book) {
				if(typeid(TechnicalBook).name() == typeid(*(book)).name()) {
					book->displayBookDetails();
					displayedBooks++;
				}
			}
		}
    }
    else if(3 == input) {
		for(auto book : books) {
			if(NULL != book) {
				if(typeid(ManagementBook).name() == typeid(*book).name()) {
					book->displayBookDetails();
					displayedBooks++;
				}
			}
		}
    }
    else {
    	cout << "Invalid option"<<endl;
    	return;
    }

    if(0 == displayedBooks) {
    	cout<<"No Books available"<<endl;
    }
	cout <<"-------------------------------------"<<endl;
}

void Bookstore::searchBook()
{
	char title[10];
	int quantity;

    cout<<"Enter title and Quantity : "<<endl;
    cin>>title>>quantity;
    double billingCost = 0;

	for(auto book : books) {
		if(NULL != book) {
			if(0 == strcmp(title, book->getBookTitle())) {
				if(quantity <= (book->getBookStock())) {
					cout<<"Book available with sufficient stock"<<endl;
					if(typeid(ManagementBook).name() == typeid(*(book)).name()) {
						billingCost = (book->getBookCost()) - (((book->getBookCost())*((ManagementBook*)(book))->getDiscount())/100.0);
					}
					else {
						billingCost = (book->getBookCost()) - (((book->getBookCost())*((TechnicalBook*)(book))->getDiscount())/100.0);
					}
					cout<<"Billing Cost : "<< quantity*billingCost<<endl;
					book->setBookStock((book->getBookStock()) - quantity);
					return;
				}
				else {
					cout<<"Book available but the stock is insufficient"<<endl;
					return;
				}
			}
    	}
    }
    cout<<"Book for the specified title does not exist"<<endl;
}

Bookstore::~Bookstore()
{
	for(auto book : books)
		if(NULL != book)
    		delete book;
}