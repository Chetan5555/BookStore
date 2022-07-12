#ifndef BOOK_H
#define BOOK_H
class Book {
private:
	char* bookTitle;
	int   bookCost;
	int   bookStock;

public:
	Book(char* title, int cost, int stock);
	void displayBookDetails();
	//void searchForBook(char* title, int quantity);
	char* getBookTitle();
	int   getBookCost();
	int   getBookStock();
	void  setBookStock(int stock);
	~Book();
};
#endif