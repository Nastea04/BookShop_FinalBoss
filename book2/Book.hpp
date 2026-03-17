#ifndef BOOK_HPP
#define BOOK_HPP
#include "Author.hpp"

class Book {
private:
	string title;
	Author author;
	int pages;
	int rate;
	double price;
	bool hardCovers;
	int count;
	string genre;
	string language;
public:
	//get
	string getTitle();
	Author getAuthor();
	int getPages();
	int getRate();
	double getPrice();
	bool getHardCovers();
	int getCount();
	string getGenre();
	string getLanguage();
	//set
	void setTitle(string title);
	void setAuthor(Author author);
	void setPages(int pages);
	void setRate(int rate);
	void setPrice(double price);
	void setHardCovers(bool hardCovers);
	void setCount(int count);
	void setGenre(string genre);
	void setLanguage(string language);

	//foo
	void getInfo();
	void printInfo();

	void putInFile();
	int getFromFile(int cursor);
};

#endif // !BOOK_HPP
