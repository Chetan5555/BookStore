#include<iostream>
#include<cstring>
using namespace std;

#include"Book.h"

void menu()
{
	cout<<"Enter"<<endl;
	cout<<"1: Version"<<endl;
	cout<<"2: Display Books"<<endl;
	cout<<"3: Search For Book"<<endl;
}
int main()
{
	int input, i, quantity;
	char title[10];
	char book1[10] = "Kannada";
	char book2[10] = "English";
	char book3[10] = "Maths";

	Book books[3] = {Book(book1, 20, 2), Book(book2, 30, 3), Book(book3, 40, 4)};
	while(1) {
		menu();
        cin >>input;
        switch(input) {
            case 1:
                cout<<"Version : 2.0"<<endl;
                break;
            case 2:
                for(i = 0; i < 3; i++)
                	books[i].displayBookDetails();
                break;
            case 3:
                cout<<"Enter title and Quantity : "<<endl;
                cin>>title>>quantity;
            	for(i = 0; i < 3; i++) {
                    if(0 == strcmp(title, books[i].getBookTitle())) {
                    	if(quantity <= books[i].getBookStock()) {
                    		cout<<"Book available with sufficient stock"<<endl;
                    		cout<<"Billing Cost : "<< quantity*books[i].getBookCost()<<endl;
                    		books[i].setBookStock(books[i].getBookStock() - quantity);
                    	}
                    	else {
                    		cout<<"Book available but the stock is insufficient"<<endl;
                    	}
                    	break;
                    }
            	}
                if(3 == i)
                	cout<<"Book for the specified title does not exist"<<endl;
                break;
            default:
                exit(0);
            	break;
        }
	}
}