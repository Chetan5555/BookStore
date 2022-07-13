#include<iostream>
#include<cstring>
using namespace std;

#include"Book.h"
#include"Bookstore.h"

void menu()
{
	cout<<"Enter"<<endl;
	cout<<"1: Version"<<endl;
	cout<<"2: Display Books"<<endl;
	cout<<"3: Search For Book"<<endl;
    cout<<"4: Add Book"<<endl;
}
int main()
{
	int input;
	Bookstore b;

	while(1) {
		menu();
        cin >>input;
        switch(input) {
            case 1:
                cout<<"Version : 2.0"<<endl;
                break;
            case 2:
                b.displayBooks();
                break;
            case 3:
                b.searchBook();
                break;
            case 4:
                b.addBook();
                break;
            default:
                exit(0);
            	break;
        }
	}
}