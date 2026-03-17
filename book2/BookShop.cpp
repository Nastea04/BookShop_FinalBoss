#include "BookShop.hpp"

vector<Book> BookShop::getBooks()
{
	return books;
}

string BookShop::getName()
{
	return name;
}

string BookShop::getAddress()
{
	return address;
}

void BookShop::setBooks(vector<Book> books)
{
	this->books = books;
}

void BookShop::setName(string name)
{
	this->name = name;
}

void BookShop::setAddress(string address)
{
	this->address = address;
}

void BookShop::availableBooks()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].getCount() > 0) {
			cout << "#" << i + 1 << endl;
			books[i].printInfo();
			cout << "------------------------\n\n";
		}
	}
}

void BookShop::missingBooks()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].getCount() == 0) {
			cout << "#" << i + 1 << endl;
			books[i].printInfo();
			cout << "------------------------\n\n";
		}
	}
}

void BookShop::printAll()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		books[i].printInfo();
		cout << "------------------------\n\n";

	}
}

void BookShop::minusBook()
{
	printAll();
	cout << "Choose book id: ";
	int id;
	cin >> id;
	id--;
	cout << "Choose count to substract: ";
	int br;
	cin >> br;
	if (books[id].getCount() < br) {
		cout << "Error!\nNot enough books!!!\n";
	}
	else {
		books[id].setCount(books[id].getCount() - br);
		cout << "Done!\nBooks left: " << books[id].getCount() << endl;
	}
}

void BookShop::plusBook()
{
	printAll();
	cout << "Choose book id: ";
	int id;
	cin >> id;
	id--;
	cout << "Choose count to add: ";
	int br;
	cin >> br;
	books[id].setCount(books[id].getCount() + br);
	cout << "Done!\nBooks left: " << books[id].getCount() << endl;
}

void BookShop::searchByLanguage()
{
	cout << "---> Search by language\n";
	cout << "Enter language: ";
	string lg;
	cin >> lg;
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].getLanguage() == lg) {
			books[i].printInfo();
		}
	}
}

void BookShop::searchByGenre()
{
	cout << "---> Search by genre\n";
	cout << "Enter genre: ";
	string g;
	cin >> g;
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].getGenre() == g) {
			books[i].printInfo();
		}
	}
}

void BookShop::searchByPriceRange()
{
	cout << "---> Search by price range\n";
	cout << "Enter starting price: ";
	int s;
	cin >> s;
	cout << "Enter ending price: ";
	int e;
	cin >> e;
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].getPrice() >= s && books[i].getPrice() <= e) {
			books[i].printInfo();
		}
	}
}

void BookShop::addBook()
{
	Book temp;
	temp.getInfo();
	books.push_back(temp);
}

void BookShop::removeBook()
{
	printAll();
	cout << "---> Remove book\n";
	cout << "Enter book id: ";
	int id;
	cin >> id;
	id--;
	books.erase(books.begin() + id);
	cout << "---> Removed!\n";
}

void BookShop::printInfo()
{
	cout << "------> " << name << endl;
	cout << "| \n";
	cout << "| address: " << address << endl;
	cout << "| \n";
	cout << "| books types: " << books.size() << endl;
	cout << "|_______________\n";
}

void BookShop::getInfo()
{
	cout << "---> BookShop new info\n";
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter address: ";
	cin.ignore();
	getline(cin, address);
}
#include<fstream>
void BookShop::putInFile()
{
	ofstream fout("info.txt");
	fout << books.size() << endl;
	fout << name << endl;
	fout << address << endl;
	fout.close();
	for (size_t i = 0; i < books.size(); i++)
	{
		books[i].putInFile();
	}
}

void BookShop::getFromFile()
{
	ifstream fin("info.txt");
	int br;
	fin >> br;
	fin.ignore();
	getline(fin, name);
	getline(fin, address);
	int cursor = fin.tellg();
	fin.close();
	for (size_t i = 0; i < br; i++)
	{
		Book temp;
		cursor = temp.getFromFile(cursor);
		books.push_back(temp);
	}
}
