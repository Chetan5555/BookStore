#include<iostream>
#include<cstring>
using namespace std;
#include <typeinfo>

#include"Bookstore.h"

Bookstore::Bookstore()
{
    for(int i = 0; i < 4; i++)
    	books[i] = NULL;
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
	int price, quantity, i;
	int index = -1;
	char title[10];
	cin >> title >> price >> quantity;

    if(1 == input) {
		for(i = 0; i < 4; i++) {
			if(NULL == books[i]) {
				if(-1 == index)
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
			books[index] = new TechnicalBook(title, price, quantity);
			cout << "New Technical Book added successfully" <<endl;
		}
    }
    else if(2 == input) {
		for(i = 0; i < 4; i++) {
			if(NULL == books[i]) {
				if(-1 == index)
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
			books[index] = new ManagementBook(title, price, quantity);
			cout << "New Management Book added successfully" <<endl;
		}
    }
}

void Bookstore::displayBooks()
{
    int displayedBooks = 0;
    int input;

    cout<<"Enter\n1: to display all Books\n2: to display Technical Books\n3: to display Management Books\n";
    cin >> input;
    if(1 == input) {
		for(int i = 0; i < 4; i++) {
			if(NULL != books[i]) {
				books[i]->displayBookDetails();
				displayedBooks++;
			}
		}
    }
    else if(2 == input) {
		for(int i = 0; i < 4; i++) {
			if(NULL != books[i]) {
				if(typeid(TechnicalBook).name() == typeid(*(books[i])).name()) {
					books[i]->displayBookDetails();
					displayedBooks++;
				}
			}
		}
    }
    else if(3 == input) {
		for(int i = 0; i < 4; i++) {
			if(NULL != books[i]) {
				if(typeid(ManagementBook).name() == typeid(*(books[i])).name()) {
					books[i]->displayBookDetails();
					displayedBooks++;
				}
			}
		}
    }
    else {
    	cout << "Invalid option"<<endl;
    }

    if(0 == displayedBooks) {
    	cout<<"No Books available"<<endl;
    }
	cout <<"-------------------------------------"<<endl;
}

void Bookstore::searchBook()
{
	char title[10];
	int quantity,i;

    cout<<"Enter title and Quantity : "<<endl;
    cin>>title>>quantity;
    int billingCost = 0;

    for(i = 0; i < 4; i++) {
    	if(NULL != books[i]) {
			if(0 == strcmp(title, books[i]->getBookTitle())) {
				if(quantity <= books[i]->getBookStock()) {
					cout<<"Book available with sufficient stock"<<endl;
					if(typeid(ManagementBook).name() == typeid(*(books[i])).name()) {
						billingCost = (books[i]->getBookCost()) - (((books[i]->getBookCost())*((ManagementBook*)(books[i]))->getDiscount())/100.0);
					}
					else {
						billingCost = (books[i]->getBookCost()) - (((books[i]->getBookCost())*((TechnicalBook*)(books[i]))->getDiscount())/100.0);
					}
					cout<<"Billing Cost : "<< quantity*billingCost<<endl;
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