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
	int input;
	cout<<"Enter 1: to add Technical Book\n2: to add Management Book"<<endl;
    cin >>input;
    if((input > 2) || (input < 1) ) {
        cout <<"Invalid Input"<<endl;
        return;
    }

	cout << "Enter Book Title, Price, Quantity";
	int price, quantity, i;
	bool index = -1;
	char title[10];
	cin >> title >> price >> quantity;

    if(1 == input) {
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
			books[index] = new TechnicalBook(title, price, quantity);
			cout << "New Technical Book added successfully" <<endl;
			bookCount++;
		}
    }
    else if(2 == input) {
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
			books[index] = new ManagementBook(title, price, quantity);
			cout << "New Management Book added successfully" <<endl;
			bookCount++;
		}
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