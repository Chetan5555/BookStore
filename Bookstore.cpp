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

    map<char*, Book*>::iterator book = books.find(title);
    if(books.end() != book) {
		book->second->setBookStock((book->second)->getBookStock() + quantity);
		cout << "Book with the title already Exist. Updated stocks"<<endl;
    }
    else {
		char* name = new char[strlen(title)+1];
		strcpy(name, title);
    	if(1 == input) {
			books.insert({name, new TechnicalBook(title, price, quantity)});
			cout << "New Technical Book added successfully" <<endl;
    	}
    	else {
			books.insert({name, new ManagementBook(title, price, quantity)});
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
		for(auto book : books) {
			(book.second)->displayBookDetails();
			displayedBooks++;
		}
    }
    else if(2 == input) {
		for(auto book : books) {
			if(typeid(TechnicalBook).name() == typeid(*(book.second)).name()) {
				(book.second)->displayBookDetails();
				displayedBooks++;
			}
		}
    }
    else if(3 == input) {
		for(auto book : books) {
			if(typeid(ManagementBook).name() == typeid(*(book.second)).name()) {
				(book.second)->displayBookDetails();
				displayedBooks++;
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

    map<char*, Book*>::iterator book = books.find(title);
    if(books.end() != book) {
		if(quantity <= (book->second->getBookStock())) {
			cout<<"Book available with sufficient stock"<<endl;
			if(typeid(ManagementBook).name() == typeid(*(book->second)).name()) {
				billingCost = (book->second->getBookCost()) - (((book->second->getBookCost())*((ManagementBook*)(book->second))->getDiscount())/100.0);
			}
			else {
				billingCost = (book->second->getBookCost()) - (((book->second->getBookCost())*((TechnicalBook*)(book->second))->getDiscount())/100.0);
			}
			cout<<"Billing Cost : "<< quantity*billingCost<<endl;
			book->second->setBookStock((book->second->getBookStock()) - quantity);
			if(0 == book->second->getBookStock()) {
				Book* temp = book->second;
			    char* name = book->first;
                books.erase(book->first);
        		delete temp;
				delete[] name;
			}
		}
		else {
			cout<<"Book available but the stock is insufficient"<<endl;
		}
    }
    else {
        cout<<"Book for the specified title does not exist"<<endl;
    }
}

Bookstore::~Bookstore()
{
	// Book* temp = NULL;
	// char* name = NULL;

	// for(auto book : books) {
	// 	temp = book.second;
	// 	name = book.first;
	// 	books.erase(book.first); 
	// FOR INCREMENAT THEIR COULD BE DEPENDENCY ON BOOK VARIABLE WHICH IS CAUSING THE ISSUE AS BOOK  
	// VARIABLE DOESN'T EXIST.
	// 	delete temp;
	// 	delete[] name;
	// }
	map<char*, Book*>::iterator itr;
	map<char*, Book*>::iterator itr1;
	char* s = NULL;
	for(itr = books.begin(); itr != books.end();)
	{
		itr1 = itr;
		itr++;
		delete (itr1->second);
		s = itr1->first;
		books.erase(itr1->first);
		delete[] s;
	}
}