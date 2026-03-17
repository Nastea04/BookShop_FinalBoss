#ifndef BOOKSHOP_HPP
#define BOOKSHOP_HPP
#include "Book.hpp"
#include<vector>

class BookShop {
private:
	vector<Book> books;
	string name;
	string address;
public:
	vector<Book> getBooks();
	string getName();
	string getAddress();

	void setBooks(vector<Book> books);
	void setName(string name);
	void setAddress(string address);

	void availableBooks();
	void missingBooks();
	void printAll();
	void minusBook();
	void plusBook();
	void searchByLanguage();
	void searchByGenre();
	void searchByPriceRange();
	void addBook();
	void removeBook();

	void printInfo();
	void getInfo();


	void putInFile();
	void getFromFile();
};

#endif