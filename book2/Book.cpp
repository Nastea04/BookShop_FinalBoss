#include "Book.hpp"

string Book::getTitle()
{
	return title;
}

Author Book::getAuthor()
{
	return author;
}

int Book::getPages()
{
	return pages;
}

int Book::getRate()
{
	return rate;
}

double Book::getPrice()
{
	return price;
}

bool Book::getHardCovers()
{
	return hardCovers;
}

int Book::getCount()
{
	return count;
}

string Book::getGenre()
{
	return genre;
}

string Book::getLanguage()
{
	return language;
}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setAuthor(Author author)
{
	this->author = author;
}

void Book::setPages(int pages)
{
	this->pages = pages;
}

void Book::setRate(int rate)
{
	this->rate = rate;
}

void Book::setPrice(double price)
{
	this->price = price;
}

void Book::setHardCovers(bool hardCovers)
{
	this->hardCovers = hardCovers;
}

void Book::setCount(int count)
{
	this->count = count;
}

void Book::setGenre(string genre)
{
	this->genre = genre;
}

void Book::setLanguage(string language)
{
	this->language = language;
}

void Book::getInfo() {
	cout << "---> Book\n";
	cout << "Title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Count of pages: ";
	cin >> pages;
	cout << "Rating(1-5): ";
	cin >> rate;
	cout << "Price: ";
	cin >> price;
	cout << "Hard covers(0-no, 1-yes): ";
	cin >> hardCovers;
	cout << "Count in bookshop: ";
	cin >> count;
	cout << "Genre: ";
	cin >> genre;
	cout << "Language: ";
	cin >> language;
	author.getInfo();
}
void Book::printInfo() {
	cout << "~~~~~" << title << "~~~~~\n";
	cout << "Pages: " << pages << endl;
	cout << "Rating: ";
	for (int i = 0; i < rate; i++) {
		cout << " * ";
	}
	cout << endl << "Price: " << price << "$\n";
	cout << "Covers: ";
	if (hardCovers) cout << "hard\n";
	else cout << "soft\n";
	cout << "Count in bookshop: " << count << endl;
	cout << "Genre: " << genre << endl;
	cout << "Language: " << language << endl;
	author.printInfo();
}
#include<fstream>
void Book::putInFile()
{
	ofstream fout("info.txt", ios::app);
	fout << title << endl;
	fout << pages << " " << rate << " " << price << " ";
	fout << hardCovers << " " << count << " ";
	fout << genre << " " << language << endl;
	fout.close();
	author.putInFile();
}

int Book::getFromFile(int cursor)
{
	ifstream fin("info.txt");
	fin.seekg(cursor);
	fin.ignore();
	getline(fin, title);
	fin >> pages >> rate >> price >> hardCovers;
	fin >> count >> genre >> language;
	cursor = fin.tellg();
	fin.close();
	cursor = author.getFromFile(cursor);
	return cursor;
}
